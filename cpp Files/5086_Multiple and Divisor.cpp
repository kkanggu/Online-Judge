#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;

int main ()
{
	int iInput1 = - 1 ;
	int iInput2 = - 1 ;



	scanf ( "%d %d" , & iInput1 , & iInput2 ) ;

	while ( ( 0 != iInput1 ) || ( 0 != iInput2 ) )
	{
		if ( 0 == ( iInput1 % iInput2 ) )
		{
			printf ( "multiple\n" ) ;
		}
		else if ( 0 == ( iInput2 % iInput1 ) )
		{
			printf ( "factor\n" ) ;
		}
		else
		{
			printf ( "neither\n" ) ;
		}
		scanf ( "%d %d" , & iInput1 , & iInput2 ) ;
	}

	return 0 ;
}