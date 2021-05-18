#include <iostream>
#include <string>
#include <sstream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;
using std :: string ;

void parsePaper ( int irgPaper [] [ 128 ] , int iLength , int iX , int iY , int & iWhite , int & iBlue ) ;

int main ()
{
	int iNum = 0 ;
	int irgPaper [ 128 ] [ 128 ] = { 0 , } ;
	int iWhite = 0 ;
	int iBlue = 0 ;
	string strInput ;
	string strToken ;



	cin >> iNum ;
	std :: getline ( cin , strInput ) ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		std :: getline ( cin , strInput ) ;
		std :: stringstream stream ( strInput ) ;

		for ( int j = 0 ; j < iNum ; ++j )
		{
			std :: getline ( stream , strToken , ' ' ) ;
			irgPaper [ i ] [ j ] = std :: stoi ( strToken ) ;
		}
	}

	parsePaper ( irgPaper , iNum , 0 , 0 , iWhite , iBlue ) ;

	printf ( "%d\n%d" , iWhite , iBlue ) ;


	return 0 ;
}

void parsePaper ( int irgPaper [] [ 128 ] , int iLength , int iX , int iY , int & iWhite , int & iBlue )
{
	int iCnt = 0 ;



	for ( int i = iX ; i < iX + iLength ; ++i )
	{
		for ( int j = iY ; j < iY + iLength ; ++j )
		{
			iCnt += irgPaper [ i ] [ j ] ;
		}
	}

	if ( iCnt == ( iLength * iLength ) )
	{
		++ iBlue ;
	}
	else if ( iCnt == 0 )
	{
		++ iWhite ;
	}
	else
	{
		parsePaper ( irgPaper , iLength / 2 , iX , iY , iWhite , iBlue ) ;
		parsePaper ( irgPaper , iLength / 2 , iX + iLength / 2 , iY , iWhite , iBlue ) ;
		parsePaper ( irgPaper , iLength / 2 , iX , iY + iLength / 2 , iWhite , iBlue ) ;
		parsePaper ( irgPaper , iLength / 2 , iX + iLength / 2 , iY + iLength / 2 , iWhite , iBlue ) ;
	}
}