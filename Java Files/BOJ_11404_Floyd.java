import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;



public class OJ_11404_Floyd
{
	static int g_iVertexCnt ;
	static int [] [] g_idrgPath ;
	
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st ;
		StringBuilder sb = new StringBuilder () ;
		int iEdge = 0 ;
		
		
		
		g_iVertexCnt = Integer.parseInt ( br.readLine () ) ;
		iEdge = Integer.parseInt ( br.readLine () ) ;
		g_idrgPath = new int [ g_iVertexCnt ] [ g_iVertexCnt ] ;
		
		for ( int i = 0 ; i < g_iVertexCnt ; ++i )
		{
			Arrays.fill ( g_idrgPath [ i ] , Integer.MAX_VALUE ) ;
			g_idrgPath [ i ] [ i ] = 0 ;
		}
		for ( int i = 0 ; i < iEdge ; ++i )
		{
			st = new StringTokenizer ( br.readLine () ) ;
			int iStart = Integer.parseInt ( st.nextToken () ) - 1 ;
			int iEnd = Integer.parseInt ( st.nextToken () ) - 1 ;
			int iLength = Integer.parseInt ( st.nextToken () ) ;
			
			g_idrgPath [ iStart ] [ iEnd ] = Integer.min ( g_idrgPath [ iStart ] [ iEnd ] , iLength ) ;
		}
		
		doFloyd () ;
		
		for ( int i = 0 ; i < g_iVertexCnt ; ++i )
		{
			for ( int j = 0 ; j < g_iVertexCnt ; ++j )
			{
				sb.append ( g_idrgPath [ i ] [ j ] == Integer.MAX_VALUE ? 0 : g_idrgPath [ i ] [ j ] ) ;
				sb.append ( ' ' ) ;
			}
			
			sb.append ( '\n' ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	public static void doFloyd ()
	{
		for ( int k = 0 ; k < g_iVertexCnt ; ++k )
		{
			for ( int i = 0 ; i < g_iVertexCnt ; ++i )
			{
				for ( int j = 0 ; j < g_iVertexCnt ; ++j )
				{
					if ( ( Integer.MAX_VALUE != g_idrgPath [ i ] [ k ] ) && ( Integer.MAX_VALUE != g_idrgPath [ k ] [ j ] ) )
					{
						g_idrgPath [ i ] [ j ] = Integer.min ( g_idrgPath [ i ] [ j ] , g_idrgPath [ i ] [ k ] + g_idrgPath [ k ] [ j ] ) ;
					}
				}
			}
		}
	}
}