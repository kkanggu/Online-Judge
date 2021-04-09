#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using std :: cin ;
using std :: cout ;

int iMinValue ( int & i1 , int & i2 ) ;
int iTripleMinValue ( int & i1 , int & i2 , int & i3 ) ;

int main ()
{
	int iNum = 0 ;
	int ipNum [ 1000001 ] ;



	cin >> iNum ;

//	ipNum = new int [ iNum + 1 ] ;
	ipNum [ 1 ] = 0 ;


	for ( int i = 2 ; i <= iNum + 1 ; ++i )
	{
		if ( ( i % 3 == 0 ) && ( i % 2 == 0 ) )				// 6
		{
			ipNum [ i ] = iTripleMinValue ( ipNum [ i - 1 ] , ipNum [ i / 2 ] , ipNum [ i / 3 ] ) + 1 ;
		}
		else if ( i % 3 == 0 )								// 3
		{
			ipNum [ i ] = iMinValue ( ipNum [ i - 1 ] , ipNum [ i / 3 ] ) + 1 ;
		}
		else if ( i % 2 == 0 )								// 2
		{
			ipNum [ i ] = iMinValue ( ipNum [ i - 1 ] , ipNum [ i / 2 ] ) + 1 ;
		}
		else
		{
			ipNum [ i ] = ipNum [ i - 1 ] + 1 ;
		}
	}


	cout << ipNum [ iNum ] ;


//	delete [] ipNum ;


	return 0 ;
}

int iMinValue ( int & i1 , int & i2 )
{
	if ( i1 < i2 )
		return i1 ;
	else
		return i2 ;
}

int iTripleMinValue ( int & i1 , int & i2 , int & i3 )
{
	if ( ( i1 <= i2 ) && ( i1 <= i3 ) )
		return i1 ;
	else if ( ( i1 >= i3 ) && ( i2 >= i3 ) )
		return i3 ;
	else
		return i2 ;
}