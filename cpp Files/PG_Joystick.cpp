#include <string>
#include <algorithm>
#include <vector>

using std :: string ;
using std :: vector ;

int answer ;

int iGetMinMove ( int iIndex , vector < bool > vMove , bool toLeft , int iCnt )
{
	int iReturn = 0 ;
	int i = iIndex ;
	int iMove = 0 ;



	if ( 0 == iCnt )
		return 0 ;
	

	do
	{
		if ( toLeft )
			-- i ;
		else
			++i ;

		if ( -1 == i )
			i = vMove.size () - 1 ;
		else if ( vMove.size () == i )
			i = 0 ;

		++ iMove ;

		if ( vMove [ i ] )
		{
			vMove [ i ] = false ;
			iReturn = iGetMinMove ( i , vMove , true , iCnt - 1 ) ;
			iReturn = std :: min ( iReturn , iGetMinMove ( i , vMove , false , iCnt - 1 ) ) ;

			return iReturn + iMove ;
		}
	} while ( i != iIndex ) ;

	return 1e4 ;
}

int solution ( string name )
{
	int iLen = name.size () ;
	const char * cpName = name.data () ;
	vector < bool > vMove ( iLen , false ) ;
	int iMove = 0 ;
	int iCnt = 0 ;



	for ( int i = 0 ; i < iLen ; ++i )
	{
		if ( 'A' != cpName [ i ] )
		{
			answer += std :: min ( cpName [ i ] - 'A' , 1 + 'Z' - cpName [ i ] ) ;
			vMove [ i ] = true ;
			++ iCnt ;
		}
	}
	if ( vMove [ 0 ] )
	{
		vMove [ 0 ] = false ;
		-- iCnt ;
	}
	iMove = iGetMinMove ( 0 , vMove , true , iCnt ) ;
	iMove = std :: min ( iMove , iGetMinMove ( 0 , vMove , false , iCnt ) ) ;


	return answer + iMove ;
}

int main ()
{
	int i = solution ( "JAZ" ) ;
}