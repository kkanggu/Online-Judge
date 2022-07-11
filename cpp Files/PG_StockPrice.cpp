#include <vector>
#include <unordered_map>

using std :: vector ;
using std :: unordered_map ;

vector < int > solution ( vector < int > prices )
{
	int iSize = prices.size () ;
	vector < int > answer ( iSize , 0 ) ;
	unordered_map < int , vector < int > > umStock ;
	vector < int > vPriceList ;



	for ( int i = 0 ; i < iSize ; ++i )
	{
		int iPrice = prices [ i ] ;

		for ( int j = vPriceList.size () - 1 ; j >= 0 ; --j  )
		{
			int iCheckPrice = vPriceList [ j ] ;

			if ( iCheckPrice <= iPrice )
				break ;

			for ( int k = 0 ; k < umStock [ iCheckPrice ].size () ; ++k )
			{
				answer [ umStock [ iCheckPrice ] [ k ] ] = i - umStock [ iCheckPrice ] [ k ] ;
			}

			umStock.erase ( iCheckPrice ) ;
			vPriceList.pop_back () ;
		}

		umStock [ iPrice ].emplace_back ( i ) ;
		vPriceList.emplace_back ( iPrice ) ;
	}
	for ( int i = 0 ; i < iSize ; ++i )
	{
		if ( 0 == answer [ i ] )
			answer [ i ] = iSize - i - 1 ;
	}

	return answer ;
}

int main ()
{
	vector < int > v = solution ( { 1 , 2 , 3 , 2 , 3 } ) ;
}