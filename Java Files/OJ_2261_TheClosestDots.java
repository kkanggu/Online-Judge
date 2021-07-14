import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;



public class OJ_2261_TheClosestDots
{
	public static void main ( String [] args )
	{
		Scanner sc = new Scanner ( System.in ) ;
		int iMin = Integer.MAX_VALUE ;
		int iCnt = sc.nextInt () ;
		int irgDot [] [] = new int [ iCnt ] [ 2 ] ;
		int iRightBound ;
		int iUpperBound ;
		int iLowerBound ;
		int j ;
		
		
		
		for ( int i = 0 ; i < iCnt ; ++i )
		{
			irgDot [ i ] [ 0 ] = sc.nextInt () ;
			irgDot [ i ] [ 1 ] = sc.nextInt () ;
		}
		
		Arrays.sort ( irgDot , new Comparator < int[] > ()
				{
					@Override
					public int compare ( int[] o1 , int[] o2 )
					{
						if ( o1 [ 0 ] == o2 [ 0 ] )
						{
							return o1 [ 1 ] - o2 [ 1 ] ;
						}
						else
						{
							return o1 [ 0 ] - o2 [ 0 ] ;
						}
					}
				} ) ;
		
		iMin = iGetDistance ( irgDot [ 0 ] [ 0 ] , irgDot [ 0 ] [ 1 ] , irgDot [ 1 ] [ 0 ] , irgDot [ 1 ] [ 1 ] ) ;
		
		
		for ( int i = 0 ; i < iCnt - 1 ; ++i )
		{
			iRightBound = ( int ) ( irgDot [ i ] [ 0 ] + Math.sqrt ( iMin - 1 ) ) ;
			iLowerBound = ( int ) ( irgDot [ i ] [ 1 ] - Math.sqrt ( iMin - 1 ) ) ;
			iUpperBound = ( int ) ( irgDot [ i ] [ 1 ] + Math.sqrt ( iMin - 1 ) ) ;
			j = i + 1 ;
			
			if ( j == iCnt )
			{
				System.out.println ( iMin ) ;
				System.exit ( 0 ) ;
			}
			
			while ( irgDot [ j ] [ 0 ] <= iRightBound )
			{
				if ( ( irgDot [ j ] [ 1 ] >= iLowerBound ) && ( irgDot [ j ] [ 1 ] <= iUpperBound ) )
				{
					iMin = Math.min ( iMin , iGetDistance ( irgDot [ i ] [ 0 ] , irgDot [ i ] [ 1 ] , irgDot [ j ] [ 0 ] , irgDot [ j ] [ 1 ] ) ) ;
					
					if ( 0 == iMin )
					{
						System.out.println ( 0 ) ;
						System.exit ( 0 ) ;
					}
					
					iRightBound = ( int ) ( irgDot [ i ] [ 0 ] + Math.sqrt ( iMin - 1 ) ) ;
					iLowerBound = ( int ) ( irgDot [ i ] [ 1 ] - Math.sqrt ( iMin - 1 ) ) ;
					iUpperBound = ( int ) ( irgDot [ i ] [ 1 ] + Math.sqrt ( iMin - 1 ) ) ;
					
					++j ;
				}
				else
				{
					while ( ( irgDot [ j ] [ 1 ] > iUpperBound ) || ( irgDot [ j ] [ 1 ] < iLowerBound ) )
					{
						++j ;
						
						if ( j == iCnt )
						{
							break ;
						}
					}
				}
				
				if ( j == iCnt )
				{
					break ;
				}
			}
		}
		
		System.out.println ( iMin ) ;
	}
	
	private static int iGetDistance ( int iX1 , int iY1 , int iX2 , int iY2 )
	{
		return ( ( iX1 - iX2 ) * ( iX1 - iX2 ) + ( iY1 - iY2 ) * ( iY1 - iY2 ) ) ;
	}
}
