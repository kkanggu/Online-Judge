import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;



public class OJ_10217_KCMTravel
{
	static int g_iAirportCnt ;
	static int [] [] g_idrgCostTime ;									// [ 0 ] [ 1 ] priority cost, [ 2 ] [ 3 ] priority Time. [ 0 , 2 ] means cost, [ 1 , 3 ] means time
	static ArrayList < cInfo > [] g_alrgTicket ;						// [ n ] means 1 ~ n-1 to n tickets.
	static int g_iLimit ;
	
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
			g_iLimit = Integer.parseInt ( st.nextToken () ) ;
			int iTicket = Integer.parseInt ( st.nextToken () ) ;
			
			g_alrgTicket = new ArrayList [ g_iAirportCnt ] ;
			g_idrgCostTime = new int [ g_iAirportCnt ] [ 4 ] ;
			
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
				
				g_alrgTicket [ iEnd ].add ( new cInfo ( iStart , iCost , iTime ) ) ;
			}
			
			Arrays.fill ( g_idrgCostTime [ 0 ] , 0 ) ;
			
			getTravelTime () ;
			
			iFinalCost = Integer.min ( g_idrgCostTime [ g_iAirportCnt - 1 ] [ 1 ] , g_idrgCostTime [ g_iAirportCnt - 1 ] [ 3 ] ) ;
			
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
		cInfo cTicket ;
		int iStart ;
		int iCost ;
		int iTime ;
		
		
		
		for ( int i = 1 ; i < g_iAirportCnt ; ++i )
		{
			for ( int j = 0 ; j < g_alrgTicket [ i ].size () ; ++j )
			{
				cTicket = g_alrgTicket [ i ].get ( j ) ;
				iStart = cTicket.m_iStartAirport ;
				iCost = cTicket.m_iCost ;
				iTime = cTicket.m_iTime ;
				
				if ( ( g_idrgCostTime [ iStart ] [ 0 ] + iCost < g_idrgCostTime [ i ] [ 0 ] )				// Cost compare
						&& ( g_idrgCostTime [ iStart ] [ 0 ] + iCost <= g_iLimit )							// Check cost exceed
						&& ( g_idrgCostTime [ iStart ] [ 0 ] != Integer.MAX_VALUE ) )
				{
					g_idrgCostTime [ i ] [ 0 ] = g_idrgCostTime [ iStart ] [ 0 ] + iCost ;
					g_idrgCostTime [ i ] [ 1 ] = g_idrgCostTime [ iStart ] [ 1 ] + iTime ;
				}
				if ( ( g_idrgCostTime [ iStart ] [ 3 ] + iTime < g_idrgCostTime [ i ] [ 3 ] )				// Time compare
						&& ( g_idrgCostTime [ iStart ] [ 2 ] + iCost <= g_iLimit )							// Check cost exceed
						&& ( g_idrgCostTime [ iStart ] [ 0 ] != Integer.MAX_VALUE ) )
				{
					g_idrgCostTime [ i ] [ 2 ] = g_idrgCostTime [ iStart ] [ 2 ] + iCost ;
					g_idrgCostTime [ i ] [ 3 ] = g_idrgCostTime [ iStart ] [ 3 ] + iTime ;
				}
			}
		}
	}
	
	static class cInfo implements Comparable < cInfo >
	{
		int m_iStartAirport ;
		int m_iCost ;
		int m_iTime ;
		
		
		public cInfo ( int iStartAirport , int iCost , int iTime )
		{
			m_iStartAirport = iStartAirport ;
			m_iCost = iCost ;
			m_iTime = iTime ;
		}
		
		@Override
		public int compareTo ( cInfo cCompare )
		{
			if ( this.m_iCost < cCompare.m_iCost )
			{
				return this.m_iCost - cCompare.m_iCost ;
			}
			
			return m_iTime - cCompare.m_iTime ;
		}
	}
}

/*
	1
	6 149 8
	1 2 60 20
	2 3 30 70
	1 3 100 80
	1 3 20 180
	3 4 20 100
	3 5 150 20
	5 6 50 40
	4 6 30 50
 */