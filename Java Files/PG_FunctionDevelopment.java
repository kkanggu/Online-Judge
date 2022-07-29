import java.util.ArrayList;
import java.util.List;

public class PG_FunctionDevelopment
{
	public int [] solution ( int[] progresses , int[] speeds )
	{
		List < Integer > lEndList = new ArrayList < Integer > () ;
		int iFunctionSize = progresses.length ;
		int iTime = 0 ;
		int iCount = 0 ;



		for ( int i = 0 ; i < iFunctionSize ; ++i )
		{
			int iCurrentEndTime = ( 100 - progresses [ i ] - 1 ) / speeds [ i ] + 1 ;

			if ( iTime < iCurrentEndTime )
			{
				iTime = iCurrentEndTime ;
				--i ;

				if ( 0 != iCount )
				{
					lEndList.add ( iCount ) ;
					iCount = 0 ;
				}
			}
			else
			{
				++ iCount ;
			}
		}

		if ( 0 != iCount )
		{
			lEndList.add ( iCount ) ;
			iCount = 0 ;
		}


		return lEndList.stream().mapToInt ( i -> i ).toArray () ;
	}
}
