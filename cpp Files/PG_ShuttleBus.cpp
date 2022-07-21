#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using std :: string ;
using std :: vector ;
using std :: pair ;
using std :: make_pair ;

vector < pair < int , int > > getTimeOfStringWithSorted ( vector < string > vStringTime , int iMaxTime )
{
	int iStringSize = vStringTime.size () ;
	vector < pair < int , int > > vIntTime ;
	int iFormerTime = -1 ;
	int iCount = 0 ;
	
	
	
	std :: sort ( vStringTime.begin () , vStringTime.end () ) ;
	
	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		const char * cpString = vStringTime [ i ].data () ;
		int iCurrentTime = ( cpString [ 0 ] - '0' ) * 600 + ( cpString [ 1 ] - '0' ) * 60 + ( cpString [ 3 ] - '0' ) * 10 + ( cpString [ 4 ] - '0' ) ;
		
		
		
			
		if ( ( 0 != iCount ) && ( iFormerTime != iCurrentTime ) )
		{
			vIntTime.emplace_back ( make_pair ( iFormerTime , iCount ) ) ;
			iCount = 0 ;
		}
		if ( iMaxTime < iCurrentTime )		// Exceed last time, no need to count
		{
			iMaxTime = -1 ;
			
			break ;
		}
		
		if ( 0 == iCount )
		{
			iFormerTime = iCurrentTime ;
			iCount = 1 ;
		}
		else if ( iFormerTime == iCurrentTime )
		{
			++ iCount ;
		}
	}
	
	if ( -1 != iMaxTime )
		vIntTime.emplace_back ( make_pair ( iFormerTime , iCount ) ) ;
	
	return vIntTime ;
}

string solution ( int n , int t , int m , vector < string > timetable )
{
	string answer = "" ;
	int iFinalShuttleArrive = 540 + ( n - 1 ) * t ;
	vector < pair < int , int > > vTime = getTimeOfStringWithSorted ( timetable , iFinalShuttleArrive ) ;	// Time , count
	int iTableSize = vTime.size () ;
	int iLineupTime = -1 ;
	int iLineupCount = 0 ;
	int iLineupIndex = -1 ;
	int iRideCount = 0 ;
	
	

	for ( int i = 0 ; i < n ; ++i )
	{
		iRideCount = ( n - i ) * m ;
		
		while ( ( n - i - 1 ) * m != iRideCount )
		{
			if ( 0 == iLineupCount )
			{
				if ( iLineupIndex + 1 == iTableSize )		// Everyone ride
					break ;
				
				pair < int , int > pTimeInfo = vTime [ ++ iLineupIndex ] ;
				iLineupTime = pTimeInfo.first ;
				iLineupCount = pTimeInfo.second ;
			}
			if ( 540 + i * t < iLineupTime )				// Current people arrive late
				break ;
			
			-- iLineupCount ;
			-- iRideCount ;
		}
	}

	
	if ( 0 < iRideCount )			// Can ride at the last
	{
		iLineupTime = iFinalShuttleArrive ;
	}
	else							// Need to come early
	{
		-- iLineupTime ;
	}
	
	answer += std :: to_string ( iLineupTime / 600 ) ;
	answer += std :: to_string ( iLineupTime % 600 / 60 ) ;
	answer += ":" ;
	answer += std :: to_string ( iLineupTime % 60 / 10 ) ;
	answer += std :: to_string ( iLineupTime % 10 ) ;
	
	
	return answer ;
}