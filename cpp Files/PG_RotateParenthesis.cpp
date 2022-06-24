#include <string>
#include <stack>

using std :: string ;
using std :: stack ;

bool bIsMatched ( char ch1 , char ch2 )
{
	if ( ( ( '(' == ch1 ) && ( ')' == ch2 ) ) ||
		 ( ( '[' == ch1 ) && ( ']' == ch2 ) ) ||
		 ( ( '{' == ch1 ) && ( '}' == ch2 ) ) )
		return true ;

	return false ;
}

bool bIsCorrectString ( const char * cpTemp , int iStart , int iLen )
{
	int iIndex = ( iStart + 1 ) % iLen ;
	stack < char > sTemp ;
	


	sTemp.emplace ( cpTemp [ iStart ] ) ;

	while ( iIndex != iStart )									// Until iIndex reach iStart
	{
		if ( sTemp.empty () )
		{
			sTemp.emplace ( cpTemp [ iIndex ] ) ;
			iIndex = ( iIndex + 1 ) % iLen ;
		}

		if ( iIndex == iStart )									// If same, stack is not empty
			return false ;

		if ( bIsMatched ( sTemp.top () , cpTemp [ iIndex ] ) )
		{
			sTemp.pop () ;
			iIndex = ( iIndex + 1 ) % iLen ;

			continue ;
		}

		sTemp.emplace ( cpTemp [ iIndex ] ) ;
		iIndex = ( iIndex + 1 ) % iLen ;
	}

	if ( sTemp.empty () )
		return true ;

	return false ;
}

int solution ( string s )
{
	int iAnswer = 0 ;
	int iLen = s.size () ;
	const char * cpTemp = s.data () ;


	for ( int i = 0 ; i < iLen ; ++i )
	{
		if ( bIsCorrectString ( cpTemp , i , iLen ) )
			++ iAnswer ;
	}


	return iAnswer ;
}