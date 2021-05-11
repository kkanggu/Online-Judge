#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int iGetGCD ( int i1 , int i2 ) ;

int main ()
{
	int iInput1 = 0 ;
	int iInput2 = 0 ;
	int iGCD = 0 ;



	scanf ( "%d %d" , & iInput1 , & iInput2 ) ;
	

	iGCD = iGetGCD ( iInput1 , iInput2 ) ;

	printf ( "%d\n%d" , iGCD , iInput1 / iGCD * iInput2 ) ;



	return 0 ;
}

int iGetGCD ( int i1 , int i2 )
{
	while ( i1 != i2 )
	{
		if ( i1 > i2 )
		{
			i1 -= i2 ;
		}
		else
		{
			i2 -= i1 ;
		}
	}


	return i1 ;
}