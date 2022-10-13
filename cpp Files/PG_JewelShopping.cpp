#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <queue>

using std :: vector ;
using std :: string ;
using std :: unordered_map ;
using std :: pair ;
using std :: max ;
using std :: priority_queue ;

struct gemInfo
{
	int iGemIndex ;
	int iStandIndex ;
} ;

struct comp
{
	bool operator () ( gemInfo & g1 , gemInfo & g2 )
	{
		return g1.iStandIndex > g2.iStandIndex ;
	}
} ;

pair < int , int > pGetFrontRange ( vector < vector < int > > & vGemPosition )
{
	int iGemSize = vGemPosition.size () ;
	int iMax = -1 ;
	priority_queue < gemInfo , vector < gemInfo > , comp > pqGem ;
	pair < int , int > pReturn ;
	
	
	
	for ( int i = 0 ; i < iGemSize ; ++i )
	{
		int iTemp = vGemPosition [ i ] [ 0 ] ;
		
		iMax = max ( iMax , iTemp ) ;
		pqGem.push ( { i , iTemp } ) ;
	}
	
	pReturn.first = pqGem.top ().iStandIndex ;
	pReturn.second = iMax ;
	
	while ( true )
	{
		// Erase old gem
		gemInfo currentGem = pqGem.top () ;
		pqGem.pop () ;
		vGemPosition [ currentGem.iGemIndex ].erase ( vGemPosition [ currentGem.iGemIndex ].begin () ) ;
		

		if ( vGemPosition [ currentGem.iGemIndex ].empty () )
			break ;
		
		pqGem.push ( { currentGem.iGemIndex , vGemPosition [ currentGem.iGemIndex ] [ 0 ] } ) ;


		// Check if better range exist
		iMax = max ( vGemPosition [ currentGem.iGemIndex ] [ 0 ] , iMax ) ;

		if ( iMax - pqGem.top ().iStandIndex < pReturn.second - pReturn.first )
		{
			pReturn.first = pqGem.top ().iStandIndex ;
			pReturn.second = iMax ;
		}
	}
	
	
	return pReturn ;
}

vector < int > solution ( vector < string > gems )
{
	int iGemSize = gems.size () ;
	int iGemCount = 0 ;
	unordered_map < string , int > umStrToIndex ;
	vector < vector < int > > vGemPosition ;
	
	
	
	for ( int i = 0 ; i < iGemSize ; ++i )
	{
		int iTemp = umStrToIndex [ gems [ i ] ] ;
		if ( 0 == umStrToIndex [ gems [ i ] ] )
		{
			iTemp = ++ iGemCount ;
			umStrToIndex [ gems [ i ] ] = iTemp ;
			
			vector < int > vTemp ;
			vGemPosition.emplace_back ( vTemp ) ;
		}
		vGemPosition [ iTemp - 1 ].emplace_back ( i + 1 ) ;
	}
	
	pair < int , int > pAnswer ;
	pAnswer = pGetFrontRange ( vGemPosition ) ;
	

	return { pAnswer.first , pAnswer.second } ;
}