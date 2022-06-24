#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cstring>

using std :: string ;
using std :: vector ;
using std :: unordered_map ;
using std :: pair ;
using std :: make_pair ;

vector < string > solution ( vector < string > record )
{
	vector < string > answer ;
	vector < pair < bool , string > > vMessage ;				// IsEnter , uid
	string * strTemp = record.data () ;
	const char * cpTemp ;
	int iLen = record.size () ;
	char crgData [ 30 ] = { 0 , } ;
	unordered_map < string , string > umStore ;
	pair < bool , string > * pTemp ;



	for ( int i = 0 ; i < iLen ; ++i )
	{
		strcpy ( crgData , strTemp [ i ].data () ) ;
		cpTemp = strtok ( crgData , " " ) ;

		if ( 0 == strcmp ( cpTemp , "Enter" ) )
		{
			cpTemp = strtok ( NULL , " " ) ;
			string strUser = cpTemp ;

			cpTemp = strtok ( NULL , " " ) ;
			string strNickname = cpTemp ;

			umStore [ strUser ] = strNickname ;
			vMessage.emplace_back ( make_pair ( true , strUser ) ) ;


			continue ;
		}
		if ( 0 == strcmp ( cpTemp , "Leave" ) )
		{
			cpTemp = strtok ( NULL , " " ) ;
			string strUser = cpTemp ;

			vMessage.emplace_back ( make_pair ( false , strUser ) ) ;


			continue ;
		}


		// Change

		cpTemp = strtok ( NULL , " " ) ;
		string strUser = cpTemp ;

		cpTemp = strtok ( NULL , " " ) ;
		string strNickname = cpTemp ;

		umStore [ strUser ] = strNickname ;
	}
	
	iLen = vMessage.size () ;					// make messages
	pTemp = vMessage.data () ;
	for ( int i = 0 ; i < iLen ; ++i )
	{
		string strMessage ;
		strMessage += umStore [ pTemp [ i ].second ] ;
		strMessage += "님이 " ;

		if ( pTemp [ i ].first )			// Enter
		{
			strMessage += "들어왔습니다." ;
		}
		else
		{
			strMessage += "나갔습니다." ;
		}

		answer.emplace_back ( strMessage ) ;
	}


	return answer ;
}

int main ()
{
	vector < string > re = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" } ;

	vector < string > result = solution ( re ) ;
}