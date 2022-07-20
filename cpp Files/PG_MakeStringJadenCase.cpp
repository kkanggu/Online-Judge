#include <string>
#include <algorithm>

using std :: string ;

string solution ( string s )
{
	int iStringSize = s.size () ;
	const char * cpString = s.data () ;
	bool bIsFirst = true ;

	
	
	std :: transform ( s.begin () , s.end () , s.begin () , :: tolower ) ;
	
	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		if ( bIsFirst && ' ' != * cpString )
		{
			if ( ( 'a' <= * cpString ) && ( * cpString <= 'z' ) )
				s [ i ] -= 32 ;
			
			bIsFirst = false ;
		}
		else if ( ! bIsFirst && ' ' == * cpString )
			bIsFirst = true ;
		
		++ cpString ;
	}
	
	
	return s ;
}