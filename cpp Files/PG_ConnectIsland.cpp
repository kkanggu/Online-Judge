#include <vector>
#include <algorithm>

using std :: vector ;

int iGetParent ( vector < int > & vNodeParent , int iIndex )
{
	while ( -1 != vNodeParent [ iIndex ] )
	{
		iIndex = vNodeParent [ iIndex ] ;
	}
	
	
	return iIndex ;
}

int solution ( int n , vector < vector < int > > costs )
{
	int answer = 0 ;
	int iCostSize = costs.size () ;
	vector < int > vNodeParent ( n , -1 ) ;
	int iCount = 0 ;
	
	
	
	for ( int i = 0 ; i < iCostSize ; ++i )					// Sort each vector
	{
		std :: sort ( costs.begin () , costs.end () , [] ( vector < int > & v1 , vector < int > & v2 ) { return v1 [ 2 ] < v2 [ 2 ] ; } ) ;
	}
	
	for ( int i = 0 ; ( iCount < n - 1 ) && ( i < iCostSize ) ; ++i )		// Kruskal
	{
		int iStart = iGetParent ( vNodeParent , costs [ i ] [ 0 ] ) ;
		int iEnd = iGetParent ( vNodeParent , costs [ i ] [ 1 ] ) ;
		int iCost = costs [ i ] [ 2 ] ;
		
		if ( iStart > iEnd )				// Swap
		{
			iStart += iEnd ;
			iEnd = iStart - iEnd ;
			iStart -= iEnd ;
		}
		
		if ( iStart != iEnd )
		{
			vNodeParent [ iEnd ] = iStart ;
			answer += iCost ;
			++ iCount ;
		}
	}
	
	
	return answer ;
}