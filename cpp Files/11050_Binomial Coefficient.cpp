#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int iGetFactorial ( int iNum ) ;

int main ()
{
	int iN = 0 ;
	int iK = 0 ;

	

	cin >> iN >> iK ;

	printf ( "%d" , iGetFactorial ( iN ) / iGetFactorial ( iK ) / iGetFactorial ( iN - iK ) ) ;


	return 0 ;
}

int iGetFactorial ( int iNum )
{
	int iFac = 1 ;



	for ( int i = 2 ; i < iNum + 1 ; ++i )
	{
		iFac *= i ;
	}

	
	return iFac ;
}