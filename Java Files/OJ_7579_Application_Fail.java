import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;



public class OJ_7579_Application
{
	static int [] [] idrgMemoization ;						// Memoization for c1 to cn(Restart Memory)
	static ArrayList < Integer > alApplicationMemory ;
	static ArrayList < Integer > alRestartMemory ;
	static int [] irgEfficiency ;
	static int [] irgIndex ;
	static int [] irgMemorySum ;							// [ 1 ] is Memory used at restart
	static int iAppCnt ;									// [ 2 ] is weights for memory
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		iAppCnt = Integer.parseInt ( st.nextToken () ) ;
		int iByte = Integer.parseInt ( st.nextToken () ) ;
		alApplicationMemory = new ArrayList <> ( iAppCnt ) ;
		alRestartMemory = new ArrayList <> ( iAppCnt ) ;
		int iCnt = 0 ;
		irgEfficiency = new int [ iAppCnt ] ;
		irgMemorySum = new int [ iAppCnt ] ;
		irgIndex = new int [ iAppCnt ] ;
		
		
		
		st = new StringTokenizer ( br.readLine () ) ;
		
		for ( int i = 0 ; i < iAppCnt ; i++ )
		{
			alApplicationMemory.add ( Integer.parseInt ( st.nextToken () ) ) ;
			irgIndex [ i ] = i ;
		}
		
		st = new StringTokenizer ( br.readLine () ) ;
		
		for ( int i = 0 ; i < iAppCnt ; i++ )
		{
			int iTemp = Integer.parseInt ( st.nextToken () ) ;
			
			
			if ( 0 == iTemp )
			{
				iByte -= alApplicationMemory.get ( i - iCnt ) ;
				alApplicationMemory.remove ( i - iCnt ) ;
				++ iCnt ;
			}
			else
			{
				alRestartMemory.add ( iTemp ) ;
				irgEfficiency [ i - iCnt ] = alApplicationMemory.get ( i - iCnt ) / alRestartMemory.get ( i - iCnt ) ;
			}
		}
		
		iAppCnt -= iCnt ;
		
		idrgMemoization = new int [ iAppCnt ] [ iAppCnt * 100 + 1 ] ;					// -1 not calculated, -2 impossible.
		
		for ( int i = 0 ; i < iAppCnt ; i++ )
		{
			Arrays.fill ( idrgMemoization [ i ] , -1 ) ;
			
			for ( int j = i + 1 ; j < iAppCnt ; j++ )
			{
				if ( irgEfficiency [ irgIndex [ i ] ] < irgEfficiency [ irgIndex [ j ] ] )
				{
					int iTemp = irgIndex [ i ] ;
					irgIndex [ i ] = irgIndex [ j ] ;
					irgIndex [ j ] = iTemp ;
				}
			}
		}
		
		irgMemorySum [ 0 ] = alApplicationMemory.stream().mapToInt ( Integer :: intValue ).sum () ;
		
		for ( int i = 1 ; i < iAppCnt ; ++i )
		{
			irgMemorySum [ i ] = irgMemorySum [ i - 1 ] - alApplicationMemory.get ( irgIndex [ i - 1 ] );
		}
		
				
		System.out.println ( iGetMinCost ( iByte , 0 , 0 ) );
	}
	
	public static int iGetMinCost ( int iRestByte , int iTotalCost , int iIndex )
	{
		int iCost = Integer.MAX_VALUE ;
		int iTemp = -1 ;
		
		
		
		if ( ( iIndex <= iAppCnt - 1 ) && ( iRestByte > 0 ) && ( irgMemorySum [ iIndex ] >= iRestByte ) )
		{
			if ( idrgMemoization [ iIndex ] [ iTotalCost ] >= 0 )
			{
				return idrgMemoization [ iIndex ] [ iTotalCost ] ;
			}
			else
			{
				for ( int i = iIndex ; i < iAppCnt ; ++i )
				{
					iTemp = iGetMinCost ( iRestByte - alApplicationMemory.get ( irgIndex [ i ] ) , iTotalCost + alRestartMemory.get ( irgIndex [ i ] ) , i + 1 ) ;
					
					if ( ( iTemp >= 0 ) && ( iTemp + iTotalCost + alRestartMemory.get ( irgIndex [ i ] ) < iCost ) )
					{
						iCost = iTemp + alRestartMemory.get ( irgIndex [ i ] ) ;
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
					idrgMemoization [ iIndex ] [ iTotalCost ] = iCost ;
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