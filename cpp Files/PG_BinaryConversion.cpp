#include <string>
#include <vector>

using std :: vector ;
using std :: string ;

vector < int > solution ( string s )
{
	vector < int > answer ( 2 , 0 ) ;
	int iCnt = 0 ;
	int iSize = s.size () ;
	const char * cpTemp = s.data () ;
	int iTarget = 0 ;



	for ( int i = 0 ; i < iSize ; ++i )
	{
		if ( '1' == cpTemp [ i ] )
			++ iCnt ;
	}
	if ( 0 == iCnt )
	{
		return answer ;
	}

	++ answer [ 0 ] ;
	answer [ 1 ] += iSize - iCnt ;
	iTarget = iCnt ;

	while ( true )
	{
		iCnt = 0 ;
		iSize = 0 ;
		
		while ( 0 != iTarget )
		{
			if ( 1 & iTarget )
				++ iCnt ;

			iTarget >>= 1 ;
			++ iSize ;
		}
		if ( 1 == iSize )
			return answer ;

		++ answer [ 0 ] ;
		answer [ 1 ] += iSize - iCnt ;
		iTarget = iCnt ;
	}

	
	return answer ;
}

int main ()
{
//	vector < int > s = solution ( "110010101001" ) ;
	vector < int > s = solution ( "01110" ) ;
}