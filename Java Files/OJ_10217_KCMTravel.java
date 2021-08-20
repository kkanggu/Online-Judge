import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;



public class OJ_10217_KCMTravel
{
	static int g_iAirportCnt ;
	static int [] [] g_idrgCostTime ;									// [ End ] [ Cost ] = Time
	static ArrayList < cInfo >[] g_alrgTicket ;						// [ n ] n -> n + 1 ~ ... tickets.
	static int g_iLimitCost ;
	static boolean [] g_brgVisit ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st ;
		StringBuilder sb = new StringBuilder () ;
		int iTestCnt = Integer.parseInt ( br.readLine () ) ;
		int iFinalCost ;
		
		
		
		for ( int i = 0 ; i < iTestCnt ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			g_iAirportCnt = Integer.parseInt ( st.nextToken () ) ;
			g_iLimitCost = Integer.parseInt ( st.nextToken () ) ;
			int iTicket = Integer.parseInt ( st.nextToken () ) ;
			
			g_alrgTicket = new ArrayList [ g_iAirportCnt ] ;
			g_idrgCostTime = new int [ g_iAirportCnt ] [ g_iLimitCost + 1 ] ;
			g_brgVisit = new boolean [ g_iAirportCnt ] ;
			
			for ( int j = 0 ; j < g_iAirportCnt ; ++j )
			{
				g_alrgTicket [ j ] = new ArrayList <> () ;
				Arrays.fill ( g_idrgCostTime [ j ] , Integer.MAX_VALUE ) ;
			}
			for ( int j = 0 ; j < iTicket ; ++j )
			{
				st = new StringTokenizer ( br.readLine () ) ;
				int iStart = Integer.parseInt ( st.nextToken () ) - 1 ;
				int iEnd = Integer.parseInt ( st.nextToken () ) - 1 ;
				int iCost = Integer.parseInt ( st.nextToken () ) ;
				int iTime = Integer.parseInt ( st.nextToken () ) ;
				
				g_alrgTicket [ iStart ].add ( new cInfo ( iEnd , iCost , iTime ) ) ;
			}
			
			Arrays.fill ( g_idrgCostTime [ 0 ] , 0 ) ;
			
			getTravelTime () ;
			
			
			iFinalCost = g_idrgCostTime [ g_iAirportCnt - 1 ] [ 0 ] ;
			
			for ( int j = 1 ; j < g_iLimitCost + 1 ; j++ )
			{
				iFinalCost = Integer.min ( iFinalCost , g_idrgCostTime [ g_iAirportCnt - 1 ] [ j ] ) ;
			}
			if ( iFinalCost == Integer.MAX_VALUE )
			{
				sb.append ( "Poor KCM" ) ;
			}
			else
			{
				sb.append ( iFinalCost ) ;
			}
			
			sb.append ( '\n' ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	public static void getTravelTime ()
	{
		Queue < cInfo > pQueue = new LinkedList <> () ;
		cInfo cAirport ;
		cInfo cTicket ;
		int iStart ;
		int iEnd ;
		int iCost ;
		int iTime ;
		int iChangeStart ;
		int iChangeEnd ;
		int iNextStart = g_iLimitCost ;
		int iNextEnd = 0 ;
		boolean bChange = false ;
		
		
		
		pQueue.add ( new cInfo ( 0 , 0 , g_iLimitCost ) ) ;
		
		while ( ! pQueue.isEmpty () )
		{
			cAirport = pQueue.poll () ;
			
			iStart = cAirport.m_iEndAirport ;
			iChangeStart = cAirport.m_iCost ;
			iChangeEnd = cAirport.m_iTime ;
			
			g_brgVisit [ iStart ] = false ;
			
			for ( int j = 0 ; j < g_alrgTicket [ iStart ].size () ; ++j )
			{
				cTicket = g_alrgTicket [ iStart ].get ( j ) ;
				iEnd = cTicket.m_iEndAirport ;
				iCost = cTicket.m_iCost ;
				iTime = cTicket.m_iTime ;
				iNextStart = g_iLimitCost ;
				iNextEnd = 0 ;
				bChange = false ;
				
				iChangeEnd = Integer.min ( cAirport.m_iTime , g_iLimitCost - iCost + 1 ) ;
				
				for ( int k = iChangeStart ; k < iChangeEnd ; k++ )
				{
					if ( ( Integer.MAX_VALUE != g_idrgCostTime [ iStart ] [ k ] )
							&& ( g_idrgCostTime [ iStart ] [ k ] + iTime < g_idrgCostTime [ iEnd ] [ iCost + k ] ) )
					{
						g_idrgCostTime [ iEnd ] [ iCost + k ] = g_idrgCostTime [ iStart ] [ k ] + iTime ;
						
						if ( ! g_brgVisit [ iEnd ] )
						{
							bChange = true ;
							iNextStart = Integer.min ( iNextStart , k ) ;
							iNextEnd = Integer.max ( iNextEnd , k ) ;
						}
					}
				}
				
				if ( ! g_brgVisit [ iEnd ] && bChange )
				{
					pQueue.add ( new cInfo ( iEnd , iNextStart , iNextEnd ) ) ;
				}
				
				g_brgVisit [ iEnd ] = true ;
			}
		}
	}
	
	static class cInfo implements Comparable < cInfo >
	{
		int m_iEndAirport ;
		int m_iCost ;
		int m_iTime ;
		
		
		public cInfo ( int iEndAirport , int iCost , int iTime )
		{
			m_iEndAirport = iEndAirport ;
			m_iCost = iCost ;
			m_iTime = iTime ;
		}
		
		@Override
		public int compareTo ( cInfo cCompare )
		{
			if ( this.m_iTime < cCompare.m_iTime )
			{
				return this.m_iTime - cCompare.m_iTime ;
			}
			
			return m_iCost - cCompare.m_iCost ;
		}
	}
}