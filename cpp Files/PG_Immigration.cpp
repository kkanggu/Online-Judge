#include <vector>
#include <algorithm>

using std :: vector ;

long long solution ( int n , vector < int > times )
{
	long long answer = 0 ;
	long long llLeft = 1 ;
	long long llRight ;
	
	
	
	llRight = ( * std :: min_element ( times.begin () , times.end () ) ) * ( long long ) n ;
	while ( llLeft <= llRight )
	{
		long long llMid = ( llLeft + llRight ) >> 1 ;
		int * ipTemp = times.data () ;
		int iTableSize = times.size () ;
		long long llTempCount = 0 ;
		
		
		
		for ( int i = 0 ; i < iTableSize ; ++i )
		{
			llTempCount += llMid / ( * ipTemp ++ ) ;
		}
		
		if ( llTempCount < n )
		{
			llLeft = llMid + 1 ;
		}
		else
		{
			llRight = llMid - 1 ;
			answer = llMid ;
		}
	}
	
	return answer ;
}