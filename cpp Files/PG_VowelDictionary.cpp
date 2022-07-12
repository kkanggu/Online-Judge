#include <string>

using std :: string ;

int solution ( string word )
{
	int iAnswer = 0 ;
	int irgGap [ 5 ] = { 781 , 156 , 31 , 6 , 1 } ;



	iAnswer = word.size () ;

	for ( int i = 0 ; i < word.size () ; ++i )
	{
		if ( 'E' == word [ i ] )
			iAnswer += irgGap [ i ] ;
		else if ( 'I' == word [ i ] )
			iAnswer += irgGap [ i ] * 2 ;
		else if ( 'O' == word [ i ] )
			iAnswer += irgGap [ i ] * 3 ;
		else if ( 'U' == word [ i ] )
			iAnswer += irgGap [ i ] * 4 ;
	}

	return iAnswer ;
}