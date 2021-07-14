import java.util.*;



public class OJ_2261_TheClosestDots
{
	static int iMin = Integer.MAX_VALUE ;
	
	
	public static void main ( String [] args )
	{
		Scanner sc = new Scanner ( System.in ) ;
		int iCnt = sc.nextInt () ;
		int irgDot [] [] = new int [ iCnt ] [ 2 ] ;
		
		
		
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
				
				getMin ( irgDot , 0 , iCnt - 1 ) ;
				
				System.out.println ( iMin ) ;
	}
	
	public static void getMin ( int irgDot [] [] , int iStart , int iEnd )
	{
		if ( 0 == ( iEnd - iStart ) )		// 1 Value
		{
			// return Integer.MAX_VALUE
		}
		else if ( 1 == ( iEnd - iStart ) )	// 2 Values
		{
			iMin = Math.min ( iMin , iGetDistance ( irgDot [ iStart ] [ 0 ] , irgDot [ iStart ] [ 1 ] , irgDot [ iEnd ] [ 0 ] , irgDot [ iEnd ] [ 1 ] ) ) ;
		}
		else if ( 2 == ( iEnd - iStart ) )	// 3 Values
		{
			iMin = Math.min ( iMin , iGetDistance ( irgDot [ iStart ] [ 0 ] , irgDot [ iStart ] [ 1 ] , irgDot [ iStart + 1 ] [ 0 ] , irgDot [ iStart + 1 ] [ 1 ] ) ) ;
			iMin = Math.min ( iMin , iGetDistance ( irgDot [ iStart ] [ 0 ] , irgDot [ iStart ] [ 1 ] , irgDot [ iEnd ] [ 0 ] , irgDot [ iEnd ] [ 1 ] ) ) ;
			iMin = Math.min ( iMin , iGetDistance ( irgDot [ iStart + 1 ] [ 0 ] , irgDot [ iStart + 1 ] [ 1 ] , irgDot [ iEnd ] [ 0 ] , irgDot [ iEnd ] [ 1 ] ) ) ;
		}
		else								// More than 4 Values
		{
			int iPivotX = irgDot [ ( iStart + iEnd ) / 2 ] [ 0 ] ;
			int iTempStart = iStart ;
			int iTempEnd = iEnd ;
			ArrayList < Integer > LeftList = new ArrayList < Integer > () ;
			ArrayList < Integer > RightList = new ArrayList < Integer > () ;
			
			
			
			getMin ( irgDot , iStart , ( iStart + iEnd ) / 2 ) ;
			getMin ( irgDot , ( iStart + iEnd ) / 2 + 1 , iEnd ) ;
			
			if ( 0 == iMin )
			{
				System.out.println ( 0 ) ;
				System.exit ( 0 ) ;
			}
			
			while ( iTempStart <= ( iStart + iEnd ) / 2 )
			{
				if ( ( irgDot [ iTempStart ] [ 0 ] - iPivotX ) * ( irgDot [ iTempStart ] [ 0 ] - iPivotX ) < iMin )
				{
					LeftList.add ( iTempStart ) ;
				}
				
				++ iTempStart ;
			}
			while ( iTempEnd > ( iStart + iEnd ) / 2 )
			{
				if ( ( irgDot [ iTempEnd ] [ 0 ] - iPivotX ) * ( irgDot [ iTempEnd ] [ 0 ] - iPivotX ) < iMin )
				{
					RightList.add ( iTempEnd ) ;
				}
				
				-- iTempEnd ;
			}
			
			Collections.sort ( LeftList , new Comparator < Integer > ()
			{
				@Override
				public int compare ( Integer o1 , Integer o2 )
				{
					if ( irgDot [ o1 ] [ 1 ] == irgDot [ o2 ] [ 1 ] )
					{
						return irgDot [ o1 ] [ 0 ] - irgDot [ o2 ] [ 0 ] ;
					}
					else
					{
						return irgDot [ o1 ] [ 1 ] - irgDot [ o2 ] [ 1 ] ;
					}
				}
			} ) ;
			Collections.sort ( RightList , new Comparator < Integer > ()
			{
				@Override
				public int compare ( Integer o1 , Integer o2 )
				{
					if ( irgDot [ o1 ] [ 1 ] == irgDot [ o2 ] [ 1 ] )
					{
						return irgDot [ o1 ] [ 0 ] - irgDot [ o2 ] [ 0 ] ;
					}
					else
					{
						return irgDot [ o1 ] [ 1 ] - irgDot [ o2 ] [ 1 ] ;
					}
				}
			} ) ;
			
			if ( iEnd - iStart > 30000 )
			{
				System.out.println ( 0 ) ;
			}
			
			for ( Integer i : LeftList )
			{
				for ( Integer j : RightList )
				{
					if ( ( irgDot [ i ] [ 1 ] - irgDot [ j ] [ 1 ] ) * ( irgDot [ i ] [ 1 ] - irgDot [ j ] [ 1 ] ) < iMin )
					{
						if ( irgDot [ i ] [ 0 ] == irgDot [ j ] [ 0 ] )
						{
							iMin = Integer.min ( iMin , ( irgDot [ i ] [ 1 ] - irgDot [ j ] [ 1 ] ) * ( irgDot [ i ] [ 1 ] - irgDot [ j ] [ 1 ] ) ) ;
						}
						else if ( irgDot [ i ] [ 1 ] == irgDot [ j ] [ 1 ] )
						{
							iMin = Integer.min ( iMin , ( irgDot [ i ] [ 0 ] - irgDot [ j ] [ 0 ] ) * ( irgDot [ i ] [ 0 ] - irgDot [ j ] [ 0 ] ) ) ;
						}
						else
						{
							iMin = Integer.min ( iMin , iGetDistance ( irgDot [ i ] [ 0 ] , irgDot [ i ] [ 1 ] , irgDot [ j ] [ 0 ] , irgDot [ j ] [ 1 ] ) ) ;
						}
					}
					else if ( ( irgDot [ i ] [ 1 ] < irgDot [ j ] [ 1 ] ) && ( ( irgDot [ i ] [ 1 ] - irgDot [ j ] [ 1 ] ) * ( irgDot [ i ] [ 1 ] - irgDot [ j ] [ 1 ] ) < iMin ) )
					{
						break ;
					}
				}
			}
			
			// Cross check
		}
	}
	
	private static int iGetDistance ( int iX1 , int iY1 , int iX2 , int iY2 )
	{
		return ( ( iX1 - iX2 ) * ( iX1 - iX2 ) + ( iY1 - iY2 ) * ( iY1 - iY2 ) ) ;
	}
}
