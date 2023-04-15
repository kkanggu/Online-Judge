import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;



public class OJ_2206_MovewithBreakingWall
{
	static int g_iRowCnt ;
	static int g_iColumnCnt ;
	static int [] [] g_idrgMap ;
	static int [] [] [] g_itrgRoute ;									// The shortest length to point
																		// [ 0 ] [][] without breaking wall, [ 1 ] [][] with braeking wall
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		g_iRowCnt = Integer.parseInt ( st.nextToken () ) ;
		g_iColumnCnt = Integer.parseInt ( st.nextToken () ) ;
		g_idrgMap = new int [ g_iRowCnt ][ g_iColumnCnt ] ;				// -1 Wall, 1 Break and Pass, 2 just Pass, 3 All , 0 not yet
		g_itrgRoute = new int [ 2 ] [ g_iRowCnt ] [ g_iColumnCnt ] ;
		
		
		
		for ( int i = 0 ; i < g_iRowCnt ; ++i )
		{
			Arrays.fill ( g_itrgRoute [ 0 ] [ i ] , Integer.MAX_VALUE ) ;
			Arrays.fill ( g_itrgRoute [ 1 ] [ i ] , Integer.MAX_VALUE ) ;
			String str = br.readLine () ;
			
			for ( int j = 0 ; j < g_iColumnCnt ; ++j )
			{
				if ( '0' == str.charAt ( j ) )
				{
					g_idrgMap [ i ] [ j ] = 0 ;
				}
				else
				{
					g_idrgMap [ i ] [ j ] = -1 ;
				}
			}
		}
		
		getShortcutLength () ;
		
		if ( ( Integer.MAX_VALUE == g_itrgRoute [ 0 ] [ g_iRowCnt - 1 ] [ g_iColumnCnt - 1 ] ) && ( Integer.MAX_VALUE == g_itrgRoute [ 1 ] [ g_iRowCnt - 1 ] [ g_iColumnCnt - 1 ] ) )
		{
			System.out.println ( -1 ) ;
		}
		else
		{
			System.out.println ( Integer.min ( g_itrgRoute [ 0 ] [ g_iRowCnt - 1 ] [ g_iColumnCnt - 1 ] , g_itrgRoute [ 1 ] [ g_iRowCnt - 1 ] [ g_iColumnCnt - 1 ] ) ) ;
		}
	}
	
	static class cInfo
	{
		int m_iRow ;
		int m_iColumn ;
		boolean m_bBreak ;
		
		public cInfo ( int iRow , int iColumn , boolean bBreak )
		{
			this.m_iRow = iRow ;
			this.m_iColumn = iColumn ;
			this.m_bBreak = bBreak ;
		}
	}
	
	static void getShortcutLength ()
	{
		int iCurrentLength = 0 ;
		int iRow = 0 ;
		int iColumn = 0 ;
		boolean bBreak = false ;
		cInfo TempInfo = new cInfo ( iRow , iColumn , bBreak ) ;
		Queue < cInfo > queue = new LinkedList <> () ;
		int [] irgTemp1 = { -1 , 1 , 0 , 0 } ;
		int [] irgTemp2 = { 0 , 0 , -1 , 1 } ;
		int iBreakCheck = 0 ;											// 1 Break, 0 not Break
		
		
		
		g_itrgRoute [ 0 ] [ 0 ] [ 0 ] = 1 ;
		g_idrgMap [ 0 ] [ 0 ] = 3 ;
		
		queue.add ( TempInfo ) ;
		
		while ( ! queue.isEmpty () )
		{
			cInfo GetInfo = queue.poll () ;
			iRow = GetInfo.m_iRow ;
			iColumn = GetInfo.m_iColumn ;
			bBreak = GetInfo.m_bBreak ;
			iBreakCheck = bBreak ? 1 : 0 ;
			iCurrentLength = g_itrgRoute [ iBreakCheck ] [ iRow ] [ iColumn ] ;
			
			for ( int i = 0 ; i < 4 ; ++i )																		// Each direction check
			{																									// bBreak ? a : b means if break, can go? = a, if not break, is it short?
				if ( ( iRow + irgTemp1 [ i ] >= 0 ) && ( iRow + irgTemp1 [ i ] < g_iRowCnt )
						&& ( iColumn + irgTemp2 [ i ] >= 0 ) && ( iColumn + irgTemp2 [ i ] < g_iColumnCnt )
						&& ( bBreak ? g_idrgMap [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] % 2 == 0 : g_idrgMap [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] < 2 ) )
				{
					if ( ! bBreak )																				// Didn't break wall yet
					{
						if ( -1 == g_idrgMap [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] )			// Pillar exist, I have to break
						{
							TempInfo = new cInfo ( iRow + irgTemp1 [ i ] , iColumn + irgTemp2 [ i ] , true ) ;
							g_itrgRoute [ 1 ] [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] = Integer.min ( iCurrentLength + 1 , g_itrgRoute [ 1 ] [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] ) ;
						}
						else																					// Same as 1 == ..., because Ma < 2 is condition
						{
							TempInfo = new cInfo ( iRow + irgTemp1 [ i ] , iColumn + irgTemp2 [ i ] , false ) ;
							g_itrgRoute [ 0 ] [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] = Integer.min ( iCurrentLength + 1 , g_itrgRoute [ 0 ] [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] ) ;
							g_idrgMap [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] = 3 ;				// Before I break and pass, but I didn't pass without break. So set 3
						}
						
						queue.add ( TempInfo ) ;
					}
					else if ( -1 != g_idrgMap [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] )			// In fact, this is wrong. Map % 2 == 0, -1 can't be here.
					{																							// It can be just else
						TempInfo = new cInfo ( iRow + irgTemp1 [ i ] , iColumn + irgTemp2 [ i ] , true ) ;
						
						g_idrgMap [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] += 1 ;					// If clean road(0), I pass with breaking. 1.
						g_itrgRoute [ iBreakCheck ] [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] =	// If passed without breaking(2), I go. So set 3
								Integer.min ( iCurrentLength + 1 , g_itrgRoute [ iBreakCheck ] [ iRow + irgTemp1 [ i ] ] [ iColumn + irgTemp2 [ i ] ] ) ;
						
						queue.add ( TempInfo ) ;
					}
				}
			}
		}
	}
}