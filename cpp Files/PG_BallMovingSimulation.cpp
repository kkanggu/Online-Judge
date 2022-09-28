#include <vector>
#include <algorithm>

using std :: vector ;
using std :: min ;
using std :: max ;

long long solution ( int n , int m , int x , int y , vector < vector < int > > queries )
{
	long long llMaxX = x ;
	long long llMinX = x ;
	long long llMaxY = y ;
	long long llMinY = y ;
	int iQuerySize = queries.size () ;



	for ( int i = iQuerySize - 1 ; i >= 0 ; --i )
	{
		int iMoveIndex = queries [ i ] [ 0 ] ;
		int iMoveCount = queries [ i ] [ 1 ] ;


		if ( 0 == iMoveIndex )
		{
			llMaxY += iMoveCount ;

			if ( llMaxY > m - 1 )
				llMaxY = m - 1 ;
			if ( 0 != llMinY )
				llMinY += iMoveCount ;
		}
		else if ( 1 == iMoveIndex )
		{
			llMinY -= iMoveCount ;

			if ( llMinY < 0 )
				llMinY = 0 ;
			if ( llMaxY != m - 1 )
				llMaxY -= iMoveCount ;
		}
		else if ( 2 == iMoveIndex )
		{
			llMaxX += iMoveCount ;

			if ( llMaxX > n - 1 )
				llMaxX = n - 1 ;
			if ( 0 != llMinX )
				llMinX += iMoveCount ;
		}
		else if ( 3 == iMoveIndex )
		{
			llMinX -= iMoveCount ;

			if ( llMinX < 0 )
				llMinX = 0 ;
			if ( llMaxX != n - 1 )
				llMaxX -= iMoveCount ;
		}

		if ( ( llMaxX < 0 ) || ( n - 1 < llMinX ) || ( llMaxY < 0 ) || ( m - 1 < llMinY ) )
			return 0 ;
	}


	return ( llMaxX - llMinX + 1 ) * ( llMaxY - llMinY + 1 ) ;
}