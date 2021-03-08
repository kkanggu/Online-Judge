#include <iostream>
#include <cstdio>
#include <sstream>
#include <climits>

using std::string ;
using std::cout ;
using std::cin ;

class WormCalc
{
private :
	int m_iHorizon ;
	int m_iVertical ;
	int ** m_irgCabbage ;

public :
	WormCalc () ;
	~ WormCalc () ;
	WormCalc ( const int iHorizon , const int iVertical ) ;
	void m_setWorm ( const int iCnt ) ;
	void printMinWorm () ;

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




	for ( int i = 0 ; i < iCnt ; ++i )
	{
		scanf ( "%d %d" , & iHorizon , iVertical ) ;

		m_irgCabbage [ iHorizon ] [ iVertical ] = 1 ;
	}
}

void WormCalc :: printMinWorm ()
{
	int iCnt = 0 ;



	while ( true )
	{

	}
}

int main ()
{

	return 0 ;
}