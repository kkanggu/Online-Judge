#include <iostream>
#include <string>
#include <vector>
#pragma warning(disable:4996)

void BackTracking ( int iMax , int iRemain , std :: vector < int > & vComb ) ;	// Max combination and check remain

int main ()
{
	int iMax = 0 ;
	int iCnt = 0 ;
	std :: vector < int > vComb ;



	scanf ( "%d %d" , & iMax , & iCnt ) ;


	for ( int i = 0 ; i < iMax ; ++i )
	{
		vComb.push_back ( i ) ;
		BackTracking ( iMax , iCnt - 1 , vComb ) ;
		vComb.pop_back () ;
	}
	


	return 0 ;
}

void BackTracking ( int iMax , int iRemain , std :: vector < int > & vComb )		// Max combination and check remain
{
	if ( iRemain )
	{
		for ( int i = 0 ; i < iMax ; ++i )
		{
			vComb.push_back ( i ) ;
			BackTracking ( iMax , iRemain - 1 , vComb ) ;
			vComb.pop_back () ;
		}
	}
	else
	{
		std :: vector < int > :: iterator iter = vComb.begin () ;

		printf ( "%d" , * iter + 1 ) ;

		++ iter ;

		for ( ; iter != vComb.end () ; ++ iter )
		{
			printf ( " %d" , * iter + 1 ) ;
		}

		printf ( "\n" ) ;
	}
}