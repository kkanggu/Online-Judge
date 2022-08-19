#include <vector>

using std :: vector ;

int solution ( int n , vector < int > stations , int w )
{
	int answer = 0 ;
	int iElectricityEndIndex = 1 ;
	int iStationSize = stations.size () ;
	
	
	
	for ( int i = 0 ; i < iStationSize ; ++i  )
	{
		if ( iElectricityEndIndex < stations [ i ] - w )
		{
			int iGap = stations [ i ] - w - iElectricityEndIndex ;
			int iQuotient = ( iGap - 1 ) / ( ( w << 1 ) + 1 ) + 1 ;
			answer += iQuotient ;
		}
	
		iElectricityEndIndex = stations [ i ] + w + 1 ;
	}
	
	if ( iElectricityEndIndex <= n )
	{
		answer += ( n - iElectricityEndIndex ) / ( ( w << 1 ) + 1 ) + 1 ;
	}
	

	return answer ;
}