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
	int irgSeqMax [ 1000 ] = { 0 , } ;																	// [ n ], n+1 is sequence length and [ n ] is the last num of sequence
	int iMax = 1000 ;
	string strInput ;
	string strToken ;



	cin >> iNum ;

	std :: getline ( cin , strInput ) ;																	// Refresh buffer (\n)
	std :: getline ( cin , strInput ) ;
	std :: stringstream stream ( strInput ) ;															// Each line

	std :: fill_n ( irgSeqMax , 1000 , 1001 ) ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		std :: getline ( stream , strToken , ' ' ) ;
		irgWine [ i ] = std :: stoi ( strToken ) ;
	}
	for ( int i = 0 ; i < iNum ; ++i )																	// Calculate
	{
		if ( irgSeqMax [ 0 ] > irgWine [ i ] )															// One length
		{
			irgSeqMax [ 0 ] = irgWine [ i ] ;
		}

		for ( int j = 1 ; j < i + 1 ; ++j )
		{
			if ( ( irgSeqMax [ j ] > irgWine [ i ] ) && ( irgSeqMax [ j - 1 ] < irgWine [ i ] ) )		// If same length, but lower data exist
			{
				irgSeqMax [ j ] = irgWine [ i ] ;
			}
		}
	}
	for ( int i = 0 ; i < 1000 ; ++i )
	{
		if ( 1001 == irgSeqMax [ i ] )
		{
			iMax = i ;

			break ;
		}
	}


	cout << iMax ;


	return 0 ;
}