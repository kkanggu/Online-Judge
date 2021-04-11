#include <iostream>
#pragma warning(disable:4996)

using std :: cin ;
using std :: cout ;

int main ()
{
	int iNum = 0 ;
	unsigned int uirgUnitDigitCnt [ 2 ] [ 10 ] = { 0 , } ;			// Count of units. ~0, ~1, ~2 ...
	unsigned int uiSum = 0 ;


	cin >> iNum ;


	for ( int i = 1 ; i < 10 ; ++i )							// Set single digit
	{
		uirgUnitDigitCnt [ 1 ] [ i ] = 1 ;
	}
	for ( int i = 1 ; i < iNum ; ++i )
	{
		for ( int j = 0 ; j < 10 ; ++j )						// Move uirg [ 1 ] to uirg [ 0 ]
		{
			uirgUnitDigitCnt [ 0 ] [ j ] = uirgUnitDigitCnt [ 1 ] [ j ] % 1000000000 ;
		}
																// Calculate ~0
		uirgUnitDigitCnt [ 1 ] [ 0 ] = uirgUnitDigitCnt [ 0 ] [ 1 ] ;

		for ( int j = 1 ; j < 9 ; ++j )							// Calculate ~1 to ~8
		{
			uirgUnitDigitCnt [ 1 ] [ j ] = uirgUnitDigitCnt [ 0 ] [ j - 1 ]
										+ uirgUnitDigitCnt [ 0 ] [ j + 1 ] ;
		}
																// Calculate ~9
		uirgUnitDigitCnt [ 1 ] [ 9 ] = uirgUnitDigitCnt [ 0 ] [ 8 ] ;
	}

	for ( int i = 0 ; i < 10 ; ++i )								// Calculate sum and divide into 1,000,000,000
	{
		uiSum += uirgUnitDigitCnt [ 1 ] [ i ] ;
		uiSum %= 1000000000 ;
	}


	cout << uiSum ;


	return 0 ;
}