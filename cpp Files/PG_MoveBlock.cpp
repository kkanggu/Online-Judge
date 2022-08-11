#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using std :: vector ;
using std :: queue ;
using std :: pair ;
using std :: make_pair ;

struct robot
{
	int iX ;
	int iY ;
	int iDirection ;				// 0 : horizontal , 1 : vertical
	int iCount ;

	robot ( int iX , int iY , int iDirection , int iCount ) : iX ( iX ) , iY ( iY ) , iDirection ( iDirection ) , iCount ( iCount ) {}
} ;

int solution ( vector < vector < int > > board )
{
	int iBoardSize = board.size () ;
	vector < vector < vector < int > > > vMapMemoization ( iBoardSize , ( vector < vector < int > > ( iBoardSize , ( vector < int > ( 2 , 1000 ) ) ) ) ) ;		 // [ i ] [ j ] [ 0 : horizontal , 1 : vertical ]
	queue < robot > qBFS ;
	int irgXDirection [ 4 ] = { -1 , 0 , 1 , 0 } ;
	int irgYDirection [ 4 ] = { 0 , -1 , 0 , 1 } ;
	
	
	
	qBFS.emplace ( 0 , 0 , 0 , 0 ) ;
	vMapMemoization [ 0 ] [ 0 ] [ 0 ] = 0 ;
	while ( ! qBFS.empty () )
	{
		robot Robot = qBFS.front () ;
		qBFS.pop () ;
		
		if ( ( iBoardSize - 1 == Robot.iX + Robot.iDirection ) && ( iBoardSize - 1 == Robot.iY + 1 - Robot.iDirection ) )
		{
			break ;
		}
		
		for ( int i = 0 ; i < 4 ; ++i )
		{
			int iTempX = Robot.iX + irgXDirection [ i ] ;
			int iTempY = Robot.iY + irgYDirection [ i ] ;
			
			if ( ( -1 == iTempX ) || ( -1 == iTempY ) || ( iBoardSize == iTempX + Robot.iDirection ) || ( iBoardSize == iTempY + 1 - Robot.iDirection ) )		 // Out of bound
				continue ;
			if ( ( vMapMemoization [ iTempX ] [ iTempY ] [ Robot.iDirection ] <= Robot.iCount + 1 )		// Can't get better
				|| ( 1 == board [ iTempX ] [ iTempY ] ) || ( 1 == board [ iTempX + Robot.iDirection ] [ iTempY + 1 - Robot.iDirection ] ) )	// Can't move here
				continue ;
			
			vMapMemoization [ iTempX ] [ iTempY ] [ Robot.iDirection ] = Robot.iCount + 1 ;
			qBFS.emplace ( iTempX , iTempY , Robot.iDirection , Robot.iCount + 1 ) ;
		}
		
		if ( 0 == Robot.iDirection )		// Rotate, horizontal
		{
			if ( ( 0 != Robot.iX ) && ( 0 == board [ Robot.iX - 1 ] [ Robot.iY ] )
									&& ( 0 == board [ Robot.iX - 1 ] [ Robot.iY + 1 ] ) )	 			// Rotate up
			{
				if ( Robot.iCount + 1 < vMapMemoization [ Robot.iX - 1 ] [ Robot.iY ] [ 1 ] )
				{
					vMapMemoization [ Robot.iX - 1 ] [ Robot.iY ] [ 1 ] = Robot.iCount + 1 ;
					qBFS.emplace ( Robot.iX - 1 , Robot.iY , 1 , Robot.iCount + 1 ) ;
				}
				if ( Robot.iCount + 1 < vMapMemoization [ Robot.iX - 1 ] [ Robot.iY + 1 ] [ 1 ] )
				{
					vMapMemoization [ Robot.iX - 1 ] [ Robot.iY + 1 ] [ 1 ] = Robot.iCount + 1 ;
					qBFS.emplace ( Robot.iX - 1 , Robot.iY + 1 , 1 , Robot.iCount + 1 ) ;
				}
			}
			if ( ( iBoardSize - 1 != Robot.iX ) && ( 0 == board [ Robot.iX + 1 ] [ Robot.iY ] )
												&& ( 0 == board [ Robot.iX + 1 ] [ Robot.iY + 1 ] ) )	// Rotate down
			{
				if ( Robot.iCount + 1 < vMapMemoization [ Robot.iX ] [ Robot.iY ] [ 1 ] )
				{
					vMapMemoization [ Robot.iX ] [ Robot.iY ] [ 1 ] = Robot.iCount + 1 ;
					qBFS.emplace (Robot.iX , Robot.iY , 1 , Robot.iCount + 1 ) ;
				}
				if ( Robot.iCount + 1 < vMapMemoization [ Robot.iX ] [ Robot.iY + 1 ] [ 1 ] )
				{
					vMapMemoization [ Robot.iX ] [ Robot.iY + 1 ] [ 1 ] = Robot.iCount + 1 ;
					qBFS.emplace (Robot.iX , Robot.iY + 1 , 1 , Robot.iCount + 1 ) ;
				}
			}
		}
		else						// Rotate, vertical
		{
			if ( ( 0 != Robot.iY ) && ( 0 == board [ Robot.iX ] [ Robot.iY - 1 ] )
									&& ( 0 == board [ Robot.iX + 1 ] [ Robot.iY - 1 ] ) )	 			// Rotate left
			{
				if ( Robot.iCount + 1 < vMapMemoization [ Robot.iX ] [ Robot.iY - 1 ] [ 0 ] )
				{
					vMapMemoization [ Robot.iX ] [ Robot.iY - 1 ] [ 0 ] = Robot.iCount + 1 ;
					qBFS.emplace ( Robot.iX , Robot.iY - 1 , 0 , Robot.iCount + 1 ) ;
				}
				if ( Robot.iCount + 1 < vMapMemoization [ Robot.iX + 1 ] [ Robot.iY - 1 ] [ 0 ] )
				{
					vMapMemoization [ Robot.iX + 1 ] [ Robot.iY - 1 ] [ 0 ] = Robot.iCount + 1 ;
					qBFS.emplace ( Robot.iX + 1 , Robot.iY - 1 , 0 , Robot.iCount + 1 ) ;
				}
			}
			if ( ( iBoardSize - 1 != Robot.iY ) && ( 0 == board [ Robot.iX ] [ Robot.iY + 1 ] )
												&& ( 0 == board [ Robot.iX + 1 ] [ Robot.iY + 1 ] ) )	// Rotate right
			{
				if ( Robot.iCount + 1 < vMapMemoization [ Robot.iX ] [ Robot.iY ] [ 0 ] )
				{
					vMapMemoization [ Robot.iX ] [ Robot.iY ] [ 0 ] = Robot.iCount + 1 ;
					qBFS.emplace ( Robot.iX , Robot.iY , 0 , Robot.iCount + 1 ) ;
				}
				if ( Robot.iCount + 1 < vMapMemoization [ Robot.iX + 1 ] [ Robot.iY ] [ 0 ] )
				{
					vMapMemoization [ Robot.iX + 1 ] [ Robot.iY ] [ 0 ] = Robot.iCount + 1 ;
					qBFS.emplace ( Robot.iX + 1 , Robot.iY , 0 , Robot.iCount + 1 ) ;
				}
			}
		}
	}
	
	
	return std :: min ( vMapMemoization [ iBoardSize - 1 ] [ iBoardSize - 2 ] [ 0 ] , vMapMemoization [ iBoardSize - 2 ] [ iBoardSize - 1 ] [ 1 ] ) ;
}