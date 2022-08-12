#include <vector>

using std :: vector ;

int solution ( vector < int > a )
{
	int answer = 2 ;
	int iSize = a.size () ;
	vector < int > vLeftMin ( iSize , 1000000000 ) ;
	vector < int > vRightMin ( iSize , 1000000000 ) ;
	int * ipBallon = a.data () ;
	int iTemp = ipBallon [ 0 ] ;
	
	

	if ( iSize <= 2 )
		return iSize ;
	
	for ( int i = 1 ; i < iSize ; ++i )				// Find left min number
	{
		if ( iTemp > ipBallon [ i - 1 ] )
			iTemp = ipBallon [ i - 1 ] ;
		vLeftMin [ i ] = iTemp ;
	}
	iTemp = ipBallon [ iSize - 1 ] ;
	for ( int i = iSize - 2 ; i >= 0 ; --i )		// Find right min number
	{
		if ( ipBallon [ i + 1 ] < iTemp )
			iTemp = ipBallon [ i + 1 ] ;
		vRightMin [ i ] = iTemp ;
	}
	
	for ( int i = 1 ; i < iSize - 1 ; ++i )
	{
		if ( ( vLeftMin [ i ] < ipBallon [ i ] ) && ( vRightMin [ i ] < ipBallon [ i ] ) )
			continue ;
		
		++ answer ;
	}
	
	
	return answer ;
}