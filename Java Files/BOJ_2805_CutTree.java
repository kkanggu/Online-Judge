import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_2805_CutTree
{
	public static void main ( String [] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		int [] irgCnt = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int [] irgTree = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int iLeft = 0 ;
		int iRight = 0 ;
		int iIndex = 0 ;
		int iValue = 0 ;
		long lTemp = 0 ;
		
		
		
		Arrays.sort ( irgTree ) ;
		
		iRight = irgTree [ irgCnt [ 0 ] - 1 ] ;
		
		while ( iLeft <= iRight )
		{
			iIndex = ( iLeft + iRight ) / 2 ;
			lTemp = 0 ;
			
			
			for ( int i = irgCnt [ 0 ] - 1 ; i >= 0 ; --i )
			{
				if ( irgTree [ i ] > iIndex )
				{
					lTemp += irgTree [ i ] - iIndex ;
					
					if ( lTemp >= irgCnt [ 1 ] )
					{
						break ;
					}
				}
				else
				{
					break ;
				}
			}
			
			if ( lTemp >= irgCnt [ 1 ] )
			{
				iValue = iIndex ;
				iLeft = iIndex + 1 ;
			}
			else
			{
				iRight = iIndex - 1 ;
			}
		}
		
		System.out.println ( iValue ) ;
	}
}
