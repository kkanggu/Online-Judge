#include <vector>
#include <algorithm>

using std :: vector ;

int solution ( int n , vector < int > money )
{
	int answer = 0 ;
	vector < long long > vDP ( n + 1 , 0 ) ;
	int iMoneySize = money.size () ;
	
	
	
	vDP [ 0 ] = 1 ;
	for ( int i = 0 ; i < iMoneySize ; ++i )
	{
		int iMoney = money [ i ] ;
		
		for ( int j = iMoney ; j <= n ; ++j )
		{
			vDP [ j ] += vDP [ j - iMoney ] ;
		}
	}
	
	
	return vDP [ n ] % 1000000007 ;
}