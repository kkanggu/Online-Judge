#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

using std :: vector ;
using std :: priority_queue ;

int solution(vector<int> scoville, int K)
{
    int answer = 0 ;
	int * ipTemp = scoville.data () ;
	priority_queue < int , vector < int > , std :: greater < int > > pq ;



	for ( int i = 0 ; i < scoville.size () ; ++i )
	{
		pq.emplace ( ipTemp [ i ] ) ;
	}

	if ( pq.empty () )
		return answer ;

	while ( ( K > pq.top () ) && ( 2 <= pq.size () ) )
	{
		int iTemp1 = pq.top () ;
		pq.pop () ;
		int iTemp2 = pq.top () ;
		pq.pop () ;

		pq.emplace ( iTemp1 + iTemp2 * 2 ) ;
		
		++ answer ;
	}

	if ( ( 1 == pq.size () ) && ( pq.top () < K ) )
		return -1 ;



    return answer;
}

int main ()
{
	vector < int > scoville = { 1 , 2 , 3 , 9 , 10 , 12 } ;
	int K = 7 ;

	printf ( "%d" , solution ( scoville , K ) ) ;
}