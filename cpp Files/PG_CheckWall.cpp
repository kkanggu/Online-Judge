#include <vector>
#include <algorithm>

using std :: vector ;

int solution ( int n , vector < int > weak , vector < int > dist )
{
	int answer = 10 ;
	int iWeakSize = weak.size () ;
	int iDistSize = dist.size () ;
	
	
	
	for ( int i = 0 ; i < iWeakSize ; ++i )		// Expand to not check circle
	{
		weak.emplace_back ( weak [ i ] + n ) ;
	}
	
	std :: sort ( dist.begin () , dist.end () , [] ( int & a , int & b ) { return a > b ; } ) ;
	
	do
	{
		for ( int i = 0 ; i < iWeakSize ; ++i )
		{
			int iStart = weak [ i ] ;
			int iEnd = weak [ i - 1 + iWeakSize ] ;
			
			for ( int j = 0 ; j < iDistSize ; ++j )
			{
				if ( answer <= j + 1 )			// Current is not best
					break ;
				
				iStart += dist [ j ] ;
				
				if ( iStart >= iEnd )			// If exceed, then check all the walls
				{
					answer = std :: min ( answer , j + 1 ) ;
					
					break ;
				}
				
				
				for ( int k = 0 ; k < iWeakSize ; ++k )
				{
					if ( iStart < weak [ k ] )
					{
						iStart = weak [ k ] ;
						
						break ;
					}
				}
			}
		}
	}
	while ( std :: prev_permutation ( dist.begin () , dist.end () ) ) ;

	
	return 10 != answer ? answer : -1 ;
}