#include <iostream>
#include <cstdio>
#include <sstream>
#include <queue>
#pragma warning(disable:4996)

using std::string ;
using std::cout ;
using std::cin ;

class WormCalc
{
private :
	int m_iHorizon ;
	int m_iVertical ;
	int ** m_irgCabbage ;
	std :: queue < std :: pair < int , int > > qCabbage ;

public :
	WormCalc () ;
	~ WormCalc () ;
	WormCalc ( const int iHorizon , const int iVertical ) ;
	void m_setWorm ( const int iCnt ) ;
	void m_printMinWorm () ;
	void m_addAdjacent ( std :: queue < std :: pair < int , int > > qPrio ) ;
} ;

WormCalc :: WormCalc ( const int iHorizon , const int iVertical )
		: m_iHorizon ( iHorizon ) , m_iVertical ( iVertical )
{
	m_irgCabbage = new int * [ m_iHorizon ] ;

	for ( int i = 0 ; i < m_iHorizon ; ++i )
	{
		m_irgCabbage [ i ] = new int [ iVertical ] ;

		for ( int j = 0 ; j < m_iVertical ; ++j )
		{
			m_irgCabbage [ i ] [ j ] = 0 ;
		}
	}
}

WormCalc :: ~ WormCalc ()
{
	for ( int i = 0 ; i < m_iHorizon ; ++i )
	{
		delete [] m_irgCabbage [ i ] ;
	}

	delete [] m_irgCabbage ;
}

void WormCalc :: m_setWorm ( const int iCnt )
{
	int iHorizon = 0 ;
	int iVertical = 0 ;
	string strInput ;




	for ( int i = 0 ; i < iCnt ; ++i )
	{
		scanf ( "%d %d" , & iHorizon , & iVertical ) ;


		m_irgCabbage [ iHorizon ] [ iVertical ] = 1 ;
		qCabbage.push ( std :: pair < int , int > ( iHorizon , iVertical ) ) ;
	}
}

void WormCalc :: m_printMinWorm ()
{
	int iCnt = 0 ;
	int iX = 0 ;
	int iY = 0 ;
	std :: queue < std :: pair < int , int > > qPrio ;
	


	while ( ! qCabbage.empty () )
	{
		iX = qCabbage.front ().first ;
		iY = qCabbage.front ().second ;


		if ( 1 == m_irgCabbage [ iX ] [ iY ] )
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

				m_irgCabbage [ iX ] [ iY ] = 2 ;

				if ( 0 != iX )
				{
					if ( 1 == m_irgCabbage [ iX - 1 ] [ iY ] )
						qPrio.push ( std :: pair < int , int > ( iX - 1 , iY ) ) ;
				}
				if ( m_iHorizon != iX + 1 )
				{
					if ( 1 == m_irgCabbage [ iX + 1 ] [ iY ] )
						qPrio.push ( std :: pair < int , int > ( iX + 1 , iY ) ) ;
				}
				if ( 0 != iY )
				{
					if ( 1 == m_irgCabbage [ iX ] [ iY - 1 ] )
						qPrio.push ( std :: pair < int , int > ( iX , iY - 1 ) ) ;
				}
				if ( m_iVertical != iY + 1 )
				{
					if ( 1 == m_irgCabbage [ iX ] [ iY + 1 ] )
						qPrio.push ( std :: pair < int , int > ( iX , iY + 1 ) ) ;
				}

				qPrio.pop () ;
			}

			++ iCnt ;
		}
	}

	cout << iCnt << std :: endl ;
}

void WormCalc :: m_addAdjacent ( std :: queue < std :: pair < int , int > > qPrio )
{
	int iX = 0 ;
	int iY = 0 ;



	while ( ! qPrio.empty () )
	{
		iX = qPrio.front ().first ;
		iY = qPrio.front ().second ;

		if ( 0 != iX )
		{
			if ( 1 == m_irgCabbage [ iX - 1 ] [ iY ] )
				qPrio.push ( std :: pair < int , int > ( iX - 1 , iY ) ) ;
		}
		if ( m_iHorizon != iX + 1 )
		{
			if ( 1 == m_irgCabbage [ iX + 1 ] [ iY ] )
				qPrio.push ( std :: pair < int , int > ( iX + 1 , iY ) ) ;
		}
		if ( 0 != iY )
		{
			if ( 1 == m_irgCabbage [ iX ] [ iY - 1 ] )
				qPrio.push ( std :: pair < int , int > ( iX - 1 , iY ) ) ;
		}
		if ( m_iVertical != iY + 1 )
		{
			if ( 1 == m_irgCabbage [ iX ] [ iY + 1 ] )
				qPrio.push ( std :: pair < int , int > ( iX + 1 , iY ) ) ;
		}
	}
}

int main ()
{
	int iRep = 0 ;
	int iHorizon = 0 ;
	int iVertical = 0 ;
	int iCnt = 0 ;
	


	cin >> iRep ;


	for ( int i = 0 ; i < iRep ; ++i )
	{
		scanf ( "%d %d %d" , & iHorizon , & iVertical , & iCnt ) ;

		WormCalc worm ( iHorizon , iVertical ) ;
		worm.m_setWorm ( iCnt ) ;

		worm.m_printMinWorm () ;
	}
	

	return 0 ;
}