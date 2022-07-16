int solution ( int n )
{
	int answer = 1 ;
	int iValue = 0 ;



	for ( int i = 2 ; ( i * i + i ) >> 1 <= n ; ++i )
	{
		iValue = ( n / i - i / 2 ) * i + ( ( i * i - i ) >> 1 ) ;		// Start from n/i-i, sum of i continuous value

		while ( iValue <= n )
		{
			if ( iValue == n )
			{
				++ answer ;

				break ;
			}

			iValue += i ;
		}
	}
	

	return answer ;
}