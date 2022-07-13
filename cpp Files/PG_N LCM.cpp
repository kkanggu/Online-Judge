#include <vector>
#include <unordered_map>
#include <cmath>

using std :: vector ;
using std :: unordered_map ;

int solution ( vector < int > arr )
{
	int answer = 1 ;
	vector < int > vPrime ;
	unordered_map < int , int > umCommonDivisor ;
	int iPrimeSize = 1 ;



	vPrime.emplace_back ( 2 ) ;					// Find prime
	for ( int i = 3 ; i < 100 ; i += 2 )
	{
		bool bPrime = true ;

		for ( int j = 0 ; ( j < iPrimeSize ) && ( vPrime [ j ] < sqrt ( i ) ) ; ++j )
		{
			if ( 0 == i % vPrime [ j ] )
			{
				bPrime = false ;

				break ;
			}
		}

		if ( bPrime )
		{
			vPrime.emplace_back ( i ) ;
			++ iPrimeSize ;
		}
	}

	for ( int i = 0 ; i < arr.size () ; ++i )
	{
		for ( int j = 0 ; ( j < iPrimeSize ) && ( 1 != arr [ i ] ) ; ++j )
		{
			int iCurrentPrime = vPrime [ j ] ;
			for ( int k = 0 ; k < umCommonDivisor [ iCurrentPrime ] ; ++k )
			{
				if ( 0 == arr [ i ] % iCurrentPrime )
					arr [ i ] /= iCurrentPrime ;
				else
					break ;
			}
			while ( 0 == arr [ i ] % iCurrentPrime )
			{
				arr [ i ] /= iCurrentPrime ;
				++ umCommonDivisor [ iCurrentPrime ] ;
				answer *= iCurrentPrime ;
			}
		}
	}

	return answer ;
}