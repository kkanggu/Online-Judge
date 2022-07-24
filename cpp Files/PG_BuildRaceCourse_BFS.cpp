#include <vector>
#include <algorithm>
#include <queue>

#define UP		0
#define LEFT	1
#define DOWN	2
#define RIGHT	3

using std :: vector ;
using std :: queue ;

struct node
{
	int iX ;
	int iY ;
	int iCost ;
	int iDirection ;

	node ( int iX , int iY , int iCost , int iDirection ) :
		iX ( iX ) , iY ( iY ) , iCost ( iCost ) , iDirection ( iDirection ) {}
} ;

int solution ( vector < vector < int > > board )
{
	vector < int > * vpBoard = board.data () ;
	int iBoardSize = board.size () ;
	vector < vector < vector < int > > > vDP ( iBoardSize , ( vector < vector < int > > ( iBoardSize , ( vector < int > ( 4 , 1e5 ) ) ) ) ) ;
	queue < node > qBFS ;
	int iXDirection [ 4 ] = { -1 , 0 , 1 , 0 } ;
	int iYDirection [ 4 ] = { 0 , -1 , 0 , 1 } ;
	int iAnswer = 1e5 ;
	vector < vector < bool > > vVisit ( iBoardSize , ( vector < bool > ( iBoardSize , false ) ) ) ;

	
	
	vDP [ 0 ] [ 0 ] [ 0 ] = vDP [ 0 ] [ 0 ] [ 1 ] = vDP [ 0 ] [ 0 ] [ 2 ] = vDP [ 0 ] [ 0 ] [ 3 ] = 0 ;
	vVisit [ 0 ] [ 0 ] = true ;
	
	qBFS.emplace ( 0 , 1 , 100 , RIGHT ) ;
	qBFS.emplace ( 1 , 0 , 100 , DOWN ) ;
	while ( ! qBFS.empty () )
	{
		node tempNode = qBFS.front () ;
		qBFS.pop () ;
		
		if ( vDP [ tempNode.iX ] [ tempNode.iY ] [ tempNode.iDirection ] < tempNode.iCost )
			continue ;
		
		if ( ( tempNode.iX == iBoardSize - 1 ) && ( tempNode.iY == iBoardSize - 1 ) )
			return iAnswer = std :: min ( iAnswer , tempNode.iCost ) ;
		
		for ( int i = 0 ; i < 4 ; ++i )
		{
			int iTempX = tempNode.iX + iXDirection [ i ] ;
			int iTempY = tempNode.iY + iYDirection [ i ] ;
			int iDirectionCost = ( i == tempNode.iDirection ) ? 100 : 600 ;

			if ( ( iTempX < 0 ) || ( iBoardSize - 1 < iTempX ) || ( iTempY < 0 ) || ( iBoardSize - 1 < iTempY ) || ( 1 == vpBoard [ iTempX ] [ iTempY ] ) )
				continue ;
			if ( ( vVisit [ iTempX ] [ iTempY ] ) && ( vDP [ iTempX ] [ iTempY ] [ i ] < tempNode.iCost + iDirectionCost ) )
				continue ;

			vDP [ iTempX ] [ iTempY ] [ i ] = tempNode.iCost + iDirectionCost ;
			vVisit [ tempNode.iX ] [ tempNode.iY ] = true ;
			qBFS.emplace ( iTempX , iTempY , tempNode.iCost + iDirectionCost , i ) ;
		}
	}
	
	
	return iAnswer;
}