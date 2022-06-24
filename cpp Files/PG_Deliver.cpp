#include <vector>
#include <algorithm>

using std :: vector ;

int solution ( int N , vector < vector < int > > road , int K )
{
	int idrgPath [ 50 ] [ 50 ] = { 0 , } ;
	bool brgVisit [ 50 ] = { false , } ;
	int iEnd = 0 ;
	int iWeight = 0 ;
	int iAnswer = 1 ;



	std :: fill ( idrgPath [ 0 ] , idrgPath [ 0 ] + 2500 , 1e6 ) ;			// For impossible node, fill with 1e6 > ( 50 * 1e4 )

	for ( int i = 0 ; i < road.size () ; ++ i )				// Initialize
	{
		int * ipTemp = road [ i ].data () ;
		int iStart = ipTemp [ 0 ] - 1 ;
		iEnd = ipTemp [ 1 ] - 1 ;
		iWeight = ipTemp [ 2 ] ;


		idrgPath [ iStart ] [ iEnd ] = std :: min ( idrgPath [ iStart ] [ iEnd ] , iWeight ) ;
		idrgPath [ iEnd ] [ iStart ] = std :: min ( idrgPath [ iEnd ] [ iStart ] , iWeight ) ;
	}

	brgVisit [ 0 ] = true ;

	for ( int i = 0 ; i < 49 ; ++i )									// Need to compute n - 1
	{
		iWeight = 1e6 ;

		for ( int j = 1 ; j < 50 ; ++j )								// Find minimal path
		{
			if ( ( ! brgVisit [ j ] ) && ( idrgPath [ 0 ] [ j ] < iWeight ) )
			{
				iWeight = idrgPath [ 0 ] [ j ] ;
				iEnd = j ; 
			}
		}

		brgVisit [ iEnd ] = true ;
		for ( int j = 1 ; j < 50 ; ++j )								// Update
		{
			idrgPath [ 0 ] [ j ] = std :: min ( idrgPath [ 0 ] [ j ] , idrgPath [ 0 ] [ iEnd ] + idrgPath [ iEnd ] [ j ] ) ;
		}
	}

	for ( int i = 1 ; i < 50 ; ++i )
	{
		if ( idrgPath [ 0 ] [ i ] <= K )
			++ iAnswer ;
	}

	return iAnswer ;
}

int main ()
{
	vector < vector < int > > v1 = { { 1 , 2 , 1 } ,
									 { 2 , 3 , 3 } ,
									 { 5 , 2 , 2 } ,
									 { 1 , 4 , 2 } ,
									 { 5 , 3 , 1 } ,
									 { 5 , 4 , 2 } } ;

	int i = solution ( 5 , v1 , 3 ) ;

	return 0 ;
}