#include <iostream>
#pragma warning(disable:4996)

using std :: cin ;
using std :: cout ;

int iMaxValue ( int & i1 , int & i2 ) ;

int main ()
{
	int iNum = 0 ;
	int iWeight = 0 ;
	int ** idpKnap ;								// DP solution. First [] is count of available thing, second [] is current weight. [] [] means max value
	int ** idpThing ;								// First [] is each thing. [] [ 0 ] is weight, [] [ 1 ] is value
	int iMax = 0 ;
	int iTemp = 0 ;



	scanf ( "%d %d" , & iNum , & iWeight ) ;

	idpKnap = new int * [ iNum + 1 ] ;
	idpThing = new int * [ iNum + 1 ] ;


	for ( int i = 0 ; i < iNum + 1 ; ++i )
	{
		idpKnap [ i ] = new int [ iWeight + 1 ] ;
		idpThing [ i ] = new int [ 2 ] ;

		std :: fill_n ( idpKnap [ i ] , iWeight + 1 , 0 ) ;
		std :: fill_n ( idpThing [ i ] , 2 , 0 ) ;
	}

	for ( int i = 1 ; i < iNum + 1 ; ++i )
	{
		scanf ( "%d %d" , & idpThing [ i ] [ 0 ] , & idpThing [ i ] [ 1 ] ) ;


		for ( int j = 1 ; j < idpThing [ i ] [ 0 ] ; ++j )
		{
			idpKnap [ i ] [ j ] = idpKnap [ i - 1 ] [ j ] ;
		}
		for ( int j = idpThing [ i ] [ 0 ] ; j < iWeight + 1 ; ++j )
		{
			iTemp = idpKnap [ i - 1 ] [ j - idpThing [ i ] [ 0 ] ] + idpThing [ i ] [ 1 ] ;

			idpKnap [ i ] [ j ] = iMaxValue ( idpKnap [ i - 1 ] [ j ] , iTemp ) ;
		}
	}


	cout << idpKnap [ iNum ] [ iWeight ] ;


	for ( int i = 0 ; i < iNum + 1 ; ++i )
	{
		delete [] idpKnap [ i ] ;
	}
	
	delete [] idpKnap ;


	return 0 ;
}

int iMaxValue ( int & i1 , int & i2 )
{
	if ( i1 > i2 )
		return i1 ;
	else
		return i2 ;
}