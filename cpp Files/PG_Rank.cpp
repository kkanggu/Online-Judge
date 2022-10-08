#include <vector>
#include <algorithm>
#include <stdio.h>

using std :: vector ;

int iGetNodeSum ( vector < vector < int > > & vMatchResult , int iIndex , int iResult , vector < bool > & vVisit )
{
	int iNodeSize = vMatchResult.size () ;
	int iReturn = 0 ;
	
	
	
	for ( int i = 0 ; i < iNodeSize ; ++i )
	{
		if ( ! vVisit [ i ] && ( iResult == vMatchResult [ iIndex ] [ i ] ) && ( i != iIndex ) )
		{
			vVisit [ i ] = true ;
			
			iReturn += iGetNodeSum ( vMatchResult , i , iResult , vVisit ) + 1 ;
		}
	}
	
	return iReturn ;
}

int solution ( int n , vector < vector < int > > results )
{
	int answer = 0 ;
	vector < vector < int > > vMatchResult ( n , vector < int > ( n , 0 ) ) ;		// 1 Win, -1 Lose
	int iResultSize = results.size () ;
	
	
	
	for ( int i = 0 ; i < iResultSize ; ++i )
	{
		int iWin = results [ i ] [ 0 ] - 1 ;
		int iLose = results [ i ] [ 1 ] - 1 ;
		
		vMatchResult [ iWin ] [ iLose ] = 1 ;
		vMatchResult [ iLose ] [ iWin ] = -1 ;
	}
	for ( int i = 0 ; i < n ; ++i )
	{
		vector < bool > vVisit ( n , false ) ;
		int iWinCount = iGetNodeSum ( vMatchResult , i , 1 , vVisit ) ;
		std :: fill ( vVisit.begin () , vVisit.end () , false ) ;
		int iLoseCount = iGetNodeSum ( vMatchResult , i , -1 , vVisit ) ;
		
		if ( n - 1 == iWinCount + iLoseCount )
			++ answer ;
	}
	
	
	return answer ;
}