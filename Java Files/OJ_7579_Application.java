import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;



public class OJ_7579_Application
{
	static int [] [] idrgMemoization ;						// Memoization for c1 to cn(Restart Memory)
	static int [] irgApplicatoinMemory ;
	static int [] irgRestartMemory ;
	static int iAppCnt ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		iAppCnt = Integer.parseInt ( st.nextToken () ) ;
		int iByte = Integer.parseInt ( st.nextToken () ) ;
		idrgMemoization = new int [ iAppCnt ] [ iAppCnt * 100 + 1 ] ;					// -1 not calculated, -2 impossible.
		irgApplicatoinMemory = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		irgRestartMemory = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		
		
		
		for ( int i = 0 ; i < iAppCnt ; ++i )
		{
			Arrays.fill ( idrgMemoization [ i ] , -1 ) ;
		}
		
		
		System.out.println ( iGetMinCost ( iByte , 0 , 0 ) ) ;
	}
	
	public static int iGetMinCost ( int iRestByte , int iTotalCost , int iIndex )
	{
		int iCost = Integer.MAX_VALUE ;
		int iTemp = -1 ;
		boolean bUsed = true ;
		
		
		
		if ( ( iIndex <= iAppCnt - 1 ) && ( iRestByte > 0 ) )
		{
			if ( idrgMemoization [ iIndex ] [ iTotalCost ] >= 0 )
			{
				return idrgMemoization [ iIndex ] [ iTotalCost ] ;
			}
			else
			{
				for ( int i = iIndex ; i < iAppCnt ; ++i )
				{
					iTemp = iGetMinCost ( iRestByte - irgApplicatoinMemory [ i ] , iTotalCost + irgRestartMemory [ i ] , i + 1 ) ;
					
					if ( ( iTemp >= 0 ) && ( iTemp + irgRestartMemory [ i ] < iCost ) )
					{
						iCost = iTemp + irgRestartMemory [ i ] ;
					}
					
					iTemp = iGetMinCost ( iRestByte , iTotalCost , i + 1 ) ;
					
					if ( ( iTemp >= 0 ) && ( iTemp < iCost ) )
					{
						iCost = iTemp ;
					}
				}
				
				
				if ( iCost == Integer.MAX_VALUE )
				{
					idrgMemoization [ iIndex ] [ iTotalCost ] = -2 ;
				}
				else
				{
					idrgMemoization [ iIndex ] [ iTotalCost ] = iTotalCost + iCost ;
				}
			}
		}
		else
		{
			if ( iRestByte > 0 )		// Can't calculate
			{
				return -1 ;
			}
			else						// calculated
			{
				return 0 ;
			}
		}
		
		
		
		return idrgMemoization [ iIndex ] [ iTotalCost ] ;
	}
}