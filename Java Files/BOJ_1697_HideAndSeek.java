import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;



public class OJ_1697_HideAndSeek
{
	public static void main ( String[] args )
	{
		Scanner sc = new Scanner ( System.in ) ;
		int iStart = sc.nextInt () ;
		int iEnd = sc.nextInt () ;
		int [] irgLength = new int [ 100001 ] ;
		boolean [] brgPassed = new boolean [ 100001 ] ;
		Queue < Integer > queue = new LinkedList <> () ;
		
		
		
		Arrays.fill ( irgLength , Integer.MAX_VALUE ) ;
		
		irgLength [ iStart ] = 0 ;
		brgPassed [ iStart ] = true ;
		queue.add ( iStart ) ;
		
		
		while ( ! queue.isEmpty () )
		{
			int iTemp = queue.poll () ;
			int iCurrentLength = irgLength [ iTemp ] ;
			
			
			
			if ( iTemp == iEnd )
			{
				System.out.println ( iCurrentLength ) ;
				System.exit ( 0 ) ;
			}
			
			if ( ( iTemp != 0 ) && ( ! brgPassed [ iTemp - 1 ] ) )
			{
				irgLength [ iTemp - 1 ] = Integer.min ( iCurrentLength + 1 , irgLength [ iTemp - 1 ] ) ;
				brgPassed [ iTemp - 1 ] = true ;
				
				queue.add ( iTemp - 1 ) ;
			}
			if ( ( iTemp != 100000 ) && ( ! brgPassed [ iTemp + 1 ] ) )
			{
				irgLength [ iTemp + 1 ] = Integer.min ( iCurrentLength + 1 , irgLength [ iTemp + 1 ] ) ;
				brgPassed [ iTemp + 1 ] = true ;
				
				queue.add ( iTemp + 1 ) ;
			}
			if ( ( iTemp <= 50000 ) && ( ! brgPassed [ iTemp * 2 ] ) )
			{
				irgLength [ iTemp * 2 ] = Integer.min ( iCurrentLength + 1 , irgLength [ iTemp * 2 ] ) ;
				brgPassed [ iTemp * 2 ] = true ;
				
				queue.add ( iTemp * 2 ) ;
			}
		}
	}
}