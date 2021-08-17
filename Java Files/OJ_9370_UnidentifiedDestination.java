import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;



public class OJ_9370_UnidentifiedDestination
{
	static int g_iVertexCnt ;
	static int g_iEdgeCnt ;
	static int g_iDestCnt ;
	static int [] g_irgPath ;							// If odd, passed. If even, not passed.
	static int [] g_irgDest ;
	static ArrayList < cInfo >[] g_alrgEdge ;
	static int g_iFirstVertex ;
	static int g_iSecondVertex ;
	
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st ;
		StringBuilder sb = new StringBuilder () ;
		int iCnt = Integer.parseInt ( br.readLine () ) ;
		int iStartVertex = 0 ;
		
		
		for ( int i = 0 ; i < iCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			g_iVertexCnt = Integer.parseInt ( st.nextToken () ) ;
			g_iEdgeCnt = Integer.parseInt ( st.nextToken () ) ;
			g_iDestCnt = Integer.parseInt ( st.nextToken () ) ;
			
			st = new StringTokenizer ( br.readLine () ) ;
			iStartVertex = Integer.parseInt ( st.nextToken () ) - 1 ;
			g_iFirstVertex = Integer.parseInt ( st.nextToken () ) - 1 ;
			g_iSecondVertex = Integer.parseInt ( st.nextToken () ) - 1 ;
			
			g_irgPath = new int [ g_iVertexCnt ] ;
			g_alrgEdge = new ArrayList [ g_iVertexCnt ] ;
			g_irgDest = new int [ g_iDestCnt ] ;
			
			Arrays.fill ( g_irgPath , Integer.MAX_VALUE / 2 * 2 ) ;
			
			
			for ( int j = 0 ; j < g_iVertexCnt ; ++j )
			{
				g_alrgEdge [ j ] = new ArrayList <> ();
			}
			for ( int j = 0 ; j < g_iEdgeCnt ; ++j )
			{
				int iStart = 0 ;
				int iEnd = 0 ;
				int iLength = 0 ;
				
				
				st = new StringTokenizer ( br.readLine () ) ;
				iStart = Integer.parseInt ( st.nextToken () ) - 1 ;
				iEnd = Integer.parseInt ( st.nextToken () ) - 1 ;
				iLength = Integer.parseInt ( st.nextToken () ) * 2 ;
				
				if ( ( g_iFirstVertex == iStart && g_iSecondVertex == iEnd ) || ( g_iFirstVertex == iEnd && g_iSecondVertex == iStart ) )
				{
					-- iLength ;
				}
				
				g_alrgEdge [ iStart ].add ( new cInfo ( iEnd , iLength ) ) ;
				g_alrgEdge [ iEnd ].add ( new cInfo ( iStart , iLength ) ) ;
			}
			for ( int j = 0 ; j < g_iDestCnt ; ++j )
			{
				g_irgDest [ j ] = Integer.parseInt ( br.readLine () ) - 1 ;
			}
			
			Arrays.sort ( g_irgDest ) ;
			
			g_irgPath [ iStartVertex ] = 0 ;
			
			doDijkstra ( iStartVertex ) ;
			
			
			for ( int j = 0 ; j < g_iDestCnt ; ++j )
			{
				if ( g_irgPath [ g_irgDest [ j ] ] % 2 == 1 )
				{
					sb.append ( g_irgDest [ j ] + 1 ) ;
					sb.append ( ' ' ) ;
				}
			}
			
			
			sb.append ( '\n' ) ;
		}
		
		
		System.out.println ( sb ) ;
	}
	
	public static void doDijkstra ( int iStartVertex )
	{
		PriorityQueue < cInfo > pq = new PriorityQueue <> () ;
		cInfo cVertex ;
		cInfo cGetEdge ;
		cInfo cTemp ;
		
		
		
		pq.add ( new cInfo ( iStartVertex , 0 ) ) ;
		
		
		while ( ! pq.isEmpty () )
		{
			do
			{
				cVertex = pq.poll () ;
			}
			while ( cVertex.m_iLength != g_irgPath [ cVertex.m_iVertex ] && ! pq.isEmpty () ) ;
			
			if ( null != cVertex )
			{
				for ( int i = 0 ; i < g_alrgEdge[ cVertex.m_iVertex ].size () ; ++i )
				{
					cGetEdge = g_alrgEdge [ cVertex.m_iVertex ].get ( i ) ;
					cTemp = new cInfo ( cGetEdge ) ;
					cTemp.m_iLength += cVertex.m_iLength ;
					
					
					if ( cTemp.m_iLength < g_irgPath [ cTemp.m_iVertex ] )
					{
						g_irgPath [ cTemp.m_iVertex ] = cTemp.m_iLength ;
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