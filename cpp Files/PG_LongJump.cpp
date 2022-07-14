int solution ( int n )
{
	int irgDP [ 3 ] = { 0 , 1 , 1 } ;

	
	
	for ( int i = 1 ; i < n ; ++i )
	{
		irgDP [ 0 ] = irgDP [ 1 ] ;
		irgDP [ 1 ] = irgDP [ 2 ] ;
		irgDP [ 2 ] = ( irgDP [ 0 ] + irgDP [ 1 ] ) % 1234567 ;
	}

	return irgDP [ 2 ] ;
}