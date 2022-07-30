public class PG_RotateParenthesisOfMatrix
{
	public int [] solution ( int rows , int columns , int[][] queries )
	{
		int iQuerySize = queries.length ;
		int [] answer = new int [ iQuerySize ] ;
		int [] [] irgRentangle = new int [ rows ] [ columns ] ;



		for ( int i = 0 ; i < rows ; ++i )
		{
			for ( int j = 0 ; j < columns ; ++j )
			{
				irgRentangle [ i ] [ j ] = i * columns + j + 1 ;
			}
		}



		for ( int iRepeat = 0 ; iRepeat < iQuerySize ; ++iRepeat )
		{
			int iStartX = queries [ iRepeat ] [ 0 ] - 1 ;
			int iStartY = queries [ iRepeat ] [ 1 ] - 1 ;
			int iEndX = queries [ iRepeat ] [ 2 ] - 1 ;
			int iEndY = queries [ iRepeat ] [ 3 ] - 1 ;
			int iMin = irgRentangle [ iStartX ] [ iStartY ] ;
			int iFormerValue = irgRentangle [ iStartX ] [ iStartY ] ;
			int iXChange = 0 ;
			int iYChange = 1 ;
			int iX = iStartX ;
			int iY = iStartY ;

			for ( int i = 1 ; i <= ( iEndX + iEndY - iStartX - iStartY ) << 1 ; ++i )
			{
				iX += iXChange ;
				iY += iYChange ;

				int iTemp = irgRentangle [ iX ] [ iY ] ;
				irgRentangle [ iX ] [ iY ] = iFormerValue ;
				iFormerValue = iTemp ;
				iMin = Math.min ( iMin , iFormerValue ) ;

				if ( i == iEndY - iStartY )
				{
					iXChange = 1 ;
					iYChange = 0 ;
				}
				else if ( i == iEndX + iEndY - iStartX - iStartY )
				{
					iXChange = 0 ;
					iYChange = -1 ;
				}
				else if ( i == iEndX - iStartX + ( iEndY - iStartY ) * 2 )
				{
					iXChange = -1 ;
					iYChange = 0 ;
				}
			}

			answer [ iRepeat ] = iMin ;
		}


		return answer ;
	}
}
