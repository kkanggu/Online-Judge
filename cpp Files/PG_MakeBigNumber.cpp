#include <string>

using std :: string ;

string solution ( string number , int k )
{
	string answer = "" ;
	int iCnt = 0 ;
	int iIndex = 0 ;
	int iTargetIndex = 0 ;
	int iLen = number.size () ;
	const char * cpTemp = number.data () ;



	while ( ( iCnt < k ) && ( iIndex < iLen ) )
	{
		if ( '9' == cpTemp [ iIndex ] )					// Biggest, don't check
		{
			answer += cpTemp [ iIndex ++ ] ;
			continue ;
		}

		iTargetIndex = iIndex ;
		for ( int i = iIndex + 1 ; ( i <= iIndex + k - iCnt ) && ( i < iLen ) ; ++i )
		{
			if ( cpTemp [ iTargetIndex ] < cpTemp [ i ] )
			{
				iTargetIndex = i ;

				if ( '9' == cpTemp [ iTargetIndex ] )	// If find 9, then don't need to check other numbers
					break ;
			}
		}

		if ( iIndex != iTargetIndex )					// erase iIndex to iTargetIndex - 1
		{
			iCnt += iTargetIndex - iIndex ;
			iIndex = iTargetIndex ;

			answer += cpTemp [ iIndex ++ ] ;

			continue ;
		}

		// iIndex == iTargetIndex
		answer += cpTemp [ iIndex ++ ] ;
	}

	if ( iCnt < k )										// If append too many number, then erase the rest
		answer = answer.substr ( 0 , iLen - k ) ;
	else												// Erased, so append the rest
	{
		for ( int i = iIndex ; i < iLen ; ++i )
		{
			answer += cpTemp [ i ] ;
		}
	}

	return answer ;
}

int main ()
{
	string str = solution ( "1924" , 2 ) ;
//	string str = solution ( "1231234" , 3 ) ;
}