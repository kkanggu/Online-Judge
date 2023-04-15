import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.Vector;



public class OJ_1707_BipartiteGraph_BFS
{
	static int [] g_irgVertexVisit ;							// 0 Not, 1 Set 1, -1 Set 2
	static Vector < Integer > [] g_vrgEdgeExist ;
	static int g_iVertexCnt ;
	static int g_iEdgeCnt ;
	
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		StringBuilder sb = new StringBuilder () ;
		int iCnt = Integer.parseInt ( st.nextToken () ) ;
		int iTemp1 = 0 ;
		int iTemp2 = 0 ;
		
		
		
		for ( int i = 0 ; i < iCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			g_iVertexCnt = Integer.parseInt ( st.nextToken () ) ;
			g_iEdgeCnt = Integer.parseInt ( st.nextToken () ) ;
			
			g_irgVertexVisit = new int [ g_iVertexCnt ] ;
			g_vrgEdgeExist = new Vector [ g_iVertexCnt ] ;
			
			
			for ( int j = 0 ; j < g_iVertexCnt ; ++j )
			{
				g_vrgEdgeExist [ j ] = new Vector <> () ;
			}
			for ( int j = 0 ; j < g_iEdgeCnt ; ++j )
			{
				st = new StringTokenizer ( br.readLine () ) ;
				iTemp1 = Integer.parseInt ( st.nextToken () ) - 1 ;
				iTemp2 = Integer.parseInt ( st.nextToken () ) - 1 ;
				
				g_vrgEdgeExist [ iTemp1 ].add ( iTemp2 ) ;
				g_vrgEdgeExist [ iTemp2 ].add ( iTemp1 ) ;
			}
			
			sb.append ( bBipartite () ? "YES\n" : "NO\n" ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	static boolean bBipartite ()
	{
		int iVertex = 0 ;
		Queue < Integer > queue = new LinkedList <> () ;
		int iSetDivision = 1 ;
		
		
		
		g_irgVertexVisit [ iVertex ] = 1 ;
		queue.add ( iVertex ) ;
		
		
		for ( int i = 0 ; i < g_iVertexCnt ; ++i )
		{
			if ( ( ! g_vrgEdgeExist [ i ].isEmpty () ) && ( 0 == g_irgVertexVisit [ i ] ) )
			{
				queue.add ( i ) ;
				g_irgVertexVisit [ i ] = 1 ;
			}
			
			while ( ! queue.isEmpty () )
			{
				iVertex = queue.poll () ;
				iSetDivision = g_irgVertexVisit [ iVertex ] ;
				
				
				for ( int j = 0 ; j < g_iVertexCnt ; ++j )
				{
					if ( g_vrgEdgeExist [ iVertex ].contains ( j ) )
					{
						if ( iSetDivision == g_irgVertexVisit [ j ] )			// Have to be different
						{
							return false ;
						}
						else if ( 0 == g_irgVertexVisit [ j ] )
						{
							g_irgVertexVisit [ j ] = iSetDivision * -1 ;
							g_vrgEdgeExist [ iVertex ].removeElement ( j ) ;
							g_vrgEdgeExist [ j ].removeElement ( iVertex ) ;
							-- g_iEdgeCnt ;
							
							queue.add ( j ) ;
						}
					}
				}
			}
			
			if ( 0 == g_iEdgeCnt )
			{
				break ;
			}
		}
		
		return true ;
	}
}