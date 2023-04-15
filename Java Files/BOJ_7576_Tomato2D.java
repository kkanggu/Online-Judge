import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;



public class OJ_7576_Tomato
{
	static int g_iRowCnt ;
	static int g_iColumnCnt ;
	static int [] [] g_idrgTomato ;							// 1 Ripen, 0 not yet, -1 not exist
	static int [] [] g_idrgDayPassed ;						// The Day passed to ripen tomato
	static Queue < Integer > queue = new LinkedList <> () ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		g_iColumnCnt = Integer.parseInt ( st.nextToken () ) ;
		g_iRowCnt = Integer.parseInt ( st.nextToken () ) ;
		g_idrgTomato = new int [ g_iRowCnt ][ g_iColumnCnt ] ;
		g_idrgDayPassed = new int [ g_iRowCnt ] [ g_iColumnCnt ] ;
		int iCnt = 0 ;
		
		
		
		for ( int i = 0 ; i < g_iRowCnt ; ++i )
		{
			Arrays.fill ( g_idrgDayPassed [ i ] , Integer.MAX_VALUE ) ;
			g_idrgTomato [ i ] = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
			
			for ( int j = 0 ; j < g_iColumnCnt ; ++j )
			{
				if ( 1 == g_idrgTomato [ i ] [ j ] )
				{
					g_idrgDayPassed [ i ] [ j ] = 0 ;
					queue.add ( i * g_iColumnCnt + j ) ;
				}
			}
		}
		
		getRipeTomato (); ;
		
		for ( int i = 0 ; i < g_iRowCnt ; i++ )
		{
			for ( int j = 0 ; j < g_iColumnCnt ; j++ )
			{
				if ( Integer.MAX_VALUE != g_idrgDayPassed [ i ] [ j ] )
				{
					iCnt = Integer.max ( iCnt , g_idrgDayPassed [ i ] [ j ] ) ;
				}
				else if ( 0 == g_idrgTomato [ i ] [ j ])
				{
					System.out.println ( -1 ) ;
					
					System.exit ( 0 ) ;
				}
			}
		}
		
		System.out.println ( iCnt ) ;
	}
	
	static void getRipeTomato ()
	{
		int iCurrentLength = 0 ;
		int iRow = 0 ;
		int iColumn = 0 ;
		
		
		
		while ( ! queue.isEmpty () )
		{
			iRow = queue.poll () ;
			iColumn = iRow % g_iColumnCnt ;
			iRow /= g_iColumnCnt ;
			iCurrentLength = g_idrgDayPassed [ iRow ] [ iColumn ] ;
			
			
			if ( ( iRow != 0 ) && ( 0 == g_idrgTomato [ iRow - 1 ] [ iColumn ] ) )
			{
				g_idrgDayPassed [ iRow - 1 ] [ iColumn ] = Integer.min ( iCurrentLength + 1 , g_idrgDayPassed [ iRow - 1 ] [ iColumn ] ) ;
				g_idrgTomato [ iRow - 1 ] [ iColumn ] = 1 ;
				
				queue.add ( ( iRow - 1 ) * g_iColumnCnt + iColumn ) ;
			}
			if ( ( iRow != g_iRowCnt - 1 ) && ( 0 == g_idrgTomato [ iRow + 1 ] [ iColumn ] ) )
			{
				g_idrgDayPassed [ iRow + 1 ] [ iColumn ] = Integer.min ( iCurrentLength + 1 , g_idrgDayPassed [ iRow + 1 ] [ iColumn ] ) ;
				g_idrgTomato [ iRow + 1 ] [ iColumn ] = 1 ;
				
				queue.add ( ( iRow + 1 ) * g_iColumnCnt + iColumn ) ;
			}
			if ( ( iColumn != 0 ) && ( 0 == g_idrgTomato [ iRow ] [ iColumn - 1 ] ) )
			{
				g_idrgDayPassed [ iRow ] [ iColumn - 1 ] = Integer.min ( iCurrentLength + 1 , g_idrgDayPassed [ iRow ] [ iColumn - 1 ] ) ;
				g_idrgTomato [ iRow ] [ iColumn - 1 ] = 1 ;
				
				queue.add ( iRow * g_iColumnCnt + iColumn - 1 ) ;
			}
			if ( ( iColumn != g_iColumnCnt - 1 ) && ( 0 == g_idrgTomato [ iRow ] [ iColumn + 1 ] ) )
			{
				g_idrgDayPassed [ iRow ] [ iColumn + 1 ] = Integer.min ( iCurrentLength + 1 , g_idrgDayPassed [ iRow ] [ iColumn + 1 ] ) ;
				g_idrgTomato [ iRow ] [ iColumn + 1 ] = 1 ;
				
				queue.add ( iRow * g_iColumnCnt + iColumn + 1 ) ;
			}
		}
	}
}