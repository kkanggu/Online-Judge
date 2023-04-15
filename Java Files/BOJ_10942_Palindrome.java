import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_10942_Palindrome
{
	static int [] irgNum ;
	static boolean [] [] bdrgMemoization ;
	static boolean [] [] bdrgVisit ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringBuilder sb = new StringBuilder () ;
		int iNumCnt = Integer.parseInt ( br.readLine () ) ;
		irgNum = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int iQuestionCnt = Integer.parseInt ( br.readLine () ) ;
		int [] irgQuestion ;
		bdrgMemoization = new boolean [ iNumCnt ] [ iNumCnt ] ;
		bdrgVisit = new boolean [ iNumCnt ] [ iNumCnt ] ;
		
		
		
		for ( int i = 0 ; i < iNumCnt ; ++i )
		{
			Arrays.fill ( bdrgVisit [ i ] , false ) ;
			bdrgMemoization [ i ] [ i ] = true ;
			bdrgVisit [ i ] [ i ] = true ;
		}
		for ( int i = 0 ; i < iQuestionCnt ; ++i )
		{
			irgQuestion = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
			
			sb.append ( bgetPalindrome ( irgQuestion [ 0 ] - 1 , irgQuestion [ 1 ] - 1 ) ? 1 : 0 ).append ( '\n' ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	public static boolean bgetPalindrome ( int iStart , int iEnd )
	{
		boolean bPalindrome = true ;
		
		
		
		if ( true == bdrgVisit [ iStart ] [ iEnd ] )
		{
			return bdrgMemoization [ iStart ] [ iEnd ] ;
		}
		else
		{
			if ( irgNum [ iStart ] == irgNum [ iEnd ] )
			{
				if ( iEnd - iStart >= 2 )
				{
					bPalindrome = bgetPalindrome ( iStart + 1 , iEnd - 1 ) ;
				}
			}
			else
			{
				bPalindrome = false ;
			}
			
			bdrgVisit [ iStart ] [ iEnd ] = true ;
			bdrgMemoization [ iStart ] [ iEnd ] = bPalindrome ;
			
			
			return bPalindrome ;
		}
	}
}