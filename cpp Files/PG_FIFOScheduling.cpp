#include <vector>
#include <queue>

using std :: vector ;
using std :: queue ;

int solution ( int n , vector < int > cores )
{
	int answer = 0 ;
	int iCoreSize = cores.size () ;
	int iLeft = 1 ;
	int iRight = n * cores [ 0 ] ;
	int iMid = ( iLeft + iRight ) >> 1 ;
	int iTime = 0 ;
	queue < int > qCore ;
	
	
	
	while ( iLeft <= iRight )
	{
		long long llTemp = 0 ;
		
		for ( int i = 0 ; i < iCoreSize ; ++i )
		{
			llTemp += iMid / cores [ i ] + 1 ;
		}
		
		if ( n <= llTemp )
		{
			iTime = iMid ;
			iRight = iMid - 1 ;
		}
		else
		{
			iLeft = iMid + 1 ;
		}
		
		iMid = ( iLeft + iRight ) >> 1 ;
	}
	
	for ( int i = 0 ; i < iCoreSize ; ++i )
	{
		int iInsertTime = iTime - iTime % cores [ i ] ;		// Remove remainder

		if ( iTime == iInsertTime )
		{
			qCore.emplace ( i ) ;			// Insert time (Upper 14 bits) | Index (Lower 14 bits)
		}

		n -= ( iTime - 1 ) / cores [ i ] + 1 ;
	}
	while ( 0 != n )
	{
		answer = qCore.front () ;
		qCore.pop () ;
		--n ;
	}
	
	
	return answer + 1 ;
}