import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_11049_SequenceOfMatrixMultiplication
{
	static int [] [] idprgMemoization ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		int iCnt = Integer.parseInt ( br.readLine () ) ;
		int [] [] idprgMatrix = new int [ iCnt ] [ 2 ] ;
		
		
		
		for ( int i = 0 ; i < iCnt ; ++i )
		{
			idprgMatrix [ i ] = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		}
		
		idprgMemoization = new int [ iCnt ] [ iCnt ] ;
		
		for ( int [] j : idprgMemoization )
		{
			Arrays.fill ( j , -1 ) ;
		}
		
		
		System.out.println ( iGetOperation ( 0 , iCnt - 1 , idprgMatrix ) ) ;
	}
	
	private static int iGetOperation ( int iStart , int iEnd , int [] [] idprgMatrix )
	{
		int iCompare = Integer.MAX_VALUE ;
		int iTemp = iCompare ;
		
		
		
		if ( -1 != idprgMemoization [ iStart ] [ iEnd ] )
		{
			return idprgMemoization [ iStart ] [ iEnd ] ;
		}
		else if ( iEnd == iStart )
		{
			idprgMemoization [ iStart ] [ iEnd ] = 0 ;
		}
		else
		{
			for ( int i = iStart ; i < iEnd ; ++i )
			{
				iTemp = iGetOperation ( iStart , i , idprgMatrix ) + iGetOperation ( i + 1 , iEnd , idprgMatrix ) ;
				iCompare = Integer.min ( iCompare , iTemp + idprgMatrix [ iStart ] [ 0 ] * idprgMatrix [ i ] [ 1 ] * idprgMatrix [ iEnd ] [ 1 ] ) ;
			}
			
			idprgMemoization [ iStart ] [ iEnd ] = iCompare ;
		}
		
		
		return idprgMemoization [ iStart ] [ iEnd ] ;
	}
}