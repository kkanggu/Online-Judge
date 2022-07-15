#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using std :: string ;
using std :: vector ;
using std :: unordered_map ;
using std :: pair ;
using std :: make_pair ;

vector < int > solution ( string msg )
{
    vector < int > answer ;
    unordered_map < string , int > umDict ;
    int iMaxDictLen = 1 ;
    string strCheck ;
    int iMsgSize = msg.size () ;
    int iMaxDictIndex = 26 ;



    for ( int i = 0 ; i < 26 ; ++i )
    {
        strCheck = 'A' + i ;
        umDict [ strCheck ] = i + 1 ;
    }

    for ( int i = 0 ; i < iMsgSize ; )
    {
        for ( int j = iMaxDictLen ; j >= 1 ; --j )
        {
            if ( i + j > iMsgSize )
                continue ;

            strCheck = msg.substr ( i , j ) ;

            if ( 0 != umDict [ strCheck ] )                 // Find dict
            {
                answer.emplace_back ( umDict [ strCheck ] ) ;

                if ( i + j < iMsgSize )                     // need to add new dict
                {
                    strCheck += msg [ i + j ] ;
                    umDict [ strCheck ] = ++ iMaxDictIndex ;

                    iMaxDictLen = std :: max ( iMaxDictLen , j + 1 ) ;
                }

                i += j ;


                break ;
            }
        }
    }

    
    return answer ;
}

int main ()
{
	vector < int > v = solution ( "KAKAO" ) ;
}