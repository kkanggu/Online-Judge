#include <iostream>
#include <string>
#include <stack>

using std :: string ;
using std :: stack ;

int solution ( string s )
{
	int i = 0 ;
	const char * cpTemp = s.data () ;
	int iLen = s.size () ;
	stack < int > sPile ;
	bool bEmplace = true ;



	if ( 1 == iLen % 2 )							// Odd number, can't remove all
		return 0 ;


	while ( i != iLen )
	{
		if ( sPile.empty () || bEmplace )
			sPile.emplace ( cpTemp [ i ++ ] ) ;

		if ( i == iLen )
			return 0 ;

		if ( sPile.top () == cpTemp [ i ] )			// Same, pop
		{
			sPile.pop () ;

			++i ;
			bEmplace = false ;

			continue ;
		}

		bEmplace = true ;
	}

	if ( ( i == iLen ) && ( sPile.empty () ) )
		return 1 ;


	return 0 ;
}

int main ()
{
	string s = "baabaa" ;
//	string s = "abcda" ;

	int i = solution ( s ) ;

	return 0 ;
}