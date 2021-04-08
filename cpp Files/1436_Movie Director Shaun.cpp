#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int main ()
{
	int iInput = 0 ;
	int iNumList [ 10000 ] ;
	int iCnt = 666 ;


	cin >> iInput ;

	for ( int i = 0 ; i < iInput ; ++i )
	{
		if ( 665666 == iCnt % 1000000 )
		{
			iNumList [ i ] = iCnt ;
			iCnt += ( 666000 - 665666 ) ;
		}
		else if ( 65666 == iCnt % 100000 )
		{
			iNumList [ i ] = iCnt ;
			iCnt += ( 66600 - 65666 ) ;
		}
		else if ( 5666 == iCnt % 10000 )
		{
			iNumList [ i ] = iCnt ;
			iCnt += ( 6660 - 5666 ) ;
		}
		else if ( 666 == iCnt % 10000000 / 10000 )
		{
			for ( int j = 0 ; j < 10000 && i < iInput ; ++j , ++i )
			{
				iNumList [ i ] = iCnt ;
				++ iCnt ;
			}

			--i ;
			iCnt += 666 ;
		}
		else if ( 666 == iCnt % 1000000 / 1000 )
		{
			for ( int j = 0 ; j < 1000 && i < iInput ; ++j , ++i )
			{
				iNumList [ i ] = iCnt ;
				++ iCnt ;
			}

			--i ;
			iCnt += 666 ;
		}
		else if ( 666 == iCnt % 100000 / 100 )
		{
			for ( int j = 0 ; j < 100 && i < iInput ; ++j , ++i )
			{
				iNumList [ i ] = iCnt ;
				++ iCnt ;
			}

			--i ;
			iCnt += ( 67666 - 66700 ) ;
		}
		else if ( 666 == iCnt % 10000 / 10 )
		{
			for ( int j = 0 ; j < 10 && i < iInput ; ++j , ++i )
			{ 
				iNumList [ i ] = iCnt ;
				++ iCnt ;
			}

			--i ;
			iCnt += ( 7666 - 6670 ) ;
		}
		else
		{
			iNumList [ i ] = iCnt ;
			iCnt += 1000 ;
		}
	}


	cout << iNumList [ iInput - 1 ] ;


	return 0 ;
}