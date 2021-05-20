#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int main ()
{
	unsigned int uiA = 0 ;
	unsigned int uiB = 0 ;
	unsigned int uiC = 0 ;
	long long llOut = 1 ;
	unsigned int irgExtra [ 32 ] = { 1 , } ;



	cin >> uiA >> uiB >> uiC ;

	llOut = uiA ;
	irgExtra [ 0 ] = llOut ;

	for ( int i = 1 ; i < 32 ; ++i )
	{
		llOut = llOut * llOut % uiC ;
		irgExtra [ i ] = llOut ;
	}

	llOut = 1 ;

	for ( int i = 0 ; i < 32 ; ++i )
	{
		if ( 1 == ( uiB % 2 ) )
		{
			llOut = llOut * irgExtra [ i ] % uiC ;
		}
		
		uiB /= 2 ;

		if ( 1 == uiB )
		{
			llOut = llOut * irgExtra [ i + 1 ] % uiC ;

			break ;
		}
	}

	cout << llOut ;


	return 0 ;
}