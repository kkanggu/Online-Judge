#include <string>
#include <sstream>
#include <limits.h>

using std :: string ;

string solution ( string s )
{
	string answer = "" ;
	std :: stringstream ss ( s ) ;
	int iStringSize = s.size () ;
	const char * cpString = s.data () ;
	int iMax = INT_MIN ;
	int iMin = INT_MAX ;
	int iTemp = 0 ;
	
	
	
	while ( ss >> iTemp )
	{
		if ( iMax < iTemp )
			iMax = iTemp ;
		if ( iTemp < iMin )
			iMin = iTemp ;
	}
	
	answer += std :: to_string ( iMin ) ;
	answer += " " ;
	answer += std :: to_string ( iMax ) ;
	
	
	return answer ;
}