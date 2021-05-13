#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

void printFraction ( int iFirst , int iSecond ) ;

int main ()
{
	int iNum = 0 ;
	int iFirst = 0 ;
	int iInput = 0 ;

	

	cin >> iNum ;
	cin >> iFirst ;


	for ( int i = 0 ; i < iNum - 1 ; ++i )
	{
		cin >> iInput ;
		printFraction ( iFirst , iInput ) ;
	}


	return 0 ;
}

void printFraction ( int iFirst , int iSecond )
{
	int iGCD = 0 ;
	int i1 = iFirst ;
	int i2 = iSecond ;



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

	iGCD = i1 > i2 ? i1 : i2 ;

	printf ( "%d/%d\n" , iFirst / iGCD , iSecond / iGCD ) ;
}