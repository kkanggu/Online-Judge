#include <string>
#include <vector>
#include <algorithm>

using std :: string ;
using std :: vector ;

int solution ( vector < vector < int > > triangle )
{
	int answer = 0 ;
	int iHeight = triangle.size () ;
	vector < vector < int > > vDP ( iHeight , ( vector < int > ( 2 , 0 ) ) ) ;		// [] [ 0 ] is Former line, [] [ 1 ] is new line
	
	
	
	vDP [ 0 ] [ 0 ] = triangle [ 0 ] [ 0 ] ;
	
	for ( int i = 1 ; i < iHeight ; ++i )
	{
		vDP [ 0 ] [ 1 ] = vDP [ 0 ] [ 0 ] + triangle [ i ] [ 0 ] ;
		for ( int j = 1 ; j < i ; ++j )
		{
			vDP [ j ] [ 1 ] = std :: max ( vDP [ j - 1 ] [ 0 ] , vDP [ j ] [ 0 ] ) + triangle [ i ] [ j ] ;
		}
		vDP [ i ] [ 1 ] = vDP [ i - 1 ] [ 0 ] + triangle [ i ] [ i ] ;
		
		
		for ( int j = 0 ; j <= i ; ++j )	  // Copy [] [ 1 ] to [] [ 0 ]
		{
			vDP [ j ] [ 0 ] = vDP [ j ] [ 1 ] ;
		}
	}
	
	for ( int i = 0 ; i < iHeight ; ++i )
	{
		answer = std :: max ( answer , vDP [ i ] [ 1 ] ) ;
	}
	
	return answer ;
}