#include <vector>
#include <algorithm>

using std :: vector ;
using std :: min ;

bool bCanDeliver ( long long llMid , long long a , long long b , vector < int > & g , vector < int > & s , vector < int > & w , vector < int > & t )
{
	int iSize = g.size () ;
	long long llTotalDeliver = a + b ;
	
	
	
	for ( int i = 0 ; i < iSize ; ++i )
	{
		if ( llMid < t [ i ] )
			continue ;
		
		long long llMaxDeliver = w [ i ] + w [ i ] * ( ( llMid - t [ i ] ) / ( t [ i ] << 1 ) ) ;
		
		
		if ( 0 != g [ i ] )
		{
			a -= min ( ( long long ) g [ i ] , llMaxDeliver ) ;
		}
		if ( 0 != s [ i ] )
		{
			b -= min ( ( long long ) s [ i ] , llMaxDeliver ) ;
		}
		
		llTotalDeliver -= min ( llMaxDeliver , ( long long ) g [ i ] + s [ i ] ) ;
	}
	
	
	if ( ( a <= 0 ) && ( b <= 0 ) && ( llTotalDeliver <= 0 ) )
		return true ;
	return false ;
}

long long solution ( int a , int b , vector < int > g , vector < int > s , vector < int > w , vector < int > t )
{
	long long answer = -1 ;
	long long llLeft = 0 ;
	long long llRight = 1e16 ;
	long long llMid = ( llLeft + llRight ) >> 1 ;
	
	
	
	while ( llLeft <= llRight )
	{
		if ( bCanDeliver ( llMid , a , b , g , s , w , t ) )
		{
			answer = llMid ;
			llRight = llMid - 1 ;
		}
		else
		{
			llLeft = llMid + 1 ;
		}
		
		llMid = ( llLeft + llRight ) >> 1 ;
	}
	
	
	return answer ;
}