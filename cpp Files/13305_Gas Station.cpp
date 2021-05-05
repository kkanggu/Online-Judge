#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;
using std :: vector ;
using std :: pair ;

typedef pair < int , int > iPair ;

bool bCompare ( const iPair & a ,
				const iPair & b ) ;
int iSetMinPrice ( int irgDistance [] [ 2 ] , int iPrice , int iStartIndex , long long & llMinPrice , int iMax ) ;

int main ()
{
	int iNum = 0 ;
	int iCnt = 0 ;
	vector < iPair > vPrice ;							// Price & Index pair
	int irgDistance [ 100000 ] [ 2 ] ;
	long long llMinPrice = 0 ;
	char cInput [ 60 ] ;
	string strInput ;
	string strToken ;



	scanf ( "%d" , & iNum ) ;


	std :: fill_n ( irgDistance [ 0 ] , iNum * 2 , 0 ) ;

	std :: getline ( cin , strInput ) ;						// Refresh buffer (\n)
	std :: getline ( cin , strInput ) ;
	
	std :: stringstream stream1 ( strInput ) ;

	for ( int i = 0 ; i < iNum - 1 ; ++i )
	{
		std :: getline ( stream1 , strToken , ' ' ) ;
		irgDistance [ i ] [ 0 ] = std :: stoi ( strToken ) ;
	}

	std :: getline ( cin , strInput ) ;
	
	std :: stringstream stream2 ( strInput ) ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		std :: getline ( stream2 , strToken , ' ' ) ;
		vPrice.push_back ( std :: make_pair ( std :: stoi ( strToken ) , i ) ) ;
	}

	vPrice.pop_back () ;

	std :: sort ( vPrice.begin () , vPrice.end () , bCompare ) ;


	for ( int i = 0 ; i < iNum - 1 ; ++i )
	{
		iCnt += iSetMinPrice ( irgDistance , vPrice [ i ].first , vPrice [ i ].second , llMinPrice , iNum - 1 ) ;


		if ( iCnt == ( iNum - 1 ) )
		{
			break ;
		}
	}


	cout << llMinPrice ;


	return 0 ;
}

bool bCompare ( const iPair & a ,
				const iPair & b )
{
	if ( a.first < b.first )
	{
		return true ;
	}
	else
	{
		return false ;
	}
}

int iSetMinPrice ( int irgDistance [] [ 2 ] , int iPrice , int iStartIndex , long long & llMinPrice , int iMax )
{
	int iCnt = 0 ;
	int i = iStartIndex ;


	for ( ; i < iMax ; ++i )
	{
		if ( 0 == irgDistance [ i ] [ 1 ] )
		{
			irgDistance [ i ] [ 1 ] = 1 ;

			iCnt += irgDistance [ i ] [ 0 ] ;
		}
		else
		{
			break ;
		}
	}


	llMinPrice += ( long long ) iPrice * iCnt ;


	return i - iStartIndex ;
}