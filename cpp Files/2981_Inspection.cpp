#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stdbool.h>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

void printDivisors ( int iGCD ) ;

int main ()
{
	int iNum = 0 ;
	int irgNum [ 100 ] = { 0 , } ;
	int iGCD = INT_MAX ;



	scanf ( "%d" , & iNum ) ;


	for ( int i = 0 ; i < iNum ; ++i )
	{
		cin >> irgNum [ i ] ;
	}

	std :: sort ( irgNum , irgNum + iNum ) ;
	
	for ( int i = 0 ; i < iNum - 1 ; ++i )
	{
		if ( ( irgNum [ i + 1 ] - irgNum [ i ] ) < iGCD )
		{
			iGCD = irgNum [ i + 1 ] - irgNum [ i ] ;
		}
	}

	printDivisors ( iGCD ) ;


	return 0 ;
}

void printDivisors ( int iGCD )
{
	int irgPrime [ 10000 ] = { 0 , } ;
	int irgDivisor [ 100 ] [ 2 ] = { 0 , } ;
	int irgPrintValue [ 10000 ] = { 0 , } ;
	int iPrimeIndex = 0 ;
	int iDivisorIndex = 0 ;
	int iTemp = 0 ;
	bool bPrime = true ;



	for ( int i = 2 ; i < sqrt ( iGCD ) ; ++i )
	{
		for ( int j = 0 ; j < iPrimeIndex ; ++j )
		{
			if ( 0 == ( i % irgPrime [ j ] ) )
			{
				bPrime = false ;

				break	;
			}
		}

		if ( bPrime )
		{
			irgPrime [ iPrimeIndex ] = i ;

			++ iPrimeIndex ;
		}
	}
	for ( int i = 0 ; i < iPrimeIndex ; ++i )
	{
		iTemp = irgPrime [ i ] ;

		if ( 0 == ( iGCD % iTemp ) )
		{
			irgDivisor [ iDivisorIndex ] [ 0 ] = iTemp ;

			while ( 0 == ( iGCD % iTemp ) )
			{
				iGCD /= iTemp ;
				++ irgDivisor [ iDivisorIndex ] [ 1 ] ;
			}

			++ iDivisorIndex ;
		}
	}

	for ( int i = 0 ; i < iDivisorIndex ; ++i )
	{
		// Put divisors into irgPrintValue , sort, print.
	}
}