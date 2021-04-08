#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#pragma warning(disable:4996)

#define ABILITYMAX 10000 ;

using std :: string ;
using std :: cin ;

void Backtracking ( int irgAbility [] [ 20 ] , int irgTeamList [] [ 10] , int & iMin , int iStartCnt , int iLinkCnt , int iCapacity ) ;

int main ()
{
	int iCnt = 0 ;
	int irgAbility [ 20 ] [ 20 ] ;
	int irgTeamList [ 2 ] [ 10 ] ;
	int iMin = ABILITYMAX ;
	string strInput ;
	string strToken ;



	scanf ( "%d" , & iCnt ) ;

	std :: getline ( cin , strInput ) ;						// Refresh buffer (\n)
	

	for ( int i = 0 ; i < iCnt ; ++i )
	{
		std :: getline ( cin , strInput ) ;
		std::stringstream stream ( strInput ) ;				// Each line
				
		for ( int j = 0 ; j < iCnt ; ++j )
		{
			std :: getline ( stream , strToken , ' ' ) ;
			irgAbility [ i ] [ j ] = std :: stoi ( strToken ) ;
		}
	}

	Backtracking ( irgAbility , irgTeamList , iMin , 0 , 0 , iCnt / 2 ) ;

	printf ( "%d" , iMin ) ;

	return 0 ;
}

void Backtracking ( int irgAbility [] [ 20 ] , int irgTeamList [] [ 10 ] , int & iMin , int iStartCnt , int iLinkCnt , int iCapacity )
{
	if ( ( iCapacity != iStartCnt ) || ( iCapacity != iLinkCnt ) )											// Anything empty
	{
		if ( iCapacity != iStartCnt )																				// Lack of start team
		{
			irgTeamList [ 0 ] [ iStartCnt ] = iStartCnt + iLinkCnt ;
			Backtracking ( irgAbility , irgTeamList , iMin , iStartCnt + 1 , iLinkCnt , iCapacity ) ;
		}
		if ( iCapacity != iLinkCnt )																				// Lack of link team
		{
			irgTeamList [ 1 ] [ iLinkCnt ] = iStartCnt + iLinkCnt ;
			Backtracking ( irgAbility , irgTeamList , iMin , iStartCnt , iLinkCnt + 1 , iCapacity ) ;
		}
	}
	else
	{
		int iStartAbility = 0 ;
		int iLinkAbility = 0 ;



		for ( int i = 0 ; i < iCapacity - 1 ; ++i )
		{
			for ( int j = i + 1 ; j < iCapacity ; ++j )
			{
				iStartAbility += irgAbility [ irgTeamList [ 0 ] [ i ] ] [ irgTeamList [ 0 ] [ j ] ] ;		// Sij + Sji
				iStartAbility += irgAbility [ irgTeamList [ 0 ] [ j ] ] [ irgTeamList [ 0 ] [ i ] ] ;
				iLinkAbility += irgAbility [ irgTeamList [ 1 ] [ i ] ] [ irgTeamList [ 1 ] [ j ] ] ;
				iLinkAbility += irgAbility [ irgTeamList [ 1 ] [ j ] ] [ irgTeamList [ 1 ] [ i ] ] ;
			}
		}

		if ( abs ( iStartAbility - iLinkAbility ) < iMin )													// Can be -, so use abs
			iMin = abs ( iStartAbility - iLinkAbility ) ;
	}
}