#include <iostream>
#include <string>
#pragma warning(disable:4996)

void Backtracking ( int irgAbility [] [ 20 ] , int irgTeamList [] [ 10] , int & iMin , int iStartCnt , int iLinkCnt , int iCapacity ) ;

int main ()
{
	int iFunctionResult [ 21 ] [ 21 ] [ 21 ] = { 1 , } ;
	int iInput1 = 0 ;
	int iInput2 = 0 ;
	int iInput3 = 0 ;
	int iResult = 1 ;



	std :: fill_n ( iFunctionResult [ 0 ] [ 0 ] , 21 * 21 * 21 , 1 ) ;			// Set all element to 1


	while ( true )
	{
		scanf ( "%d %d %d" , & iInput1 , & iInput2 , & iInput3 ) ;


		if ( ( -1 != iInput1 ) || ( -1 != iInput2 ) || ( -1 != iInput3 ) )
		{
			for ( int i = 1 ; i < 21 ; ++i )
			{
				for ( int j = 1 ; j < 21 ; ++j )
				{
					for ( int k = 1 ; k < 21 ; ++k )
					{
						if ( ( i < j ) && ( j < k ) )
						{
							iFunctionResult [ i ] [ j ] [ k ] = iFunctionResult [ i ] [ j ] [ k - 1 ]
															+ iFunctionResult [ i ] [ j - 1 ] [ k - 1 ]
															- iFunctionResult [ i ] [ j - 1 ] [ k ] ;
						}
						else
						{
							iFunctionResult [ i ] [ j ] [ k ] = iFunctionResult [ i - 1 ] [ j ] [ k ]
															+ iFunctionResult [ i - 1 ] [ j - 1 ] [ k ]
															+ iFunctionResult [ i - 1 ] [ j ] [ k - 1 ]
															- iFunctionResult [ i - 1 ] [ j - 1 ] [ k - 1 ] ;
						}
					}
				}
			}

			if ( ( iInput1 <= 0 ) || ( iInput2 <= 0 ) || ( iInput3 <= 0 ) )
			{
				iResult = 1 ;
			}
			else if ( ( iInput1 > 20 ) || ( iInput2 > 20 ) || ( iInput3 > 20 ) )
			{
				iResult = iFunctionResult [ 20 ] [ 20 ] [ 20 ] ;
			}
			else
			{
				iResult = iFunctionResult [ iInput1 ] [ iInput2 ] [ iInput3 ] ;
			}

			printf ( "w(%d, %d, %d) = %d\n" , iInput1 , iInput2 , iInput3 , iResult ) ;
		}
		else
		{
			break ;
		}
	}


	return 0 ;
}