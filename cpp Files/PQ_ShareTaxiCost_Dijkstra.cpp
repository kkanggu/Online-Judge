#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define PII pair < int , int >

using std :: vector ;
using std :: pair ;
using std :: make_pair ;
using std :: priority_queue ;

struct pqPII
{
	int iTarget ;
	int iCost ;
	
	pqPII ( int iTarget , int iCost ) : iTarget ( iTarget ) , iCost ( iCost ) {}
} ;

struct comp
{
	bool operator () ( const pqPII & a , const pqPII & b )
	{
		return a.iCost > b.iCost ;
	}
} ;

vector < vector < PII > > vPath ;
int iTotalNode ;
int iCurrentAnswer ;
int iExpectAnswer ;

void updateMinimumLength ( int iStart , int iEnd )							// Update iExpectAnswer
{
	priority_queue < pqPII , vector < pqPII > , comp > pqBFS ;				// Store the index to update
	vector < bool > vVisit ( iTotalNode + 1 , false ) ;
	vector < int > vMinimumLength ( iTotalNode + 1 , -1 ) ;

	
	
	vMinimumLength [ iStart ] = 0 ;
	pqBFS.emplace ( iStart , 0 ) ;
	
	while ( -1 == vMinimumLength [ iEnd ] )
	{
		while ( ( ! pqBFS.empty () ) && ( vVisit [ pqBFS.top ().iTarget ] ) )
		{
			pqBFS.pop () ;
		}
		if ( pqBFS.empty () || ( iCurrentAnswer < pqBFS.top ().iCost + iExpectAnswer ) )	// Can't reach to iEnd
		{
			iExpectAnswer = 2e7 ;
			return ;
		}
		
		int iTarget = pqBFS.top ().iTarget ;
		int iCost = pqBFS.top ().iCost ;
		pqBFS.pop () ;
		
		vVisit [ iTarget ] = true ;
		vMinimumLength [ iTarget ] = iCost ;
		int iGraphSize = vPath [ iTarget ].size () ;
		PII * pTemp = vPath [ iTarget ].data () ;
		
		for ( int i = 0 ; i < iGraphSize ; ++i )
		{
			PII tempPII = pTemp [ i ] ;
			if ( ! vVisit [ tempPII.first ] )
			{
				pqBFS.emplace ( tempPII.first , iCost + tempPII.second ) ;
			}
		}
	}
	
	iExpectAnswer += vMinimumLength [ iEnd ] ;
}

int solution ( int n , int s , int a , int b , vector < vector < int > > fares )
{
	iCurrentAnswer = 2e7 ;
	vPath.resize ( n + 1 ) ;			// [ Start ] < End , Cost >
	int iFareSize = fares.size () ;
	iTotalNode = n ;
	
	

	for ( int i = 0 ; i < iFareSize ; ++i )
	{
		int * ipTemp = fares [ i ].data () ;
		int iTempStart = * ipTemp ++ ;
		int iTempEnd = * ipTemp ++ ;
		int iTempCost = * ipTemp ++ ;
		
		vPath [ iTempStart ].emplace_back ( make_pair ( iTempEnd , iTempCost ) ) ;
		vPath [ iTempEnd ].emplace_back ( make_pair ( iTempStart , iTempCost ) ) ;
	}
	
	for ( int i = 1 ; i <= n ; ++i )
	{
		iExpectAnswer = 0 ;
		updateMinimumLength ( s , i ) ;
		updateMinimumLength ( i , a ) ;
		updateMinimumLength ( i , b ) ;
		
		iCurrentAnswer = std :: min ( iCurrentAnswer , iExpectAnswer ) ;
	}
	
	
	return iCurrentAnswer ;
}