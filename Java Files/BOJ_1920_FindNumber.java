import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_1920_FindNumber
{
	public static void main ( String [] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		int iArrayCnt = Integer.parseInt ( br.readLine () ) ;
		int [] irgArray = Arrays.stream ( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int iTargetCnt = Integer.parseInt ( br.readLine () ) ;
		int [] iTargetArray = Arrays.stream ( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int iIndex = 0 ;
		int iLeft = 0 ;
		int iRight = 0 ;
		
		
		Arrays.sort ( irgArray ) ;
		
		for ( int i = 0 ; i < iTargetCnt ; ++i )
		{
			iLeft = 0 ;
			iRight = iArrayCnt - 1 ;
			iIndex = iArrayCnt / 2 ;
			
			
			while ( iLeft <= iRight )
			{
				if ( iTargetArray [ i ] == irgArray [ iIndex ] )
				{
					break ;
				}
				else if ( iTargetArray [ i ] < irgArray [ iIndex ] )
				{
					iRight = iIndex - 1 ;
				}
				else
				{
					iLeft = iIndex + 1 ;
				}
				
				iIndex = ( iLeft + iRight ) / 2 ;
			}
			
			if ( iLeft <= iRight )
			{
				System.out.println ( 1 ) ;
			}
			else
			{
				System.out.println ( 0 ) ;
			}
		}
	}
}
