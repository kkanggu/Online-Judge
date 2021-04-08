#include <iostream>

void BackTracking ( int irgSudoku [] [ 9 ] , int irgEmptyBlock [] [ 2 ] , int iMax , int iCnt ) ;
bool bValid ( int irgSudoku [] [ 9 ] , int iX , int iY , int iNum ) ;

int main ()
{
	int iCnt = 0 ;
	int irgSudoku [ 9 ] [ 9 ] ;
	int iRemainCnt [ 27 ] ;														// 0-8 Horizon, 9-17 Vertical, 18-26 Square
	int irgEmptyBlock [ 81 ] [ 2 ] ;
	char cInput [ 18 ] ;
	


	for ( int i = 0 ; i < 9 ; ++i )												// Input sudoku
	{
		fgets ( cInput , 19 , stdin ) ;
		
		for ( int j = 0 ; j < 9 ; ++j )
		{
			irgSudoku [ i ] [ j ] = cInput [ j * 2 ] - '0' ;

			if ( '0' == cInput [ j * 2 ] )
			{
				irgEmptyBlock [ iCnt ] [ 0 ] = i ;
				irgEmptyBlock [ iCnt ] [ 1 ] = j ;
				++ iCnt ;
			}
		}
	}
	
/*	for ( int i = 0 ; i < 9 ; ++i )												// check 
	{
		int iHorCnt = 0 ;
		int iVerCnt = 0 ;
		int iSquCnt = 0 ;

		for ( int j = 0 ; j < 9 ; ++j )
		{
			if ( 0 == irgSudoku [ i ] [ j ] )
				++ iHorCnt ;
			if ( 0 == irgSudoku [ j ] [ i ] )
				++ iVerCnt ;
			if ( 0 == irgSudoku [ i / 3 * 3 + j / 3 ] [ i % 3 * 3 + j % 3 ] )
				++ iSquCnt ;
		}

		iRemainCnt [ i ] = iHorCnt ;
		iRemainCnt [ i + 9 ] = iVerCnt ;
		iRemainCnt [ i + 18 ] = iSquCnt ;
	}
	for ( int i = 0 ; i < 27 ; ++i )
	{
		if ( 1 == iRemainCnt [ i ] )
		{
			if ( 0 == i / 9 )													// Horizon
			{
				for ( int j = 0 ; j < 9 ; ++j )
				{
					if ( 0 == irgSudoku [ i ] [ j ] )
					{
						for ( int k = 0 ; k < 9 ; ++k )
						{
							if ( bValid ( irgSudoku , i , j , k ) )
							{

								break ;
							}
						}

						break ;
					}					
				}
			}
		}
	} */
	
	BackTracking ( irgSudoku , irgEmptyBlock , iCnt , 0 ) ;





	return 0 ;
}

void BackTracking ( int irgSudoku [] [ 9 ] , int irgEmptyBlock [] [ 2 ] , int iMax , int iCnt )
{
	if ( iMax != iCnt )
	{
		int iX = irgEmptyBlock [ iCnt ] [ 0 ] ;
		int iY = irgEmptyBlock [ iCnt ] [ 1 ] ;



		for ( int i = 0 ; i < 9 ; ++i )
		{
			if ( bValid ( irgSudoku , iX , iY , i + 1 ) )
			{
				irgSudoku [ iX ] [ iY ] = i + 1  ;
				BackTracking ( irgSudoku , irgEmptyBlock , iMax , iCnt + 1 ) ;
				irgSudoku [ iX ] [ iY ] = 0 ;
			}
		}
	}
	else
	{
		for ( int i = 0 ; i < 9 ; ++i )
		{
			printf ( "%d %d %d %d %d %d %d %d %d\n" , irgSudoku [ i ] [ 0 ] , irgSudoku [ i ] [ 1 ] , irgSudoku [ i ] [ 2 ] , irgSudoku [ i ] [ 3 ] , 
				irgSudoku [ i ] [ 4 ] , irgSudoku [ i ] [ 5 ] , irgSudoku [ i ] [ 6 ] , irgSudoku [ i ] [ 7 ] , irgSudoku [ i ] [ 8 ] ) ;
		}

		exit ( 0 ) ;
	}
}

bool bValid ( int irgSudoku [] [ 9 ] , int iX , int iY , int iNum )
{
	for ( int i = 0 ; i < 9 ; ++i )
	{
		if ( iNum == irgSudoku [ iX ] [ i ] )
			return false ;
		if ( iNum == irgSudoku [ i ] [ iY ] )
			return false ;
		if ( iNum == irgSudoku [ iX / 3 * 3 + i % 3 ] [ iY / 3 * 3 + i / 3 ] )
			return false ;
	}


	return true ;
}