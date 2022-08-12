#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using std :: vector ;
using std :: queue ;
using std :: pair ;
using std :: make_pair ;
using std :: min ;

int solution ( vector < vector < int > > routes )
{
	int answer = 0 ;
	queue < pair < int , int > > q1 ;
	queue < pair < int , int > > q2 ;
	queue < pair < int , int > > * qpCurrent = & q1 ;
	queue < pair < int , int > > * qpNext = & q2 ;
	int iCurrentMinEnd = 30000 ;
	int iNextMinEnd ;
	int iRouteSize = routes.size () ;
	
	
	
	for ( int i = 0 ; i < iRouteSize ; ++i )
	{
		int * ipTemp = routes [ i ].data () ;
		
		( * qpCurrent ).emplace ( make_pair ( ipTemp [ 0 ] , ipTemp [ 1 ] ) ) ;
		iCurrentMinEnd = min ( iCurrentMinEnd , ipTemp [ 1 ] ) ;
	}
	while ( ! ( * qpCurrent ).empty () )
	{
		iNextMinEnd = 30000 ;
		
		while ( ! ( * qpCurrent ).empty () )
		{
			pair < int , int > pTemp = ( * qpCurrent ).front () ;
			( * qpCurrent ).pop () ;

			if ( ( iCurrentMinEnd < pTemp.first ) || ( pTemp.second < iCurrentMinEnd ) )
			{
				( * qpNext ).emplace ( pTemp ) ;
				iNextMinEnd = min ( iNextMinEnd , pTemp.second ) ;
			}
		}
		
		++ answer ;
		if ( q1.empty () )		// Set qpCurrent : q2 , qpNext : q1
		{
			qpCurrent = & q2 ;
			qpNext = & q1 ;
		}
		else					// Set qpCurrent : q2 , qpNext : q1
		{
			qpCurrent = & q1 ;
			qpNext = & q2 ;
		}
		
		iCurrentMinEnd = iNextMinEnd ;
	}
	
	
	return answer ;
}