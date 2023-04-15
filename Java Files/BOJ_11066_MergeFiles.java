import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_11066_MergeFiles
{
	static int [] [] idprgMemorization ;
	static int [] irgSum ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		int iN = Integer.parseInt ( br.readLine () ) ;
		int iFiles = 0 ;
		int [] irgFile ;
		int iTime = 0 ;
		
		
		
		for ( int i = 0 ; i < iN ; ++i )
		{
			iFiles = Integer.parseInt ( br.readLine () ) ;
			irgFile = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
			idprgMemorization = new int [ iFiles ] [ iFiles ] ;
			irgSum = new int [ iFiles + 1 ] ;
			irgSum [ 0 ] = 0 ;
			irgSum [ 1 ] = irgFile [ 0 ] ;
			
			for ( int [] j : idprgMemorization )
			{
				Arrays.fill ( j , -1 ) ;
			}
			for ( int j = 1 ; j < iFiles + 1 ; ++j )
			{
				irgSum [ j ] = irgSum [ j - 1 ] + irgFile [ j - 1 ] ;
			}

			
			System.out.println ( iGetMergeTime ( 0 , iFiles - 1 , irgFile ) ) ;
		}
	}
	
	private static int iGetMergeTime ( int iStart , int iEnd , int [] irgFile )
	{
		int iCompareTime = Integer.MAX_VALUE ;
		
		
		
		if ( -1 != idprgMemorization [ iStart ] [ iEnd ] )
		{
			return idprgMemorization [ iStart ] [ iEnd ] ;
		}
		else if ( iEnd == iStart )
		{
			idprgMemorization [ iStart ] [ iEnd ] = 0 ;
		}
		else
		{
			for ( int i = iStart ; i < iEnd ; ++i )
			{
				iCompareTime = Integer.min ( iCompareTime , iGetMergeTime ( iStart , i , irgFile ) + iGetMergeTime ( i + 1 , iEnd , irgFile ) ) ;			// Calculate, then a and b is in the stack.
			}
			
			idprgMemorization [ iStart ] [ iEnd ] = iCompareTime + irgSum [ iEnd + 1 ] - irgSum [ iStart ] ;
		}
		
		
		return idprgMemorization [ iStart ] [ iEnd ] ;
	}
}
