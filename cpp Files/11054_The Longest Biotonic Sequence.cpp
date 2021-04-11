#include <iostream>
#include <sstream>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;

int main ()
{
	int iNum = 0 ;
	int irgWine [ 1000 ] ;
	int irgSeq [ 2 ] [ 1000 ] = { 0 , } ;				// [] [ n ], n+1 is sequence length and [] [ n ] is the last num of sequence
	int iMax = 1000 ;									// [ 0 ] [] mean Increasing, [ 1 ] [] mean decreasing.
	string strInput ;
	string strToken ;



	cin >> iNum ;

	std :: getline ( cin , strInput ) ;					// Refresh buffer (\n)
	std :: getline ( cin , strInput ) ;
	std :: stringstream stream ( strInput ) ;			// Each line

	std :: fill_n ( irgSeq [ 0 ] , 1000 , 1001 ) ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		std :: getline ( stream , strToken , ' ' ) ;
		irgWine [ i ] = std :: stoi ( strToken ) ;
	}
	for ( int i = 0 ; i < iNum ; ++i )					// Calculate
	{
		for ( int j = i ; j > 0 ; --j )
		{
			if ( ( irgSeq [ 0 ] [ j ] > irgWine [ i ] ) && ( irgSeq [ 0 ] [ j - 1 ] < irgWine [ i ] ) )			// If same length, but lower efficient data exist
			{
				irgSeq [ 0 ] [ j ] = irgWine [ i ] ;
			}
			if ( ( ( 1001 != irgSeq [ 0 ] [ j - 1 ] ) && ( irgSeq [ 0 ] [ j - 1 ] < irgWine [ i ] ) && ( irgSeq [ 1 ] [ j ] > irgWine [ i ] ) )				// Increasing
				|| ( ( 1001 != irgSeq [ 0 ] [ j - 1 ] ) && ( irgSeq [ 0 ] [ j - 1 ] > irgWine [ i ] ) && ( irgSeq [ 1 ] [ j ] < irgWine [ i ] ) )			// Increasing change to Decreasing
				|| ( ( 0 != irgSeq [ 1 ] [ j - 1 ] ) && ( irgSeq [ 1 ] [ j - 1 ] > irgWine [ i ] ) && ( irgSeq [ 1 ] [ j ] < irgWine [ i ] ) ) )			// Decreasing data
			{
				irgSeq [ 1 ] [ j ] = irgWine [ i ] ;
			}
		}

		if ( irgSeq [ 0 ] [ 0 ] > irgWine [ i ] )		// One length, increasing & decreasing
		{
			irgSeq [ 0 ] [ 0 ] = irgWine [ i ] ;
			irgSeq [ 1 ] [ 0 ] = irgWine [ i ] ;
		}
	}
	for ( int i = 0 ; i < 1000 ; ++i )
	{
		if ( ( 1001 == irgSeq [ 0 ] [ i ] ) && ( 0 == irgSeq [ 1 ] [ i ] ) )
		{
			iMax = i ;

			break ;
		}
	}


	cout << iMax ;


	return 0 ;
}