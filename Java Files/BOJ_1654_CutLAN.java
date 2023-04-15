import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_1654_CutLAN
{
	public static void main ( String [] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		int [] irgCnt = Arrays.stream ( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int [] irgLine = new int [ irgCnt [ 0 ] ] ;
		long [] lrgTemp ;
		int iValue = 0 ;
		long lLeft = 0 ;
		long lRight = 0 ;
		
		
		
		for ( int i = 0 ; i < irgCnt [ 0 ] ; ++i )
		{
			irgLine [ i ] = Integer.parseInt ( br.readLine () ) ;
		}
		
		Arrays.sort ( irgLine ) ;
		
		lLeft = 1 ;
		lRight = irgLine [ irgCnt [ 0 ] - 1 ] ;
		
		while ( lLeft <= lRight )
		{
			final long lTemp = ( lLeft + lRight ) / 2 ;
			lrgTemp = Arrays.stream( irgLine.clone () ).mapToLong ( operand -> operand / lTemp ).toArray () ;
			
			
			if ( Long.valueOf ( irgCnt[ 1 ] ) <= Arrays.stream ( lrgTemp ).sum () )
			{
				iValue = ( int ) lTemp ;
				lLeft = lTemp + 1 ;
			}
			else
			{
				lRight = lTemp - 1 ;
			}
		}
		
		
		System.out.println ( iValue ) ;
	}
}