#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;
using std :: vector ;

int main ()
{
	int iNum = 0 ;
	vector < int > vNum ;
	int irgParen [ 49 ] = { 0 , } ;
	int iCnt = 0 ;															// The cnt of number, temp variable
	char cInput [ 50 ] ;
	vector < int > :: iterator iter ;



	scanf ( "%s" , cInput ) ;


	for ( int i = 0 ; '\0' != cInput [ i ] ; ++i )
	{
		if ( ( '0' <= cInput [ i ] ) && ( cInput [ i ] <= '9' ) )			// If number
		{
			iNum = iNum * 10 + cInput [ i ] - 48 ;
		}
		else
		{
			if ( '+' == cInput [ i ] )										// If +, 1
			{
				irgParen [ iCnt ] = 1 ;
			}
			else															// If -, 2
			{
				irgParen [ iCnt ] = 2 ;
			}

			vNum.push_back ( iNum ) ;
			iNum = 0 ;
			++ iCnt ;
		}
	}

//	for ( iter = vNum.begin () ; iter != vNum.end () ; ++ iter )
	iter = vNum.begin () ;
	iCnt = 0 ;

	for ( int i = 0 ; i < vNum.size () ; ++i )
	{
		++ iCnt ;

		if ( irgParen [ i ] == 1 )
		{
			vNum [ i ] = vNum [ i ] + vNum [ i + 1 ] ;
			iter += iCnt + 1 ;
			vNum.erase ( iter ) ;
			iCnt = 0 ;
		}
	}
	while ( 1 != vNum.size () )
	{
		vNum [ 0 ] = vNum [ 0 ] - vNum [ 1 ] ;
		iter = vNum.begin () + 1 ;
		vNum.erase ( iter ) ;
	}


	cout << vNum.at ( 0 ) ;



	return 0 ;
}