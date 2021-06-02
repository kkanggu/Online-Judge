#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

void multiplyMatrix ( int irgResult [] [ 5 ] , int irgMatrix [] [ 5 ] , int iSize ) ;
void squareMatrix ( int irgMatrix [] [ 5 ] , int iSize ) ;

int main ()
{
	int iSize = 0 ;
	long long llSquare = 0 ;
	int irgMatrix [ 5 ] [ 5 ] = { 0 , } ;
	int irgTemp [ 5 ] [ 5 ] = { 0 , } ;
	int irgResult [ 5 ] [ 5 ] = { 1 , } ;



	for ( int i = 1 ; i < 5 ; ++i )
	{
		irgResult [ i ] [ i ] = 1 ;
	}
	cin >> iSize >> llSquare ;


	for ( int i = 0 ; i < iSize ; ++i )
	{
		scanf ( "%d" , irgMatrix [ i ] ) ;

		for ( int j = 1 ; j < iSize ; ++j )
		{
			scanf ( "%d" , & irgMatrix [ i ] [ j ] ) ;
		}
	}

	while ( 0 != llSquare )
	{
		if ( 1 == ( llSquare % 2 ) )
		{
			multiplyMatrix ( irgResult , irgMatrix , iSize ) ;
		}

		squareMatrix ( irgMatrix , iSize ) ;
		llSquare /= 2 ;
	}

	for ( int i = 0 ; i < iSize ; ++i )
	{
		for ( int j = 0 ; j < iSize ; ++j )
		{
			printf ( "%d " , irgResult [ i ] [ j ] ) ;
		}

		printf ( "\n" ) ;
	}


	return 0 ;
}

void multiplyMatrix ( int irgResult [] [ 5 ] , int irgMatrix [] [ 5 ] , int iSize )
{
	int irgTemp [ 5 ] [ 5 ] = { 0 , } ;



	for ( int i = 0 ; i < iSize ; ++i )
	{
		for ( int j = 0 ; j < iSize ; ++j )
		{
			irgTemp [ i ] [ j ] = irgResult [ i ] [ j ] ;
			irgResult [ i ] [ j ] = 0 ;
		}
	}

	for ( int i = 0 ; i < iSize ; ++i )
	{
		for ( int j = 0 ; j < iSize ; ++j )
		{
			for ( int k = 0 ; k < iSize ; ++k )
			{
				irgResult [ i ] [ j ] += irgTemp [ i ] [ k ] * irgMatrix [ k ] [ j ] ;
			}
		}
	}

	for ( int i = 0 ; i < iSize ; ++i )
	{
		for ( int j = 0 ; j < iSize ; ++j )
		{
			irgResult [ i ] [ j ] %= 1000 ;
		}
	}
}

void squareMatrix ( int irgMatrix [] [ 5 ] , int iSize )
{
	int irgTemp [ 5 ] [ 5 ] = { 0 , } ;



	for ( int i = 0 ; i < iSize ; ++i )
	{
		for ( int j = 0 ; j < iSize ; ++j )
		{
			irgTemp [ i ] [ j ] = irgMatrix [ i ] [ j ] ;
			irgMatrix [ i ] [ j ] = 0 ;
		}
	}

	for ( int i = 0 ; i < iSize ; ++i )
	{
		for ( int j = 0 ; j < iSize ; ++j )
		{
			for ( int k = 0 ; k < iSize ; ++k )
			{
				irgMatrix [ i ] [ j ] += irgTemp [ i ] [ k ] * irgTemp [ k ] [ j ] ;
			}
		}
	}

	for ( int i = 0 ; i < iSize ; ++i )
	{
		for ( int j = 0 ; j < iSize ; ++j )
		{
			irgMatrix [ i ] [ j ] %= 1000 ;
		}
	}
}