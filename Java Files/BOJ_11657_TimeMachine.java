import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;



public class OJ_11657_TimeMachine
{
	static int g_iVertexCnt ;
	static int g_iEdgeCnt ;
	static long [] g_lrgPath ;
	static ArrayList < cInfo > g_alEdge ;
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
		g_lrgPath = new long [ g_iVertexCnt ] ;
		g_alEdge = new ArrayList <> () ;
		g_bVisit = new boolean [ g_iVertexCnt ] ;
		
		
		
		Arrays.fill ( g_lrgPath , Long.MAX_VALUE ) ;
		
		
		for ( int i = 0 ; i < g_iEdgeCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			int iStart = Integer.parseInt ( st.nextToken () ) - 1 ;
			int iEnd = Integer.parseInt ( st.nextToken () ) - 1 ;
			int iLength = Integer.parseInt ( st.nextToken () ) ;
			
			g_alEdge.add ( new cInfo ( iStart , iEnd , iLength ) ) ;
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
				sb.append ( g_lrgPath [ i ] != Long.MAX_VALUE ? g_lrgPath [ i ] : -1 ) ;
				sb.append ( '\n' ) ;
			}
		}
		
		
		System.out.println ( sb ) ;
	}
	
	public static void doBellmanFord ()
	{
		cInfo cEdge ;
		int iStart = 0 ;
		int iEnd = 0 ;
		long lLength = 0 ;
		
		
		
		g_lrgPath [ 0 ] = 0 ;
		
		
		for ( int i = 0 ; i < g_iVertexCnt - 1 ; ++i )
		{
			for ( int j = 0 ; j < g_alEdge.size () ; ++j )
			{
				cEdge = g_alEdge.get ( j ) ;
				iStart = cEdge.m_iStartVertex ;
				iEnd = cEdge.m_iEndVertex ;
				lLength = cEdge.m_lLength ;
				
				
				if ( ( g_lrgPath [ iStart ] != Long.MAX_VALUE ) && ( g_lrgPath [ iStart ] + lLength < g_lrgPath [ iEnd ] ) )
				{
					g_lrgPath [ iEnd ] = g_lrgPath [ iStart ] + lLength ;
				}
			}
		}
		for ( int i = 0 ; i < g_alEdge.size () ; ++i )																				// Check the cycle
		{
			cEdge = g_alEdge.get ( i ) ;
			iStart = cEdge.m_iStartVertex ;
			iEnd = cEdge.m_iEndVertex ;
			lLength = cEdge.m_lLength ;
			
			
			if ( ( g_lrgPath [ iStart ] != Long.MAX_VALUE ) && ( g_lrgPath [ iStart ] + lLength < g_lrgPath [ iEnd ] ) )			// Cycle exist
			{
				System.out.println ( -1 ) ;
				System.exit ( 0 ) ;
			}
		}
	}
	
	static class cInfo implements Comparable < cInfo >
	{
		int m_iStartVertex ;
		int m_iEndVertex ;
		Long m_lLength ;
		
		public cInfo ( int iStartVertex , int iEndVertex , long lLength )
		{
			m_iStartVertex = iStartVertex ;
			m_iEndVertex = iEndVertex ;
			m_lLength = lLength ;
		}
		
		@Override
		public int compareTo ( cInfo cCompare )
		{
			return ( int ) ( this.m_lLength - cCompare.m_lLength ) ;

//			if ( this.m_lLength < cCompare.m_lLength )
//			{
//				return this.m_lLength - cCompare.m_lLength ;
//			}
//
//			return this.m_iVertex - cCompare.m_iVertex ;
		}
	}
}