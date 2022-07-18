#include <vector>
#include <unordered_map>

using std :: vector ;
using std :: unordered_map ;

int solution ( vector < int > numbers , int target )
{
	int answer = 0 ;
	unordered_map < int , int > umCurrent ;
	unordered_map < int , int > umNext ;
	int * ipNumber = numbers.data () ;
	int iNumberSize = numbers.size () ;
	unordered_map < int , int > * umpCurrent = & umCurrent ;
	unordered_map < int , int > * umpNext = & umNext ;



	++ umCurrent [ * ipNumber ] ;
	++ umCurrent [ * ipNumber * -1 ] ;

	for ( int i = 1 ; i < iNumberSize ; ++i )
	{
		int iNum = * ++ ipNumber ;
		
		for ( auto iter = ( * umpCurrent ).begin () ; iter != ( * umpCurrent ).end () ; ++ iter )
		{
			( * umpNext ) [ iter -> first + iNum ] += iter -> second ;
			( * umpNext ) [ iter -> first - iNum ] += iter -> second ;
		}

		if ( 0 == i % 2 )			// umpCurrent -> umNext
		{
			umNext.clear () ;
			umpCurrent = & umCurrent ;
			umpNext = & umNext ;
		}
		else						// umpCurrent -> umCurrent
		{
			umCurrent.clear () ;
			umpCurrent = & umNext ;
			umpNext = & umCurrent ;
		}
	}


	return ( * umpCurrent ) [ target ] ;
}