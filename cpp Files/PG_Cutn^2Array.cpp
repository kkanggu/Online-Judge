#include <vector>
#include <algorithm>

using std :: vector ;

vector < int > solution ( int n , long long left , long long right )
{
	vector < int > answer ;



	while ( left <= right )
	{
		answer.emplace_back ( std :: max ( left / n + 1 , left % n + 1 ) ) ;
		++ left ;
	}


	return answer ;
}

int main ()
{
	vector < int > v = solution ( 3 , 2 , 5 ) ;
}