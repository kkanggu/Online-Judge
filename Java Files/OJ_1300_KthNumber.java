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
		int iTempCnt = 0 ;
		
		
		
		while ( lLeft <= lRight )
		{
			lIndex = ( lLeft + lRight ) / 2 ;
			iTempCnt = 0 ;							// Cnt of numbers lower than iIndex
			
			
			for ( int i = 1 ; i <= iN ; ++i )
			{
				if ( lIndex < i )
				{
					break ;
				}
				
				if ( lIndex / i >= iN )
				{
					iTempCnt += iN ;
				}
				else
				{
					iTempCnt += lIndex / i ;
				}
			}
			
			if ( iTempCnt <= iK )
			{
				lValue = lIndex ;
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
