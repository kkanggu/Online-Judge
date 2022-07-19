#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using std :: vector ;
using std :: string ;
using std :: unordered_map ;
using std :: pair ;
using std :: make_pair ;

pair < pair < int , int > , bool > pGetRecordInfo ( string strInfo )		// Time to minute , Car number , IsGetIn
{
	int iStringSize = strInfo.size () ;
	const char * cpString = strInfo.data () ;
	int iMinute = ( cpString [ 0 ] - '0' ) * 600 + ( cpString [ 1 ] - '0' ) * 60 + ( cpString [ 3 ] - '0' ) * 10 + ( cpString [ 4 ] - '0' ) ;
	int iCarNumber = 0 ;
	bool bIsGetIn = true ;
	
	
	
	for ( int i = 6 ; i < iStringSize ; ++i )
	{
		if ( ' ' == cpString [ i ] )
		{
			iCarNumber = std :: stoi ( strInfo.substr ( 6 , i - 6 ) ) ;
			
			if ( 'O' == cpString [ i + 1 ] )
				bIsGetIn = false ;
			
			return make_pair ( make_pair ( iMinute , iCarNumber ) , bIsGetIn ) ;
		}
	}
}

vector < int > solution ( vector < int > fees , vector < string > records )
{
	vector < int > answer ;
	vector < pair < int , int > > vCarAndCost ;
	unordered_map < int , int > umTotalMinute ;
	unordered_map < int , int > umCarInMinute ;
	int iBasicTime = fees [ 0 ] ;
	int iBasicCost = fees [ 1 ] ;
	int iUnitTime = fees [ 2 ] ;
	int iUnitCost = fees [ 3 ] ;
	int iRecordSize = records.size () ;
	
	
	
	for ( int i = 0 ; i < iRecordSize ; ++i )
	{
		pair < pair < int , int > , bool > pRecordInfo = pGetRecordInfo ( records [ i ] ) ;
		
		if ( pRecordInfo.second )		// In
		{
			umCarInMinute [ pRecordInfo.first.second ] = pRecordInfo.first.first ;
		}
		else							// Out
		{
			umTotalMinute [ pRecordInfo.first.second ] += pRecordInfo.first.first - umCarInMinute [ pRecordInfo.first.second ] ;
			umCarInMinute.erase ( pRecordInfo.first.second ) ;
		}
	}
	
	for ( auto iter = umCarInMinute.begin () ; iter != umCarInMinute.end () ; ++ iter )
	{
		umTotalMinute [ iter -> first ] += 1439 - iter -> second ;
	}
	for ( auto iter = umTotalMinute.begin () ; iter != umTotalMinute.end () ; ++ iter )
	{
		vCarAndCost.emplace_back ( make_pair ( iter -> first , iter -> second ) ) ;
	}
	
	std :: sort ( vCarAndCost.begin () , vCarAndCost.end () ) ;
	int iCarSize = vCarAndCost.size () ;
	
	for ( int i = 0 ; i < iCarSize ; ++i )
	{
		int iMinute = vCarAndCost [ i ].second ;
		int iMoney = iBasicCost ;
		
		if ( iBasicTime < iMinute )
			iMoney += ( iMinute - iBasicTime + iUnitTime - 1 ) / iUnitTime * iUnitCost ;
		
		answer.emplace_back ( iMoney ) ;
		
		printf ( "%d\n" , iMoney ) ;
	}
	
	
	return answer ;
}