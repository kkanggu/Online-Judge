#include <iostream>
#include <sstream>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;

int main ()
{
	int iNum = 0 ;
	int irgMax [ 2 ] = { -1000 , -1000 } ;						// [ 0 ] is max broken sequence, [ 1 ] is a sequencial sum
	int iMax = -1000 ;
	int iTemp = 0 ;
	string strInput ;
	string strToken ;



	cin >> iNum ;

	std :: getline ( cin , strInput ) ;							// Refresh buffer (\n)
	std :: getline ( cin , strInput ) ;
	std :: stringstream stream ( strInput ) ;					// Each line

	std :: getline ( stream , strToken , ' ' ) ;
	iTemp = std :: stoi ( strToken ) ;
	irgMax [ 0 ] = iTemp ;
	irgMax [ 1 ] = iTemp ;

	for ( int i = 1 ; i < iNum ; ++i )
	{
		std :: getline ( stream , strToken , ' ' ) ;

		iTemp = std :: stoi ( strToken ) ;


		if ( ( irgMax [ 1 ] + iTemp ) > iTemp )					// Still sequencial
		{
			if ( ( iTemp < 0 ) && ( irgMax [ 0 ] < irgMax [ 1 ] ) )
			{
				irgMax [ 0 ] = irgMax [ 1 ] ;
			}

			irgMax [ 1 ] += iTemp ;
		}
		else													// Sequence have to be broken
		{
			if ( irgMax [ 0 ] < irgMax [ 1 ] )
			{
				irgMax [ 0 ] = irgMax [ 1 ] ;
			}

			irgMax [ 1 ] = iTemp ;
		}
	}


	if ( irgMax [ 0 ] > irgMax [ 1 ] )
		iMax = irgMax [ 0 ] ;
	else
		iMax = irgMax [ 1 ] ;


	cout << iMax ;


	return 0 ;
}