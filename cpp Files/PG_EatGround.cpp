#include <vector>
#include <algorithm>

using std :: vector ;
using std :: max ;

int solution(vector<vector<int> > land)
{
	int irgDP [ 2 ] [ 4 ] = { 0 , } ;
	int iLandSize = land.size () ;
	int iReturn = 0 ;



	for ( int i = 0 ; i < 4 ; ++i )
	{
		irgDP [ 1 ] [ i ] = land [ 0 ] [ i ] ;
	}
	for ( int i = 1 ; i < iLandSize ; ++i )
	{
		for ( int j = 0 ; j < 4 ; ++j )
		{
			irgDP [ 0 ] [ j ] = irgDP [ 1 ] [ j ] ;
			irgDP [ 1 ] [ j ] = 0 ;
		}
		for ( int j = 0 ; j < 4 ; ++j )
		{
			for ( int k = 0 ; k < 4 ; ++k )
			{
				if ( j != k )
				{
					irgDP [ 1 ] [ k ] = max ( irgDP [ 1 ] [ k ] , irgDP [ 0 ] [ j ] ) ;
				}
			}
		}
		for ( int j = 0 ; j < 4 ; ++j )
		{
			irgDP [ 1 ] [ j ] += land [ i ] [ j ] ;
		}
	}

	for ( int i = 0 ; i < 4 ; ++i )
	{
		iReturn = max ( iReturn , irgDP [ 1 ] [ i ] ) ;
	}

	return iReturn ;
}

int main ()
{
	int i = solution ( {{1,2,3,5},{5,6,7,8},{4,3,2,1}} ) ;
}