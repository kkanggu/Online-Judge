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
	vector < char > vParen ;
	char cInput [ 60 ] ;



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
				vParen.push_back ( '+' ) ;
			}
			else															// If -, 2
			{
				vParen.push_back ( '-' ) ;
			}

			vNum.push_back ( iNum ) ;
			iNum = 0 ;
		}
	}

	vNum.push_back ( iNum ) ;


	for ( int i = 0 ; i < vParen.size () ; ++i )
	{
		if ( '+' == vParen [ i ] )
		{
			vNum [ i ] = vNum [ i ] + vNum [ i + 1 ] ;
			vNum.erase ( vNum.begin () + i + 1 ) ;
			vParen.erase ( vParen.begin () + i ) ;

			--i ;
		}
	}
	while ( 1 != vNum.size () )
	{
		vNum [ 0 ] = vNum [ 0 ] - vNum [ 1 ] ;
		vNum.erase ( vNum.begin () + 1 ) ;
	}


	cout << vNum.at ( 0 ) ;


	return 0 ;
}