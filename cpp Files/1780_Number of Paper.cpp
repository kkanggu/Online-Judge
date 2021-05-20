#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int ** idpPaper ;

void parsePaper ( int iLength , int iX , int iY , int * irgCnt ) ;

int main ()
{
	int iNum = 0 ;
	int irgCnt [ 3 ] = { 0 , } ;					// [ 0 ] mean -1, [ 1 ] mean 0, [ 2 ] mean 1



	cin >> iNum ;

	idpPaper = new int * [ iNum ] ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		idpPaper [ i ] = new int [ iNum ] ;

		scanf ( "%d" , & idpPaper [ i ] [ 0 ] ) ;

		for ( int j = 1 ; j < iNum ; ++j )
		{
			scanf ( " %d" , & idpPaper [ i ] [ j ] ) ;
		}
	}

	parsePaper ( iNum , 0 , 0 , irgCnt ) ;

	printf ( "%d\n%d\n%d" , irgCnt [ 0 ] , irgCnt [ 1 ] , irgCnt [ 2 ] ) ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		delete idpPaper [ i ] ;
	}

	delete idpPaper ;

	return 0 ;
}

void parsePaper ( int iLength , int iX , int iY , int * irgCnt )
{
	int iCnt = idpPaper [ iX ] [ iY ] ;



	for ( int i = iX ; i < iX + iLength ; ++i )
	{
		for ( int j = iY ; j < iY + iLength ; ++j )
		{
			if ( iCnt != idpPaper [ i ] [ j ] )
			{
				iCnt = 2 ;
				break ;
			}
		}

		if ( 2 == iCnt )
		{
			break ;
		}
	}

	if ( 1 == iCnt )
	{
		++ irgCnt [ 2 ] ;
	}
	else if ( 0 == iCnt )
	{
		++ irgCnt [ 1 ] ;
	}
	else if ( -1 == iCnt )
	{
		++ irgCnt [ 0 ] ;
	}
	else
	{
		for ( int i = 0 ; i < 3 ; ++i )
		{
			for ( int j = 0 ; j < 3 ; ++j )
			{
				parsePaper ( iLength / 3 , iX + i * iLength / 3 , iY + j * iLength / 3 , irgCnt ) ;
			}
		}
	}
}