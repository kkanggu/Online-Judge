#include <string>
#include <unordered_map>

using std :: string ;
using std :: unordered_map ;

int solution ( string dirs )
{
	int answer = 0 ;
	unordered_map < int , int > umCoordinate ;
	int iX = 0 ;
	int iY = 0 ;
	const char * cpTemp = dirs.data () ;
	int iSize = dirs.size () ;



	for ( int i = 0 ; i < iSize ; ++i )
	{
		int iTempX = iX + 5 ;
		int iTempY = iY + 5 ;

		if ( 'U' == cpTemp [ i ] )
			++ iY ;
		else if ( 'D' == cpTemp [ i ] )
			-- iY ;
		else if ( 'L' == cpTemp [ i ] )
			-- iX ;
		else if ( 'R' == cpTemp [ i ] )
			++ iX ;

		if ( ( iY < -5 ) || ( iX < -5 ) || ( 5 < iY ) || ( 5 < iX ) )
		{
			iX = iTempX - 5 ;
			iY = iTempY - 5 ;

			continue ;
		}

		++ umCoordinate [ ( iTempX << 12 ) + ( iTempY << 8 ) + ( ( iX + 5 ) << 4 ) + ( iY + 5 ) ] ;
		++ umCoordinate [ ( ( iX + 5 ) << 12 ) + ( ( iY + 5 ) << 8 ) + ( iTempX << 4 ) + iTempY ] ;
	}
	

	return umCoordinate.size () >> 1 ;
}

int main ()
{
	int i = solution ( "LULLLLLLU" ) ;
}