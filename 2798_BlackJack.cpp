#include <iostream>
#include <cstdio>
#include <sstream>
#include <climits>
#pragma warning(disable:4996)

using std::string ;
using std::cout ;
using std::cin ;

int main ()
{
	int iCnt ;
	int iMax ;
	int * irgCard ;
	string strInput ;
	string strToken ;
	int iSum = 0 ;
	int iTemp = 0 ;



	scanf ( "%d %d" , & iCnt , & iMax ) ;

	irgCard = new int [ iMax ] ;

	std :: getline ( cin , strInput ) ;
	std :: getline ( cin , strInput ) ;



	std::stringstream stream ( strInput ) ;


	for ( int i = 0 ; i < iCnt ; ++i )
	{
		std :: getline ( stream , strToken , ' ' ) ;
		irgCard [ i ] = std :: stoi ( strToken ) ;
	}


	for ( int i = 0 ; i < iCnt ; ++i )
	{
		for ( int j = i + 1; j < iCnt ; ++j )
		{
			for ( int k = j + 1 ; k < iCnt ; ++k )
			{
				iTemp = irgCard [ i ] + irgCard [ j ] + irgCard [ k ] ;


				if ( ( iSum < iTemp ) && ( iTemp <= iMax ) )
				{
					iSum = iTemp ;
				}
			}
		}
	}


	cout << iSum ;


	delete [] irgCard ;


	return 0 ;
}