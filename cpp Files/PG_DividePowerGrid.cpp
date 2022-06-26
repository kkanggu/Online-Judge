#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using std :: vector ;
using std :: queue ;

int solution ( int n , vector < vector < int > > wires )
{
	int answer = 100 ;
	vector < int > * vpWire = wires.data () ;
	queue < int > qBFS ;
	vector < bool > vVisit ;				// Specialized version of vector
	vVisit.resize ( n ) ;
	int iCnt = 0 ;
	int iIndex = 0 ;



	for ( int i = 0 ; i < n - 1 ; ++i )		// n tower, n-1 wires
	{
		std :: fill ( vVisit.begin () , vVisit.end () , false ) ;
		iCnt = 1 ;
		iIndex = 0 ;
		vVisit [ 0 ] = true ;
		qBFS.emplace ( 0 ) ;

		while ( ! qBFS.empty () )
		{
			iIndex = qBFS.front () ;
			qBFS.pop () ;

			for ( int j = 0 ; j < n - 1 ; ++j )
			{
				if ( i == j )			// Cut this wire
					continue ;

				int iNode1 = vpWire [ j ] [ 0 ] - 1 ;
				int iNode2 = vpWire [ j ] [ 1 ] - 1 ;

				if ( iNode2 == iIndex )		// If iNode2 is iIndex, then swap with 1
				{
					iNode1 += iNode2 ;
					iNode2 = iNode1 - iNode2 ;
					iNode1 -= iNode2 ;
				}

				if ( ( iNode1 == iIndex ) && ( ! vVisit [ iNode2 ] ) )		// Find new node to check
				{
					vVisit [ iNode2 ] = true ;
					qBFS.emplace ( iNode2 ) ;

					++ iCnt ;
				}
			}
		}

		answer = std :: min ( answer , abs ( n - 2 * iCnt ) ) ;		// iCnt , n - iCnt. Latter - former = n - 2 * iCnt
	}


	return answer ;
}

int main ()
{
	vector < vector < int > > wire = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}} ;

	int i = solution ( 9 , wire ) ;
}