#include <iostream>
#include <string>
//#include <sstream>
#pragma warning(disable:4996)

using std :: string ;
using std :: cout ;
using std :: cin ;

void findMin ( char crgBoard [] [ 50 ] , int & iMin , int iX , int iY ) ;			// Find min value and set

int main ()
{
	int iX = 0 ;
	int iY = 0 ;
	char crgBoard [ 50 ] [ 50 ] ;
	string strInput ;
	int iMin = 64 ;



	scanf ( "%d %d" , & iX , & iY ) ;
	std :: getline ( cin , strInput ) ;			// refresh buffer
	

	for ( int i = 0 ; i < iX ; ++i )
	{
		std :: getline ( cin , strInput ) ;

		for ( int j = 0 ; j < iY ; ++j )
		{
			crgBoard [ i ] [ j ] = strInput [ j ] ;
		}
	}

	for ( int i = 0 ; i < iX - 7 ; ++i )
	{
		for ( int j = 0 ; j < iY - 7 ; ++j )
		{
			findMin ( crgBoard , iMin , i , j ) ;								// Send start position
		}
	}

	cout << iMin ;


	return 0 ;
}

void findMin ( char crgBoard [] [ 50 ] , int & iMin , int iX , int iY )				// Find min value and set
{
	int iFirstWhite = 0 ;
	int iSecondWhite = 0 ;
	int iSum = 0 ;



	for ( int i = 0 ; i < 8 ; ++i )
	{
		for ( int j = 0 ; j < 8 ; ++j )
		{
			if ( 'W' == crgBoard [ iX + i ] [ iY + j ] )
			{
				if ( 0 == ( ( i + j ) % 2 ) )
				{
					++ iFirstWhite ;
				}
				else
				{
					++ iSecondWhite ;
				}
			}
		}
	}

	if ( ( iFirstWhite - iSecondWhite + 32 ) < ( iSecondWhite - iFirstWhite + 32 ) )
	{
		iSum = iFirstWhite - iSecondWhite + 32 ;
	}
	else
	{
		iSum = iSecondWhite - iFirstWhite + 32 ;
	}

	if ( iSum < iMin )
		iMin = iSum ;
}