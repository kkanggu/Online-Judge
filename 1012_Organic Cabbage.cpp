#include <iostream>
#include <cstdio>
#include <sstream>
#include <queue>
#pragma warning(disable:4996)

using std::string ;
using std::cout ;
using std::cin ;

int main ()
{
	int iRep = 0 ;
	int iHorizon = 0 ;
	int iVertical = 0 ;
	int iCnt = 0 ;
	int ** irgCabbage ;
	int iX = 0 ;
	int iY = 0 ;
	std :: queue < std :: pair < int , int > > qCabbage ;


	cin >> iRep ;


	for ( int k = 0 ; k < iRep ; ++k )
	{
		scanf ( "%d %d %d" , & iHorizon , & iVertical , & iCnt ) ;

		
		irgCabbage = new int * [ iHorizon ] ;

		for ( int i = 0 ; i < iHorizon ; ++i )
		{
			irgCabbage [ i ] = new int [ iVertical ] ;

			for ( int j = 0 ; j < iHorizon ; ++j )
			{
				irgCabbage [ i ] [ j ] = 0 ;
			}
		}


		string strInput ;

		for ( int i = 0 ; i < iCnt ; ++i )
		{
			scanf ( "%d %d" , & iX , & iY ) ;


			irgCabbage [ iX ] [ iY ] = 1 ;
			qCabbage.push ( std :: pair < int , int > ( iX , iY ) ) ;
		}


		iCnt = 0 ;
		std :: queue < std :: pair < int , int > > qPrio ;
	

		while ( ! qCabbage.empty () )
		{
			iX = qCabbage.front ().first ;
			iY = qCabbage.front ().second ;


			if ( 1 == irgCabbage [ iX ] [ iY ] )
			{
				qPrio.push ( std :: pair < int , int > ( iX , iY ) ) ;
			}

			qCabbage.pop () ;


			if ( ! qPrio.empty () )
			{
				while ( ! qPrio.empty () )
				{
					iX = qPrio.front ().first ;
					iY = qPrio.front ().second ;

					irgCabbage [ iX ] [ iY ] = 2 ;

					if ( 0 != iX )
					{
						if ( 1 == irgCabbage [ iX - 1 ] [ iY ] )
							qPrio.push ( std :: pair < int , int > ( iX - 1 , iY ) ) ;
					}
					if ( iHorizon != iX + 1 )
					{
						if ( 1 == irgCabbage [ iX + 1 ] [ iY ] )
							qPrio.push ( std :: pair < int , int > ( iX + 1 , iY ) ) ;
					}
					if ( 0 != iY )
					{
						if ( 1 == irgCabbage [ iX ] [ iY - 1 ] )
							qPrio.push ( std :: pair < int , int > ( iX , iY - 1 ) ) ;
					}
					if ( iVertical != iY + 1 )
					{
						if ( 1 == irgCabbage [ iX ] [ iY + 1 ] )
							qPrio.push ( std :: pair < int , int > ( iX , iY + 1 ) ) ;
					}

					qPrio.pop () ;
				}

				++ iCnt ;
			}
		}

		cout << iCnt << std :: endl ;


		for ( int i = 0 ; i < iHorizon ; ++i )
		{
			delete [] irgCabbage [ i ] ;
		}

		delete [] irgCabbage ;
	}
	

	return 0 ;
}