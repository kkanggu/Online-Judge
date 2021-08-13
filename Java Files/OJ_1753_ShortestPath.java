import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;



public class OJ_1753_ShortestPath
{
	static int g_iVertexCnt ;
	static int g_iEdgeCnt ;
	static int [] g_irgPath ;
	static boolean [] g_brgVisit ;
	static Queue < cInfo > [] g_qrgEdge ;
	
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st ;
		int iStartVertex = 0 ;
		StringBuilder sb = new StringBuilder () ;
		
		
		
		st = new StringTokenizer ( br.readLine () ) ;
		g_iVertexCnt = Integer.parseInt ( st.nextToken () ) ;
		g_iEdgeCnt = Integer.parseInt ( st.nextToken () ) ;
		iStartVertex = Integer.parseInt ( br.readLine () ) - 1 ;
		g_irgPath = new int [ g_iVertexCnt ] ;
		g_brgVisit = new boolean [ g_iVertexCnt ] ;
		g_qrgEdge = new Queue [ g_iVertexCnt ] ;
		
		
		Arrays.fill ( g_irgPath , Integer.MAX_VALUE ) ;
		g_irgPath [ iStartVertex ] = 0 ;
		
		for ( int i = 0 ; i < g_iVertexCnt ; ++i )
		{
			g_qrgEdge [ i ] = new LinkedList <> () ;
		}
		for ( int i = 0 ; i < g_iEdgeCnt ; ++i )
		{
			int iStart = 0 ;
			int iEnd = 0 ;
			int iLength = 0 ;
			
			
			st = new StringTokenizer ( br.readLine () ) ;
			iStart = Integer.parseInt ( st.nextToken () ) - 1 ;
			iEnd = Integer.parseInt ( st.nextToken () ) - 1 ;
			iLength = Integer.parseInt ( st.nextToken () ) ;
			
			cInfo cTemp = new cInfo ( iEnd , iLength ) ;
			g_qrgEdge [ iStart ].add ( cTemp ) ;
		}
		
		doDijkstra ( iStartVertex ) ;
		
		sb.append ( g_irgPath [ 0 ] != Integer.MAX_VALUE ? g_irgPath [ 0 ] : "INF" ) ;
		
		for ( int i = 1 ; i < g_iVertexCnt ; ++i )
		{
			sb.append ( "\n" ) ;
			sb.append ( g_irgPath [ i ] != Integer.MAX_VALUE ? g_irgPath [ i ] : "INF" ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	public static void doDijkstra ( int iStartVertex )
	{
		PriorityQueue < cInfo > pq = new PriorityQueue <> () ;
		cInfo cVertex ;
		cInfo cTemp ;
		
		
		
		pq.add ( new cInfo ( iStartVertex , 0 ) ) ;
		
		
		while ( ! pq.isEmpty () )
		{
			cVertex = pq.poll () ;
			
			while ( g_brgVisit [ cVertex.m_iVertex ] && ! pq.isEmpty () )
			{
				cVertex = pq.poll () ;
			}
			
			if ( null != cVertex )
			{
				g_brgVisit [ cVertex.m_iVertex ] = true ;
				
				while ( ! g_qrgEdge [ cVertex.m_iVertex ].isEmpty () )
				{
					cTemp = g_qrgEdge [ cVertex.m_iVertex ].poll () ;
					cTemp.m_iLength += g_irgPath [ cVertex.m_iVertex ] ;
					
					g_irgPath [ cTemp.m_iVertex ] = Integer.min ( g_irgPath [ cTemp.m_iVertex ] , cTemp.m_iLength ) ;
					
					if ( ! g_brgVisit [ cTemp.m_iVertex ] )
					{
						pq.add ( cTemp ) ;
					}
				}
			}
		}
	}
	
	static class cInfo implements Comparable < cInfo >
	{
		int m_iVertex ;
		int m_iLength ;
		
		public cInfo ( int iVertex , int iLength )
		{
			m_iVertex = iVertex ;
			m_iLength = iLength ;
		}
		
		@Override
		public int compareTo ( cInfo cCompare )
		{
			return this.m_iLength - cCompare.m_iLength ;
//			if ( this.m_iLength < cCompare.m_iLength )
//			{
//				return this.m_iLength - cCompare.m_iLength ;
//			}
//
//			return this.m_iVertex - cCompare.m_iVertex ;
		}
	}
}