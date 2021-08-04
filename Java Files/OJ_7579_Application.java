import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;



public class OJ_7579_Application
{
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		int iAppCnt = Integer.parseInt ( st.nextToken () ) ;
		int iByte = Integer.parseInt ( st.nextToken () ) ;
		int [] irgApplicationMemory = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int [] irgRestartMemory = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int iSum = Arrays.stream( irgRestartMemory ).sum () ;
		int [] irgMemoization = new int [ iSum + 1 ] ;
		
		
		
		for ( int i = 0 ; i < iAppCnt ; ++i )
		{
			for ( int j = iSum ; j >= irgRestartMemory [ i ] ; --j )
			{
				irgMemoization [ j ] = Integer.max ( irgMemoization [ j ] , irgMemoization [ j - irgRestartMemory [ i ] ] + irgApplicationMemory [ i ] ) ;
			}
		}
		
		
		for ( int i = 0 ; i < iSum + 1 ; ++i )
		{
			if ( irgMemoization [ i ] >= iByte )
			{
				System.out.println ( i ) ;
				
				break ;
			}
		}
	}
}