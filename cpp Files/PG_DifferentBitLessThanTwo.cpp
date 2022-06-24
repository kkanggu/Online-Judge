#include <vector>

using std :: vector ;

vector < long long > solution ( vector < long long > numbers )
{
	vector < long long > answer ;
	long long * llpTemp = numbers.data () ;
	int iLen = numbers.size () ;



	for ( int i = 0 ; i < iLen ; ++i )
	{
		for ( int j = 0 ; j <= 50 ; ++j )					// Max 50 bit, but it''s not all 1. So check only 50 bits
		{
			if ( 0 == ( ( llpTemp [ i ] >> j ) % 2 ) )		// Find 0
			{
				long long llTemp = 1LL << j ;
				
				answer.emplace_back ( llpTemp [ i ] + llTemp - ( llTemp >> 1 ) ) ;

				break ;
			}
		}
	}


	return answer ;
}

int main ()
{
	vector < long long > l = { 2 , 1001 , 337 , 0 , 1 , 333 } ;

	vector < long long > ans = solution ( l ) ;
}