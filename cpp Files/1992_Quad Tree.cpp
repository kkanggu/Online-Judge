#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

void parseQuadTree ( int irgQuadTree [] [ 64 ] , int iLength , int iX , int iY ) ;

int main ()
{
	int iNum = 0 ;
	int irgQuadTree [ 64 ] [ 64 ] = { 0 , } ;
	int iWhite = 0 ;
	int iBlue = 0 ;



	cin >> iNum ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		getchar () ;

		for ( int j = 0 ; j < iNum ; ++j )
		{
			irgQuadTree [ i ] [ j ] = getchar () - '0' ;
		}
	}

	parseQuadTree ( irgQuadTree , iNum , 0 , 0 ) ;


	return 0 ;
}

void parseQuadTree ( int irgQuadTree [] [ 64 ] , int iLength , int iX , int iY )
{
	int iCnt = 0 ;



	for ( int i = iX ; i < iX + iLength ; ++i )
	{
		for ( int j = iY ; j < iY + iLength ; ++j )
		{
			iCnt += irgQuadTree [ i ] [ j ] ;
		}
	}

	if ( iCnt == ( iLength * iLength ) )
	{
		printf ( "1" ) ;
	}
	else if ( iCnt == 0 )
	{
		printf ( "0" ) ;
	}
	else
	{
		printf ( "(" ) ;
		parseQuadTree ( irgQuadTree , iLength / 2 , iX , iY ) ;
		parseQuadTree ( irgQuadTree , iLength / 2 , iX , iY + iLength / 2 ) ;
		parseQuadTree ( irgQuadTree , iLength / 2 , iX + iLength / 2 , iY ) ;
		parseQuadTree ( irgQuadTree , iLength / 2 , iX + iLength / 2 , iY + iLength / 2 ) ;
		printf ( ")" ) ;
	}
}