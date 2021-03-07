#include <iostream>
#include <cstdio>
#include <sstream>

using std::string ;
using std::cout ;
using std::cin ;

class Dice
{
private :
	int m_irgWeight [ 6 ] ;
	int m_iSize ;

public :/*
	Dice () ;
	~ Dice () ;*/
	Dice ( const int Size ) ;
	void m_setWeight ( const string strInput ) ;
	void m_sortWeight ( const int iWeight , const int iRep ) ;
	void m_printMinSum () ;
	long long m_llgetSumOfPlane ( const int iPlane ) ;
} ;

Dice :: Dice ( const int Size )
{
	m_iSize = Size ;
	

	for ( int i = 0 ; i < 6 ; ++i )
	{
		m_irgWeight [ i ] = INT_MAX ;
	}
}

void Dice :: m_setWeight ( const string strInput )
{
	std::stringstream stream ( strInput ) ;
	string strToken ;



	/*stream.str ( strInput ) ;*/

	for ( int i = 0 ; i < 6 ; ++i )
	{
		stream >> strToken ;
		m_sortWeight ( std::stoi ( strToken ) , i ) ;
	}
}

void Dice :: m_sortWeight ( const int iWeight , const int iRep )
{
	if ( 0 == iRep )
	{
		m_irgWeight [ 0 ] = iWeight ;
	}
	else
	{
		int i = 0 ;


		while ( i < iRep )
		{
			if ( m_irgWeight [ i ] > iWeight )
			{
				for ( int j = iRep ; j > i ; --j )
				{
					m_irgWeight [ j + 1 ] = m_irgWeight [ j ] ;
				}


				m_irgWeight [ i ] = iWeight ;

				break ;
			}
			else
			{
				++i ;
			}
		}


		if ( i == iRep )
		{
			m_irgWeight [ iRep ] = iWeight ;
		}
	}
}

void Dice :: m_printMinSum ()
{
	long long llSum = 0 ;



	if ( 1 == m_iSize )
	{
		for ( int i = 0 ; i < 5 ; ++i )
		{
			llSum += m_irgWeight [ i ] ;
		}
	}
	else
	{
		llSum = m_llgetSumOfPlane ( 3 ) * 4 ;																						// 3 Plane
		llSum += m_llgetSumOfPlane ( 2 ) * 4 * ( 2 * m_iSize - 3 ) ;																// 2 Plane
		llSum += m_llgetSumOfPlane ( 1 ) * ( ( long long ) ( m_iSize - 2 ) * ( m_iSize - 1 ) * 4 + ( long long ) ( m_iSize - 2 ) * ( m_iSize - 2 ) ) ;		// 1 Plane

		cout << llSum ;
	}
}

long long Dice :: m_llgetSumOfPlane ( const int iPlane )
{
	if ( 1 == iPlane )
	{
		return m_irgWeight [ 0 ] ;
	}
	else if ( 2 == iPlane )
	{
		return m_irgWeight [ 0 ] + m_irgWeight [ 1 ] ;
	}
	else if ( 3 == iPlane )
	{
		return m_irgWeight [ 0 ] + m_irgWeight [ 1 ] + m_irgWeight [ 2 ] ;
	}
	else
		return -1 ;
}

int main ()
{
	int iSize = 0 ;
	string strInput ;

	cin >> iSize ;
	Dice dice ( iSize ) ;

	std::getline ( cin , strInput ) ;
	std::getline ( cin , strInput ) ;

	dice.m_setWeight ( strInput	) ;
	dice.m_printMinSum () ;


	return 0 ;
}