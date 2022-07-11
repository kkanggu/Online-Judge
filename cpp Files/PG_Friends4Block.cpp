#include <string>
#include <vector>
#include <queue>
#include <utility>

using std :: string ;
using std :: vector ;
using std :: queue ;
using std :: pair ;
using std :: make_pair ;

int solution (int m , int n , vector < string > board )
{
	int answer = 0 ;
	bool bErase = true ;
	queue < pair < int , int > > qErase ;
	queue < char > qReplace ;



	while ( bErase )
	{
		bErase = false ;

		for ( int i = 0 ; i < m - 1 ; ++i )
		{
			for ( int j = 0 ; j < n - 1 ; ++j )
			{
				char cBlock = board [ i ] [ j ] ;

				if ( '-' == cBlock )
					continue ;

				if ( ( cBlock == board [ i ] [ j + 1 ] ) && ( cBlock == board [ i + 1 ] [ j ] ) && ( cBlock == board [ i + 1 ] [ j + 1 ] ) )
				{
					qErase.emplace ( make_pair ( i , j ) ) ;
					qErase.emplace ( make_pair ( i , j + 1 ) ) ;
					qErase.emplace ( make_pair ( i + 1 , j ) ) ;
					qErase.emplace ( make_pair ( i + 1 , j + 1 ) ) ;

					bErase = true ;
				}
			}
		}

		while ( ! qErase.empty () )
		{
			pair < int , int > pPoint = qErase.front () ;
			qErase.pop () ;

			if ( '-' != board [ pPoint.first ] [ pPoint.second ] )
			{
				board [ pPoint.first ] [ pPoint.second ] = '-' ;

				++ answer ;
			}
		}
		if ( bErase )
		{
			for ( int j = 0 ; j < n ; ++j )
			{
				for ( int i = m - 1 ; i >= 0 ; --i )
				{
					if ( '-' != board [ i ] [ j ] )
						qReplace.emplace ( board [ i ] [ j ] ) ;
				}
				for ( int i = m - 1 ; i >= 0 ; --i )
				{
					if ( qReplace.empty () )
						board [ i ] [ j ] = '-' ;
					else
					{
						board [ i ] [ j ] = qReplace.front () ;
						qReplace.pop () ;
					}
				}
			}
		}
	}


	return answer ;
}

int main ()
{
//	int i = solution ( 4 , 5 , {"CCBDE", "AAADE", "AAABF", "CCBBF"} ) ;
	int i = solution ( 6 , 6 , {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"} ) ;
}