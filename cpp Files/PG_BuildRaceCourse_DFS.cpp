#include <vector>
#include <algorithm>

#define DOWN	0
#define RIGHT	1
#define UP		2
#define LEFT	3

using std :: vector ;

vector < int > * g_vpBoard ;
vector < vector < vector < int > > > g_vDP ;
int g_iBoardSize ;
int g_iMinCost ;

void getMinimumBuildCost ( int iX , int iY , int iDirection , int iCost )
{
	int iXDirection [ 4 ] = { 1 , 0 , -1 , 0 } ;
	int iYDirection [ 4 ] = { 0 , 1 , 0 , -1 } ;
	int iMinimumCost = 1e5 ;

	
	
	if ( ( iX == g_iBoardSize - 1 ) && ( iY == g_iBoardSize - 1 ) )
		g_iMinCost = std :: min ( g_iMinCost , iCost ) ;
	if ( g_iMinCost < iCost )
		return ;
	
	for ( int i = 0 ; i < 4 ; ++i )
	{
		int iTempX = iX + iXDirection [ i ] ;
		int iTempY = iY + iYDirection [ i ] ;
		int iDirectionCost = ( i == iDirection ) ? 100 : 600 ;
		
		if ( ( iTempX < 0 ) || ( g_iBoardSize - 1 < iTempX ) || ( iTempY < 0 ) || ( g_iBoardSize - 1 < iTempY )
			|| ( 1 == g_vpBoard [ iTempX ] [ iTempY ] ) || ( g_vDP [ iTempX ] [ iTempY ] [ i ] < iCost + iDirectionCost ) )
			continue ;
		
		g_vDP [ iTempX ] [ iTempY ] [ i ] = iCost + iDirectionCost ;
		
		getMinimumBuildCost ( iTempX , iTempY , i , iCost + iDirectionCost ) ;
	}
}

int solution ( vector < vector < int > > board )
{
	g_iBoardSize = board.size () ;
	g_vpBoard = board.data () ;
	g_vDP.resize ( g_iBoardSize , ( vector < vector < int > > ( g_iBoardSize , ( vector < int > ( 4 , 1e5 ) ) ) ) ) ;
	g_iMinCost = 1e5 ;
	
	g_vDP [ 0 ] [ 0 ] [ 0 ] = g_vDP [ 0 ] [ 0 ] [ 1 ] = g_vDP [ 0 ] [ 0 ] [ 2 ] = g_vDP [ 0 ] [ 0 ] [ 3 ] = 0 ;
	
	getMinimumBuildCost ( 0 , 1 , RIGHT , 100 ) ;
	getMinimumBuildCost ( 1 , 0 , DOWN , 100 ) ;
	
	
	return g_iMinCost ;
}