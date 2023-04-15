import java.io.*;
import java.util.Arrays;



public class OJ_10816_NumberCard2
{
	public static void main ( String [] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringBuilder sb = new StringBuilder () ;
		int iCnt = Integer.parseInt ( br.readLine () ) ;
		int [] irgArray = Arrays.stream ( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int iTarget = Integer.parseInt ( br.readLine () ) ;
		int [] irgTarget = Arrays.stream ( br.readLine ().split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray () ;
		int iLeft = 0 ;
		int iRight = iCnt ;
		int iIndex = 0 ;
		int iBoundLeft = 0 ;
		int iBoundRight = 0 ;
		int iTemp = 0 ;
		
		
		
		Arrays.sort ( irgArray ) ;
		
		
		for ( int i = 0 ; i < iTarget ; ++i )
		{
			iLeft = 0 ;
			iRight = iCnt - 1 ;
			iIndex = iCnt / 2 ;
			iBoundLeft = 0 ;
			iBoundRight = -1 ;
			
			
			while ( iLeft <= iRight )
			{
				if ( irgTarget [ i ] == irgArray [ iIndex ] )
				{
					iBoundLeft = iIndex ;
					iBoundRight = iIndex ;
					iTemp = iIndex + 1 ;
					iRight = iIndex - 1 ;
					iIndex = ( iLeft + iRight ) / 2 ;
					
					
					while ( iLeft <= iRight )
					{
						if ( irgTarget [ i ] == irgArray [ iIndex ] )
						{
							iBoundLeft = iIndex ;
							iRight = iIndex - 1 ;
						}
						else if ( irgTarget [ i ] < irgArray [ iIndex ] )
						{
							iRight = iIndex - 1 ;
						}
						else
						{
							iLeft = iIndex + 1 ;
						}
						
						iIndex = ( iLeft + iRight ) / 2 ;
					}
					
					iLeft = iTemp ;
					iRight = iCnt - 1 ;
					iIndex = ( iLeft + iRight ) / 2 ;
					
					while ( iLeft <= iRight )
					{
						if ( irgTarget [ i ] == irgArray [ iIndex ] )
						{
							iBoundRight = iIndex ;
							iLeft = iIndex + 1 ;
						}
						else if ( irgTarget [ i ] < irgArray [ iIndex ] )
						{
							iRight = iIndex - 1 ;
						}
						else
						{
							iLeft = iIndex + 1 ;
						}
						
						iIndex = ( iLeft + iRight ) / 2 ;
					}
					
					iLeft = iRight + 1 ;
					
					break ;
				}
				else if ( irgTarget [ i ] < irgArray [ iIndex ] )
				{
					iRight = iIndex - 1 ;
				}
				else
				{
					iLeft = iIndex + 1 ;
				}
				
				iIndex = ( iLeft + iRight ) / 2 ;
			}
			
			sb.append ( iBoundRight - iBoundLeft + 1 ) ;
			sb.append ( "\n" ) ;
		}
		
		System.out.println ( sb ) ;
	}
}
