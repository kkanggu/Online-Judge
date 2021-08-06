import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;



public class OJ_1260_DFSandBFS
{
	static int g_iVertexCnt ;
	static boolean [] g_brgVisit ;
	static boolean [] [] g_bdrgEdge ;
	static StringBuilder sb ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		g_iVertexCnt = Integer.parseInt ( st.nextToken () ) ;
		int iEdgeCnt = Integer.parseInt ( st.nextToken () ) ;
		int iStartVertx = Integer.parseInt ( st.nextToken () ) - 1 ;
		g_brgVisit = new boolean [ g_iVertexCnt ] ;
		g_bdrgEdge = new boolean [ g_iVertexCnt ][ g_iVertexCnt ] ;
		sb = new StringBuilder () ;
		
		
		
		for ( int i = 0 ; i < iEdgeCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			int iTemp1 = Integer.parseInt ( st.nextToken () ) - 1 ;
			int iTemp2 = Integer.parseInt ( st.nextToken () ) - 1 ;
			
			g_bdrgEdge [ iTemp1 ] [ iTemp2 ] = true ;
			g_bdrgEdge [ iTemp2 ] [ iTemp1 ] = true ;
		}
		
		DFS ( iStartVertx ) ;
		sb.append ( "\n" ) ;
		
		Arrays.fill ( g_brgVisit , false ) ;
		
		BFS ( iStartVertx ) ;
		System.out.println ( sb ) ;
	}
	
	static void DFS ( int iStartVertex )
	{
		g_brgVisit [ iStartVertex ] = true ;
		sb.append ( iStartVertex + 1 + " " ) ;
		
		for ( int i = 0 ; i < g_iVertexCnt ; ++i )
		{
			if ( ( g_bdrgEdge [ iStartVertex ] [ i ] ) && ( ! g_brgVisit [ i ] ) )
			{
				DFS ( i ) ;
			}
		}
	}
	
	static void BFS ( int iStartVertex )
	{
		Queue < Integer > queue = new LinkedList <> () ;
		int iVertex = 0 ;
		
		
		
		queue.add ( iStartVertex ) ;
		g_brgVisit [ iStartVertex ] = true ;
		sb.append ( iStartVertex + 1 + " " ) ;
		
		
		while ( ! queue.isEmpty () )
		{
			iVertex = queue.poll () ;
			
			for ( int i = 0 ; i < g_iVertexCnt ; ++i )
			{
				if ( ( g_bdrgEdge [ iVertex ] [ i ] ) && ( ! g_brgVisit [ i ] ) )
				{
					queue.add ( i ) ;
					g_brgVisit [ i ] = true ;
					sb.append ( i + 1 + " " ) ;
				}
			}
		}
	}
}