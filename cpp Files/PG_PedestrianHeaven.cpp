#include <vector>

using std :: vector ;

int MOD = 20170805;

int solution ( int m , int n , vector < vector < int > > city_map )
{
	int answer = 0 ;
	vector < vector < vector < int > > > vDP ( m , ( vector < vector < int > > ( n , ( vector < int > ( 2 , 0 ) ) ) ) ) ;		 // [ X ] [ Y ] [ 0 : Vertical, 1 : Horizontal]
	
	
	
	vDP [ 0 ] [ 0 ] [ 0 ] = vDP [ 0 ] [ 0 ] [ 1 ] = 1 ;
	
	for ( int i = 0 ; i < m ; ++i )
	{
		int * ipMap = city_map [ i ].data () ;
		
		for ( int j = 0 ; j < n ; ++j )
		{
			int iMapIndicator = * ipMap ++ ;
			int irgXDirection [ 2 ] = { 0 , -1 } ;
			int irgYDirection [ 2 ] = { -1 , 0 } ;
			
			if ( 1 == iMapIndicator )			// Forbidden
				continue ;
			
			for ( int iDirection = 0 ; iDirection < 2 ; ++ iDirection )			 // 0 : Count left, 1 : Count up
			{
				int iTempX = i + irgXDirection [ iDirection ] ;
				int iTempY = j + irgYDirection [ iDirection ] ;
				
				
				if ( ( iTempX < 0 ) || ( m - 1 < iTempX ) || ( iTempY < 0 ) || ( n - 1 < iTempY ) )		 // Out of bound
					continue ;
				
				
				vDP [ i ] [ j ] [ iDirection ] += vDP [ iTempX ] [ iTempY ] [ iDirection ] ;
				vDP [ i ] [ j ] [ iDirection ] %= MOD ;

				if ( 0 == iMapIndicator )
				{
					vDP [ i ] [ j ] [ ( iDirection + 1 ) & 1 ] += vDP [ iTempX ] [ iTempY ] [ iDirection ] ;
					vDP [ i ] [ j ] [ ( iDirection + 1 ) & 1 ] %= MOD ;
				}
			}
		}
	}
	
	
	return ( vDP [ m - 1 ] [ n - 2 ] [ 0 ] + vDP [ m - 2 ] [ n - 1 ] [ 1 ] ) % MOD ;
}