#include <string>
#include <vector>
#include <utility>

using std :: vector ;
using std :: string ;
using std :: pair ;
using std :: make_pair ;

string eraseSharp ( string strTarget )
{
	int iStrSize = strTarget.size () ;



	for ( int i = 1 ; i < iStrSize ; ++i )
	{
		if ( '#' == strTarget [ i ] )
		{
			strTarget [ i - 1 ] += 7 ;
			strTarget = strTarget.substr ( 0 , i ) + strTarget.substr ( i + 1 , iStrSize - i - 1 ) ;
			-- iStrSize ;
		}
	}

	return strTarget ;
}

pair < string , pair < int , string > > pGetMusicInfo ( string strMusic )
{
	int iIndex = 0 ;
	int iMusicStart = ( strMusic [ 0 ] - '0' ) * 600 + ( strMusic [ 1 ] - '0' ) * 60 + ( strMusic [ 3 ] - '0' ) * 10 + ( strMusic [ 4 ] - '0' ) ;
	int iMusicEnd = ( strMusic [ 6 ] - '0' ) * 600 + ( strMusic [ 7 ] - '0' ) * 60 + ( strMusic [ 9 ] - '0' ) * 10 + ( strMusic [ 10 ] - '0' ) ;
	int iMusicLen = iMusicEnd - iMusicStart ;



	if ( iMusicLen < 0 )
		iMusicLen += 1440 ;
	
	for ( iIndex = 12 ; iIndex < strMusic.size () ; ++ iIndex )
	{
		if ( ',' == strMusic [ iIndex ] )
			break ;
	}

	string strName = strMusic.substr ( 12 , iIndex - 12 ) ;
	++ iIndex ;
	string strTemp = eraseSharp ( strMusic.substr ( iIndex , strMusic.size () - iIndex ) ) ;
	string strSheet = "" ;

	for ( int i = 0 ; i < ( iMusicLen / strTemp.size () ) ; ++i )
	{
		strSheet += strTemp ;
	}
	strSheet += strTemp.substr ( 0 , iMusicLen % strTemp.size () ) ;

	return { strName , { iMusicLen , strSheet } } ;
}

string solution ( string m , vector < string > musicinfos )
{
	string strInput = eraseSharp ( m ) ;
	int iInputSize = eraseSharp ( strInput ).size () ;
	int iMusicSize = musicinfos.size () ;
	pair < string , int > pAnswer ;				// Music name , length



	pAnswer.first = "" ;
	pAnswer.second = -1 ;

	for ( int i = 0 ; i < iMusicSize ; ++i )
	{
		pair < string , pair < int , string > > pTemp = pGetMusicInfo ( musicinfos [ i ] ) ;	// Music name , length , sheet

		if ( ( pTemp.second.first < iInputSize ) || ( pTemp.second.first < pAnswer.second ) )
			continue ;

		for ( int j = 0 ; j <= pTemp.second.first - iInputSize ; ++j )
		{
			if ( 0 == strInput.compare ( pTemp.second.second.substr ( j , iInputSize ) ) )
			{
				if ( pAnswer.second < pTemp.second.first )		// Longer music
				{
					pAnswer.first = pTemp.first ;
					pAnswer.second = pTemp.second.first ;
				}

				break ;
			}
		}
	}


	return ( "" != pAnswer.first ) ? pAnswer.first : "(None)" ;
}

int main ()
{
	//string str = solution ( "ABCDEFG", {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"} ) ;
	string str = solution ( "CC#BCC#BCC#BCC#B", {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"} ) ;
	//string str = solution ( "A#", {"13:00,13:02,HAPPY,B#A#"} ) ;
	//string str = solution ( "CDEFGAC", {"12:00,12:06,HELLO,CDEFGA"} ) ;
	//string str = solution ( "CC#BCC#BCC#", {"03:00,03:08,FOO,CC#B" , "03:00,03:16,ABC,CC#B" , "03:00,03:47,DEF,CC#B" } ) ;
	//string str = solution ( "CC#BCC#BCC#BCC#B", {"03:00,03:10,FOO,CC#BAAFECDBEAFECDBEAEDBCBAFEADB", "04:00,04:08,BAR,CC#BCC#BCC#B"} ) ;
	// str = solution ( "CC", {"04:00,04:02,ZERO,ACC"} ) ;
}