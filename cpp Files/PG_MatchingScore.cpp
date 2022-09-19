#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std :: vector ;
using std :: string ;
using std :: transform ;
using std :: unordered_map ;

struct link
{
	string strLink ;
	vector < string > strExtLink ;
	double dBasicScore ;
	double dLinkScore ;
} ;

int iGetMatchingScore ( string strWord , string strPage , int iStartIndex , int iEndIndex )
{
	int iIndex = iStartIndex ;
	int iScore = 0 ;
	
	
	
	transform ( strWord.begin () , strWord.end () , strWord.begin () , :: tolower ) ;
	
	for ( int i = iStartIndex ; i < iEndIndex ; ++i )
	{
		if ( 0 == isalpha ( strPage [ i ] ) )
		{
			++ iIndex ;

			string strTemp = strPage.substr ( iIndex , i - iIndex ) ;
			transform ( strTemp.begin () , strTemp.end () , strTemp.begin () , :: tolower ) ;
			
			if ( 0 == strTemp.compare ( strWord ) )
				++ iScore ;
			
			iIndex = i ;
		}
	}
	
	
	return iScore ;
}

int solution ( string word , vector < string > pages )
{
	int answer = 0 ;
	double dMaxScore = 0 ;
	int iIndex = 0 ;
	int iPageSize = pages.size () ;
	string strLinkHeader = "<meta property=\"og:url\" content=\"" ;
	string strExtLinkHeader = "<a href=\"" ;
	vector < link > vLinks ;
	unordered_map < string , int > umLinkToIndex ;
	
	
	for ( int i = 0 ; i < iPageSize ; ++i )
	{
		link newLink ;
		
		int iStartIndex = pages [ i ].find ( strLinkHeader ) + strLinkHeader.size () ;      // Get url
		int iEndIndex = pages [ i ].find ( "\"/" , iStartIndex ) ;
		newLink.strLink = pages [ i ].substr ( iStartIndex , iEndIndex - iStartIndex ) ;
		umLinkToIndex [ newLink.strLink ] = i + 1 ;
		
		iStartIndex = pages [ i ].find ( "<body>" , iEndIndex ) + 6 ;						// Get basic score
		iEndIndex = pages [ i ].find ( "</body>" , iStartIndex ) ;
		newLink.dBasicScore = iGetMatchingScore ( word , pages [ i ] , iStartIndex , iEndIndex ) ;
		newLink.dLinkScore = 0 ;
		
		
		for ( int j = iStartIndex ; j < iEndIndex ; ++j )									// Get external links
		{
			j = pages [ i ].find ( strExtLinkHeader , j ) + strExtLinkHeader.size () ;
			
			if ( ( j == string :: npos ) || ( j < iStartIndex ) || ( j > iEndIndex ) )
				break ;
			
			int iTempEndIndex = pages [ i ].find ( "\">" , j ) ;
			newLink.strExtLink.emplace_back ( pages [ i ].substr ( j , iTempEndIndex - j ) ) ;
		}
		
		vLinks.emplace_back ( newLink ) ;
	}
	
	for ( int i = 0 ; i < iPageSize ; ++i )							// Calculate link score
	{
		link tempLink = vLinks [ i ] ;
		int iLinkSize = tempLink.strExtLink.size () ;
		double dLinkScore = tempLink.dBasicScore / iLinkSize ;
		
		for ( int j = 0 ; j < iLinkSize ; ++j )
		{
			int iIndex = umLinkToIndex [ tempLink.strExtLink [ j ] ] - 1 ;
			
			if ( -1 != iIndex )
				vLinks [ iIndex ].dLinkScore += dLinkScore ;
		}
	}
	for ( int i = 0 ; i < iPageSize ; ++i )
	{
		link tempLink = vLinks [ i ] ;
		
		if ( dMaxScore < tempLink.dBasicScore + tempLink.dLinkScore )
		{
			dMaxScore = tempLink.dBasicScore + tempLink.dLinkScore ;
			answer = i ;
		}
	}
	
	
	return answer ;
}