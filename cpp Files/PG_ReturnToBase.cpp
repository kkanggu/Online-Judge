#include <vector>
#include <queue>

using std :: vector ;
using std :: queue ;

vector < int > solution ( int n , vector < vector < int > > roads , vector < int > sources , int destination )
{
	vector < int > answer ;
	vector < vector < int > > vPath ( n ) ;
	vector < int > vDest ( n , 1e5 ) ;
	int iRoadSize = roads.size () ;
	queue < int > qNode ;
	
	
	
	for ( int i = 0 ; i < iRoadSize ; ++i )
	{
		vPath [ roads [ i ] [ 0 ] - 1 ].emplace_back ( roads [ i ] [ 1 ] - 1 ) ;
		vPath [ roads [ i ] [ 1 ] - 1 ].emplace_back ( roads [ i ] [ 0 ] - 1 ) ;
	}
	
	qNode.emplace ( -- destination ) ;
	vDest [ destination ] = 0 ;
	
	while ( ! qNode.empty () )
	{
		int iNode = qNode.front () ;
		int iLength = vDest [ iNode ] ;
		qNode.pop () ;
		
		for ( int iTempDest : vPath [ iNode ] )
		{
			if ( 1e5 != vDest [ iTempDest ] )
				continue ;

			if ( iLength + 1 < vDest [ iTempDest ] )
			{
				vDest [ iTempDest ] = iLength + 1 ;
				qNode.emplace ( iTempDest ) ;
			}
		}
	}
	
	for ( int i : sources )
	{
		--i ;
		
		int iLength = vDest [ i ] ;
		
		if ( 1e5 <= iLength )
			iLength = -1 ;
		
		answer.emplace_back ( iLength ) ;
	}
	
	
	return answer ;
}