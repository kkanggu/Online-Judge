#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#pragma warning(disable:4996)

using std :: string ;
using std :: cout ;
using std :: cin ;

void Backtracking ( int * iNum , int * iOperator , int * iMaxMin , int iMax , int iCnt , int iResult ) ;

int main ()
{
	int iCnt = 0 ;
	int iOperator [ 4 ] = { 0 , } ;
	int iNum [ 11 ] = { 0 , } ;
	int iMaxMin [ 2 ] ;
	string strInput ;
	string strToken ;



	scanf ( "%d" , & iCnt ) ;
	std :: getline ( cin , strInput ) ;						// Refresh buffer (\n)
	std :: getline ( cin , strInput ) ;
	
	std::stringstream stream ( strInput ) ;

	for ( int i = 0 ; i < iCnt ; ++i )
	{
		std :: getline ( stream , strToken , ' ' ) ;
		iNum [ i ] = std :: stoi ( strToken ) ;
	}

	scanf ( "%d %d %d %d" , iOperator , iOperator + 1 , iOperator + 2 , iOperator + 3 ) ;
	iMaxMin [ 0 ] = INT_MIN ;
	iMaxMin [ 1 ] = INT_MAX ;


	Backtracking ( iNum , iOperator , iMaxMin , iCnt - 1 , 0 , iNum [ 0 ] ) ;

	printf ( "%d\n%d" , iMaxMin [ 0 ] , iMaxMin [ 1 ] ) ;


	return 0 ;
}

void Backtracking ( int * iNum , int * iOperator , int * iMaxMin , int iMax , int iCnt , int iResult )
{
	if ( iMax != iCnt )
	{
		if ( iOperator [ 0 ] )				// If can do +
		{
			-- iOperator [ 0 ] ;
			Backtracking ( iNum , iOperator , iMaxMin , iMax , iCnt + 1 , iResult + iNum [ iCnt + 1 ] ) ;
			++ iOperator [ 0 ] ;
		}
		if ( iOperator [ 1 ] )				// If can do -
		{
			-- iOperator [ 1 ] ;
			Backtracking ( iNum , iOperator , iMaxMin , iMax , iCnt + 1 , iResult - iNum [ iCnt + 1 ] ) ;
			++ iOperator [ 1 ] ;
		}
		if ( iOperator [ 2 ] )				// If can do *
		{
			-- iOperator [ 2 ] ;
			Backtracking ( iNum , iOperator , iMaxMin , iMax , iCnt + 1 , iResult * iNum [ iCnt + 1 ] ) ;
			++ iOperator [ 2 ] ;
		}
		if ( iOperator [ 3 ] )				// If can do /
		{
			-- iOperator [ 3 ] ;
			Backtracking ( iNum , iOperator , iMaxMin , iMax , iCnt + 1 , iResult / iNum [ iCnt + 1 ] ) ;
			++ iOperator [ 3 ] ;
		}
	}
	else
	{
		if ( iMaxMin [ 0 ] < iResult )
			iMaxMin [ 0 ] = iResult ;
		if ( iResult < iMaxMin [ 1 ] )
			iMaxMin [ 1 ] = iResult ;
	}
}