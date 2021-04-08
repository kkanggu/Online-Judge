#include <iostream>
#include <string>
#include <vector>
#pragma warning(disable:4996)

void BackTracking ( int * irgSequence , int iMax , int iRemain , std :: vector < int > & vComb ) ;	// Max combination and check remain

int main ()
{
	int iMax = 0 ;
	int iCnt = 0 ;
	int irgSequence [ 8 ] ;
	std :: vector < int > vComb ;


	for ( int i = 0 ; i < 8 ; ++i )
	{
		irgSequence [ i ] = i + 1 ;
	}


	scanf ( "%d %d" , & iMax , & iCnt ) ;


	for ( int i = 0 ; i < iMax ; ++i )
	{
		vComb.push_back ( i ) ;
		irgSequence [ i ] = 0 ;
		BackTracking ( irgSequence , iMax , iCnt - 1 , vComb ) ;
		vComb.pop_back () ;
		irgSequence [ i ] = i + 1 ;
	}
	


	return 0 ;
}

void BackTracking ( int * irgSequence , int iMax , int iRemain , std :: vector < int > & vComb )		// Max combination and check remain
{
	if ( iRemain )
	{
		for ( int i = 0 ; i < iMax ; ++i )
		{
			if ( irgSequence [ i ] )
			{
				vComb.push_back ( i ) ;
				irgSequence [ i ] = 0 ;
				BackTracking ( irgSequence , iMax , iRemain - 1 , vComb ) ;
				vComb.pop_back () ;
				irgSequence [ i ] = i + 1 ;
			}
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