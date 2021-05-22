#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int main ()
{
	int iN = 0 ;
	int iM = 0 ;
	int iK = 0 ;
	int ** idpMatrixA ;
	int ** idpMatrixB ;
	int ** idpResultMatrix ;


	cin >> iN >> iM ;

	idpMatrixA = new int * [ iN ] ;

	for ( int i = 0 ; i < iN ; ++i )
	{
		idpMatrixA [ i ] = new int [ iM ] ;

		scanf ( "%d" , idpMatrixA [ i ] ) ;

		for ( int j = 1 ; j < iM ; ++j )
		{
			scanf ( "%d" , & idpMatrixA [ i ] [ j ] ) ;
		}
	}

	cin >> iM >> iK ;

	idpMatrixB = new int * [ iM ] ;

	for ( int i = 0 ; i < iM ; ++i )
	{
		idpMatrixB [ i ] = new int [ iK ] ;

		scanf ( "%d" , idpMatrixB [ i ] ) ;

		for ( int j = 1 ; j < iK ; ++j )
		{
			scanf ( "%d" , & idpMatrixB [ i ] [ j ] ) ;
		}
	}


	idpResultMatrix = new int * [ iN ] ;

	for ( int i = 0 ; i < iN ; ++i )
	{
		idpResultMatrix [ i ] = new int [ iK ] ;

		std :: fill ( idpResultMatrix [ i ] , idpResultMatrix [ i ] + iK , 0 ) ;
	}

	for ( int i = 0 ; i < iN ; ++i )
	{
		for ( int j = 0 ; j < iK ; ++j )
		{
			for ( int k = 0 ; k < iM ; ++k )
			{
				idpResultMatrix [ i ] [ j ] += idpMatrixA [ i ] [ k ] * idpMatrixB [ k ] [ j ] ;
			}
		}
	}

	for ( int i = 0 ; i < iN ; ++i )
	{
		for ( int j = 0 ; j < iK ; ++j )
		{
			printf ( "%d " , idpResultMatrix [ i ] [ j ] ) ;
		}

		printf ( "\n" ) ;
	}

	for ( int i = 0 ; i < iN ; ++i )
	{
		delete [] idpMatrixA [ i ] ;
		delete [] idpResultMatrix [ i ] ;
	}
	for ( int i = 0 ; i < iM ; ++i )
	{
		delete [] idpMatrixB [ i ] ;
	}

	delete [] idpMatrixA ;
	delete [] idpMatrixB ;
	delete [] idpResultMatrix ;

	return 0 ;
}