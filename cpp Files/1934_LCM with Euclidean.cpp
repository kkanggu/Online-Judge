#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int iGetGCD ( int i1 , int i2 ) ;

int main ()
{
	int iNum = 0 ;
	int iInput1 = 0 ;
	int iInput2 = 0 ;
	int iGCD = 0 ;



	scanf ( "%d" , & iNum ) ;


	for ( int i = 0 ; i < iNum ; ++i )
	{
		scanf ( "%d %d" , & iInput1 , & iInput2 ) ;
	

		iGCD = iGetGCD ( iInput1 , iInput2 ) ;

		printf ( "%d\n" , iInput1 / iGCD * iInput2 ) ;
	}
	


	return 0 ;
}

int iGetGCD ( int i1 , int i2 )
{
	while ( ( 0 != i1 ) && ( 0 != i2 ) )
	{
		if ( i1 > i2 )
		{
			i1 %= i2 ;
		}
		else
		{
			i2 %= i1 ;
		}
	}


	return i1 > i2 ? i1 : i2 ;
}