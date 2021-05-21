#include <iostream>
#pragma warning(disable:4996)

#define Prime 1000000007 ;

using std :: cout ;
using std :: cin ;

int main ()
{
	int iN = 0 ;
	int iK = 0 ;
	long long llOut = 1 ;
	unsigned int irgExtra [ 32 ] = { 1 , } ;
														// a^(p-1) = 1 ( mod p, p is prime)
														// nCr = n! / k! * (n-k)!
														// Let denominator a. Multiply a^(p-2) each, then denominator is 1 (mod p)
	cin >> iN >> iK ;									// So I need to get n! * a^(p-2) % p.


	for ( int i = 2 ; i < iK + 1 ; ++i )
	{
		llOut = llOut * i % Prime ;
	}
	for ( int i = 2 ; i < iN - iK + 1 ; ++i )
	{
		llOut = llOut * i % Prime ;
	}
	
	irgExtra [ 0 ] = llOut ;

	for ( int i = 1 ; i < 31 ; ++i )
	{
		llOut = llOut * llOut % Prime ;
		irgExtra [ i ] = llOut ;
	}

	llOut = 1 ;
	iK = Prime - 2 ;

	for ( int i = 0 ; i < 32 ; ++i )
	{
		if ( 1 == ( iK % 2 ) )
		{
			llOut = llOut * irgExtra [ i ] % Prime ;
		}
		
		iK /= 2 ;

		if ( 1 == iK )
		{
			llOut = llOut * irgExtra [ i + 1 ] % iK ;

			break ;
		}
	}

	for ( int i = 2 ; i < iN + 1 ; ++i )
	{
		llOut = llOut * i % Prime ;
	}

	cout << llOut ;


	return 0 ;
}