#include <iostream>
#include <cstdio>
#include <sstream>
#include <queue>
#pragma warning(disable:4996)

using std::string ;
using std::cout ;
using std::cin ;

void addWorm ( int iX , int iY , const int iHorizon , const int iVertical , int irgCabbage [] [ 2500 ] )
{
	irgCabbage [ iX ] [ iY ] = 2 ;

	if ( 0 != iX )
	{
		if ( 1 == irgCabbage [ iX - 1 ] [ iY ] )
			addWorm ( iX - 1 , iY , iHorizon , iVertical , irgCabbage ) ;
	}
	if ( iHorizon != iX + 1 )
	{
		if ( 1 == irgCabbage [ iX + 1 ] [ iY ] )
			addWorm ( iX + 1 , iY , iHorizon , iVertical , irgCabbage ) ;
	}
	if ( 0 != iY )
	{
		if ( 1 == irgCabbage [ iX ] [ iY - 1 ] )
			addWorm ( iX , iY - 1 , iHorizon , iVertical , irgCabbage ) ;
	}
	if ( iVertical != iY + 1 )
	{
		if ( 1 == irgCabbage [ iX ] [ iY + 1 ] )
			addWorm ( iX , iY + 1 , iHorizon , iVertical , irgCabbage ) ;
	}
}

int main ()
{
	int iRep = 0 ;
	int iHorizon = 0 ;
	int iVertical = 0 ;
	int iCnt = 0 ;
	int irgCabbage [ 2500 ] [ 2500 ] ;
	int iX = 0 ;
	int iY = 0 ;
	std :: queue < std :: pair < int , int > > qCabbage ;



	for ( int i = 0 ; i < 2500 ; ++i )
	{
		for ( int j = 0 ; j < 2500 ; ++j )
		{
			irgCabbage [ i ] [ j ] = 0 ;
		}
	}


	cin >> iRep ;


	for ( int k = 0 ; k < iRep ; ++k )
	{
		scanf ( "%d %d %d" , & iHorizon , & iVertical , & iCnt ) ;

		
		string strInput ;

		for ( int i = 0 ; i < iCnt ; ++i )
		{
			scanf ( "%d %d" , & iX , & iY ) ;


			irgCabbage [ iX ] [ iY ] = 1 ;
			qCabbage.push ( std :: pair < int , int > ( iX , iY ) ) ;
		}


		iCnt = 0 ;
	

		while ( ! qCabbage.empty () )
		{
			iX = qCabbage.front ().first ;
			iY = qCabbage.front ().second ;


			if ( 1 == irgCabbage [ iX ] [ iY ] )
			{
				addWorm ( iX , iY , iHorizon , iVertical , irgCabbage ) ;
				++ iCnt ;
			}

			qCabbage.pop () ;			
		}

		cout << iCnt << std :: endl ;
	}
	

	return 0 ;
}