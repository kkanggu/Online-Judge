#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using std :: string ;
using std :: vector ;

bool bIsPossible ( char ch , int iCurGap , int iGivenGap )
{
	if ( ( ( '=' == ch ) && ( iCurGap == iGivenGap ) ) ||
		( ( '>' == ch ) && ( iCurGap > iGivenGap ) ) ||
		( ( '<' == ch ) && ( iCurGap < iGivenGap ) ) )
	{
		return true ;
	}

	return false ;
}

int solution(int n, vector<string> data)
{
    int answer = 0 ;
	string * strTemp = data.data () ;			// Without this, about maximum 4M access at single string
	string strPerm = "ACFJMNRT" ;
	int iLen = data.size () ;					// Without this, about 40k call
	bool bFail = false ;



	do
	{
		bFail = false ;
		for ( int i = 0 ; i < iLen ; ++i )
		{
			int iCurrentGap = abs ( ( int ) strPerm.find ( strTemp [ i ] [ 0 ] ) - ( int ) strPerm.find ( strTemp [ i ] [ 2 ] ) ) - 1 ;
			int iGivenGap = strTemp [ i ] [ 4 ] - '0' ;
			char cSign = strTemp [ i ] [ 3 ] ;

			if ( ! bIsPossible ( cSign , iCurrentGap , iGivenGap ) )		// If can't satisfy condition, break
			{
				bFail = true ;

				break ;
			}
		}

		if ( ! bFail )
			++ answer ;

	} while ( std :: next_permutation ( strPerm.begin () , strPerm.end () ) ) ;



    return answer;
}

int main ()
{
//	vector < string > data = { "N~F=0" , "R~T>2" } ;
//	vector < string > data = { "N~F=0" , "R~T>2" , "C~F<5" , "T~A=2" } ;		// 556
	vector < string > data = { "N~F=0" , "R~T>2" , "C~F<5" , "T~A=2" , "M~J<1" } ;		// 192
	vector < string > data2 = { "M~C<2" , "C~M>1" } ;

	int iAnswer = solution ( 2 , data ) ;			// 2184
//	int iAnswer = solution ( 2 , data2 ) ;

	printf ( "%d" , iAnswer ) ;

    return 0 ;
}