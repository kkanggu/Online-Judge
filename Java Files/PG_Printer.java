import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution
{
	public int solution ( int [] priorities , int location )
	{
		int answer = 0 ;
		int iDocumentSize = priorities.length ;
		int iIndex = 0 ;
		boolean bPrinted = false ;
		int iCnt = 0 ;



		for ( int i = 0 ; i < iDocumentSize ; ++i )
		{
			bPrinted = false ;

			int iMaxPriority = -1 ;
			for ( int j = 0 ; j < iDocumentSize ; ++j ) iMaxPriority = Math.max ( iMaxPriority , priorities [ j ] ) ;

			for ( int j = iIndex ; ! bPrinted && ( j < iDocumentSize ) ; ++j )
			{
				if ( priorities [ j ] == iMaxPriority )
				{
					++ iCnt ;
					iIndex = j ;
					priorities [ j ] = -1 ;
					bPrinted = true ;

					break ;
				}
			}
			for ( int j = 0 ; ! bPrinted && ( j < iIndex ) ; ++j )
			{
				if ( priorities [ j ] == iMaxPriority )
				{
					++ iCnt ;
					iIndex = j ;
					priorities [ j ] = -1 ;
				}
			}

			if ( iIndex == location )
			{
				answer = iCnt ;

				break ;
			}
		}


		return answer ;
	}
}