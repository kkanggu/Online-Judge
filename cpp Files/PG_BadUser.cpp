#include <string>
#include <vector>
#include <algorithm>

using std :: string ;
using std :: vector ;

int iUserSize ;

bool bCanBanUser ( long long llUser , long long llBan )
{
	while ( ( 0 != llUser ) && ( 0 != llBan ) )
	{
		int iUserValue = llUser & 63 ;
		int iBanValue = llBan & 63 ;
		
		if ( ( 63 != iBanValue ) && ( iUserValue != iBanValue ) )
			break ;
		
		llUser >>= 6 ;
		llBan >>= 6 ;
	}
	
	if ( ( 0 != llUser ) || ( 0 != llBan ) )
		return false ;
	
	return true ;
}

bool bIsConfigPossible ( long long * llpUser , long long * llpBan , vector < bool > & vUserIsUsed , int iBanCount , int iMaxBan )
{
	if ( iBanCount == iMaxBan )				// If all user is banned
		return true ;
	
	for ( int i = 0 ; i < iUserSize ; ++i )
	{
		if ( vUserIsUsed [ i ] )
			continue ;
		
		long long llUser = llpUser [ i ] ;
		
		if ( bCanBanUser ( llUser , llpBan [ iBanCount ] ) )		// Can ban this user
		{
			vUserIsUsed [ i ] = true ;
			if ( bIsConfigPossible ( llpUser , llpBan , vUserIsUsed , iBanCount + 1 , iMaxBan ) )
			{
				vUserIsUsed [ i ] = false ;

				return true ;
			}
			vUserIsUsed [ i ] = false ;
		}
	}

	return false ;
}

int iGetCharToInt ( char cChar )		// Change alphabet,number -> 1~36 and 63. 1~26 alphabet, 27~35 number, 63 *
{
	if ( '*' == cChar )
		return 63 ;
	if ( ( 'a' <= cChar) && ( cChar <= 'z' ) )
		return cChar - 'a' + 1 ;
	else
		return cChar - '0' + 27 ;
}

int solution ( vector < string > user_id , vector < string > banned_id )
{
	int answer = 0 ;
	iUserSize = user_id.size () ;
	int iBannedUserSize = banned_id.size () ;
	vector < long long > vUserList ;
	vector < long long > vBanList ;
	
	
	
	for ( int i = 0 ; i < iUserSize ; ++i )				// Change user_id to long long
	{
		int iStringSize = user_id [ i ].size () ;
		const char * cpString = user_id [ i ].data () ;
		long long llValue = 0 ;
		
		for ( int j = 0 ; j < iStringSize ; ++j )
		{
			llValue <<= 6 ;
			llValue += iGetCharToInt ( * cpString ++ ) ;
		}
		
		vUserList.emplace_back ( llValue ) ;
	}
	for ( int i = 0 ; i < iBannedUserSize ; ++i )		// Change banned_id to long long
	{
		int iStringSize = banned_id [ i ].size () ;
		const char * cpString = banned_id [ i ].data () ;
		long long llValue = 0 ;
		
		for ( int j = 0 ; j < iStringSize ; ++j )
		{
			llValue <<= 6 ;
			llValue += iGetCharToInt ( * cpString ++ ) ;
		}
		
		vBanList.emplace_back ( llValue ) ;
	}


	vector < bool > vUserIsUsed ( iUserSize , true ) ;
	std :: fill ( vUserIsUsed.begin () , vUserIsUsed.begin () + iBannedUserSize , false ) ;

	do
	{
		if ( bIsConfigPossible ( vUserList.data () , vBanList.data () , vUserIsUsed , 0 , iBannedUserSize ) )
			++ answer ;
	} while ( std :: next_permutation ( vUserIsUsed.begin () , vUserIsUsed.end () ) ) ;
	
	
	return answer ;
}