#include <iostream>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;

void Fibonacci ( int n ) ;

int main ()
{
	int iInput = 0 ;
	int iFibo = 0 ;

	cin >> iInput ;


	for ( int i = 0 ; i < iInput ; ++i )
	{
		cin >> iFibo ;

		Fibonacci ( iFibo ) ;
	}

	return 0 ;
}

void Fibonacci ( int n )
{
	int iZero1 = 1 ;
	int iOne1 = 0 ;
	int iZero2 = 0 ;
	int iOne2 = 1 ;


	if ( 0 == n )
	{
		printf ( "%d %d\n" , 1 , 0 ) ;
	}
	else if ( 1 == n )
	{
		printf ( "%d %d\n" , 0 , 1 ) ;
	}
	else
	{
		for ( int i = 2 ; i <= n ; ++i )
		{
			iZero2 += iZero1 ;
			iOne2 += iOne1 ;

			iZero1 = iZero2 - iZero1 ;
			iOne1 = iOne2 - iOne1 ;
		}

		printf ( "%d %d\n" , iZero2 , iOne2 ) ;
	}
}