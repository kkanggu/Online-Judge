import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



public class OJ_2606_Virus
{
	static int g_iVertexCnt ;
	static boolean [] g_brgVisit ;
	static boolean [] [] g_bdrgEdge ;
	static int g_VirusCnt ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st ;
		g_iVertexCnt = Integer.parseInt ( br.readLine () ) ;
		int iEdgeCnt = Integer.parseInt ( br.readLine () ) ;
		g_brgVisit = new boolean [ g_iVertexCnt ] ;
		g_bdrgEdge = new boolean [ g_iVertexCnt ][ g_iVertexCnt ] ;
		g_VirusCnt = -1 ;
		
		
		
		for ( int i = 0 ; i < iEdgeCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			int iTemp1 = Integer.parseInt ( st.nextToken () ) - 1 ;
			int iTemp2 = Integer.parseInt ( st.nextToken () ) - 1 ;
			
			g_bdrgEdge [ iTemp1 ] [ iTemp2 ] = true ;
			g_bdrgEdge [ iTemp2 ] [ iTemp1 ] = true ;
		}
		
		DFS ( 0 ) ;
		
		System.out.println ( g_VirusCnt ) ;
	}
	
	static void DFS ( int iStartVertex )
	{
		g_brgVisit [ iStartVertex ] = true ;
		++ g_VirusCnt ;
		
		for ( int i = 0 ; i < g_iVertexCnt ; ++i )
		{
			if ( ( g_bdrgEdge [ iStartVertex ] [ i ] ) && ( ! g_brgVisit [ i ] ) )
			{
				DFS ( i ) ;
			}
		}
	}
}