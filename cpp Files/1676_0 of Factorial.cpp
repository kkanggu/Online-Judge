#include <iostream>
#pragma warning(disable:4996)

using std :: cout ;
using std :: cin ;


int main ()
{
	int iNum = 0 ;
	int iCnt = 0 ;

	

	scanf ( "%d" , & iNum ) ;


	for ( int i = 5 ; i <= iNum ; i += 5 )					// Count only 5
	{
		if ( 0 == ( i % 125 ) )
		{
			iCnt += 3 ;
		}
		else if ( 0 == ( i % 25 ) )
		{
			iCnt += 2 ;
		}
		else if ( 0 == ( i % 5 ) )
		{
			++ iCnt ;
		}
	}


	cout << iCnt ;



	return 0 ;
}