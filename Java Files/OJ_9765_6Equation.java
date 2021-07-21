import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class OJ_9765_6Equation
{
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		long [] lrgCArray = Arrays.stream( br.readLine ().split ( " " ) ).mapToLong ( Long :: parseLong ).toArray () ;
		int [] irgXArray = new int [ 7 ] ;
		int iTemp = 0 ;
		
		
		
		for ( int i = 2 ; i <= 20000000 ; ++i )
		{
			irgXArray [ 0 ] = i ;									// x1, x4
			//	irgXArray [ 3 ] = ( int ) lrgCArray [ 3 ] * i ;
			
			if ( lrgCArray [ 0 ] % i == 0 )							// use x1, x2
			{
				irgXArray [ 1 ] = ( int ) ( lrgCArray [ 0 ] / i ) ;
				
				if ( lrgCArray [ 4 ] % irgXArray [ 1 ] == 0 )		// use x2, x3
				{
					irgXArray [ 2 ] = ( int ) ( lrgCArray [ 4 ] / irgXArray [ 1 ] ) ;
					++ iTemp ;
					break ;
				}
			}
		}
		for ( int i = 2 ; i <= 20000000 ; ++i )
		{
			irgXArray [ 6 ] = i ;								// x7, x8
			//	irgXArray [ 7 ] = ( int ) lrgCArray [ 3 ] * i ;
			
			if ( lrgCArray [ 2 ] % i == 0 )						// use x7, x6
			{
				irgXArray [ 5 ] = ( int ) ( lrgCArray [ 2 ] / i ) ;
				
				if ( lrgCArray [ 5 ] % irgXArray [ 5 ] == 0 )	// use x6, x5
				{
					irgXArray [ 4 ] = ( int ) ( lrgCArray [ 5 ] / irgXArray [ 5 ] ) ;
					++ iTemp ;
					break ;
				}
			}
		}
		
		if ( 2 == iTemp )
			System.out.println ( irgXArray [ 0 ] + " " + irgXArray [ 1 ] + " " + irgXArray [ 2 ] + " " + irgXArray [ 4 ] + " " + irgXArray [ 5 ] + " " + irgXArray [ 6 ] ) ;
	}
}
