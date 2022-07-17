#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std :: vector ;
using std :: string ;

int solution ( int n , int k )
{
	int answer = 0 ;
	vector < long long > vStringParseNumber ;
	string strKDigit = "" ;
	int iMaxDigit = 0 ;
	const char * cpString ;
	int iStringSize ;
	int iTemp = 0 ;
	long long llMaxPrime = 0 ;
	long long llSubstrNumber = 0 ;


	while ( 0 != n )
	{
		strKDigit += '0' + n % k ;
		n /= k ;
	}
	std :: reverse ( strKDigit.begin () , strKDigit.end () ) ;
	cpString = strKDigit.data () ;
	iStringSize = strKDigit.size () ;

	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		if ( ( 0 != iTemp ) && ( '0' == cpString [ i ] ) )		// Parse number
		{
			llSubstrNumber = std :: stoll ( strKDigit.substr ( i - iTemp , iTemp ) ) ;

			if ( 2 == llSubstrNumber || ( ( 0 != ( llSubstrNumber % 2 ) ) && ( 1 != llSubstrNumber ) ) )			// Odd number
			{
				vStringParseNumber.emplace_back ( llSubstrNumber ) ;
				iMaxDigit = std :: max ( iMaxDigit , iTemp ) ;
			}
			
			iTemp = 0 ;
		}
		else if ( '0' != cpString [ i ] )
		{
			++ iTemp ;
		}
	}
	if ( 0 != iTemp )
	{
		llSubstrNumber = std :: stoll ( strKDigit.substr ( iStringSize - iTemp , iTemp ) ) ;
		
		if ( 2 == llSubstrNumber || ( ( 0 != ( llSubstrNumber % 2 ) ) && ( 1 != llSubstrNumber ) ) )				// Odd number
		{
			vStringParseNumber.emplace_back ( llSubstrNumber ) ;
			iMaxDigit = std :: max ( iMaxDigit , iTemp ) ;
		}
	}
	
	iTemp = vStringParseNumber.size () ;

	for ( int i = 0 ; i < iMaxDigit ; ++i )					// Find max prime number to check
	{
		llMaxPrime = llMaxPrime * 10 + iMaxDigit - 1 ;
	}
	for ( long long i = 2 ; i + 1 <= sqrt ( llMaxPrime ) + 1 ; ++i )
	{
		for ( int j = 0 ; j < iTemp ; ++j )
		{
			if ( ( vStringParseNumber [ j ] != i ) && ( 0 == ( vStringParseNumber [ j ] % i ) ) )
			{
				vStringParseNumber.erase ( vStringParseNumber.begin () + j ) ;
				-- iTemp ;
				-- j ;
			}
		}
	}


	return vStringParseNumber.size () + answer ;
}

int main ()
{
	int i = solution ( 36 , 3 ) ;
}