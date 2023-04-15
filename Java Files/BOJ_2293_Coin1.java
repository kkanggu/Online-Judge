import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



public class OJ_2293_Coin1
{
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		int iCoinCnt = Integer.parseInt ( st.nextToken () ) ;
		int iSum = Integer.parseInt ( st.nextToken () ) ;
		int iInput ;
		int [] irgMemoization = new int [ iSum + 1 ] ;
		
		
		
		irgMemoization [ 0 ] = 1 ;
		
		
		for ( int i = 0 ; i < iCoinCnt ; ++i )
		{
			iInput = Integer.parseInt ( br.readLine () ) ;
			
			for ( int j = iInput ; j <= iSum ; ++j )
			{
				irgMemoization [ j ] += irgMemoization [ j - iInput ] ;
			}
		}
		
		
		System.out.println ( irgMemoization [ iSum ] ) ;
	}
}