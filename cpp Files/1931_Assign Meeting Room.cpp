#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;
using std :: vector ;
using std :: pair ;

typedef pair < unsigned int , unsigned int > uiPair ;

bool bCompare ( const uiPair & a ,
				const uiPair & b ) ;

int iDoGreedy ( vector < uiPair > & vMeetTime ) ;

int main ()
{
	int iNum = 0 ;
	int iValue = 0 ;
	vector < uiPair > vMeetTime ;
	unsigned int iInput1 = 0 ;
	unsigned int iInput2 = 0 ;


	cin >> iNum ;


	for ( int i = 0 ; i < iNum ; ++i )
	{
		scanf ( "%u %u" , & iInput1 , & iInput2 ) ;

		vMeetTime.push_back ( std :: make_pair ( iInput1 , iInput2 ) ) ;
	}

	std :: sort ( vMeetTime.begin () , vMeetTime.end () , bCompare ) ;

	cout << iDoGreedy ( vMeetTime ) ;


	return 0 ;
}

bool bCompare ( const uiPair & a ,
				const uiPair & b )
{
	if ( a.second < b.second )
	{
		return true ;
	}
	else if ( ( a.second == b.second ) && ( a.first < b.first ) )
	{
		return true ;
	}
	else
	{
		return false ;
	}
}

int iDoGreedy ( vector < uiPair > & vMeetTime )
{
	int iCnt = 0 ;
	unsigned int uiEndTime = 0 ;



	for ( vector < uiPair > :: iterator iter = vMeetTime.begin () ; iter != vMeetTime.end () ; ++ iter )
	{
		if ( ( uiEndTime <= iter -> second ) && ( uiEndTime <= iter -> first ) )
		{
			uiEndTime = iter -> second ;
			++ iCnt ;
		}
	}


	return iCnt ;
}