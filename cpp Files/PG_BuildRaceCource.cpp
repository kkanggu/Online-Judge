#include <vector>
#include <queue>
#include <algorithm>

using std :: vector ;
using std :: priority_queue ;

struct mapInfo
{
	int iX ;
	int iY ;
	int iDirection ;
	int iCost ;
} ;

struct comp
{
   bool operator () ( mapInfo & a , mapInfo & b )
   {
	   return a.iCost > b.iCost ;
   }
} ;

int solution ( vector < vector < int > > board )
{
	int iBoardSize = board.size () ;
	vector < vector < vector < int > > > vMap ( iBoardSize , ( vector < vector < int > > ( iBoardSize , ( vector < int > ( 2 , 1e6 ) ) ) ) ) ;			// 0 Vertical , 1 Horizontal
	priority_queue < mapInfo , vector < mapInfo > , comp > pqBFS ;
	int irgXDirection [ 4 ] = { -1 , 0 , 1 , 0 } ;
	int irgYDirection [ 4 ] = { 0 , -1 , 0 , 1 } ;
	
	
	
	vMap [ 0 ] [ 0 ] [ 0 ] = vMap [ 0 ] [ 0 ] [ 1 ] = 0 ;
	pqBFS.push ( { 0 , 0 , 0 , 0 } ) ;
	pqBFS.push ( { 0 , 0 , 1 , 0 } ) ;
	while ( ! pqBFS.empty () )
	{
		mapInfo currentInfo = pqBFS.top () ;
		pqBFS.pop () ;
		
		if ( currentInfo.iCost > vMap [ currentInfo.iX ] [ currentInfo.iY ] [ currentInfo.iDirection ] )
			continue ;

		for ( int i = 0 ; i < 4 ; ++i )
		{
			int iX = currentInfo.iX + irgXDirection [ i ] ;
			int iY = currentInfo.iY + irgYDirection [ i ] ;
			int iDirection = i & 1 ;
			int iCost = ( iDirection == currentInfo.iDirection ) ? 100 : 600 ;
			iCost += currentInfo.iCost ;
			
			if ( ( -1 == iX ) || ( -1 == iY ) || ( iBoardSize == iX ) || ( iBoardSize == iY ) || ( 1 == board [ iX ] [ iY ] ) )		// Out of bound, find wall
				continue ;
			if ( vMap [ iX ] [ iY ] [ iDirection ] <= iCost )		// Current path is worse
				continue ;
			
			vMap [ iX ] [ iY ] [ iDirection ] = iCost ;
			pqBFS.push ( { iX , iY , iDirection , iCost } ) ;
		}		
	}
	
	
	return std :: min ( vMap [ iBoardSize - 1 ] [ iBoardSize - 1 ] [ 0 ] , vMap [ iBoardSize - 1 ] [ iBoardSize - 1 ] [ 1 ] ) ;
}