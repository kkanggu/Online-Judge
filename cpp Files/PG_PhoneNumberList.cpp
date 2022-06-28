#include <string>
#include <vector>

using std :: string ;
using std :: vector ;

bool solution ( vector < string > phone_book )
{
	int iLen = phone_book.size () ;
	int iCurrentSize = 0 ;
	int iNextSize = 0 ;



	std :: sort ( phone_book.begin () , phone_book.end () ) ;
	iNextSize = phone_book [ 0 ].size () ;


	for ( int i = 0 ; i < iLen - 1 ; ++i )
	{
		iCurrentSize = iNextSize ;
		iNextSize = phone_book [ i + 1 ].size () ;

		if ( ( iCurrentSize > iNextSize ) ||
			( phone_book [ i ] != phone_book [ i + 1 ].substr ( 0 , iCurrentSize ) ) )
		{
			continue ;
		}

		return false ;
	}


	return true ;
}