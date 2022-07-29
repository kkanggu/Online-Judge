import java.util.LinkedList;
import java.util.Queue;

class Node
{
	public int iX ;
	public int iY ;

	Node ( int iX , int iY )
	{
		this.iX = iX ;
		this.iY = iY ;
	}
}

public class PG_KakaoFriendsColoringBook
{
	public static int [] solution ( int m , int n , int[][] picture )
	{
		int iAreaCnt = 0 ;
		int iMaxAreaSize = 0 ;
		int [] irgXDirection = { -1 , 0 , 1 , 0 } ;
		int [] irgYDirection = { 0 , -1 , 0 , 1 } ;
		Queue < Node > qBFS = new LinkedList <> () ;
		int [] [] idrgTempPicture = new int [ m ] [ n ] ;



		for ( int i = 0 ; i < m ; ++i )
			for ( int j = 0 ; j < n ; ++j )
				idrgTempPicture [ i ] [ j ] = picture [ i ] [ j ] ;

		for ( int i = 0 ; i < m ; ++i )
		{
			for ( int j = 0 ; j < n ; ++j )
			{
				int iColor = idrgTempPicture [ i ] [ j ] ;
				int iCnt = 0 ;

				if ( 0 == iColor )
					continue ;

				idrgTempPicture [ i ] [ j ] = 0 ;
				qBFS.offer ( new Node ( i , j ) ) ;

				while ( ! qBFS.isEmpty () )
				{
					Node tempNode = qBFS.poll () ;
					++ iCnt ;

					for ( int k = 0 ; k < 4 ; ++k )
					{
						int iX = tempNode.iX + irgXDirection [ k ] ;
						int iY = tempNode.iY + irgYDirection [ k ] ;

						if ( ( iX < 0 ) || ( iY < 0 ) || ( m == iX ) || ( n == iY ) || ( iColor != idrgTempPicture [ iX ] [ iY ] ) )
							continue ;

						idrgTempPicture [ iX ] [ iY ] = 0 ;
						qBFS.offer ( new Node ( iX , iY  ) ) ;
					}
				}

				++ iAreaCnt ;
				iMaxAreaSize = Math.max ( iMaxAreaSize , iCnt ) ;
			}
		}

		return new int [] { iAreaCnt , iMaxAreaSize };
	}

	public static void main ( String[] args )
	{
		int [] i = solution ( 6 , 4 , new int [] [] {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}} ) ;
	}
}