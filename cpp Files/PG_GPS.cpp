#include <vector>
#include <algorithm>

using std :: vector ;
using std :: min ;

int solution ( int n , int m , vector < vector < int > > edge_list , int k , vector < int > gps_log )
{
	vector < vector < bool > > vPath ( n , vector < bool > ( n , false ) ) ;
	vector < vector < int > > vDP ( 2 , vector < int > ( n , 1000 ) ) ;		// [ 0 ] current, [ 1 ] former
	int iEdgeSize = edge_list.size () ;
	int iGpsSize = gps_log.size () ;
	
	
	
	for ( int i = 0 ; i < iEdgeSize ; ++i )
	{
		int iFirst = edge_list [ i ] [ 0 ] - 1 ;
		int iSecond = edge_list [ i ] [ 1 ] - 1 ;
		
		vPath [ iFirst ] [ iSecond ] = true ;
		vPath [ iSecond ] [ iFirst ] = true ;
	}
	for ( int i = 0 ; i < n ; ++i )
	{
		vPath [ i ] [ i ] = true ;
	}
	
	vDP [ 0 ] [ gps_log [ 0 ] - 1 ] = 0 ;
	for ( int i = 1 ; i < iGpsSize ; ++i )
	{
		for ( int j = 0 ; j < n ; ++j )						// Copy i - 1 DP to former
		{
			vDP [ 1 ] [ j ] = vDP [ 0 ] [ j ] ;
		}
		for ( int iTarget = 0 ; iTarget < n ; ++ iTarget )	// Update DP
		{
			int iGap = ( iTarget == gps_log [ i ] - 1 ) ? 0 : 1 ;
			vDP [ 0 ] [ iTarget ] += iGap ;
			
			for ( int iStart = 0 ; iStart < n ; ++ iStart )
			{
				if ( ! vPath [ iStart ] [ iTarget ] )		// No path exist
					continue ;
				
				vDP [ 0 ] [ iTarget ] = min ( vDP [ 0 ] [ iTarget ] , vDP [ 1 ] [ iStart ] + iGap ) ;
			}
		}
	}
	
	if ( 1000 <= vDP [ 0 ] [ gps_log [ iGpsSize - 1 ] - 1 ] )
		return -1 ;
	
	return vDP [ 0 ] [ gps_log [ iGpsSize - 1 ] - 1 ] ;
}