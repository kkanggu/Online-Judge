#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

void plusMatrix ( int irgMatrix [] [ 8 ] , int irgResult [] [ 8 ] , int iSize ) ;
void squareMatrix ( int irgMatrix [] [ 8 ] ) ;
void squareMatrix ( int irgSmallMatrix [] [ 4 ] , int iSize , int iX , int iY ) ;

int main ()
{
	int iSize = 0 ;
	int iBin = 0 ;
	int iSquare = 0 ;
	int irgMatrix [ 8 ] [ 8 ] = { 0 , } ;
	int irgResult [ 8 ] [ 8 ] = { 0 , } ;



	cin >> iSize >> iSquare ;


	for ( int i = 0 ; i < iSize ; ++i )
	{
		scanf ( "%d" , irgMatrix [ i ] ) ;

		for ( int j = 1 ; j < iSize ; ++j )
		{
			scanf ( "%d" , & irgMatrix [ i ] [ j ] ) ;
		}
	}

	if ( 2 == iSize )
	{
		iBin = 2 ;
	}
	else if ( 5 == iSize )
	{
		iBin = 8 ;
	}
	else
	{
		iBin = 4 ;
	}

	for ( ; iSquare > 0 ; )
	{
		if ( 1 == ( iSquare % 2 ) )
		{
			plusMatrix ( irgMatrix , irgResult , iSize ) ;
		}

		squareMatrix ( irgMatrix , iBin ) ;

		iSquare /= 2 ;
	}


	return 0 ;
}

void plusMatrix ( int irgResult [] [ 4 ] , int irgMatrix [] [ 8 ] , int iX1 , int iY1 , int iX2 , int iY2 )
{
	for ( int i = 0 ; i < 4 ; ++i )
	{
		for ( int j = 0 ; j < 4 ; ++j )
		{
			irgResult [ i ] [ j ] = ( irgMatrix [ iX1 + i ] [ iY1 + j ] + irgMatrix [ iX2 + i ] [ iY2 + j ] ) % 1000 ;
		}
	}
}

void plusMatrix ( int irgResult [] [ 2 ] , int irgMatrix [] [ 4 ] , int iX1 , int iY1 , int iX2 , int iY2 )
{
	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			irgResult [ i ] [ j ] = ( irgMatrix [ iX1 + i ] [ iY1 + j ] + irgMatrix [ iX2 + i ] [ iY2 + j ] ) % 1000 ;
		}
	}
}

void copyMatrix ( int irgResult [] [ 4 ] , int irgMatrix [] [ 8 ] , int iX1 , int iY1 , int iX2 , int iY2 )
{
	for ( int i = 0 ; i < 4 ; ++i )
	{
		for ( int j = 0 ; j < 4 ; ++j )
		{
			irgResult [ i ] [ j ] = ( irgMatrix [ iX1 + i ] [ iY1 + j ] + irgMatrix [ iX2 + i ] [ iY2 + j ] ) % 1000 ;
		}
	}
}

void copyMatrix ( int irgResult [] [ 2 ] , int irgMatrix [] [ 4 ] , int iX1 , int iY1 , int iX2 , int iY2 )
{
	for ( int i = 0 ; i < 2 ; ++i )
	{
		for ( int j = 0 ; j < 2 ; ++j )
		{
			irgResult [ i ] [ j ] = ( irgMatrix [ iX1 + i ] [ iY1 + j ] + irgMatrix [ iX2 + i ] [ iY2 + j ] ) % 1000 ;
		}
	}
}

void squareMatrix ( int irgMatrix [] [ 8 ] )
{
	int irgM1 [ 4 ] [ 4 ] = { 0 , } ;
	int irgM2 [ 4 ] [ 4 ] = { 0 , } ;
	int irgM3 [ 4 ] [ 4 ] = { 0 , } ;
	int irgM4 [ 4 ] [ 4 ] = { 0 , } ;
	int irgM5 [ 4 ] [ 4 ] = { 0 , } ;
	int irgM6 [ 4 ] [ 4 ] = { 0 , } ;
	int irgM7 [ 4 ] [ 4 ] = { 0 , } ;
	int irgTemp1 [ 4 ] [ 4 ] = { 0 , } ;
	int irgTemp2 [ 4 ] [ 4 ] = { 0 , } ;
	

	
	plusMatrix ( irgTemp1 , irgMatrix , 0 , 0 , 4 , 4 ) ;		// cause A=B
	squareMatrix ( irgM1 , irgTemp1 , irgTemp1 ) ;				// Set M1

	plusMatrix ( irgTemp1 , irgMatrix , 4 , 0 , 4 , 4 ) ;
}

void squareMatrix ( int irgResult [] [ 4 ] , int irgTemp1 [] [ 4 ] , int irgTemp2 [] [ 4 ] )
{

}
