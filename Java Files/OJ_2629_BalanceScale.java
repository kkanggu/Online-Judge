import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_2629_BalanceScale
{
	static int [] [] idrgMemoization ;									// 1 can measure, -1 can't measure
	static int [] irgWeight ;
	static boolean [] brgWeightUsed ;
	static int iWeightCnt ;
	
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringBuilder sb = new StringBuilder () ;
		iWeightCnt = Integer.parseInt ( br.readLine () ) ;
		irgWeight = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		Arrays.sort ( irgWeight ) ;
		int iQuestionCnt = Integer.parseInt ( br.readLine () ) ;
		int [] irgBall ;
		idrgMemoization = new int [ iWeightCnt ] [ 15001 ] ;
		brgWeightUsed = new boolean [ iWeightCnt ] ;
		
		
		
		irgBall = Arrays.stream( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		
		for ( int i = 0 ; i < iQuestionCnt ; ++i )
		{
			sb.append ( bIsMeasurable ( irgBall [ i ] , 0 ) ? 'Y' : 'N' ).append ( '\n' ) ;
		}
		
		System.out.println ( sb ) ;
	}
	
	public static boolean bIsMeasurable ( int iBall , int iCompareStartPosition )
	{
		int iTemp = iBall ;
		
		
		
		if ( ( iCompareStartPosition == iWeightCnt ) || ( iBall > 15000 ) )
		{
			return false ;
		}
		else if ( 0 != idrgMemoization [ iCompareStartPosition ] [ iBall ] )
		{
			return idrgMemoization [ iCompareStartPosition ] [ iBall ] == 1 ? true : false ;
		}
		else
		{
			for ( int i = iCompareStartPosition ; i < iWeightCnt ; ++i )
			{
				if ( bIsMeasurable ( iBall + irgWeight [ i ] , i + 1 ) )
				{
					idrgMemoization [ i ] [ iBall ] = 1 ;
					
					return true	;
				}
				
				iTemp = Math.abs ( iBall - irgWeight [ i ] ) ;
				
				if ( 0 == iTemp )
				{
					idrgMemoization [ i ] [ iBall ] = 1 ;
					
					return true	;
				}
				else if ( iTemp != iBall )
				{
					if ( bIsMeasurable ( iTemp , i + 1 ) )
					{
						idrgMemoization [ i ] [ iBall ] = 1 ;
						
						return true	;
					}
				}
				
				brgWeightUsed [ i ] = false ;
			}
			
			idrgMemoization [ iCompareStartPosition ] [ iBall ] = -1 ;
			
			return false ;
		}
	}
}