#include <vector>
#include <algorithm>

using std :: vector ;
using std :: sort ;

int solution ( vector < int > A , vector < int > B )
{
	int answer = 0 ;
	int iHumanSize = A.size () ;
	int iALeftIndex = 0 ;
	int iARightIndex = iHumanSize - 1 ;
	
	
	
	sort ( A.begin () , A.end () ) ;
	sort ( B.begin () , B.end () ) ;
	
	for ( int i = 0 ; i < iHumanSize ; ++i )
	{
		if ( A [ iALeftIndex ] < B [ i ] )
		{
			++ iALeftIndex ;
			++ answer ;
		}
		else
		{
			-- iARightIndex ;
		}
	}
		
	
	return answer ;
}