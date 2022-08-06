#include <string>
#include <vector>
#include <map>
#include <numeric>

using std :: string ;
using std :: vector ;
using std :: map ;
using std :: to_string ;

int iGetTimeStringToInt ( string strTime )
{
	int iHour = ( strTime [ 0 ] - '0' ) * 10 + strTime [ 1 ] - '0' ;
	int iMinute = ( strTime [ 3 ] - '0' ) * 10 + strTime [ 4 ] - '0' ;
	int iSecond = ( strTime [ 6 ] - '0' ) * 10 + strTime [ 7 ] - '0' ;
	
	return iHour * 3600 + iMinute * 60 + iSecond ;
}

string solution ( string play_time , string adv_time , vector < string > logs )
{
	string answer = "" ;
	int iLogSize = logs.size () ;
	map < int , int > mUserChange ;
	long long llTemp = 0 ;
	int iPlayTime = iGetTimeStringToInt ( play_time ) ;
	int iAdvTime = iGetTimeStringToInt ( adv_time ) ;
	int iStartIndex = 0 ;
	int iEndIndex = iAdvTime - 1 ;
	long long llMaxAccumulate = 0 ;
	int iMinStartTime = 0 ;
	vector < int > vViewerAtEachTime ( iPlayTime , 0 ) ;
	int * ipViewer = vViewerAtEachTime.data () ;
	
	
	
	for ( int i = 0 ; i < iLogSize ; ++i )
	{
		int iStart = iGetTimeStringToInt ( logs [ i ].substr ( 0 , 8 ) ) ;
		int iEnd = iGetTimeStringToInt ( logs [ i ].substr ( 9 , 8 ) ) ;
		
		++ mUserChange [ iStart ] ;
		-- mUserChange [ iEnd ] ;
	}
	
	for ( auto iter = mUserChange.begin () ; iter != mUserChange.end () ; ++ iter )
	{
		if ( 0 != llTemp )
		{
			std :: fill ( ipViewer + iStartIndex , ipViewer + iter -> first , llTemp ) ;
		}
		
		llTemp += iter -> second ;
		iStartIndex = iter -> first ;
	}
	iStartIndex = 0 ;
	
	llTemp = std :: accumulate ( vViewerAtEachTime.begin () , vViewerAtEachTime.begin () + iAdvTime , 0 ) ;
	llMaxAccumulate = llTemp ;
	iMinStartTime = 0 ;
	for ( int i = iAdvTime ; i < iPlayTime ; ++i )
	{
		llTemp -= ipViewer [ iStartIndex ++ ] ;
		llTemp += ipViewer [ ++ iEndIndex ] ;

		if ( llMaxAccumulate < llTemp )
		{
			llMaxAccumulate = llTemp ;
			iMinStartTime = iStartIndex ;
		}
	}

	answer = to_string ( iMinStartTime / 36000 ) + to_string ( iMinStartTime % 36000 / 3600 ) + ':' + to_string ( iMinStartTime % 3600 / 600 ) + to_string ( iMinStartTime % 600 / 60 ) + ':' + to_string ( iMinStartTime % 60 / 10 ) + to_string ( iMinStartTime % 10 ) ;
	
	return answer ;
}