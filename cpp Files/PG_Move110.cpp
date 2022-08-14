#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using std :: vector ;
using std :: string ;
using std :: stack ;

string strGetMinimumString ( string strTarget )
{
	int iStringSize = strTarget.size () ;
	int iCount = 0 ;
	int iConditionCount = 0 ;
	stack < int > stackCheck ;
	string strReturn ;
	
	
	
	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		stackCheck.emplace ( strTarget [ i ] ) ;

		if ( ( iConditionCount <= 1 ) && ( '1' == stackCheck.top () ) )
			++ iConditionCount ;
		else if ( ( 2 == iConditionCount ) && ( '0' == stackCheck.top () ) )
		{
			stackCheck.pop () ;
			stackCheck.pop () ;
			stackCheck.pop () ;
			
			char cTemp = '\0' ;
			iConditionCount = 0 ;
			++ iCount ;
			
			if ( ! stackCheck.empty () )
				cTemp = stackCheck.top () ;
			
			if ( '1' == cTemp )
			{
				stackCheck.pop () ;
				iConditionCount = 1 ;
				
				
				if ( ( ! stackCheck.empty () ) && ( '1' == stackCheck.top () ) )
				{
					iConditionCount = 2 ;
				}
				
				stackCheck.emplace ( cTemp ) ;
				
				continue ;
			}
		}
		else if ( '0' == stackCheck.top () )
		{
			iConditionCount = 0 ;
		}
	}
	
	while ( ! stackCheck.empty () )
	{
		if ( ( 0 != iCount ) && ( '0' == stackCheck.top () ) )
		{
			for ( int i = 0 ; i < iCount ; ++i )
			{
				strReturn += "011" ;
			}

			iCount = 0 ;
		}
		
		strReturn += stackCheck.top () ;
		stackCheck.pop () ;
	}
	if ( 0 != iCount )
	{
		for ( int i = 0 ; i < iCount ; ++i )
		{
			strReturn += "011" ;
		}
	}
	
	std :: reverse ( strReturn.begin () , strReturn.end () ) ;
	
	
	return strReturn ;
}

vector < string > solution ( vector < string > s )
{
	vector < string > answer ;
	int iStringSize = s.size () ;
	
	
	
	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		answer.emplace_back ( strGetMinimumString ( s [ i ] ) ) ;
	}
	
	return answer ;
}

int main ()
{
	vector < string > s = solution ( { "1100111011101001" }) ;
}