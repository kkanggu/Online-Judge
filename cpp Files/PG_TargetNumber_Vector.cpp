#include <vector>
#include <utility>

using std :: vector ;
using std :: pair ;
using std :: make_pair ;

int solution ( vector < int > numbers , int target )
{
	int answer = 0 ;
	vector < pair < int , int > > vCurrent ;
	vector < pair < int , int > > vNext ;
	int * ipNumber = numbers.data () ;
	int iNumberSize = numbers.size () ;
	vector < pair < int , int > > * vpCurrent = & vCurrent ;
	vector < pair < int , int > > * vpNext = & vNext ;



	vCurrent.emplace_back ( make_pair ( * ipNumber , 1 ) ) ;
	vCurrent.emplace_back ( make_pair ( * ipNumber * -1 , 1 ) ) ;

	for ( int i = 1 ; i < iNumberSize ; ++i )
	{
		int iNum = * ++ ipNumber ;
		int iCurrentSize = ( * vpCurrent ).size () ;
		
		for ( int j = 0 ; j < iCurrentSize ; ++j )
		{
			pair < int , int > pTemp = ( * vpCurrent ) [ j ] ;
			( * vpNext ).emplace_back ( make_pair ( pTemp.first + iNum , pTemp.second ) ) ;
			( * vpNext ).emplace_back ( make_pair ( pTemp.first - iNum , pTemp.second ) ) ;
		}

		if ( 0 == i % 2 )			// vpCurrent -> vNext
		{
			vNext.clear () ;
			vpCurrent = & vCurrent ;
			vpNext = & vNext ;
		}
		else						// vpCurrent -> vCurrent
		{
			vCurrent.clear () ;
			vpCurrent = & vNext ;
			vpNext = & vCurrent ;
		}
	}

	iNumberSize = ( *vpCurrent ).size () ;
	for ( int i = 0 ; i < iNumberSize ; ++i )
	{
		pair < int , int > pTemp = ( * vpCurrent ) [ i ] ;

		if ( target == pTemp.first )
		{
			answer += pTemp.second ;
		}
	}


	return answer ;
}