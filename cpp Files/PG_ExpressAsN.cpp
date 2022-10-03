#include <vector>
#include <algorithm>

using std :: vector ;

int solution ( int N , int number )
{
	vector < vector < int > > vNumbers ( 9 ) ;		// [ i ] : Result numbers using i Ns
	long long llTemp = N ;
	
	
	
	if ( N == number )
		return 1 ;
	for ( int i = 1 ; i <= 8 ; ++i )
	{
		if ( llTemp == number )
			return i ;
		
		vNumbers [ i ].emplace_back ( llTemp ) ;
		llTemp *= 10 ;
		llTemp += N ;
	}
	for ( int i = 2 ; i <= 8 ; ++i )
	{
		for ( int j = 1 ; j < i ; ++j )
		{
			int iLeftCount = vNumbers [ j ].size () - 1 ;
			
			for ( ; iLeftCount >= 0 ; -- iLeftCount )
			{
				if ( 0 == vNumbers [ j ] [ iLeftCount ] )
						continue ;

				int iRightCount = vNumbers [ i - j ].size () - 1 ;
				
				for ( ; iRightCount >= 0 ; -- iRightCount )
				{
					if ( 0 == vNumbers [ i - j ] [ iRightCount ] )
					{
						vNumbers [ i ].emplace_back ( vNumbers [ j ] [ iLeftCount ] ) ;
						vNumbers [ i ].emplace_back ( 0 ) ;
						continue ;
					}


					llTemp = ( long long ) vNumbers [ j ] [ iLeftCount ] + vNumbers [ i - j ] [ iRightCount ] ;
					if ( ( -1e9 <= llTemp ) && ( llTemp <= 1e9 ) )
					{
						if ( llTemp == number )
							return i ;
						vNumbers [ i ].emplace_back ( llTemp ) ;
					}

					llTemp = ( long long ) vNumbers [ j ] [ iLeftCount ] - vNumbers [ i - j ] [ iRightCount ] ;
					if ( ( -1e9 <= llTemp ) && ( llTemp <= 1e9 ) )
					{
						if ( llTemp == number )
							return i ;
						vNumbers [ i ].emplace_back ( llTemp ) ;
					}
					
					llTemp = ( long long ) vNumbers [ j ] [ iLeftCount ] * vNumbers [ i - j ] [ iRightCount ] ;
					if ( ( -1e9 <= llTemp ) && ( llTemp <= 1e9 ) )
					{
						if ( llTemp == number )
							return i ;
						vNumbers [ i ].emplace_back ( llTemp ) ;
					}
					
					llTemp = ( long long ) vNumbers [ j ] [ iLeftCount ] / vNumbers [ i - j ] [ iRightCount ] ;
					if ( ( -1e9 <= llTemp ) && ( llTemp <= 1e9 ) )
					{
						if ( llTemp == number )
							return i ;
						vNumbers [ i ].emplace_back ( llTemp ) ;
					}
				}
			}
		}
		
		std :: sort ( vNumbers [ i ].begin () , vNumbers [ i ].end () ) ;
		vNumbers [ i ].erase ( std :: unique ( vNumbers [ i ].begin () , vNumbers [ i ].end () ) , vNumbers [ i ].end () ) ;
	}
	
	
	return -1 ;
}