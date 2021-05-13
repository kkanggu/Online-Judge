#include <iostream>
#include <stdbool.h>
#include <cstring>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

void getCombination ( int iN , int iK ) ;

int main ()
{
	int irgCount [ 30 ] = { 0 , } ;
	char cszClothes [ 30 ] [ 21 ] ;
	char cszTemp [ 21 ] ;
	int iTemp = 0 ;
	int iClothCnt = 0 ;
	int iNum = 0 ;
	int iIndex = -1 ;
	int iPrint = 1 ;

	

	scanf ( "%d" , & iNum ) ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		scanf ( "%d" , & iClothCnt ) ;

		iTemp = 0 ;
		iPrint = 1 ;
		std :: fill ( irgCount , & irgCount [ 30 ] , 0 ) ;

		for ( int j = 0 ; j < iClothCnt ; ++j )
		{
			scanf ( "%s" , cszTemp ) ;
			scanf ( "%s" , cszTemp ) ;

			for ( int k = 0 ; k < iTemp ; ++k )
			{
				if ( 0 == ( strcmp ( cszClothes [ k ] , cszTemp ) ) )
				{
					iIndex = k ;

					break ;
				}
			}

			if ( -1 == iIndex )
			{
				strcpy ( cszClothes [ iTemp ] , cszTemp ) ;
				++ irgCount [ iTemp ] ;
				++ iTemp ;
			}
			else
			{
				++ irgCount [ iIndex ] ;
			}

			iIndex = -1 ;
		}

		for ( int j = 0 ; j < iTemp ; ++j )
		{
			iPrint *= irgCount [ j ] + 1 ;
		}

		printf ( "%d\n" , iPrint - 1 ) ;
	}



	return 0 ;
}