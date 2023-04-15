import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Vector;



public class OJ_2667_NumberingComplex
{
	static int g_iRowCnt ;
	static boolean [] [] g_bdrgHouse ;
	static int g_iHouseCnt ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringBuilder sb = new StringBuilder () ;
		g_iRowCnt = Integer.parseInt ( br.readLine () ) ;
		g_bdrgHouse = new boolean [ g_iRowCnt ][ g_iRowCnt ] ;
		int iComplexCnt = 0 ;
		Vector < Integer > vHouse = new Vector <> () ;
		
		
		
		for ( int i = 0 ; i < g_iRowCnt ; ++i )
		{
			String st = br.readLine () ;
			
			for ( int j = 0 ; j < g_iRowCnt ; ++j )
			{
				if ( '0' == st.charAt ( j ) )
				{
					g_bdrgHouse [ i ] [ j ] = false ;
				}
				else
				{
					g_bdrgHouse [ i ] [ j ] = true ;
					++ g_iHouseCnt ;
				}
			}
		}
		
		for ( int i = 0 ; i < g_iRowCnt * g_iRowCnt ; ++i )
		{
			if ( g_bdrgHouse [ i / g_iRowCnt ] [ i % g_iRowCnt ] )
			{
				vHouse.add ( iGetDFS ( i / g_iRowCnt , i % g_iRowCnt ) ) ;
				++ iComplexCnt ;
			}
		}
		
		Collections.sort ( vHouse ) ;
		
		sb.append ( iComplexCnt ) ;
		
		
		for ( int i = 0 ; i < vHouse.size () ; i++ )
		{
			sb.append ( "\n" + vHouse.get ( i ) ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	static int iGetDFS ( int iRow , int iColumn )
	{
		int iCnt = 0 ;
		
		
		
		g_bdrgHouse [ iRow ] [ iColumn ] = false ;
		-- g_iHouseCnt ;
		++ iCnt ;
		
		
		if ( ( iRow != 0 ) && ( g_bdrgHouse [ iRow - 1 ] [ iColumn ] ) )
		{
			iCnt += iGetDFS ( iRow - 1 , iColumn ) ;
		}
		if ( ( iRow != g_iRowCnt - 1 ) && ( g_bdrgHouse [ iRow + 1 ] [ iColumn ] ) )
		{
			iCnt += iGetDFS ( iRow + 1 , iColumn ) ;
		}
		if ( ( iColumn != 0 ) && ( g_bdrgHouse [ iRow ] [ iColumn - 1 ] ) )
		{
			iCnt += iGetDFS ( iRow , iColumn - 1 ) ;
		}
		if ( ( iColumn != g_iRowCnt - 1 ) && ( g_bdrgHouse [ iRow ] [ iColumn + 1 ] ) )
		{
			iCnt += iGetDFS ( iRow , iColumn + 1 ) ;
		}
		
		
		return iCnt ;
	}
}