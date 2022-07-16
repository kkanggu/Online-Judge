#include <string>
#include <vector>
#include <unordered_map>

using std :: vector ;
using std :: string ;
using std :: unordered_map ;

vector < int > solution ( string s )
{
	int iStringSize = s.size () ;
	vector < int > answer ;
	unordered_map < int , int > umTupleCount ;
	const char * cpString = s.data () ;
	int iFirstNumberShowIndex = -1 ;



	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		if ( ( -1 == iFirstNumberShowIndex ) && ( '0' <= cpString [ i ] ) && ( cpString [ i ] <= '9' ) )			// Find number start
		{
			iFirstNumberShowIndex = i ;
		}
		else if ( ( -1 != iFirstNumberShowIndex ) && ( ( cpString [ i ] < '0' ) || ( '9' < cpString [ i ] ) ) )		// Find number end
		{
			++ umTupleCount [ stoi ( s.substr ( iFirstNumberShowIndex , i - iFirstNumberShowIndex ) ) ] ;
			iFirstNumberShowIndex = -1 ;
		}
	}

	int iTupleSize = umTupleCount.size () ;
	answer.resize ( iTupleSize , 0 ) ;

	for ( auto iter = umTupleCount.begin () ; iter != umTupleCount.end () ; ++ iter )								// Update answer vector
	{
		answer [ iTupleSize - iter -> second ] = iter -> first ;
	}


	return answer ;
}

int main ()
{
	vector < int > v = solution ( "{{2},{2,1},{2,1,3},{2,1,3,4}}" ) ;
}