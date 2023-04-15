import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;



public class OJ_1300_KthNumber
{
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		int iN = Integer.parseInt ( br.readLine () ) ;
		int iK = Integer.parseInt ( br.readLine () ) ;
		long lLeft = 1 ;
		long lRight = ( long ) iN * iN ;
		long lValue = 0 ;
		long lIndex = 0 ;
		long lTempCnt = 0 ;
		
		
		
		-- iK ;
		
		while ( lLeft <= lRight )
		{
			lIndex = ( lLeft + lRight ) / 2 ;
			lTempCnt = 0 ;							// Cnt of numbers <= iIndex
			
			
			for ( int i = 1 ; i <= iN ; ++i )
			{
				if ( lIndex < i )
				{
					break ;
				}
				
				if ( lIndex / i >= iN )
				{
					lTempCnt += iN ;
				}
				else
				{
					lTempCnt += lIndex / i ;
				}
			}
			
			if ( lTempCnt <= iK )
			{
				lLeft = lIndex + 1 ;
			}
			else
			{
				lValue = lIndex ;
				lRight = lIndex - 1 ;
			}
		}
		
		System.out.println ( lValue ) ;
	}
}
