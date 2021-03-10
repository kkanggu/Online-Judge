#include <iostream>
#include <cstdio>
#pragma warning(disable:4996)

using std::cout ;
using std::cin ;

int main ()
{
	int iCnt = 0 ;
	int iWeight = 0 ;
	int iHeight = 0 ;
	int ** irgHuman ;



	cin >> iCnt ;

	irgHuman = new int * [ iCnt ] ;


	for ( int i = 0 ; i < iCnt ; ++i )
	{
		scanf ( "%d %d" , & iWeight , & iHeight ) ;

		irgHuman [ i ] = new int [ 3 ] ;
		
		irgHuman [ i ] [ 0 ] = iWeight ;
		irgHuman [ i ] [ 1 ] = iHeight ;
		irgHuman [ i ] [ 2 ] = 1 ;
	}

	for ( int i = 0 ; i < iCnt ; ++i )
	{
		for ( int j = i + 1 ; j < iCnt ; ++j )
		{
			if ( ( irgHuman [ i ] [ 0 ] > irgHuman [ j ] [ 0 ] ) && ( irgHuman [ i ] [ 1 ] > irgHuman [ j ] [ 1 ] ) )
			{
				++ irgHuman [ j ] [ 2 ] ;
			}
			else if ( ( irgHuman [ i ] [ 0 ] < irgHuman [ j ] [ 0 ] ) && ( irgHuman [ i ] [ 1 ] < irgHuman [ j ] [ 1 ] ) )
			{
				++ irgHuman [ i ] [ 2 ] ;
			}
		}
	}

	cout << irgHuman [ 0 ] [ 2 ] ;

	for ( int i = 1 ; i < iCnt ; ++i )
	{
		cout << " " << irgHuman [ i ] [ 2 ] ;
	}

	for ( int i = 0 ; i < iCnt ; ++i )
	{
		delete [] irgHuman [ i ] ;
	}

	delete [] irgHuman ;


	return 0 ;
}

/*
* 
* 10
50 150
51 151
	52 152
		53 153
			54 154
			52 154
		53 153
			50 156
				59 159
51 150
8 7 5 3 2 2 3 2 1 7
*/