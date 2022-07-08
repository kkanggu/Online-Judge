#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#define ll long long

using std :: vector ;
using std :: string ;
using std :: pair ;
using std :: make_pair ;

vector < string > solution ( vector < vector < int > > line )
{
	vector < string > answer ;
	int iLen = line.size () ;
	vector < pair < ll , ll > > vPoints ;
	ll llUpper = -1e6 ;
	ll llDown = 1e6 ;
	ll llLeft = 1e6 ;
	ll llRight = -1e6 ;
	int iIndex = 0 ;



	for ( int i = 0 ; i < iLen ; ++i )
	{
		ll llA = line [ i ] [ 0 ] ;
		ll llB = line [ i ] [ 1 ] ;
		ll llE = line [ i ] [ 2 ] ;

		for ( int j = i + 1 ; j < iLen ; ++j )
		{
			ll llC = line [ j ] [ 0 ] ;
			ll llD = line [ j ] [ 1 ] ;
			ll llF = line [ j ] [ 2 ] ;

			if ( 0 != llA * llD - llB * llC )
			{
				ll llX = ( llB * llF - llE * llD ) / ( llA * llD - llB * llC ) ;
				ll llY = ( llE * llC - llA * llF ) / ( llA * llD - llB * llC ) ;

				if ( ( 0 == llX * llA + llY * llB + llE )
					&& ( 0 == llX * llC + llY * llD + llF ) )
				{
					vPoints.emplace_back ( make_pair ( llX , llY ) ) ;
				}
			}
		}
	}

	std :: sort ( vPoints.begin () , vPoints.end () , [] ( pair < ll , ll > a , pair < ll , ll > b )
		{ if ( ( a.second == b.second ) && ( a.first < b.first ) ) return true ; return ( a.second > b.second ) ; } ) ;
	iLen = vPoints.size () ;

	for ( int i = 0 ; i < iLen ; ++i )								// Check bound
	{
		llLeft = std :: min ( llLeft , vPoints [ i ].first ) ;
		llRight = std :: max ( llRight , vPoints [ i ].first ) ;
	}
	llUpper = vPoints [ 0 ].second ;
	llDown = vPoints [ iLen - 1 ].second ;


	for ( long long i = llUpper ; i >= llDown ; --i )
	{
		string strTemp ( llRight - llLeft + 1 , '.' ) ;

		while ( ( iIndex < iLen ) && ( i == vPoints [ iIndex ].second ) )
		{
			strTemp [ vPoints [ iIndex ++ ].first - llLeft ] = '*' ;
		}

		answer.emplace_back ( strTemp ) ;
	}


	return answer ;
}

int main ()
{
	vector < string > f = solution ( {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}} ) ;
}