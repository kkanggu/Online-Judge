long long solution ( int w ,int h )
{
	long long answer = 0 ;
	int iFormer = 0 ;
	int iCurret = 0 ;
	double dTemp = 0 ;



	for ( int i = 1 ; i <= w ; ++i )
	{
		iCurret = dTemp = ( long long ) h * i / ( double ) w ;

		if ( iCurret == dTemp )					// Find small rectangle to split
		{
			answer += iCurret - iFormer ;

			answer *= w / i ;

			break ;
		}

		++ iCurret ;
		answer += iCurret - iFormer ;
		iFormer = iCurret - 1 ;
	}

	return ( long long ) w * h - answer ;
}

int main ()
{
	int i = solution ( 8 , 12 ) ;

	return 0 ;
}