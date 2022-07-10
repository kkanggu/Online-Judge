#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std :: string ;
using std :: vector ;
using std :: unordered_map ;

vector < string > solution ( vector < string > orders , vector < int > course )
{
	vector < string > answer ;
	unordered_map < string , int > umCheck ;
	unordered_map < string , int > umCnt ;
	int iOrderSize = orders.size () ;
	int iCourseSize = course.size () ;
	vector < int > vMaxOrder ( 11 , 0 ) ;



	for ( int i = 0 ; i < iOrderSize ; ++i )
	{
		std :: sort ( orders [ i ].begin () , orders [ i ].end () ) ;
	}
	for ( int i = 0 ; i < iOrderSize ; ++i )
	{
		string strOrder = orders [ i ] ;
		int iStrSize = strOrder.size () ;

		for ( int j = 0 ; j < iCourseSize ; ++j )
		{
			vector < bool > vPermutation ( iStrSize , true ) ;
			std :: fill ( vPermutation.begin () , vPermutation.begin () + course [ j ] , false ) ;

			do
			{
				string strTemp = "" ;

				for ( int i = 0 ; i < iStrSize ; ++i )
				{
					if ( ! vPermutation [ i ] )
						strTemp += strOrder [ i ] ;
				}

				if ( 0 == umCheck [ strTemp ] )
				{
					++ umCheck [ strTemp ] ;
					++ umCnt [ strTemp ] ;
					vMaxOrder [ course [ j ] ] = std :: max ( vMaxOrder [ course [ j ] ] , umCnt [ strTemp ] ) ;
				}
			} while ( std :: next_permutation ( vPermutation.begin () , vPermutation.end () ) ) ;
		}

		umCheck.clear () ;
	}
	for ( auto iter = umCnt.begin () ; iter != umCnt.end () ; ++ iter )
	{
		int iStrSize = iter -> first.size () ;

		if ( ( 1 < vMaxOrder [ iStrSize ] ) && ( umCnt [ iter -> first ] == vMaxOrder [ iStrSize ] ) )
			answer.emplace_back ( iter -> first ) ;
	}

	std :: sort ( answer.begin () , answer.end () ) ;

	return answer ;
}

int main ()
{
	vector < string > v = solution ( {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"} , { 2 , 3 , 4 } ) ;
}