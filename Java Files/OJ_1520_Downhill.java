import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_1520_Downhill
{
	static int [] [] idprgMemoization ;
	static int [] [] idprgMap ;
	static int [] irgSize ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		
		
		
		irgSize = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		idprgMap = new int [ irgSize [ 0 ] ] [] ;
		
		for ( int i = 0 ; i < irgSize [ 0 ] ; ++i )
		{
			idprgMap [ i ] = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		}
		
		idprgMemoization = new int [ irgSize [ 0 ] ] [ irgSize [ 1 ] ] ;
		
		for ( int [] j : idprgMemoization )
		{
			Arrays.fill ( j , -1 ) ;
		}
		
		idprgMemoization [ 0 ] [ 0 ] = 1 ;
		
		
		System.out.println ( iGetRoute ( irgSize [ 0 ] - 1 , irgSize [ 1 ] - 1 ) ) ;
	}
	
	private static int iGetRoute ( int iRow , int iColumn )
	{
		if ( -1 == idprgMemoization [ iRow ] [ iColumn ] )
		{
			idprgMemoization [ iRow ] [ iColumn ] = 0 ;
			
			
			if ( ( 0 != iRow ) && ( idprgMap [ iRow ] [ iColumn ] < idprgMap [ iRow - 1 ] [ iColumn ] ) )
			{
				idprgMemoization [ iRow ] [ iColumn ] += iGetRoute ( iRow - 1 , iColumn ) ;
			}
			if ( ( iRow != irgSize [ 0 ] - 1 ) && ( idprgMap [ iRow ] [ iColumn ] < idprgMap [ iRow + 1 ] [ iColumn ] ) )
			{
				idprgMemoization [ iRow ] [ iColumn ] += iGetRoute ( iRow + 1 , iColumn ) ;
			}
			if ( ( 0 != iColumn ) && ( idprgMap [ iRow ] [ iColumn ] < idprgMap [ iRow ] [ iColumn - 1 ] ) )
			{
				idprgMemoization [ iRow ] [ iColumn ] += iGetRoute ( iRow , iColumn - 1 ) ;
			}
			if ( ( iColumn != irgSize [ 1 ] - 1 ) && ( idprgMap [ iRow ] [ iColumn ] < idprgMap [ iRow ] [ iColumn + 1 ] ) )
			{
				idprgMemoization [ iRow ] [ iColumn ] += iGetRoute ( iRow , iColumn + 1 ) ;
			}
		}
		
		
		
		return idprgMemoization [ iRow ] [ iColumn ] ;
	}
}
