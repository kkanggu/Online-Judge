#include <vector>
#include <cmath>

using std :: vector ;
using std :: max ;
using std :: min ;

		
void markMap ( vector < vector < int > > & vMap , vector < int > & vRect )
{
	int iMinX = vRect [ 0 ] << 1 ;
	int iMinY = vRect [ 1 ] << 1 ;
	int iMaxX = vRect [ 2 ] << 1 ;
	int iMaxY = vRect [ 3 ] << 1 ;
	
	
	
	for ( int i = iMinX ; i <= iMaxX ; ++i )			// Bottom and Top line
	{
		vMap [ i ] [ iMinY ] = vMap [ i ] [ iMaxY ] = 1 ;
	}
	for ( int j = iMinY + 1 ; j < iMaxY ; ++j )			// Left and Right line
	{
		vMap [ iMinX ] [ j ] = vMap [ iMaxX ] [ j ] = 1 ;
	}
}

int solution ( vector < vector < int > > rectangle , int characterX , int characterY , int itemX , int itemY )
{
	int answer = 0 ;
	int iMinX = min ( characterX , itemX ) << 1 ;
	int iMinY = min ( characterY , itemY ) << 1 ;
	int iMaxX = max ( characterX , itemX ) << 1 ;
	int iMaxY = max ( characterY , itemY ) << 1 ;
	vector < vector < int > > vMap ( 101 , ( vector < int > ( 101 , 0 ) ) ) ;
	int iRectangleSize = rectangle.size () ;
	int iDirection = 0 ;					// 0 UP , 1 RIGHT , 2 DOWN , 3 RIGHT
	int iCount = 1 ;
	int iItemCount = 0 ;
	int iCharacterCount = 0 ;
	
	
	
	for ( int i = 0 ; i < iRectangleSize ; ++i )
	{
		markMap ( vMap , rectangle [ i ] ) ;
		
		iMinX = min ( iMinX , rectangle [ i ] [ 0 ] << 1 ) ;
		iMinY = min ( iMinY , rectangle [ i ] [ 1 ] << 1 ) ;
		iMaxX = max ( iMaxX , rectangle [ i ] [ 2 ] << 1 ) ;
		iMaxY = max ( iMaxY , rectangle [ i ] [ 3 ] << 1 ) ;
	}
	
	int iStartX = iMinX ;
	int iStartY = iMinY ;
	for ( ; 0 == vMap [ iStartX ] [ iStartY ] ; ++ iStartY ) {}
	int iX = iStartX ;
	int iY = iStartY ;
	int irgXDirection [ 4 ] = { 0 , 1 , 0 , -1 } ;		// UP RIGHT DOWN LEFT
	int irgYDirection [ 4 ] = { 1 , 0 , -1 , 0 } ;
	
	while ( ( 1 == iCount ) || ! ( ( iX - 1 == iStartX ) && ( iY == iStartY ) ) )
	{
		if ( ( iX == ( characterX << 1 ) ) && ( iY == ( characterY << 1 ) ) )
			iCharacterCount = iCount ;
		else if ( ( iX == ( itemX << 1 ) ) && ( iY == ( itemY << 1 ) ) )
			iItemCount = iCount ;
		
		for ( int i = 0 ; i < 4 ; ++i )
		{
			int iTempX = iX + irgXDirection [ ( iDirection - 1 + i ) & 3 ] ;		// Start from direction - 1, clockwise check
			int iTempY = iY + irgYDirection [ ( iDirection - 1 + i ) & 3 ] ;

			if ( ( iMaxX < iTempX ) || ( iMaxY < iTempY ) )
				continue ;
			
			if ( 0 != vMap [ iTempX ] [ iTempY ] )
			{
				vMap [ iX ] [ iY ] = 0 ;

				iX = iTempX ;
				iY = iTempY ;
				iDirection = ( iDirection - 1 + i ) & 3 ;							// Direction changes everytime

					
				break ;
			}
		}
		
		++ iCount ;
	}
	
	
	return min ( abs ( iCharacterCount - iItemCount ) , iCount - abs ( iCharacterCount - iItemCount ) ) >> 1 ;
}