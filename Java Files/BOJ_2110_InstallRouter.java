import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_2110_InstallRouter
{
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		int [] irgCnt = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int [] irgHome = new int [ irgCnt [ 0 ] ] ;
		int iLeft = 2 ;
		int iRight = 0 ;
		int iIndex = 0 ;
		int iValue = 1 ;
		int iRouterCnt = 0 ;
		int iTemp = 0 ;
		
		
		
		for ( int i = 0 ; i < irgCnt [ 0 ] ; ++i )
		{
			irgHome [ i ] = Integer.parseInt ( br.readLine () ) ;
		}
		
		Arrays.sort ( irgHome ) ;
		
		iRight = irgHome [ irgCnt [ 0 ] - 1 ] ;
		
		while ( iLeft <= iRight )
		{
			iIndex = ( iLeft + iRight ) / 2 ;
			iRouterCnt = irgCnt [ 1 ] - 1 ;
			iTemp = irgHome [ 0 ] ;
			
			
			for ( int i = 1 ; i < irgCnt [ 0 ] ; ++i )
			{
				if ( irgHome [ i ] - iTemp >= iIndex )
				{
					-- iRouterCnt ;
					iTemp = irgHome [ i ] ;
				}
				if ( iRouterCnt == 0 )
				{
					break ;
				}
			}
			
			if ( 0 == iRouterCnt )
			{
				iLeft = iIndex + 1 ;
				iValue = iIndex ;
			}
			else
			{
				iRight = iIndex - 1 ;
			}
		}
		
		System.out.println ( iValue ) ;
	}
}
