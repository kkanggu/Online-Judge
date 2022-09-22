#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using std :: vector ;
using std :: max ;
using std :: min ;
using std :: sort ;
using std :: unordered_map ;

int solution ( int n , vector < vector < int > > data )
{
	int answer = 0 ;
	int iDataSize = data.size () ;
	vector < int > vCompressX ;
	vector < int > vCompressY ;
	unordered_map < int , int > umCompressX ;
	unordered_map < int , int > umCompressY ;
	int iMaxX = 0 ;
	int iMaxY = 0 ;
	
	
	for ( int i = 0 ; i < iDataSize ; ++i )				// Add X,Y to vector
	{
		vCompressX.emplace_back ( data [ i ] [ 0 ] ) ;
		vCompressY.emplace_back ( data [ i ] [ 1 ] ) ;
	}
	
	sort ( vCompressX.begin () , vCompressX.end () ) ;
	sort ( vCompressY.begin () , vCompressY.end () ) ;
	sort ( data.begin () , data.end () , [] ( vector < int > & a , vector < int > & b )	 // Sort origin coordinate
											{
												if ( a [ 0 ] < b [ 0 ] )
													return true ;
												else if ( a [ 0 ] == b [ 0 ] )
													return a [ 1 ] < b [ 1 ] ;
												else
													return false ;
											} ) ;
	
	for ( int i = 0 ; i < iDataSize ; ++i )				// Compres X,Y
	{
		if ( ( 0 != vCompressX [ i ] ) && ( 0 == umCompressX [ vCompressX [ i ] ] ) )
		{
			umCompressX [ vCompressX [ i ] ] = ++ iMaxX ;
		}
		if ( ( 0 != vCompressY [ i ] ) && ( 0 == umCompressY [ vCompressY [ i ] ] ) )
		{
			umCompressY [ vCompressY [ i ] ] = ++ iMaxY ;
		}
	}
	
	vector < vector < int > > vDP ( iMaxX + 1 , vector < int > ( iMaxY + 1 , 0 ) ) ;
	
	for ( int i = 0 ; i < iDataSize ; ++i )				// Add compressed coordinate
	{
		int iX = data [ i ] [ 0 ] ;
		int iY = data [ i ] [ 1 ] ;
		
		++ vDP [ umCompressX [ iX ] ] [ umCompressY [ iY ] ] ;
	}
	
	for ( int i = 0 ; i <= iMaxX ; ++i )				// Change coordinate to DP
	{
		for ( int j = 0 ; j < iMaxY ; ++j )
		{
			vDP [ i ] [ j + 1 ] += vDP [ i ] [ j ] ;
		}
	}
	for ( int j = 0 ; j <= iMaxY ; ++j )
	{
		for ( int i = 0 ; i < iMaxX ; ++i )
		{
			vDP [ i + 1 ] [ j ] += vDP [ i ] [ j ] ;
		}
	}
	
	
	for ( int i = 0 ; i < iDataSize - 1 ; ++i )			// Find if can place tent with every pair
	{
		int iMinX = umCompressX [ data [ i ] [ 0 ] ] ;

		for ( int j = i + 1 ; j < iDataSize ; ++j )
		{
			int iMaxX = umCompressX [ data [ j ] [ 0 ] ] ;
			int iMaxY = max ( umCompressY [ data [ i ] [ 1 ] ] , umCompressY [ data [ j ] [ 1 ] ] ) ;
			int iMinY = min ( umCompressY [ data [ i ] [ 1 ] ] , umCompressY [ data [ j ] [ 1 ] ] ) ;


			if ( ( iMaxX == iMinX ) || ( iMaxY == iMinY ) )
				continue ;

			if ( ( iMaxX + 1 == iMinX ) || ( 1 == abs ( iMaxY - iMinY ) ) )
				++ answer ;
			else if ( 0 == vDP [ iMaxX - 1 ] [ iMaxY - 1 ] - vDP [ iMinX ] [ iMaxY - 1 ] - vDP [ iMaxX - 1 ] [ iMinY ] + vDP [ iMinX ] [ iMinY ] )
				++ answer ;
		}
	}
	
	
	return answer ;
}