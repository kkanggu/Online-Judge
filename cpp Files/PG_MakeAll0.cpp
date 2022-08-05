#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <utility>

using std :: string ;
using std :: vector ;
using std :: unordered_map ;
using std :: pair ;
using std :: make_pair ;

pair < long long , int > iEraseSingleLine ( vector < unordered_map < int , int > > & vGraph ,
										long long * llpNodeWeight , int iTarget )		// If a is the only node that connected to b, then erase 'a to b' line
{																						// Return ( process count , erased node count )
	long long llProcessCount = 0 ;
	int iEraseCount = 0;
	
	auto iter = vGraph [ iTarget ].begin () ;
				
	llProcessCount += labs ( llpNodeWeight [ iTarget ] ) ;
	++ iEraseCount ;
	
	llpNodeWeight [ iter -> first ] += llpNodeWeight [ iTarget ] ;
	llpNodeWeight [ iTarget ] = 0 ;

	vGraph [ iTarget ].clear () ;
	vGraph [ iter -> first ].erase ( iTarget ) ;

	
	if ( 1 == vGraph [ iter -> first ].size () )			// If transfered node has only one line, then process recursively
	{
		pair < long long , int > pTemp = iEraseSingleLine ( vGraph , llpNodeWeight , iter -> first ) ;
		
		llProcessCount += pTemp.first ;
		iEraseCount += pTemp.second ;
	}
	
	
	return { llProcessCount , iEraseCount } ;
}

long long solution ( vector < int > a , vector < vector < int > > edges )
{
	long long answer = 0 ;
	int iNodeSize = a.size () ;
	vector < unordered_map < int , int > > vGraph ( iNodeSize ) ;
	int iCnt = 0 ;
	int * ipNodeWeight = a.data () ;
	vector < long long > vWeight ( iNodeSize , 0 ) ;
	long long * llpNodeWeight = vWeight.data () ;
	
	
	
	for ( int i = 0 ; i < iNodeSize - 1 ; ++i )
	{
		int * ipTemp = edges [ i ].data () ;
		int iStart = * ipTemp ++ ;
		int iEnd = * ipTemp ;
		
		++ vGraph [ iStart ] [ iEnd ] ;
		++ vGraph [ iEnd ] [ iStart ] ;
		
		answer += * ipNodeWeight ;
		llpNodeWeight [ i ] = * ipNodeWeight ++ ;
	}
	llpNodeWeight [ iNodeSize - 1 ] = * ipNodeWeight ;	
	if ( 0 != answer + * ipNodeWeight )					// Sum is not 0, then can't make all 0
		return -1 ;
	
	answer = 0 ;
	
	for ( int i = 0 ; i < iNodeSize ; ++i )
	{
		if ( 0 == vGraph [ i ].size () )
			++ iCnt ;
	}
	bool bUpdate = false ;
	while ( iNodeSize != iCnt )
	{
		bUpdate = false ;
		
		for ( int i = 0 ; i < iNodeSize ; ++i )
		{
			if ( 1 == vGraph [ i ].size () )			// If only one line exist, transfer weight to connected Node
			{
				pair < long long , int > pUpdate = iEraseSingleLine ( vGraph , llpNodeWeight , i ) ;
				
				answer += pUpdate.first ;
				iCnt += pUpdate.second ;
				
				
				bUpdate = true ;
			}
		}
		
		if ( ! bUpdate )
			break ;
	}
	
	
	return answer ;
}