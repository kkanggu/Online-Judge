#include <vector>
#include <queue>
#include <utility>

using std :: vector ;
using std :: queue ;
using std :: pair ;
using std :: make_pair ;

int solution ( int bridge_length , int weight , vector < int > truck_weights )
{
	int answer = 1 ;
	int iCnt = 0 ;
	int iCurrentWeight = 0 ;
	int iLen = truck_weights.size () ;
	int * ipTemp = truck_weights.data () ;
	int iIndex = 0 ;
	queue < pair < int , int > > qCheck ;			// < weight , start time >



	while ( iCnt < iLen )
	{
		if ( ( ! qCheck.empty () ) && ( bridge_length + qCheck.front ().second == answer ) )
		{
			iCurrentWeight -= qCheck.front ().first ;
			qCheck.pop () ;
			++ iCnt ;
		}

		if ( iCnt == iLen )
			return answer ;

		if ( ( iIndex != iLen ) && ( iCurrentWeight + ipTemp [ iIndex ] <= weight ) )		// If can load the truck to bridge
		{
			qCheck.emplace ( make_pair ( ipTemp [ iIndex ] , answer ) ) ;
			++ answer ;
			iCurrentWeight += ipTemp [ iIndex ++ ] ;

			continue ;
		}

		// If can't load new truck, need to unload the truck
		answer = qCheck.front ().second + bridge_length ;
	}
}

int main ()
{
	vector < int > t = { 7 , 4 , 5 , 6 } ;

	int i = solution ( 2 , 10 , t ) ;

	return 0 ;
}