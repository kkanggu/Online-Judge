#include <vector>

using std :: vector ;

int solution ( int m , int n , vector < vector < int > > puddles )
{
	int answer = 0 ;
	int iPuddleSize = puddles.size () ;
	vector < vector < int > > vDP ( n , ( vector < int > ( m , 0 ) ) ) ;
	
	
	
	vDP [ 0 ] [ 0 ] = 1 ;
	for ( int i = 0 ; i < iPuddleSize ; ++i )
	{
		vDP [ puddles [ i ] [ 1 ] - 1 ] [ puddles [ i ] [ 0 ] - 1 ] = -1 ;
	}
	
	for ( int i = 0 ; i < n ; ++i )
	{
		for ( int j = 0 ; j < m ; ++j )
		{
			if ( -1 == vDP [ i ] [ j ] )	// If puddle, ignore
				continue ;
			
			for ( int k = 0 ; k < 2 ; ++k )
			{
				int iX = i + 1 - k ;		// DOWN , RIGHT
				int iY = j + k ;
				
				if ( ( n == iX ) || ( m == iY ) || ( -1 == vDP [ iX ] [ iY ] ) )
					continue ;
				
				vDP [ iX ] [ iY ] += vDP [ i ] [ j ] ;
				vDP [ iX ] [ iY ] %= 1000000007 ;
			}
		}
	}
	
	
	return vDP [ n - 1 ] [ m - 1 ] ;
}