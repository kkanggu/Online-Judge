import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;



public class OJ_2178_MazeSeek
{
	static int g_iRowCnt ;
	static int g_iColumnCnt ;
	static boolean [] [] g_bdrgMaze ;
	static int [] [] g_idrgRoute ;						// The length to point
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		g_iRowCnt = Integer.parseInt ( st.nextToken () ) ;
		g_iColumnCnt = Integer.parseInt ( st.nextToken () ) ;
		g_bdrgMaze = new boolean [ g_iRowCnt ][ g_iColumnCnt ] ;
		g_idrgRoute = new int [ g_iRowCnt ] [ g_iColumnCnt ] ;
		
		
		
		for ( int i = 0 ; i < g_iRowCnt ; ++i )
		{
			Arrays.fill ( g_idrgRoute [ i ] , Integer.MAX_VALUE ) ;
			String str = br.readLine () ;
			
			for ( int j = 0 ; j < g_iColumnCnt ; ++j )
			{
				if ( '0' == str.charAt ( j ) )
				{
					g_bdrgMaze [ i ] [ j ] = false ;
				}
				else
				{
					g_bdrgMaze [ i ] [ j ] = true ;
				}
			}
		}
		
		getMazeShortcutLength () ;
		
		System.out.println ( g_idrgRoute [ g_iRowCnt - 1 ] [ g_iColumnCnt - 1 ] ) ;
	}
	
	static void getMazeShortcutLength ()
	{
		int iCurrentLength = 0 ;
		int iRow = 0 ;
		int iColumn = 0 ;
		Queue < Integer > queue = new LinkedList <> () ;
		
		
		
		g_idrgRoute [ 0 ] [ 0 ] = 1 ;
		g_bdrgMaze [ 0 ] [ 0 ] = false ;
		
		queue.add ( iRow * g_iColumnCnt + iColumn ) ;
		
		while ( ! queue.isEmpty () )
		{
			iRow = queue.poll () ;
			iColumn = iRow % g_iColumnCnt ;
			iRow /= g_iColumnCnt ;
			iCurrentLength = g_idrgRoute [ iRow ] [ iColumn ] ;
			
			
			if ( ( iRow != 0 ) && ( g_bdrgMaze [ iRow - 1 ] [ iColumn ] ) )
			{
				g_idrgRoute [ iRow - 1 ] [ iColumn ] = Integer.min ( iCurrentLength + 1 , g_idrgRoute [ iRow - 1 ] [ iColumn ] ) ;
				g_bdrgMaze [ iRow - 1 ] [ iColumn ] = false	;
				
				queue.add ( ( iRow - 1 ) * g_iColumnCnt + iColumn ) ;
			}
			if ( ( iRow != g_iRowCnt - 1 ) && ( g_bdrgMaze [ iRow + 1 ] [ iColumn ] ) )
			{
				g_idrgRoute [ iRow + 1 ] [ iColumn ] = Integer.min ( iCurrentLength + 1 , g_idrgRoute [ iRow + 1 ] [ iColumn ] ) ;
				g_bdrgMaze [ iRow + 1 ] [ iColumn ] = false	;
				
				queue.add ( ( iRow + 1 ) * g_iColumnCnt + iColumn ) ;
			}
			if ( ( iColumn != 0 ) && ( g_bdrgMaze [ iRow ] [ iColumn - 1 ] ) )
			{
				g_idrgRoute [ iRow ] [ iColumn - 1 ] = Integer.min ( iCurrentLength + 1 , g_idrgRoute [ iRow ] [ iColumn - 1 ] ) ;
				g_bdrgMaze [ iRow ] [ iColumn - 1 ] = false	;
				
				queue.add ( iRow * g_iColumnCnt + iColumn - 1 ) ;
			}
			if ( ( iColumn != g_iColumnCnt - 1 ) && ( g_bdrgMaze [ iRow ] [ iColumn + 1 ] ) )
			{
				g_idrgRoute [ iRow ] [ iColumn + 1 ] = Integer.min ( iCurrentLength + 1 , g_idrgRoute [ iRow ] [ iColumn + 1 ] ) ;
				g_bdrgMaze [ iRow ] [ iColumn + 1 ] = false	;
				
				queue.add ( iRow * g_iColumnCnt + iColumn + 1 ) ;
			}
		}
	}
}