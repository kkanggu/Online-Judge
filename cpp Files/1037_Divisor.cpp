#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int main ()
{
	int iNum = 0 ;
	int iHigh = 0 ;
	int iLow = 0 ;
	int iTemp = 0 ;



	scanf ( "%d" , & iNum ) ;
	scanf ( "%d" , & iHigh ) ;
	iLow = iHigh ;
	

	for ( int i = 1 ; i < iNum ; ++i )
	{
		scanf ( "%d" , & iTemp ) ;

		if ( iTemp > iHigh )
		{
			iHigh = iTemp ;
		}
		else if ( iTemp < iLow )
		{
			iLow = iTemp ;
		}
	}


	printf ( "%d" , iLow * iHigh ) ;



	return 0 ;
}