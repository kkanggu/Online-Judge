#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std :: string ;
using std :: unordered_map ;
using std :: vector ;

string strGetTwoChar ( char c1 , char c2 )			// return right string if c1,c2 are alphabet
{
	string strReturn = "" ;

	if ( ( 0 != isalpha ( c1 ) ) && ( 0 != isalpha ( c2 ) ) )
	{
		c1 = toupper ( c1 ) ;
		c2 = toupper ( c2 ) ;
		strReturn = strReturn + c1 + c2 ;
	}

	return strReturn ;
}

int solution ( string str1 , string str2 )
{
	unordered_map < string , int > umSet1 ;
	unordered_map < string , int > umSet2 ;
	vector < string > vStringList ;
	const char * cpStr1 = str1.data () ;
	const char * cpStr2 = str2.data () ;
	int iLen1 = str1.size () ;
	int iLen2 = str2.size () ;
	int iNumerator = 0 ;
	int iDenominator = 0 ;



	for ( int i = 0 ; i < iLen1 - 1 ; ++i )
	{
		string strTemp = strGetTwoChar ( cpStr1 [ i ] , cpStr1 [ i + 1 ] ) ;
		
		if ( "" != strTemp )
		{
			++ umSet1 [ strTemp ] ;
			vStringList.emplace_back ( strTemp ) ;
		}
	}
	for ( int i = 0 ; i < iLen2 - 1 ; ++i )
	{
		string strTemp = strGetTwoChar ( cpStr2 [ i ] , cpStr2 [ i + 1 ] ) ;
		
		if ( "" != strTemp )
		{
			++ umSet2 [ strTemp ] ;
			vStringList.emplace_back ( strTemp ) ;
		}
	}

	std :: sort ( vStringList.begin () , vStringList.end () ) ;
	vStringList.erase ( std :: unique ( vStringList.begin () , vStringList.end () ) , vStringList.end () ) ;

	for ( int i = 0 ; i < vStringList.size () ; ++i )
	{
		iNumerator += std :: min ( umSet1 [ vStringList [ i ] ] , umSet2 [ vStringList [ i ] ] ) ;
		iDenominator += std :: max ( umSet1 [ vStringList [ i ] ] , umSet2 [ vStringList [ i ] ] ) ;
	}



	if ( 0 == iDenominator )
		return 65536 ;
	return ( long long ) iNumerator * 65536 / iDenominator ;
}

int main ()
{
//	int a = solution ( "FRANCE" , "french" ) ;
	int a = solution ( "aa1+aa2" , "AAAA12" ) ;
}