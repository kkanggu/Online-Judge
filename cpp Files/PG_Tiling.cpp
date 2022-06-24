#include <string>
#include <vector>

using std :: vector ;
using std :: string ;

int solution ( int n )
{
	int irgDP [ 3 ] = { 1 , 2 , 3 } ;



	if ( n <= 3 )
		return irgDP [ n - 1 ] ;

	for ( int i = 3 ; i < n ; ++i )
	{
		irgDP [ 0 ] = irgDP [ 1 ] ;
		irgDP [ 1 ] = irgDP [ 2 ] ;
		irgDP [ 2 ] = ( irgDP [ 0 ] + irgDP [ 2 ] ) % 1000000007 ;
		
	}

	

	return irgDP [ 2 ] ;
}