#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;


int main ()
{
	int iN = 0 ;
	int iM = 0 ;
	int iLow = 0 ;
	long long llFiveCnt = 0 ;
	long long llTwoCnt = 0 ;
	int iTemp = 0 ;

	

	scanf ( "%d %d" , & iN , & iM ) ;

	iLow = iM < iN - iM ? iM : iN - iM ;
	iTemp = iN ;

	while ( iTemp >= 2 )
	{
		iTemp /= 2 ;
		llTwoCnt += iTemp ;
	}

	iTemp = iN ;

	while ( iTemp >= 5 )
	{
		iTemp /= 5 ;
		llFiveCnt += iTemp ;
	}

	iTemp = iN - iLow ;

	while ( iTemp >= 2 )
	{
		iTemp /= 2 ;
		llTwoCnt -= iTemp ;
	}

	iTemp = iN - iLow ;

	while ( iTemp >= 5 )
	{
		iTemp /= 5 ;
		llFiveCnt -= iTemp ;
	}

	iTemp = iLow ;

	while ( iTemp >= 2 )
	{
		iTemp /= 2 ;
		llTwoCnt -= iTemp ;
	}

	iTemp = iLow ;

	while ( iTemp >= 5 )
	{
		iTemp /= 5 ;
		llFiveCnt -= iTemp ;
	}

	cout << ( llFiveCnt < llTwoCnt ? llFiveCnt : llTwoCnt ) ;


	return 0 ;
}