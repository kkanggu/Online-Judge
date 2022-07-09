#include <string>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using std :: vector ;
using std :: string ;
using std :: pair ;
using std :: unordered_map ;

pair < int , int > getCondition ( string strCondition )
{
	int iApplyInfo = 0 ;			// Bit masking. Each details at 1 bit. All 9 bits
	char * cpTemp = strtok ( & strCondition [ 0 ] , " " ) ;



	if ( 'c' == cpTemp [ 0 ] )
		iApplyInfo |= 0b100000000 ;
	else if ( 'j' == cpTemp [ 0 ] )
		iApplyInfo |= 0b010000000 ;
	else if ( 'p' == cpTemp [ 0 ] )
		iApplyInfo |= 0b001000000 ;
	else
		iApplyInfo |= 0b111000000 ;

	cpTemp = strtok ( NULL , " " ) ;
	if ( 'a' == cpTemp [ 0 ] )
		cpTemp = strtok ( NULL , " " ) ;

	if ( 'b' == cpTemp [ 0 ] )
		iApplyInfo |= 0b000100000 ;
	else if ( 'f' == cpTemp [ 0 ] )
		iApplyInfo |= 0b000010000 ;
	else
		iApplyInfo |= 0b000110000 ;
	
	cpTemp = strtok ( NULL , " " ) ;
	if ( 'a' == cpTemp [ 0 ] )
		cpTemp = strtok ( NULL , " " ) ;

	if ( 'j' == cpTemp [ 0 ] )
		iApplyInfo |= 0b000001000 ;
	else if ( 's' == cpTemp [ 0 ] )
		iApplyInfo |= 0b000000100 ;
	else
		iApplyInfo |= 0b000001100 ;

	cpTemp = strtok ( NULL , " " ) ;
	if ( 'a' == cpTemp [ 0 ] )
		cpTemp = strtok ( NULL , " " ) ;

	if ( 'c' == cpTemp [ 0 ] )
		iApplyInfo |= 0b000000010 ;
	else if ( 'p' == cpTemp [ 0 ] )
		iApplyInfo |= 0b000000001 ;
	else
		iApplyInfo |= 0b000000011 ;

	cpTemp = strtok ( NULL , " " ) ;

	return std :: make_pair ( iApplyInfo , atoi ( cpTemp ) ) ;
}

vector < int > solution ( vector < string > info , vector < string > query )
{
	vector < int > answer ;
	int iInfoLen = info.size () ;
	int iQueryLen = query.size () ;
	unordered_map < int , vector < int > > umApply ;



	answer.resize ( iQueryLen ) ;
	for ( int i = 0 ; i < iInfoLen ; ++i )
	{
		pair < int , int > tempPair = getCondition ( info [ i ] ) ;

		umApply [ tempPair.first ].emplace_back ( tempPair.second ) ;
	}

	for ( auto iter = umApply.begin () ; iter != umApply.end () ; ++ iter )
	{
		std :: sort ( iter -> second.begin () , iter -> second.end () ) ;
	}

	for ( int i = 0 ; i < iQueryLen ; ++i )
	{
		pair < int , int > conditionPair = getCondition ( query [ i ] ) ;

		for ( auto iter = umApply.begin () ; iter != umApply.end () ; ++ iter )
		{
			if ( iter -> first != ( iter -> first & conditionPair.first ) )
				continue ;

			vector < int > vTemp = umApply [ iter -> first ] ;

			if ( ! vTemp.empty () )
			{
				answer [ i ] += ( vTemp.size () - ( std :: lower_bound ( vTemp.begin () , vTemp.end () , conditionPair.second ) - vTemp.begin () ) ) ;
			}
		}
	}


	return answer ;
}

int main ()
{
	vector < int > a = solution ( {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"}
	, {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"} ) ;
}