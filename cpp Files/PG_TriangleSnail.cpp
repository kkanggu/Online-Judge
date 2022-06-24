#include <vector>

using std :: vector ;

vector < int > solution ( int n )
{
	vector < int > answer ;
	answer.resize ( ( n * ( n + 1 ) ) / 2 ) ;
	int * ipTemp = answer.data () ;
	int iLen = ( n * ( n + 1 ) ) / 2 ;
	int iLevel = 1 ;							// level of index
	int iIndex = 0 ;
	int iCnt = 0 ;



	--n ;
	while ( iCnt < iLen )
	{
		if ( iCnt + 1 == iLen )					// only one node left
		{
			ipTemp [ iIndex ] = ++ iCnt ;

			break ;
		}


		for ( int i = 0 ; i < n ; ++i )			// Left down = Current + level
		{
			ipTemp [ iIndex ] = ++ iCnt ;
			iIndex += iLevel ++ ;
		}
		for ( int i = 0 ; i < n ; ++i )			// Right = Current + 1
		{
			ipTemp [ iIndex ++ ] = ++ iCnt ;
		}
		for ( int i = 0 ; i < n ; ++i )			// Left up = Current - level
		{
			ipTemp [ iIndex ] = ++ iCnt ;
			iIndex -= iLevel -- ;
		}

		n -= 3 ;								// Start node, so need to move right down and left down
		iIndex += iLevel ++ ;					// Right down = Current + level + 1
		iIndex += ++ iLevel ;					// Left down = Current + level
	}


	return answer ;
}

int main ()
{
	vector < int > adf = solution ( 4 ) ;
}