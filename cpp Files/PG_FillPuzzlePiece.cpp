#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using std :: string ;
using std :: vector ;
using std :: queue ;
using std :: pair ;
using std :: make_pair ;
using std :: max ;
using std :: min ;

struct puzzle
{
	int iWidth ;					// iWidth >= iHeight
	int iHeight ;
	int iPuzzleCount ;
	string strPuzzle ;				// 1 0 0	Concat of each line
} ;									// 1 1 0	-> "100" + "110" -> "100110"

bool bCompare ( puzzle & a , puzzle & b )
{
	if ( a.iWidth > b.iWidth )
		return true ;
	else if ( a.iWidth == b.iWidth )
		return a.iHeight > b.iHeight ;

	return false ;
}

bool bDoesPuzzleMatch ( puzzle a , puzzle b )
{
	if ( ( a.iWidth != b.iWidth ) || ( a.iHeight != b.iHeight ) )
		return false ;
 

	string strTransform = "" ;
	string strReverse = b.strPuzzle ;
	std :: reverse ( strReverse.begin () , strReverse.end () ) ;
	
	if ( ( 0 == a.strPuzzle.compare ( b.strPuzzle ) ) || ( 0 == a.strPuzzle.compare ( strReverse ) ) )
		return true ;
	

	if ( ( a.iWidth == b.iHeight ) && ( a.iHeight == b.iWidth ) )			// Same row and column, rotate 90 degree
	{
		strTransform = "" ;
		for ( int j = 0 ; j < a.iWidth ; ++j )
		{
			for ( int i = a.iWidth - 1 ; i >= 0 ; --i )
			{
				strTransform += b.strPuzzle [ i * a.iWidth + j ] ;
			}
		}
		
		strReverse = strTransform ;
		std :: reverse ( strReverse.begin () , strReverse.end () ) ;
		
		if ( ( 0 == a.strPuzzle.compare ( strTransform ) ) || ( 0 == a.strPuzzle.compare ( strReverse ) ) )
			return true ;
	}
	
	return false ;
}

puzzle getPuzzle ( int iX , int iY , vector < vector < int > > & vBoard , int iCondition )
{
	string strTemp [ 6 ] = { "00000000000" , "00000000000" , "00000000000" , "00000000000" , "00000000000" , "00000000000" } ;
	queue < pair < pair < int , int > , int > > qBFS ;		  // i , j ,  count
	int irgXDirection [ 4 ] = { 0 , 0 , 1 , -1 } ;
	int irgYDirection [ 4 ] = { -1 , 1 , 0 , 0 } ;
	int iBoardSize = vBoard.size () ;
	int iMinX = 5 ;
	int iMaxX = 0 ;
	int iMinY = 8 ;
	int iMaxY = 0 ;
	string strPuzzle = "" ;
	int iPuzzleCount = 0 ;
	
	
	
	qBFS.emplace ( make_pair ( make_pair ( iX , iY ) , 1 ) ) ;
	vBoard [ iX ] [ iY ] = 1 - iCondition ;
	while ( ! qBFS.empty () )
	{
		pair < int , int > pCoordinate = qBFS.front ().first ;
		int iCnt = qBFS.front ().second ;
		++ iPuzzleCount ;
		qBFS.pop () ;
		
		strTemp [ pCoordinate.first - iX ] [ pCoordinate.second - iY + 5 ] = '1' ;
		
		iMinX = min ( iMinX , pCoordinate.first - iX ) ;
		iMaxX = max ( iMaxX , pCoordinate.first - iX ) ;
		iMinY = min ( iMinY , pCoordinate.second - iY + 5 ) ;
		iMaxY = max ( iMaxY , pCoordinate.second - iY + 5 ) ;
		
		
		for ( int i = 0 ; i < 4 ; ++i )
		{
			int iTempX = pCoordinate.first + irgXDirection [ i ] ;
			int iTempY = pCoordinate.second + irgYDirection [ i ] ;
			
			if ( ( -1 == iTempX ) || ( iBoardSize == iTempX ) || ( -1 == iTempY ) || ( iBoardSize == iTempY )	// Exceed board
				|| ( -1 == iTempX - iX ) || ( -1 == iTempY - iY + 5 ) || ( 11 == iTempY - iY + 5 )				// Exceed string boundary
				|| ( iCondition != vBoard [ iTempX ] [ iTempY ] ) )												// No need to check
				continue ;
			
			vBoard [ iTempX ] [ iTempY ] = 1 - iCondition ;
			qBFS.emplace ( make_pair ( make_pair ( iTempX , iTempY ) , iCnt + 1 ) ) ;
		}
	}
	
	if ( iMaxX - iMinX <= iMaxY - iMinY )
	{
		for ( int i = iMinX ; i <= iMaxX ; ++i )
		{
			strPuzzle += strTemp [ i ].substr ( iMinY , iMaxY - iMinY + 1 ) ;
		}
	}
	else							// If width < height, then rotate 90 degree
	{
		for ( int j = iMinY ; j <= iMaxY ; ++j )
		{
			for ( int i = iMaxX ; i >= iMinX ; --i )
			{
				strPuzzle += strTemp [ i ] [ j ] ;
			}
		}
		
		int iTempX = iMaxX - iMinX + 1 ;
		int iTempY = iMaxY - iMinY + 1 ;
		iMaxX = iTempY ;
		iMinX = 1 ;
		iMaxY = iTempX ;
		iMinY = 1 ;
	}
	
	return { iMaxY - iMinY + 1 , iMaxX - iMinX + 1 , iPuzzleCount , strPuzzle } ;
}

int solution ( vector < vector < int > > game_board , vector < vector < int > > table )
{
	int answer = 0 ;
	int iBoardSize = table.size () ;
	vector < puzzle > vEmptyPlace ;
	vector < puzzle > vPuzzle ;
	
	
	
	for ( int i = 0 ; i < iBoardSize ; ++i )			// Emplace each puzzle
	{
		for ( int j = 0 ; j < iBoardSize ; ++j )
		{
			if ( 0 == game_board [ i ] [ j ] )
				vEmptyPlace.emplace_back ( getPuzzle ( i , j , game_board , 0 ) ) ;
			if ( 1 == table [ i ] [ j ] )
				vPuzzle.emplace_back ( getPuzzle ( i , j , table , 1 ) ) ;
		}
	}
	
	int iPuzzleSize = vPuzzle.size () ;

	std :: sort ( vEmptyPlace.begin () , vEmptyPlace.end () , bCompare ) ;
	std :: sort ( vPuzzle.begin () , vPuzzle.end () , bCompare ) ;
	
	for ( auto emptyPlace : vEmptyPlace )
	{
		for ( int i = 0 ; i < iPuzzleSize ; ++i )
		{
			if ( emptyPlace.iWidth > vPuzzle [ i ].iWidth )					// Latter vPuzzle, all the puzzle.iWidth is smaller
				break ;

			if ( bDoesPuzzleMatch ( emptyPlace , vPuzzle [ i ] ) )			// If puzzle matches, process
			{
				answer += emptyPlace.iPuzzleCount ;
				vPuzzle.erase ( vPuzzle.begin () + i ) ;
				-- iPuzzleSize ;
				
				break ;
			}
		}
	}
	
	
	return answer;
}