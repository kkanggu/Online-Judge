#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using std :: string ;
using std :: vector ;
using std :: pair ;
using std :: make_pair ;

int iGetIndexOfString ( string strInput , int iIndex )
{
	int iStringSize = strInput.size () ;
	const char * cpString = strInput.data () ;
	


	if ( 0 == iIndex )		// Find head section, string
	{
		for ( int i = 1 ; i < iStringSize ; ++i )
		{
			if ( ( '0' <= cpString [ i ] ) && ( cpString [ i ] <= '9' ) )
				return i - 1 ;
		}

		return iStringSize ;
	}
	else					// Find number section, number
	{
		for ( int i = iIndex + 1 ; ( i < iIndex + 5 ) && ( i < iStringSize ) ; ++i )
		{
			if ( ( cpString [ i ] < '0' ) || ( '9' < cpString [ i ] ) )
				return i - 1 ;
		}

		return ( iIndex + 4 < iStringSize ) ? iIndex + 4 : iStringSize - 1 ;
	}
}

bool bCompare ( pair < pair < string , int > , string > a , pair < pair < string , int > , string > b )
{
	if ( a.first.first < b.first.first )
		return true ;
	else if ( a.first.first > b.first.first )
		return false ;

	return a.first.second < b.first.second ;
}

vector < string > solution ( vector < string > files )
{
	int iFileSize = files.size () ;
	vector < string > answer ( iFileSize ) ;
	vector < pair < pair < string , int > , string > > vFileInfo ;		// Head , Number , Index



	for ( int i = 0 ; i < iFileSize ; ++i )
	{
		int iHeadEndIndex = iGetIndexOfString ( files [ i ] , 0 ) ;
		int iNumberEndIndex = iGetIndexOfString ( files [ i ] , iHeadEndIndex + 1 ) ;
		string strHead = files [ i ].substr ( 0 , iHeadEndIndex + 1 ) ;
		std :: transform ( strHead.begin () , strHead.end () , strHead.begin () , :: tolower ) ;

		vFileInfo.emplace_back ( make_pair ( make_pair ( strHead , std :: stoi ( files [ i ].substr ( iHeadEndIndex + 1 , iNumberEndIndex - iHeadEndIndex ) ) ) , files [ i ] ) ) ;
	}

	std :: stable_sort ( vFileInfo.begin () , vFileInfo.end () , bCompare ) ;

	for ( int i = 0 ; i < iFileSize ; ++i )
	{
		answer [ i ] = vFileInfo [ i ].second ;
	}

	return answer ;
}

int main ()
{
	vector < string > v = solution ( {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"} ) ;
}