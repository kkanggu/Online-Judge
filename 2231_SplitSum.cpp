#include <iostream>
#include <cstdio>
#include <cmath>

using std::cout ;
using std::cin ;

int splitSum ( int iOrigin )
{
	int iSum = iOrigin ;



	while ( 0 != iOrigin )
	{
		iSum += iOrigin % 10 ;
		iOrigin /= 10 ;
	}


	return iSum ;
}

int main ()
{
	int iNum = 0 ;
	int iSum = 0 ;
	int iDigit = 0 ;


	cin >> iNum ;

	
	for ( int i = 0 ; i < 7 ; ++i )
	{
		if ( iNum <= ( pow ( 10 , i + 1 ) - 1 + 9 * ( i + 1 ) ) )
		{
			iDigit = i ;


			break ;
		}
	}


	iSum = iNum - 9 - ( iDigit * 9 ) ;


	for ( int i = iSum ; i < pow ( 10 , iDigit + 1 ) ; ++i )
	{
		iSum = splitSum ( i ) ;


		if ( iNum == iSum )
		{
			iSum = i * -1 ;


			break ;
		}				
	}


	if ( iSum < 0 )
		cout << ( iSum * -1 ) ;
	else
		cout << 0 ;


	return 0 ;
}