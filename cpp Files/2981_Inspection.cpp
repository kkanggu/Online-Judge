#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdbool.h>
#include <vector>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;
using std :: vector ;

void getGCD ( int irgNum [] , int iNum ) ;
void printDivisors ( int iGCD ) ;
void addDivisors ( int iGCD , int irgDivisor [] [ 2 ] , vector < int > & vDivisors , int iDivisorCnt , int iMultiple ) ;

int main ()
{
	int iNum = 0 ;
	int irgNum [ 100 ] = { 0 , } ;
	int irgMinus [ 99 ] = { 0 , } ;



	scanf ( "%d" , & iNum ) ;


	for ( int i = 0 ; i < iNum ; ++i )
	{
		cin >> irgNum [ i ] ;
	}

	std :: sort ( irgNum , irgNum + iNum ) ;

	for ( int i = 0 ; i < iNum - 1 ; ++i )
	{
		irgMinus [ i ] = irgNum [ i + 1 ] - irgNum [ i ] ;
	}

	getGCD ( irgMinus , iNum ) ;
	
	printDivisors ( * irgMinus ) ;


	return 0 ;
}

void getGCD ( int irgNum [] , int iNum )
{
	int i1 = 0 ;
	int i2 = 0 ;
	int irgGCD [ 100 ] = { 0 , } ;



	while ( 1 != iNum )
	{
		for ( int i = 0 ; i < iNum - 1 ; ++i )
		{
			i1 = irgNum [ i ] ;
			i2 = irgNum [ i + 1 ] ;

			while ( ( 0 != i1 ) && ( 0 != i2 ) )
			{
				if ( i1 > i2 )
				{
					i1 %= i2 ;
				}
				else
				{
					i2 %= i1 ;
				}
			}

			irgGCD [ i ] = i1 > i2 ? i1 : i2 ;
		}

		std :: copy ( irgGCD , irgGCD + iNum - 1 , irgNum ) ;
		-- iNum ;
	}
}

void printDivisors ( int iGCD )
{
	int irgPrime [ 10000 ] = { 0 , } ;
	int irgDivisor [ 9 ] [ 2 ] = { 0 , } ;
	int iPrimeIndex = 0 ;
	int iDivisorIndex = 0 ;
	int iTemp1 = 0 ;
	int iTemp2 = iGCD ;
	bool bPrime = true ;
	vector < int > vDivisors ;
	vector < int > :: iterator iter ;



	for ( int i = 2 ; i <= sqrt ( iGCD ) ; ++i )
	{
		for ( int j = 0 ; j < iPrimeIndex ; ++j )
		{
			bPrime = true ;

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
		iTemp1 = irgPrime [ i ] ;

		if ( 0 == ( iTemp2 % iTemp1 ) )
		{
			irgDivisor [ iDivisorIndex ] [ 0 ] = iTemp1 ;

			while ( 0 == ( iTemp2 % iTemp1 ) )
			{
				iTemp2 /= iTemp1 ;
				++ irgDivisor [ iDivisorIndex ] [ 1 ] ;
			}

			++ iDivisorIndex ;
		}
	}

	addDivisors ( iGCD , irgDivisor , vDivisors , iDivisorIndex , 1 ) ;

	std :: sort ( vDivisors.begin () , vDivisors.end () ) ;
	vDivisors.erase ( std :: unique ( vDivisors.begin () , vDivisors.end () ) , vDivisors.end () ) ;

	for ( iter = vDivisors.begin () ; iter != vDivisors.end () ; ++iter )
	{
		printf ( "%d " , * iter ) ;
	}

	if ( 1 != iGCD )
	{
		printf ( "%d" , iGCD ) ;
	}
}

void addDivisors ( int iGCD , int irgDivisor [] [ 2 ] , vector < int > & vDivisors , int iDivisorCnt , int iMultiple )
{
	int iTemp = iMultiple ;



	for ( int i = 0 ; i < iDivisorCnt ; ++i )
	{
		if ( irgDivisor [ i ] [ 1 ] )				// If remain
		{
			iTemp = iMultiple * irgDivisor [ i ] [ 0 ] ;

			if ( iTemp <= sqrt ( iGCD ) )
			{
				vDivisors.push_back ( iTemp ) ;
				vDivisors.push_back ( iGCD / iTemp ) ;

				-- irgDivisor [ i ] [ 1 ] ;

				addDivisors ( iGCD , irgDivisor , vDivisors , iDivisorCnt , iTemp ) ;

				++ irgDivisor [ i ] [ 1 ] ;
			}
		}
	}
}