#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

void multiplyMatrix ( long long irgResult [] [ 2 ] , long long irgMatrix [] [ 2 ] ) ;
void squareMatrix ( long long irgMatrix [] [ 2 ] ) ;

int main ()
{
	long long llCnt = 0 ;
	long long irgMatrix [ 2 ] [ 2 ] = { 1 , 1 , 1 , 0 } ;
	long long irgResult [ 2 ] [ 2 ] = { 1 , 0 , 0 , 1 } ;



	cin >> llCnt ;

	
	while ( llCnt )
	{
		if ( 1 == ( llCnt % 2 ) )
		{
			multiplyMatrix ( irgResult , irgMatrix ) ;
		}

		squareMatrix ( irgMatrix ) ;
		llCnt /= 2 ;
	}

	cout << irgResult [ 0 ] [ 1 ] ;
	
	
	return 0 ;
}

void multiplyMatrix ( long long irgResult [] [ 2 ] , long long irgMatrix [] [ 2 ] )
{
	long long irgTemp [ 2 ] [ 2 ] = { 0 , } ;



	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			irgTemp [ i ] [ j ] = irgResult [ i ] [ j ] ;
			irgResult [ i ] [ j ] = 0 ;
		}
	}

	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			for ( int k = 0 ; k < 2 ; ++k )
			{
				irgResult [ i ] [ j ] += irgTemp [ i ] [ k ] * irgMatrix [ k ] [ j ] ;
			}
		}
	}

	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			irgResult [ i ] [ j ] %= 1000000007 ;
		}
	}
}

void squareMatrix ( long long irgMatrix [] [ 2 ] )
{
	long long irgTemp [ 2 ] [ 2 ] = { 0 , } ;



	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			irgTemp [ i ] [ j ] = irgMatrix [ i ] [ j ] ;
			irgMatrix [ i ] [ j ] = 0 ;
		}
	}

	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			for ( int k = 0 ; k < 2 ; ++k )
			{
				irgMatrix [ i ] [ j ] += irgTemp [ i ] [ k ] * irgTemp [ k ] [ j ] ;
			}
		}
	}

	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			irgMatrix [ i ] [ j ] %= 1000000007 ;
		}
	}
}