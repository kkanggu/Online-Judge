import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;



public class OJ_11657_TimeMachine
{
	static int g_iVertexCnt ;
	static int g_iEdgeCnt ;
	static int [] g_irgPath ;
	static ArrayList < cInfo > [] g_alrgEdge ;
	static boolean g_bInf = false ;
	static boolean [] g_bVisit ;
	
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st ;
		StringBuilder sb = new StringBuilder () ;
		
		
		
		st = new StringTokenizer ( br.readLine () ) ;
		g_iVertexCnt = Integer.parseInt ( st.nextToken () ) ;
		g_iEdgeCnt = Integer.parseInt ( st.nextToken () ) ;
		g_irgPath = new int [ g_iVertexCnt ] ;
		g_alrgEdge = new ArrayList [ g_iVertexCnt ] ;
		g_bVisit = new boolean [ g_iVertexCnt ] ;
		
		Arrays.fill ( g_irgPath , Integer.MAX_VALUE ) ;
		
		
		for ( int j = 0 ; j < g_iVertexCnt ; ++j )
		{
			g_alrgEdge [ j ] = new ArrayList <> ();
		}
		for ( int i = 0 ; i < g_iEdgeCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			int iStart = Integer.parseInt ( st.nextToken () ) - 1 ;
			int iEnd = Integer.parseInt ( st.nextToken () ) - 1 ;
			int iLength = Integer.parseInt ( st.nextToken () ) ;
			
			g_alrgEdge [ iStart ].add ( new cInfo ( iEnd , iLength ) ) ;
		}
		
		doBellmanFord () ;
		
		
		if ( g_bInf )
		{
			sb.append ( -1 ) ;
		}
		else
		{
			for ( int i = 1 ; i < g_iVertexCnt ; ++i )
			{
				sb.append ( g_irgPath [ i ] != Integer.MAX_VALUE ? g_irgPath [ i ] : -1 ) ;
				sb.append ( '\n' ) ;
			}
		}
		
		
		System.out.println ( sb ) ;
	}
	
	public static void doBellmanFord ()
	{
		PriorityQueue < cInfo > pq = new PriorityQueue <> () ;
		cInfo cEdge ;
		cInfo cCurrent ;
		int iCurrentLength = 0 ;
		
		
		
		pq.add ( new cInfo (  0 , 0 ) ) ;
		g_irgPath [ 0 ] = 0 ;
		
		
		for ( int i = 0 ; i < g_iVertexCnt ; ++i )
		{
			cCurrent = pq.poll () ;
			
			while ( null != cCurrent && g_bVisit [ cCurrent.m_iVertex ] )
			{
				cCurrent = pq.poll () ;
			}
			
			if ( pq.isEmpty () && null == cCurrent )
			{
				break ;
			}
			
			
			iCurrentLength = cCurrent.m_iLength ;
			
			g_bVisit [ cCurrent.m_iVertex ] = true ;
			
			
			for ( int j = 0 ; j < g_alrgEdge [ i ].size () ; ++j )
			{
				cEdge = g_alrgEdge [ cCurrent.m_iVertex ].get ( j ) ;
				
				
				if ( iCurrentLength + cEdge.m_iLength < g_irgPath [ cEdge.m_iVertex ] )
				{
					if ( g_bVisit [ cEdge.m_iVertex ] )
					{
						g_bInf = true ;
						
						break ;
					}
					
					g_irgPath [ cEdge.m_iVertex ] = iCurrentLength + cEdge.m_iLength ;
					pq.add ( new cInfo ( cEdge.m_iVertex , g_irgPath [ cEdge.m_iVertex ] ) ) ;
				}
			}
			
			if ( g_bInf )
			{
				break ;
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
		
		public cInfo ( cInfo cTemp )
		{
			m_iVertex = cTemp.m_iVertex ;
			m_iLength = cTemp.m_iLength ;
		}
		
		@Override
		public int compareTo ( cInfo cCompare )
		{
			return this.m_iLength - cCompare.m_iLength ;

//			if ( this.m_lLength < cCompare.m_lLength )
//			{
//				return this.m_lLength - cCompare.m_lLength ;
//			}
//
//			return this.m_iVertex - cCompare.m_iVertex ;
		}
	}
}