import java.util.Arrays;

public class PG_GroupPicture
{
	public int iGetPosition ( char cUser )
	{
		if ( 'A' == cUser )
			return 0 ;
		else if ( 'C' == cUser )
			return 1 ;
		else if ( 'F' == cUser )
			return 2 ;
		else if ( 'J' == cUser )
			return 3 ;
		else if ( 'M' == cUser )
			return 4 ;
		else if ( 'N' == cUser )
			return 5 ;
		else if ( 'R' == cUser )
			return 6 ;
		else
			return 7 ;
	}

	public int iGetPermutationCount ( boolean [] [] [] btrgPlace , int iPlaceCount , int [] irgPlaced , boolean [] brgUserUsed )
	{
		if ( 8 == iPlaceCount )
		{
			return 1 ;

		}

		int iReturn = 0 ;


		if ( 0 == iPlaceCount )
		{
			brgUserUsed [ 0 ] = true ;

			for ( int i = 0 ; i < 4 ; ++i )
			{
				irgPlaced [ i ] = 0 ;
				iReturn += iGetPermutationCount ( btrgPlace , 1 , irgPlaced , brgUserUsed ) ;
				irgPlaced [ i ] = -1 ;
			}
		}
		else
		{
			for ( int iPlaceHere = 0 , iUser = 1 , k ; iPlaceHere < 8 ; ++ iPlaceHere )
			{
				if ( -1 != irgPlaced [ iPlaceHere ] )		// This place is not empty
					continue ;


				for ( iUser = 1 ; iUser < 8 ; ++ iUser )
				{
					boolean bCanPlace = true ;

					if ( brgUserUsed [ iUser ] )
						continue ;

					for ( k = 0 ; k < 8 ; ++k )				// Compare all user that can place here
					{
						if ( -1 == irgPlaced [ k ] )
							continue ;
						if ( ! btrgPlace [ iUser ] [ irgPlaced [ k ] ] [ Math.abs ( iPlaceHere - k ) - 1 ] )
						{
							bCanPlace = false ;
							break ;
						}
					}

					if ( bCanPlace )
					{
						irgPlaced [ iPlaceHere ] = iUser ;
						brgUserUsed [ iUser ] = true ;
						iReturn += iGetPermutationCount ( btrgPlace , iPlaceCount + 1 , irgPlaced , brgUserUsed ) ;
						irgPlaced [ iPlaceHere ] = -1 ;
						brgUserUsed [ iUser ] = false ;
					}
				}

				break ;
			}
		}


		return iReturn ;
	}

	public int solution ( int n , String [] data )
	{
		int answer = 0 ;
		boolean [] [] [] btrgPlace = new boolean [ 8 ] [ 8 ] [ 8 ] ;



		for ( int i = 0 ; i < 8 ; ++i )
		{
			for ( int j = 0 ; j < 8 ; ++j )
			{
				Arrays.fill ( btrgPlace [ i ] [ j ] , true ) ;
			}
		}
		for ( int i = 0 ; i < n ; ++i )
		{
			String strTemp = data [ i ] ;

			int iFirst = iGetPosition ( strTemp.charAt ( 0 ) ) ;
			int iSecond = iGetPosition ( strTemp.charAt ( 2 ) ) ;
			int iStart = strTemp.charAt ( 4 ) - '0' ;
			int iEnd = strTemp.charAt ( 3 ) == '>' ? 0 : 7 ;

			if ( strTemp.charAt ( 3 ) == '=' )
			{
				Arrays.fill ( btrgPlace [ iFirst ] [ iSecond ] , false ) ;
				Arrays.fill ( btrgPlace [ iSecond ] [ iFirst ] , false ) ;
				btrgPlace [ iFirst ] [ iSecond ] [ iStart ] = btrgPlace [ iSecond ] [ iFirst ] [ iStart ] = true ;
			}
			else if ( strTemp.charAt ( 3 ) == '>' )
			{
				for ( int j = iStart ; j >= iEnd ; --j )
				{
					btrgPlace [ iFirst ] [ iSecond ] [ j ] = btrgPlace [ iSecond ] [ iFirst ] [ j ] = false ;
				}
			}
			else
			{
				for ( int j = iStart ; j <= iEnd ; ++j )
				{
					btrgPlace [ iFirst ] [ iSecond ] [ j ] = btrgPlace [ iSecond ] [ iFirst ] [ j ] = false ;
				}
			}
		}

		int [] irgPlaced = new int [ 8 ] ;
		boolean [] brgUserUsed = new boolean [ 8 ] ;
		Arrays.fill ( irgPlaced , -1 ) ;


		return iGetPermutationCount ( btrgPlace , 0 , irgPlaced , brgUserUsed ) << 1 ;
	}
}