public class PG_RightRectangle
{
	public long solution ( int w , int h )
	{
		long answer = ( long ) w * h - w - h ;
		int iGCD = 1 ;



		while ( w != h )
		{
			if ( w > h )
				w -= h ;
			else
				h -= w ;
		}


		return answer + w ;
	}
}
