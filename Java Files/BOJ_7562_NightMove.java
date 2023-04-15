import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;



public class OJ_7562_NightMove
{
	static boolean [] [] g_bdrgMap ;
	static int [] [] g_idrgMove ;
	static int g_iLength ;
	
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		StringBuilder sb = new StringBuilder () ;
		int iCnt = Integer.parseInt ( st.nextToken () ) ;
		int iStartX = 0 ;
		int iStartY = 0 ;
		int iEndX = 0 ;
		int iEndY = 0 ;
		
		
		
		for ( int i = 0 ; i < iCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			g_iLength = Integer.parseInt ( st.nextToken () ) ;
			st = new StringTokenizer ( br.readLine () ) ;
			iStartX = Integer.parseInt ( st.nextToken () ) ;
			iStartY = Integer.parseInt ( st.nextToken () ) ;
			st = new StringTokenizer ( br.readLine () ) ;
			iEndX = Integer.parseInt ( st.nextToken () ) ;
			iEndY = Integer.parseInt ( st.nextToken () ) ;
			
			g_bdrgMap = new boolean [ g_iLength ] [ g_iLength ] ;
			g_idrgMove = new int [ g_iLength ] [ g_iLength ] ;
			
			for ( int j = 0 ; j < g_iLength ; ++j )
			{
				Arrays.fill ( g_idrgMove [ j ] , Integer.MAX_VALUE ) ;
			}
			
			getNightMove ( iStartX , iStartY ) ;
			sb.append ( g_idrgMove [ iEndX ] [ iEndY ] + "\n" ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	static void getNightMove ( int iStartX , int iStartY )
	{
		int iX ;
		int iY ;
		Queue < Integer > queue = new LinkedList <> () ;
		int [] iTempMove1 = { -2 , -2 , -1 , -1 , 1 , 1 , 2 , 2 } ;
		int [] iTempMove2 = { -1 , 1 , -2 , 2 , -2 , 2 , -1 , 1 } ;
		int iLength ;
		
		
		
		g_bdrgMap [ iStartX ] [ iStartY ] = true ;
		g_idrgMove [ iStartX ] [ iStartY ] = 0 ;
		queue.add ( iStartX * g_iLength + iStartY ) ;
		
		
		while ( ! queue.isEmpty () )
		{
			iX = queue.poll () ;
			iY = iX % g_iLength ;
			iX /= g_iLength ;
			iLength = g_idrgMove [ iX ] [ iY ] ;
			
			
			for ( int i = 0 ; i < 8 ; ++i )
			{
				if ( bValid ( iX + iTempMove1 [ i ] , iY + iTempMove2 [ i ] ) )
				{
					g_idrgMove [ iX + iTempMove1 [ i ] ] [ iY + iTempMove2 [ i ] ] = iLength + 1 ;
					g_bdrgMap [ iX + iTempMove1 [ i ] ] [ iY + iTempMove2 [ i ] ] = true ;
					
					queue.add ( ( iX + iTempMove1 [ i ] ) * g_iLength + iY + iTempMove2 [ i ] ) ;
				}
			}
		}
	}
	
	static boolean bValid ( int iX , int iY )
	{
		return ( iX >= 0 ) && ( iX <= g_iLength - 1 ) && ( iY >= 0 ) && ( iY <= g_iLength - 1 ) && ! g_bdrgMap [ iX ] [ iY ] ;
	}
}
