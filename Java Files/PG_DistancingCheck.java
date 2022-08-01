import java.util.LinkedList;
import java.util.Queue;

class PlaceNode
{
	public int iX ;
	public int iY ;
	public int iCount ;

	PlaceNode ( int iX , int iY , int iCount )
	{
		this.iX = iX ;
		this.iY = iY ;
		this.iCount = iCount ;
	}
}

public class PG_DistancingCheck
{
	public boolean bIsDistancing ( String [] strPlaces )
	{
		Queue < PlaceNode > qPlace = new LinkedList <> () ;
		int [] irgXDirection = { 0 , 1 , -1 } ;		// RIGHT , DOWN , UP
		int [] irgYDirection = { 1 , 0 , 0 } ;

		for ( int i = 0 ; i < 5 ; ++i )
		{
			for ( int j = 0 ; j < 5 ; ++j )
			{
				if ( 'P' == strPlaces [ i ].charAt ( j ) )
					qPlace.offer ( new PlaceNode ( i , j , 0 ) ) ;

				while ( ! qPlace.isEmpty () )
				{
					PlaceNode tempPlace = qPlace.poll () ;

					for ( int k = 0 ; k < 3 ; ++k )
					{
						int iTempX = tempPlace.iX + irgXDirection [ k ] ;
						int iTempY = tempPlace.iY + irgYDirection [ k ] ;

						if ( ( -1 == iTempX ) || ( iTempX == 5 ) || ( -1 == iTempY ) || ( 5 == iTempY ) || ( 'X' == strPlaces [ iTempX ].charAt ( iTempY ) ) )
							continue ;


						if ( ( 'P' == strPlaces [ iTempX ].charAt ( iTempY ) ) && ( ( i != iTempX ) || ( j != iTempY ) ) )
							return false ;
						else if ( 0 == tempPlace.iCount )
							qPlace.offer ( new PlaceNode ( iTempX , iTempY , 1 ) ) ;
					}
				}
			}
		}


		return true ;
	}

	public int [] solution ( String [] [] places )
	{
		int iPlaceSize = places.length ;
		int [] answer = new int [ iPlaceSize ] ;



		for ( int i = 0 ; i < iPlaceSize ; ++i )
		{
			answer [ i ] = bIsDistancing ( places [ i ] ) ? 1 : 0 ;
		}


		return answer ;
	}
}
