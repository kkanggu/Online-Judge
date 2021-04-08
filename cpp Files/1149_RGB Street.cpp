#include <iostream>
#pragma warning(disable:4996)

using std :: cin ;
using std :: cout ;

int iMinValue ( int & i1 , int & i2 ) ;

int main ()
{
	int iCnt = 0 ;
	int irgColorMin [ 2 ] [ 3 ] = { 0 , } ;
	int iRed = 0 ;
	int iGreen = 0 ;
	int iBlue = 0 ;
	int iMin = 0 ;

	cin >> iCnt ;
	scanf ( "%d %d %d" , & iRed , & iGreen , & iBlue ) ;


	irgColorMin [ 1 ] [ 0 ] = iRed ;
	irgColorMin [ 1 ] [ 1 ] = iGreen ;
	irgColorMin [ 1 ] [ 2 ] = iBlue ;


	for ( int i = 1 ; i < iCnt ; ++i )
	{
		scanf ( "%d %d %d" , & iRed , & iGreen , & iBlue ) ;


		irgColorMin [ 0 ] [ 0 ] = irgColorMin [ 1 ] [ 0 ] ;							// R
		irgColorMin [ 0 ] [ 1 ] = irgColorMin [ 1 ] [ 1 ] ;							// G
		irgColorMin [ 0 ] [ 2 ] = irgColorMin [ 1 ] [ 2 ] ;							// B

		irgColorMin [ 1 ] [ 0 ] = iMinValue ( irgColorMin [ 0 ] [ 1 ] , irgColorMin [ 0 ] [ 2 ] ) + iRed ;		// Paint Red
		irgColorMin [ 1 ] [ 1 ] = iMinValue ( irgColorMin [ 0 ] [ 0 ] , irgColorMin [ 0 ] [ 2 ] ) + iGreen ;	// Paint Green
		irgColorMin [ 1 ] [ 2 ] = iMinValue ( irgColorMin [ 0 ] [ 0 ] , irgColorMin [ 0 ] [ 1 ] ) + iBlue ;		// Paint Blue
	}

	iMin = irgColorMin [ 1 ] [ 0 ] ;							// Set Red is min value
	if ( iMin > irgColorMin [ 1 ] [ 1 ] )						// If Green is smaller than Red
		iMin = irgColorMin [ 1 ] [ 1 ] ;						// Min value is green
	if ( iMin > irgColorMin [ 1 ] [ 2 ] )						// If Blue is smaller than Red
		iMin = irgColorMin [ 1 ] [ 2 ] ;						// Min value is green


	cout << iMin ;


	return 0 ;
}

int iMinValue ( int & i1 , int & i2 )
{
	if ( i1 > i2 )
		return i2 ;
	else
		return i1 ;
}