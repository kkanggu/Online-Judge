#include <vector>

using std :: vector ;

int solution ( int n )
{
	int iReturn = 0 ;



	while ( 1 < n )
	{
		if ( 1 == ( n & 1 ) )
			++ iReturn ;

		n >>= 1 ;
	}
	
	return iReturn + 1 ;
}