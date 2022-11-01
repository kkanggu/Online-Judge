#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using std :: vector ;
using std :: pair ;
using std :: make_pair ;
using std :: priority_queue ;
using std :: min ;

struct cardInfo
{
	int iX ;
	int iY ;
	bool bCanUse ;
} ;

struct moveInfo
{
	int iX ;
	int iY ;
	int iMove ;
	bool bVertical ;
} ;

struct comp
{
	bool operator () ( moveInfo & m1 , moveInfo & m2 )
	{
		return m1.iMove > m2.iMove ;
	}
} ;

int answer ;

int iGetMinMove ( vector < vector < int > > & board , int iStartX , int iStartY , int iEndX , int iEndY , int iMaxMove )
{
	priority_queue < moveInfo , vector < moveInfo > , comp > pqBFS ;
	int iMinMove = iMaxMove + 1 ;
	int iXDirection [ 4 ] = { 0 , 1 , 0 , -1 } ;	// Right Down Left Up
	int iYDirection [ 4 ] = { 1 , 0 , -1 , 0 } ;
	
	
	
	pqBFS.push ( { iStartX , iStartY , 0 , true } ) ;
	pqBFS.push ( { iStartX , iStartY , 0 , false } ) ;
	while ( ! pqBFS.empty () )
	{
		moveInfo currentMove = pqBFS.top () ;
		pqBFS.pop () ;
		
		if ( iMaxMove < currentMove.iMove )		// Can't find more moves
			break ;
		if ( ( currentMove.iX == iEndX ) && ( currentMove.iY == iEndY ) )		// Reach at destination, update
		{
			iMinMove = currentMove.iMove ;
			iMaxMove = iMinMove ;
			
			continue ;
		}
		
		
		for ( int i = 0 ; i < 4 ; ++i )		// Move to each direction
		{
			if ( ! ( ( currentMove.bVertical && 1 == ( i & 1 ) ) || ( ! currentMove.bVertical && 0 == ( i & 1 ) ) ) )		// If moved vertical, then move to horizontal. Same when moved horizontal
				continue ;

			int iMove = 0 ;
			int iFormerMove = 0 ;

			for ( int j = 0 ; j < 3 ; ++j )		// Max 3 move (0 -> 3, 3 -> 0)
			{
				int iTempX = currentMove.iX + iXDirection [ i ] * ( j + 1 ) ;
				int iTempY = currentMove.iY + iYDirection [ i ] * ( j + 1 ) ;
				
				if ( ( iTempX < 0 ) || ( 4 <= iTempX ) || ( iTempY < 0 ) || ( 4 <= iTempY ) )
					continue ;
				
				if ( ( 0 != board [ iTempX ] [ iTempY ] )											// Reach at card, 1 move
					|| ( currentMove.bVertical && ( ( 0 == iTempX ) || ( 3 == iTempX ) ) )			// Reach at end
					|| ( ! currentMove.bVertical && ( ( 0 == iTempY ) || ( 3 == iTempY ) ) ) )		// Reach at end
				{
					iMove = iFormerMove ;
					++ iFormerMove ;
				}
				++ iMove ;
				
				if ( iMove + currentMove.iMove <= iMaxMove )		// Can be candidate move
				{
					pqBFS.push ( { iTempX , iTempY , iMove + currentMove.iMove , ! currentMove.bVertical } ) ;
				}
			}
		}
	}
	
	
	if ( iMinMove <= iMaxMove )
		return iMinMove ;
	return -1 ;
}

pair < int , int > pGetPosition ( vector < vector < int > > & board , vector < cardInfo > & vCard , int iStartX , int iStartY )
{
	int iNumber = board [ iStartX ] [ iStartY ] ;
	
	
	
	for ( int i = 0 ; i < 4 ; ++i )
	{
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( ( board [ i ] [ j ] == iNumber ) && ( ( i != iStartX ) || ( j != iStartY ) ) )
			{
				return make_pair ( i , j ) ;
			}
		}
	}
}

void getBestMove ( vector < vector < int > > board , vector < cardInfo > & vCard , int iStartX , int iStartY , bool bPairExist , int iMove , int iCardLeft )
{
	pair < int , int > pNext ;
	int iCardSize = vCard.size () ;
	
	
	
	if ( 0 == iCardLeft )			// If no card left, then update answer
	{
		answer = min ( answer , iMove ) ;
		
		return ;
	}
	
	if ( bPairExist )				// Pair exist, it means only one destination
	{
		int iTemp = board [ iStartX ] [ iStartY ] ;


		pNext = pGetPosition ( board , vCard , iStartX , iStartY ) ;
		int iNextMove = iGetMinMove ( board , iStartX , iStartY , pNext.first , pNext.second , answer - iMove ) ;
		board [ iStartX ] [ iStartY ] = 0 ;
		
		if ( -1 != iNextMove )
		{
			board [ pNext.first ] [ pNext.second ] = 0 ;
			
			for ( int i = 0 ; i < iCardSize ; ++i )		// To update board
			{
				if ( ( pNext.first == vCard [ i ].iX ) && ( pNext.second == vCard [ i ].iY ) )
				{
					vCard [ i ].bCanUse = false ;
					getBestMove ( board , vCard , pNext.first , pNext.second , false , iMove + iNextMove , iCardLeft - 1 ) ;
					vCard [ i ].bCanUse = true ;
					
					break ;
				}
			}
		}
		
		return ;
	}
	
	
	for ( int i = 0 ; i < iCardSize ; ++i )
	{
		if ( vCard [ i ].bCanUse )
		{
			int iNextMove = iGetMinMove ( board , iStartX , iStartY , vCard [ i ].iX , vCard [ i ].iY , answer - iMove ) ;
		
			if ( -1 != iNextMove )
			{
				vCard [ i ].bCanUse = false ;
				getBestMove ( board , vCard , vCard [ i ].iX , vCard [ i ].iY , true , iMove + iNextMove , iCardLeft - 1 ) ;
				vCard [ i ].bCanUse = true ;
			}
		}
	}
}

int solution ( vector < vector < int > > board , int r , int c )
{
	vector < cardInfo > vCard ;
	answer = 79 ;
	
	
	
	for ( int i = 0 ; i < 4 ; ++i )			// Add card information
	{
		for ( int j = 0 ; j < 4 ; ++j )
		{
			if ( 0 != board [ i ] [ j ] )
			{
				vCard.push_back ( { i , j , true } ) ;
			}
		}
	}
	
	int iCardSize = vCard.size () ;
	for ( int i = 0 ; i < iCardSize ; ++i )		// Visit every card
	{
		int iMove = iGetMinMove ( board , r , c , vCard [ i ].iX , vCard [ i ].iY , answer ) ;
		
		vCard [ i ].bCanUse = false ;
		getBestMove ( board , vCard , vCard [ i ].iX , vCard [ i ].iY , true , iMove , iCardSize - 1 ) ;
		vCard [ i ].bCanUse = true ;
	}
	
	return answer + iCardSize ;
}