#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

void getCombination ( int iN , int iK ) ;

int main ()
{
	int iN = 0 ;
	int iK = 0 ;

	

	cin >> iN >> iK ;

	getCombination ( iN , iK ) ;


	return 0 ;
}

void getCombination ( int iN , int iK )
{
	int ** idpPascal = new int * [ iN + 1 ] ;



	for ( int i = 0 ; i < iN + 1 ; ++i )
	{
		idpPascal [ i ] = new int [ i + 3 ] { 0 , } ;
	}

	idpPascal [ 0 ] [ 1 ] = 1 ;

	for ( int i = 1 ; i < iN + 1 ; ++i )
	{
		for ( int j = 1 ; j < i + 2 ; ++j )
		{
			idpPascal [ i ] [ j ] = ( idpPascal [ i - 1 ] [ j - 1 ] + idpPascal [ i - 1 ] [ j ] ) % 10007 ;
		}
	}

	printf ( "%d" , idpPascal [ iN ] [ iK + 1 ] ) ;

	for ( int i = 0 ; i < iN + 1 ; ++i )
	{
		delete [] idpPascal [ i ] ;
	}

	delete [] idpPascal ;
}