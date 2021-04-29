#include <iostream>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;

int main ()
{
	int iNum = 0 ;
	int iValue = 0 ;
	int * idpNumber ;
	int iCnt = 0 ;



	cin >> iNum ;
	cin >> iValue ;

	idpNumber = new int [ iNum ] ;


	for ( int i = 0 ; i < iNum ; ++i )
	{
		cin >> idpNumber [ i ] ;
	}

	for ( int i = iNum - 1 ; i >= 0 ; --i )
	{
		if ( iValue >= idpNumber [ i ] )				// Can use this coin
		{
			iCnt += iValue / idpNumber [ i ] ;
			iValue %= idpNumber [ i ] ;
		}
	}


	cout << iCnt ;

	delete [] idpNumber ;

	return 0 ;
}