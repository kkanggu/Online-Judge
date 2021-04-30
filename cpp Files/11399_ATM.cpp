#include <iostream>
#include <sstream>
#include <algorithm>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;

int main ()
{
	int iNum = 0 ;
	int irgTime [ 1000 ] = { 0 , } ;
	int iMinTime = 0 ;
	string strInput ;
	string strToken ;



	cin >> iNum ;

	std :: getline ( cin , strInput ) ;						// Refresh buffer (\n)
	std :: getline ( cin , strInput ) ;

	std::stringstream stream ( strInput ) ;


	for ( int i = 0 ; i < iNum ; ++i )
	{
		std :: getline ( stream , strToken , ' ' ) ;
		irgTime [ i ] = std :: stoi ( strToken ) ;
	}

	std :: sort ( irgTime , irgTime + iNum ) ;


	for ( int i = 0 ; i < iNum ; ++i )
	{
		iMinTime += irgTime [ i ] * ( iNum - i ) ;
	}


	cout << iMinTime ;


	return 0 ;
}