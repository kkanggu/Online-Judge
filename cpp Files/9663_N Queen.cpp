#include <iostream>
#pragma warning(disable:4996)

void BackTracking ( int iQueen , int iRemain , int iChess [ 15 ] , int & iCnt ) ;		// iQueen is input N, iRemain have to arrange queens
bool bPossiblePosition ( int iX , int iY , int iChess [ 15 ] ) ;							// ( iX , iY ) is possible, then true

int main ()
{
	int iCnt = 0 ;
	int iQueen = 0 ;
	int iChess [ 15 ] ;															// if [ 0 ] = 3, then queen is at ( 0 , 3 )


	
	for ( int i = 0 ; i < 15 ; ++i )
	{
		iChess [ i ] = -1 ;
	}

	scanf ( "%d" , & iQueen ) ;


	for ( int i = 0 ; i < iQueen / 2 ; ++i )
	{
		iChess [ 0 ] = i ;
		BackTracking ( iQueen , iQueen - 1 , iChess , iCnt ) ;
		iChess [ 0 ] = -1 ;
	}

	iCnt *= 2 ;

	if ( 1 == ( iQueen % 2 ) )				// If odd number
	{
		iChess [ 0 ] = iQueen / 2 ;
		BackTracking ( iQueen , iQueen - 1 , iChess , iCnt ) ;
	}
	

	std :: cout << iCnt ;

	return 0 ;
}

void BackTracking ( int iQueen , int iRemain , int iChess [] , int & iCnt )				// iQueen is input N, iRemain have to arrange queens
{
	if ( iRemain )
	{
		for ( int i = 0 ; i < iQueen ; ++i )
		{
			if ( bPossiblePosition ( iQueen - iRemain , i , iChess ) )
			{
				iChess [ iQueen - iRemain ] = i ;
				BackTracking ( iQueen , iRemain - 1 , iChess , iCnt ) ;
				iChess [ iQueen - iRemain ] = -1 ;
			}
		}
	}
	else
	{
		++ iCnt ;
	}
}

bool bPossiblePosition ( int iX , int iY , int iChess [] )								// ( iX , iY ) is possible, then true
{
	for ( int i = 0 ; i < iX ; ++i )
	{
		if ( ( iChess [ i ] == iY ) ||										// Vertical check
			( ( iX + iY ) == ( i + iChess [ i ] ) ) ||						// ¢×
			( ( iX - i ) == ( iY - iChess [ i ] ) ) )						// ¢Ù
		{
			return false ;
		}
	}


	return true ;
}