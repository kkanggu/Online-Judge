#include <vector>
#include <algorithm>

using std :: vector ;
using std :: min ;

int iGetLightSum ( vector < vector < int > > & vAdjacent , vector < vector < int > > & vDP , int iFormer , int iIndex , bool bLight )
{
	int iSize = vAdjacent [ iIndex ] .size () ;
	int iSum = bLight ? 1 : 0 ;
	
	
	
	for ( int i = 0 ; i < iSize ; ++i )
	{
		int iNext = vAdjacent [ iIndex ] [ i ] ;
		
		if ( iFormer != iNext )
		{
			if ( ( ! bLight ) && ( -1 != vDP [ iNext ] [ true ] ) )
			{
				iSum += vDP [ iNext ] [ true ] ;
			}
			else if ( ( bLight ) && ( -1 != vDP [ iNext ] [ true ] ) && ( -1 != vDP [ iNext ] [ false ] ) )
			{
				iSum += min ( vDP [ iNext ] [ true ] , vDP [ iNext ] [ false ] ) ;
			}
			else
			{
				if ( -1 == vDP [ iNext ] [ true ] )
					vDP [ iNext ] [ true ] = iGetLightSum ( vAdjacent , vDP , iIndex , iNext , true ) ;
				if ( -1 == vDP [ iNext ] [ false ] )
					vDP [ iNext ] [ false ] = iGetLightSum ( vAdjacent , vDP , iIndex , iNext , false ) ;
				
				if ( ! bLight )
					iSum += vDP [ iNext ] [ true ] ;
				else
					iSum += min ( vDP [ iNext ] [ true ] , vDP [ iNext ] [ false ] ) ;
			}
		}
	}
	
	return iSum ;
}

int solution ( int n , vector < vector < int > > lighthouse )
{
	vector < vector < int > > vAdjacent ( n ) ;
	vector < vector < int > > vDP ( n , vector < int > ( 2 , -1 ) ) ;	// [ DP with false, DP with true ]
	
	
	
	for ( int i = 0 ; i < n - 1 ; ++i )
	{
		int iNode1 = lighthouse [ i ] [ 0 ] - 1 ;
		int iNode2 = lighthouse [ i ] [ 1 ] - 1 ;
		
		vAdjacent [ iNode1 ].emplace_back ( iNode2 ) ;
		vAdjacent [ iNode2 ].emplace_back ( iNode1 ) ;
	}
	
	int iAnswer = iGetLightSum ( vAdjacent , vDP , -1 , 0 , true ) ;
	
	return min ( iAnswer , n - iAnswer ) ;
}

int main ()
{
	int i = solution ( 8, {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {5, 6}, {5, 7}, {5, 8}} ) ;
}