#include <vector>
#include <algorithm>

using std :: vector ;

int solution ( vector < int > A , vector < int > B )
{
	int answer = 0 ;
	int iArraySize = A.size () ;
	int * ipAData = A.data () ;
	int * ipBData = B.data () ;



	std :: sort ( A.begin () , A.end () ) ;
	std :: sort ( B.begin () , B.end () , [] ( int a , int b ) { return a > b ; } ) ;

	for ( int i = 0 ; i < iArraySize ; ++i )
	{
		answer += ( * ipAData ++ ) * ( * ipBData ++ ) ;
	}

	return answer ;
}