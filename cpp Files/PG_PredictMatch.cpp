int solution ( int n , int a , int b )
{
	int iAnswer = 0 ;



	--a ;
	--b ;

	while ( a != b )
	{
		++ iAnswer ;
		
		a >>= 1 ;
		b >>= 1 ;
	}


	return iAnswer ;
}