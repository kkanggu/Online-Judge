#include <string>
#include <vector>
#include <unordered_map>

using std :: string ;
using std :: vector ;
using std :: unordered_map ;

vector < int > solution ( int n , vector < string > words )
{
	vector < int > answer ;
	unordered_map < string , int > umWordCheck ;
	int iSize = words.size () ;



	++ umWordCheck [ words [ 0 ] ] ;

	for ( int i = 1 ; i < iSize ; ++i )
	{
		string strFormer = words [ i - 1 ] ;
		++ umWordCheck [ words [ i ] ] ;

		if ( ( 2 == umWordCheck [ words [ i ] ] ) || ( strFormer [ strFormer.size () - 1 ] != words [ i ] [ 0 ] ) )
		{
			answer.emplace_back ( i % n + 1 ) ;
			answer.emplace_back ( i / n + 1 ) ;

			break ;
		}
	}

	if ( answer.empty () )
	{
		answer.emplace_back ( 0 ) ;
		answer.emplace_back ( 0 ) ;
	}
    

	return answer ;
}