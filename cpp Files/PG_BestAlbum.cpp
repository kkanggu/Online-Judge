#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using std :: vector ;
using std :: string ;
using std :: unordered_map ;
using std :: pair ;
using std :: sort ;

struct songNode
{
	int iIndex ;
	int iPlayed ;
	
	songNode ( int iIndex , int iPlayed ) : iIndex ( iIndex ) , iPlayed ( iPlayed ) {}
} ;

bool comp ( pair < string , pair < int , vector < songNode > > > & a , pair < string , pair < int , vector < songNode > > > & b )
{
	return a.second.first > b.second.first ;
}

vector < int > solution ( vector < string > genres , vector < int > plays )
{
	vector < int > answer ;
	unordered_map < string , pair < int , vector < songNode > > > umGenrePlayed ;
	int iSongSize = genres.size () ;
	
	
	
	for ( int i = 0 ; i < iSongSize ; ++i )						// Add song played group by genre
	{
		umGenrePlayed [ genres [ i ] ].first += plays [ i ] ;
		umGenrePlayed [ genres [ i ] ].second.emplace_back ( i , plays [ i ] ) ;
	}
	
	vector < pair < string , pair < int , vector < songNode > > > > vUmToVector ( umGenrePlayed.begin () , umGenrePlayed.end () ) ;			// Convert to vector to process easily
	std :: sort ( vUmToVector.begin () , vUmToVector.end () , comp ) ;
	iSongSize = vUmToVector.size () ;
	
	for ( int i = 0 ; i < iSongSize ; ++i )
	{
		vector < songNode > vSongList = vUmToVector [ i ].second.second ;
		sort ( vSongList.begin () , vSongList.end () , [] ( songNode & a , songNode & b )			// Sort by played, and index
			  {
				  if ( a.iPlayed > b.iPlayed )
					  return true ;
				  else if ( ( a.iPlayed == b.iPlayed ) && ( a.iIndex < b.iIndex ) )
					  return true ;
				  return false ;
			  } ) ;
		
		answer.emplace_back ( vSongList [ 0 ].iIndex ) ;
		
		if ( 1 != vSongList.size () )
		{
			answer.emplace_back ( vSongList [ 1 ].iIndex ) ;
		}
	}
	
	
	return answer ;
}