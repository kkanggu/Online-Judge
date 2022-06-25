#include <string>
#include <vector>
#include <algorithm>

using std :: vector ;
using std :: string ;

char chToLowerCase ( char ch )
{
	if ( 'a' <= ch )
		ch -= 32 ;

	return ch ;
}

int solution ( int cacheSize , vector < string > cities )
{
    int answer = 0 ;
	vector < string > vCache ;
	vCache.resize ( 30 ) ;
	int irgCache [ 30 ] = { 0 , } ;
	string * strpTemp = cities.data () ;
	string * strpCache = vCache.data () ;
	int iCitySize = cities.size () ;
	bool bCacheMiss = true ;



	std :: fill ( irgCache , irgCache + 30 , -1 ) ;	// Fill with -1 to replace first

	if ( 0 == cacheSize )
		return 5 * iCitySize ;

	for ( int i = 0 ; i < iCitySize ; ++i )			// Each city
	{
		string strLower = strpTemp [ i ] ;
		std :: transform ( strLower.begin () , strLower.end () , strLower.begin () , chToLowerCase ) ;
		bCacheMiss = true ;

		for ( int j = 0 ; j < cacheSize ; ++j )
		{
			if ( 0 == strLower.compare ( strpCache [ j ] ) )		// If hit
			{
				bCacheMiss = false ;
				++ answer ;
				irgCache [ j ] = i ;

				break ;
			}
		}

		if ( bCacheMiss )
		{
			int iIndex = 0 ;

			for ( int j = 1 ; j < cacheSize ; ++j )
			{
				if ( irgCache [ j ] < irgCache [ iIndex ] )
				{
					iIndex = j ;
				}
			}

			irgCache [ iIndex ] = i ;
			strpCache [ iIndex ] = strLower ;

			answer += 5 ;
		}
	}


    return answer ;
}

int main ()
{
	vector < string > city = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"} ;

	int i = solution ( 3 , city ) ;
}