#include <string>

using std :: string ;

bool solution ( string s )
{
	int iStringSize = s.size () ;
	const char * cpStirng = s.data () ;
	int iLeftParenthesisCount = 0 ;

	

	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		if ( '(' == * cpStirng ++ )
			++ iLeftParenthesisCount ;
		else
			-- iLeftParenthesisCount ;
		

		if ( iLeftParenthesisCount < 0 )
		{
			return false ;
		}		
	}


	return 0 == iLeftParenthesisCount ;
}