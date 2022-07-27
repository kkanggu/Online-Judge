#include <string>
#include <vector>
#include <queue>
#include <utility>

using std :: vector ;
using std :: string ;
using std :: priority_queue ;
using std :: pair ;
using std :: make_pair ;

struct Node
{
	pair < int , int > pFirst ;
	pair < int , int > pSecond ;
	char cTile ;
	
	Node ( pair < int , int > pFirst , pair < int , int > pSecond , char cTile )
		: pFirst ( pFirst ) , pSecond ( pSecond ) , cTile ( cTile ) {}
} ;

struct comp
{
	bool operator () ( Node & a , Node & b )
	{
		if ( a.cTile > b.cTile )
			return true ;

		return false ;
	}
} ;

int iWidth ;
int iHeight ;

pair < int , int > getMatchingTile ( vector < string > & vpBoard , int iX , int iY , char cTile )
{
	for ( int j = iY + 1 ; j < iHeight ; ++j )				// Right down
	{
		char cTempTile = vpBoard [ iX ] [ j ] ;
		
		if ( '*' == cTempTile )
			break ;
		if ( '.' == cTempTile )
		{
			for ( int i = iX + 1 ; i < iWidth ; ++i )
			{
				cTempTile = vpBoard [ i ] [ j ] ;
				
				if ( '*' == cTempTile )
					break ;
				if ( '.' == cTempTile )
					continue ;
				else										// Find matching tile, RIGHT
				{
					if ( cTempTile == cTile )
						return make_pair ( i , j ) ;

					break ;
				}
			}
			
			continue ;
		}
		else												// Find matching tile, RIGHT
		{
			if ( cTempTile == cTile )
				return make_pair ( iX , j ) ;
			
			break ;
		}
	}
	for ( int i = iX + 1 ; i < iWidth ; ++i )				// Down
	{
		char cTempTile = vpBoard [ i ] [ iY ] ;
		
		if ( '*' == cTempTile )
			break ;
		if ( '.' == cTempTile )
		{
			for ( int j = iY + 1 ; j < iHeight ; ++j )		// Down right
			{
				cTempTile = vpBoard [ i ] [ j ] ;
				
				if ( '*' == cTempTile )
					break ;
				if ( '.' == cTempTile )
					continue ;
				else										// Find matching tile, DOWN RIGHT
				{
					if ( cTempTile == cTile )
						return make_pair ( i , j ) ;

					break ;
				}
			}
			for ( int j = iY - 1 ; j >= 0 ; --j )			// Down left
			{
				cTempTile = vpBoard [ i ] [ j ] ;
				
				if ( '*' == cTempTile )
					break ;
				if ( '.' == cTempTile )
					continue ;
				else										// Find matching tile, DOWN LEFT
				{
					if ( cTempTile == cTile )
						return make_pair ( i , j ) ;

					break ;
				}
			}
			
			continue ;
		}
		else												// Find matching tile, DOWN
		{
			if ( cTempTile == cTile )
				return make_pair ( i , iY ) ;
			
			break ;
		}
	}
	for ( int j = iY - 1 ; j >= 0 ; --j )					// Left down
	{
		char cTempTile = vpBoard [ iX ] [ j ] ;
		
		if ( '*' == cTempTile )
			break ;
		if ( '.' == cTempTile )
		{
			for ( int i = iX + 1 ; i < iWidth ; ++i )
			{
				cTempTile = vpBoard [ i ] [ j ] ;
				
				if ( '*' == cTempTile )
					break ;
				if ( '.' == cTempTile )
					continue ;
				else										// Find matching tile, RIGHT DOWN
				{
					if ( cTempTile == cTile )
						return make_pair ( i , j ) ;

					break ;
				}
			}
			
			continue ;
		}
		else
			break ;
	}
	
	return make_pair ( -1 , 0 ) ;
}

string solution(int m, int n, vector<string> board )
{
	string answer = "";
	int iTileCount = 0 ;
	iWidth = m ;
	iHeight = n ;
	priority_queue < Node , vector < Node > , comp > pq ;
	char cTile = 'Z' + 1 ;

	
	
	for ( int i = 0 ; i < m ; ++i )
	{
		const char * cpString = board [ i ].data () ;
		
		for ( int j = 0 ; j < n ; ++j )
		{
			if ( ( '.' != * cpString ) && ( '*' != * cpString ) )
				++ iTileCount ;
			
			++ cpString ;
		}
	}
	
	iTileCount >>= 1 ;
	while ( 0 != iTileCount )
	{
		for ( int i = 0 ; i < m ; ++i )				// Find matching tile
		{
			for ( int j = 0 ; j < n ; ++j )
			{
				char cTempTile = board [ i ] [ j ] ;
				
				if ( ( '.' == cTempTile ) || ( '*' == cTempTile ) || ( cTile <= cTempTile ) )
					continue ;
				
				pair < int , int > pMatchingTile = getMatchingTile ( board , i , j , cTempTile ) ;
				
				if ( -1 != pMatchingTile.first )
				{
					pq.emplace ( make_pair ( i , j ) , pMatchingTile , cTempTile ) ;
					board [ i ] [ j ] = '*' ;
					board [ pMatchingTile.first ] [ pMatchingTile.second ] = '*' ;
				}
			}
		}
		
		if ( pq.empty () )
		{
			answer = "IMPOSSIBLE" ;
			
			break ;
		}
		
		Node tempNode = pq.top () ;					// Erase matching tile
		pq.pop () ;

		-- iTileCount ;
		answer += tempNode.cTile ;
		board [ tempNode.pFirst.first ] [ tempNode.pFirst.second ] = '.' ;
		board [ tempNode.pSecond.first ] [ tempNode.pSecond.second ] = '.' ;
		
		if ( pq.empty () )
			cTile = 'Z' + 1 ;
		else
			cTile = pq.top ().cTile ;
	}
	
	
	return answer ;
}