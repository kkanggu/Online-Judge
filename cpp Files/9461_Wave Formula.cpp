#include <iostream>
#pragma warning(disable:4996)

using std :: cin ;

int main ()
{
	long long ll1 = 1 ;										// Used only 5 variables to calculate.
	long long ll2 = 1 ;
	long long ll3 = 1 ;
	long long ll4 = 2 ;
	long long ll5 = 2 ;
	long long ll6 = 3 ;
	long long iCnt = 0 ;
	long long iN = 0 ;


	cin >> iCnt ;


	for ( int i = 0 ; i < iCnt ; ++i )
	{
		cin >> iN ;


		for ( int j = 6 ; j < iN ; ++j )
		{
			ll1 = ll2 ;
			ll2 = ll3 ;
			ll3 = ll4 ;
			ll4 = ll5 ;
			ll5 = ll6 ;
			ll6 = ll1 + ll5 ;
		}


		switch ( iN )
		{
			case 1 :
			case 2 :
			case 3 :
				printf ( "1\n" ) ;
				break ;
			case 4 :
			case 5 :
				printf ( "2\n" ) ;
				break ;
			default :
				printf ( "%lld\n" , ll6 ) ;
				break ;
		}

		ll1 = ll2 = ll3 = 1 ;
		ll4 = ll5 = 2 ;
		ll6 = 3 ;
	}


	return 0 ;
}