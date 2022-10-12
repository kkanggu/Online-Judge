#include <vector>

using std :: vector ;

vector < int > solution ( int n , int s )
{
	vector < int > answer ;
	
	
	
	if ( s < n )			// Can't make set
		return { -1 } ;
	
	
	int iLow = s / n ;
	int iLowCount = n - ( s % n ) ;
	
	for ( int i = 0 ; i < iLowCount ; ++i )
		answer.emplace_back ( iLow ) ;
	for ( int i = iLowCount ; i < n ; ++i )
		answer.emplace_back ( iLow + 1 ) ;
	
	
	return answer ;
}