#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using std :: cin ;
using std :: cout ;

int iMaxValue ( int & i1 , int & i2 ) ;

int main ()
{
	int iCnt = 0 ;
	int irgStairMax [ 300 ] [ 2 ] = { 0 , } ;									// [] [ n ] means climbed n + 1 stairs in a row.
	int iStair = 0 ;



	cin >> iCnt ;
	cin >> iStair ;

	if ( iCnt > 1 )																// More than 1 stair
	{
		irgStairMax [ 0 ] [ 0 ] = iStair ;

		cin >> iStair ;

		irgStairMax [ 1 ] [ 0 ] = iStair ;
		irgStairMax [ 1 ] [ 1 ] = irgStairMax [ 0 ] [ 0 ] + iStair ;


		for ( int i = 2 ; i < iCnt ; ++i )										// Do n lines.
		{
			cin >> iStair ;


			irgStairMax [ i ] [ 0 ] = iMaxValue ( irgStairMax [ i - 2 ] [ 0 ] , irgStairMax [ i - 2 ] [ 1 ] )
										+ iStair ;																	// Can climb two steps anytime
			irgStairMax [ i ] [ 1 ] = irgStairMax [ i - 1 ] [ 0 ] + iStair ;
		}

		cout << iMaxValue ( irgStairMax [ iCnt - 1 ] [ 0 ] , irgStairMax [ iCnt - 1 ] [ 1 ] ) ;
	}
	else
	{
		cout << iStair ;
	}


	return 0 ;
}

int iMaxValue ( int & i1 , int & i2 )
{
	if ( i1 > i2 )
		return i1 ;
	else
		return i2 ;
}