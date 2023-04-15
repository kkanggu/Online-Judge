import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.Vector;



public class OJ_1707_BipartiteGraph_DFS
{
	static int [] g_irgVertexVisit ;							// 0 Not, 1 Set 1, -1 Set 2
	static Queue < Integer > [] g_qrgEdgeExist ;
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
		boolean bCheck = true ;
		
		
		
		for ( int i = 0 ; i < iCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			g_iVertexCnt = Integer.parseInt ( st.nextToken () ) ;
			g_iEdgeCnt = Integer.parseInt ( st.nextToken () ) ;
			bCheck = true ;
			
			g_irgVertexVisit = new int [ g_iVertexCnt ] ;
			g_qrgEdgeExist = new Queue [ g_iVertexCnt ] ;
			
			
			for ( int j = 0 ; j < g_iVertexCnt ; ++j )
			{
				g_qrgEdgeExist [ j ] = new LinkedList <> () ;
			}
			for ( int j = 0 ; j < g_iEdgeCnt ; ++j )
			{
				st = new StringTokenizer ( br.readLine () ) ;
				iTemp1 = Integer.parseInt ( st.nextToken () ) - 1 ;
				iTemp2 = Integer.parseInt ( st.nextToken () ) - 1 ;
				
				g_qrgEdgeExist [ iTemp1 ].add ( iTemp2 ) ;
				g_qrgEdgeExist [ iTemp2 ].add ( iTemp1 ) ;
			}
			for ( int j = 0 ; j < g_iVertexCnt ; ++j )
			{
				if ( ( ! g_qrgEdgeExist [ j ].isEmpty () ) && ( 0 == g_irgVertexVisit [ j ] ) )
				{
					if ( ! bBipartite ( j , 1 ) )
					{
						bCheck = false ;
						
						break ;
					}
				}
			}
			
			sb.append ( bCheck ? "YES\n" : "NO\n" ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	static boolean bBipartite ( int iVertex , int iVisit )
	{
		int iTemp = 0 ;
		boolean bCheck = true ;
		int iSetDivision = iVisit * -1 ;
		
		
		
		g_irgVertexVisit [ iVertex ] = iSetDivision ;
		
		while ( ! g_qrgEdgeExist [ iVertex ].isEmpty () && bCheck )
		{
			iTemp = g_qrgEdgeExist [ iVertex ].poll () ;
			
			if ( 0 == g_irgVertexVisit [ iTemp ] )
			{
				bCheck = bBipartite ( iTemp , iVisit * -1 ) ;
			}
			else if ( iSetDivision == g_irgVertexVisit [ iTemp ] )
			{
				bCheck = false ;
			}
		}
		
		
		return bCheck ;
	}
}