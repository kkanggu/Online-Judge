#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;
using std :: vector ;
using std :: tuple ;
using std :: get ;

typedef tuple < unsigned int , unsigned int , unsigned int > tui ;

bool bCompare ( const tui & a ,
				const tui & b ) ;

int iDoGreedy ( vector < tui > & vMeetTime , int iNum ) ;

int main ()
{
	int iNum = 0 ;
	int iValue = 0 ;
	vector < tui > vMeetTime ;
	int iCnt = 0 ;
	unsigned int iInput1 = 0 ;
	unsigned int iInput2 = 0 ;


	cin >> iNum ;


	for ( int i = 0 ; i < iNum ; ++i )
	{
		scanf ( "%u %u" , & iInput1 , & iInput2 ) ;

		vMeetTime.push_back ( std :: make_tuple ( iInput1 , iInput2 , ( unsigned int ) iInput2 - iInput1 ) ) ;
	}

	std :: sort ( vMeetTime.begin () , vMeetTime.end () , bCompare ) ;

	iDoGreedy ( vMeetTime , iNum ) ;

	for ( int i = 0 ; i < iNum ; ++i )
	{
		printf ( "%u %u %u\n" , get < 0 > ( vMeetTime.at ( i ) ) , get < 1 > ( vMeetTime.at ( i ) ) , get < 2 > ( vMeetTime.at ( i ) ) ) ;
	}


	return 0 ;
}

bool bCompare ( const tui & a ,
				const tui & b )
{
	return ( get < 2 > ( a ) < get < 2 > ( b ) ) ;
}

int iDoGreedy ( vector < tui > & vMeetTime , int iNum )
{
	int i = 0 ;
	int * ipMeetTime ;
	int iMax = 0 ;



	iMax = get < 1 > ( vMeetTime.back () ) ;


	while ( i != iNum )
	{

	}
}