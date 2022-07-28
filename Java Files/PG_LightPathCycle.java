import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PG_LightPathCycle
{
	public static int [] solution ( String [] grid )
	{
		int [] irgXDirection = { -1 , 0 , 1 , 0 } ;			// UP LEFT DOWN RIGHT
		int [] irgYDirection = { 0 , -1 , 0 , 1 } ;
		int iHeight = grid.length ;
		int iWidth = grid [ 0 ].length () ;
		boolean [] [] [] btrgLight = new boolean [ iHeight ] [ iWidth ] [ 4 ] ;			// [] [] [ Direction ]
		int iTotalLight = iHeight * iWidth * 4 ;
		List < Integer > answerList = new ArrayList < Integer > () ;



		while ( 0 != iTotalLight )
		{
			for ( int i = 0 ; i < iHeight ; ++i )
			{
				for ( int j = 0 ; j < iWidth ; ++j )
				{
					for ( int k = 0 ; k < 4 ; ++k )
					{
						int iX = i ;
						int iY = j ;
						int iDirection = k ;
						int iCnt = 0 ;

						while ( ! btrgLight [ iX ] [ iY ] [ iDirection ] )
						{
							btrgLight [ iX ] [ iY ] [ iDirection ] = true ;
							++ iCnt ;
							iX += irgXDirection [ iDirection ] ;
							iY += irgYDirection [ iDirection ] ;

							if ( iX < 0 ) iX += iHeight ;
							else if ( iHeight == iX ) iX -= iHeight ;
							if ( iY < 0 ) iY += iWidth ;
							else if ( iWidth == iY ) iY -= iWidth ;

							if ( 'L' == grid [ iX ].charAt ( iY ) )
								iDirection = ( iDirection + 1 ) & 3 ;
							else if ( 'R' == grid [ iX ].charAt ( iY ) )
								iDirection = ( iDirection - 1 ) & 3 ;
						}

						if ( 0 != iCnt )
						{
							answerList.add ( iCnt ) ;
							iTotalLight -= iCnt ;
						}
					}
				}
			}
		}

		Collections.sort ( answerList ) ;


		return answerList.stream ().mapToInt ( Integer :: intValue ).toArray () ;
	}

	public static void main ( String[] args )
	{
		int [] i = solution ( new String[] { "R" , "R" } ) ;
	}
}