#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int main ()
{
/*	int * ipBinaryCnt ;
	int iCnt = 0 ;



	cin >> iCnt ;

	ipBinaryCnt = new int [ iCnt + 1 ] ;
	ipBinaryCnt [ 0 ] = 0 ;
	ipBinaryCnt [ 1 ] = 1 ;


	if ( 1 != iCnt )
	{
		ipBinaryCnt [ 2 ] = 2 ;

		for ( int i = 3 ; i < iCnt + 1 ; ++i )
		{
			ipBinaryCnt [ i ] = ( ipBinaryCnt [ i - 2 ] + ipBinaryCnt [ i -1 ] ) % 15746 ;
		}
	}


	cout << ipBinaryCnt [ iCnt ] ;


	delete [] ipBinaryCnt ;
*/
	int i1 = 0 ;
	int i2 = 1 ;
	int i3 = 1 ;
	int iCnt = 0 ;



	cin >> iCnt ;


	for ( int i = 1 ; i < iCnt ; ++i )
	{
		i1 = i2 ;
		i2 = i3 ;
//		i3 = ( i1 + i2 ) % 15746 ;
		i3 = i1 + i2 ;

		if ( i3 > 15745 )
			i3 %= 15746 ;
	}

	
	cout << i3 ;


	return 0 ;
}