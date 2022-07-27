#include <string>
#include <vector>
#include <utility>

using std :: vector ;
using std :: string ;
using std :: pair ;
using std :: make_pair ;

int iWidth ;
int iHeight ;

pair < int , int > getMatchingTile ( vector < string > & vpBoard , int iX , int iY , char cCurrentTile )
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
					if ( cTempTile == cCurrentTile )
						return make_pair ( i , j ) ;

					break ;
				}
			}
			
			continue ;
		}
		else												// Find matching tile, RIGHT
		{
			if ( cTempTile == cCurrentTile )
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
					if ( cTempTile == cCurrentTile )
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
					if ( cTempTile == cCurrentTile )
						return make_pair ( i , j ) ;

					break ;
				}
			}
			
			continue ;
		}
		else												// Find matching tile, DOWN
		{
			if ( cTempTile == cCurrentTile )
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
					if ( cTempTile == cCurrentTile )
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
	pair < int , int > pFirst = { 0 , 0 } ;
	pair < int , int > pSecond = { 0 , 0 } ;
	char cCurrentTile ;
	char cNextTile = 'Z' + 1 ;
	
	
	
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
		cCurrentTile = cNextTile ;
		cNextTile = 'Z' + 1 ;

		for ( int i = 0 ; i < m ; ++i )			// Find matching tile
		{
			for ( int j = 0 ; j < n ; ++j )
			{
				char cTempTile = board [ i ] [ j ] ;
				
				if ( ( '.' == cTempTile ) || ( '*' == cTempTile ) || ( cCurrentTile < cTempTile ) )
					continue ;
				
				pair < int , int > pMatchingTile = getMatchingTile ( board , i , j , cTempTile ) ;
				
				if ( -1 != pMatchingTile.first )
				{
					if ( cTempTile < cCurrentTile )
					{
						pFirst.first = i ;
						pFirst.second = j ;
						pSecond = pMatchingTile ;
						cCurrentTile = cTempTile ;
					}
					else if ( cTempTile < cNextTile )
					{
						cNextTile = cTempTile ;
					}
				}
			}
		}
		
		if ( 'Z' + 1 == cCurrentTile )
		{
			answer = "IMPOSSIBLE" ;
			
			break ;
		}
		
		
		-- iTileCount ;
		answer += cCurrentTile ;
		board [ pFirst.first ] [ pFirst.second ] = '.' ;
		board [ pSecond.first ] [ pSecond.second ] = '.' ;
	}
	
	
	return answer ;
}