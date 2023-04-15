import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;



public class OJ_7569_Tomato3D
{
	static int g_iRowCnt ;
	static int g_iColumnCnt ;
	static int g_iHeightCnt ;
	static int [] [] [] g_itrgTomato ;							// 1 Ripen, 0 not yet, -1 not exist
	static int [] [] [] g_itrgDayPassed ;						// The Day passed to ripen tomato
	static Queue < Integer > queue = new LinkedList <> () ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		g_iColumnCnt = Integer.parseInt ( st.nextToken () ) ;
		g_iRowCnt = Integer.parseInt ( st.nextToken () ) ;
		g_iHeightCnt = Integer.parseInt ( st.nextToken () ) ;
		g_itrgTomato = new int [ g_iHeightCnt ] [ g_iRowCnt ][ g_iColumnCnt ] ;
		g_itrgDayPassed = new int [ g_iHeightCnt ] [ g_iRowCnt ] [ g_iColumnCnt ] ;
		int iCnt = 0 ;
		
		
		
		for ( int h = 0 ; h < g_iHeightCnt ; h++ )
		{
			for ( int i = 0 ; i < g_iRowCnt ; ++i )
			{
				Arrays.fill ( g_itrgDayPassed [ h ] [ i ] , Integer.MAX_VALUE ) ;
				g_itrgTomato [ h ] [ i ] = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
				
				for ( int j = 0 ; j < g_iColumnCnt ; ++j )
				{
					if ( 1 == g_itrgTomato [ h ] [ i ] [ j ] )
					{
						g_itrgDayPassed [ h ] [ i ] [ j ] = 0 ;
						queue.add ( h * g_iRowCnt * g_iColumnCnt + i * g_iColumnCnt + j ) ;
					}
				}
			}
		}
		
		
		getRipeTomato (); ;
		
		for ( int h = 0 ; h < g_iHeightCnt ; h++ )
		{
			for ( int i = 0 ; i < g_iRowCnt ; i++ )
			{
				for ( int j = 0 ; j < g_iColumnCnt ; j++ )
				{
					if ( Integer.MAX_VALUE != g_itrgDayPassed [ h ] [ i ] [ j ] )
					{
						iCnt = Integer.max ( iCnt , g_itrgDayPassed [ h ] [ i ] [ j ] ) ;
					}
					else if ( 0 == g_itrgTomato [ h ] [ i ] [ j ])
					{
						System.out.println ( -1 ) ;
						
						System.exit ( 0 ) ;
					}
				}
			}
		}
		
		
		System.out.println ( iCnt ) ;
	}
	
	static void getRipeTomato ()
	{
		int iCurrentLength = 0 ;
		int iRow = 0 ;
		int iHeight = 0 ;
		int iColumn = 0 ;
		
		
		
		while ( ! queue.isEmpty () )
		{
			iHeight = queue.poll () ;
			iRow = iHeight / g_iColumnCnt % g_iRowCnt ;
			iColumn = iHeight % g_iColumnCnt ;
			iHeight /= g_iRowCnt * g_iColumnCnt ;
			iCurrentLength = g_itrgDayPassed [ iHeight ] [ iRow ] [ iColumn ] ;
			
			
			if ( ( iRow != 0 ) && ( 0 == g_itrgTomato [ iHeight ] [ iRow - 1 ] [ iColumn ] ) )
			{
				g_itrgDayPassed [ iHeight ] [ iRow - 1 ] [ iColumn ] = Integer.min ( iCurrentLength + 1 , g_itrgDayPassed [ iHeight ] [ iRow - 1 ] [ iColumn ] ) ;
				g_itrgTomato [ iHeight ] [ iRow - 1 ] [ iColumn ] = 1 ;
				
				queue.add ( iHeight * g_iRowCnt * g_iColumnCnt + ( iRow - 1 ) * g_iColumnCnt + iColumn ) ;
			}
			if ( ( iRow != g_iRowCnt - 1 ) && ( 0 == g_itrgTomato [ iHeight ] [ iRow + 1 ] [ iColumn ] ) )
			{
				g_itrgDayPassed [ iHeight ] [ iRow + 1 ] [ iColumn ] = Integer.min ( iCurrentLength + 1 , g_itrgDayPassed [ iHeight ] [ iRow + 1 ] [ iColumn ] ) ;
				g_itrgTomato [ iHeight ] [ iRow + 1 ] [ iColumn ] = 1 ;
				
				queue.add ( iHeight * g_iRowCnt * g_iColumnCnt + ( iRow + 1 ) * g_iColumnCnt + iColumn ) ;
			}
			if ( ( iColumn != 0 ) && ( 0 == g_itrgTomato [ iHeight ] [ iRow ] [ iColumn - 1 ] ) )
			{
				g_itrgDayPassed [ iHeight ] [ iRow ] [ iColumn - 1 ] = Integer.min ( iCurrentLength + 1 , g_itrgDayPassed [ iHeight ] [ iRow ] [ iColumn - 1 ] ) ;
				g_itrgTomato [ iHeight ] [ iRow ] [ iColumn - 1 ] = 1 ;
				
				queue.add ( iHeight * g_iRowCnt * g_iColumnCnt + iRow * g_iColumnCnt + iColumn - 1 ) ;
			}
			if ( ( iColumn != g_iColumnCnt - 1 ) && ( 0 == g_itrgTomato [ iHeight ] [ iRow ] [ iColumn + 1 ] ) )
			{
				g_itrgDayPassed [ iHeight ] [ iRow ] [ iColumn + 1 ] = Integer.min ( iCurrentLength + 1 , g_itrgDayPassed [ iHeight ] [ iRow ] [ iColumn + 1 ] ) ;
				g_itrgTomato [ iHeight ] [ iRow ] [ iColumn + 1 ] = 1 ;
				
				queue.add ( iHeight * g_iRowCnt * g_iColumnCnt + iRow * g_iColumnCnt + iColumn + 1 ) ;
			}
			if ( ( iHeight != 0 ) && ( 0 == g_itrgTomato [ iHeight - 1 ] [ iRow ] [ iColumn ] ) )
			{
				g_itrgDayPassed [ iHeight - 1 ] [ iRow ] [ iColumn ] = Integer.min ( iCurrentLength + 1 , g_itrgDayPassed [ iHeight - 1 ] [ iRow ] [ iColumn ] ) ;
				g_itrgTomato [ iHeight - 1 ] [ iRow ] [ iColumn ] = 1 ;
				
				queue.add ( ( iHeight - 1 ) * g_iRowCnt * g_iColumnCnt + iRow * g_iColumnCnt + iColumn ) ;
			}
			if ( ( iHeight != g_iHeightCnt - 1 ) && ( 0 == g_itrgTomato [ iHeight + 1 ] [ iRow ] [ iColumn ] ) )
			{
				g_itrgDayPassed [ iHeight + 1 ] [ iRow ] [ iColumn ] = Integer.min ( iCurrentLength + 1 , g_itrgDayPassed [ iHeight + 1 ] [ iRow ] [ iColumn ] ) ;
				g_itrgTomato [ iHeight + 1 ] [ iRow ] [ iColumn ] = 1 ;
				
				queue.add ( ( iHeight + 1 ) * g_iRowCnt * g_iColumnCnt + iRow * g_iColumnCnt + iColumn ) ;
			}
		}
	}
}