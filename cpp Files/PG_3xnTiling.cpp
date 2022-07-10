int solution ( int n )
{
	int idrgDP [ 2 ] [ 2 ] = { { 0 , 0 } , { 2 , 1 } } ;		// [] [ 0 ] = Last tile is vertical



	if ( 1 == ( n & 1 ) )
		return 0 ;

	n >>= 1 ;

	for ( int i = 1 ; i < n ; ++i )
	{
		idrgDP [ 0 ] [ 0 ] = idrgDP [ 1 ] [ 0 ] ;
		idrgDP [ 0 ] [ 1 ] = idrgDP [ 1 ] [ 1 ] ;

		idrgDP [ 1 ] [ 0 ] = ( ( idrgDP [ 0 ] [ 0 ] + idrgDP [ 0 ] [ 1 ] ) * ( long long ) 2 + idrgDP [ 0 ] [ 0 ] ) % 1000000007 ;
		idrgDP [ 1 ] [ 1 ] = ( ( long long ) idrgDP [ 0 ] [ 0 ] + idrgDP [ 0 ] [ 1 ] ) % 1000000007 ;
	}

	return ( ( long long ) idrgDP [ 1 ] [ 0 ] + idrgDP [ 1 ] [ 1 ] ) % 1000000007 ;
}

int main ()
{
	int i = solution ( 4 ) ;
}