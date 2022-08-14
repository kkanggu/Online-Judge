#include <string>
#include <vector>
#include <algorithm>

using std :: string ;
using std :: vector ;
using std :: max ;

int solution ( string s )
{
	int answer = 1 ;
	int iStringSize = s.size () ;
	vector < vector < int > > vDP ( iStringSize , ( vector < int > ( iStringSize + 1 , 0 ) ) ) ;		// [ Start Index ] [ Length ]
	const char * cpString = s.data () ;
	
	
	
	vDP [ 0 ] [ 1 ] = 1 ;
	for ( int i = 1 ; i < iStringSize ; ++i )
	{
		char cCurrent = cpString [ i ] ;
		vDP [ i ] [ 1 ] = 1 ;
		
		for ( int iIndex = 0 ; iIndex < i ; ++ iIndex )
		{
			if ( ( cCurrent == cpString [ iIndex ] ) && ( 0 != vDP [ iIndex + 1 ] [ i - iIndex - 1 ] ) )
				vDP [ iIndex ] [ i - iIndex + 1 ] = cCurrent == cpString [ iIndex ] ? vDP [ iIndex + 1 ] [ i - iIndex - 1 ] + 2 : 0 ;
			vDP [ iIndex ] [ 2 ] = cCurrent == cpString [ iIndex ] ? 2 : 0 ;
			
			answer = max ( answer , vDP [ iIndex ] [ i - iIndex + 1 ] ) ;
		}
	}


	return answer ;
}