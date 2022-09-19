#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using std :: string ;
using std :: vector ;
using std :: tolower ;

struct pageInfo
{
	string strURL ;
	vector < string > vExtref ;
	int iBasicScore ;
	long double ldLinkScore ;
} ;

int iGetBasicScore ( string strBody , string strWord )
{
	int iWordStartIndex = -1 ;
	int iBodySize = strBody.size () ;
	int iWordSize = strWord.size () ;
	int iCount = 0 ;
	
	
	std :: transform ( strBody.begin () , strBody.end () , strBody.begin () , [] ( unsigned char ch ) { return std :: tolower ( ch ) ; } ) ;
	std :: transform ( strWord.begin () , strWord.end () , strWord.begin () , [] ( unsigned char ch ) { return std :: tolower ( ch ) ; } ) ;

	for ( int i = 0 ; i < iBodySize ; ++i )
	{
		if ( ( -1 == iWordStartIndex ) && ( isalpha ( strBody [ i ] ) ) )
		{
			iWordStartIndex = i ;
		}
		else if ( ( -1 != iWordStartIndex ) && ( ! isalpha ( strBody [ i ] ) ) )
		{
			if ( ( iWordSize == i - iWordStartIndex ) && ( 0 == strBody.substr ( iWordStartIndex , iWordSize ).compare ( strWord ) ) )
			{
				++ iCount ;
			}
			
			iWordStartIndex = -1 ;
		}
	}
	
	
	return iCount ;
}

int solution ( string word , vector < string > pages )
{
	int answer = 0 ;
	long double ldMaxScore = -1 ;
	int iPageSize = pages.size () ;
	vector < pageInfo > vPageInfo ( iPageSize ) ;

	
	
	for ( int i = 0 ; i < iPageSize ; ++i )
	{
		string strPage = pages [ i ] ;
		string strPreURL = "<meta property=\"og:url\" content=\"https://" ;
		string strPreBody = "<body>" ;
		string strPreRef = "<a href=\"https://" ;
		string strURL = "" ;
		int iTemp ;
		vector < string > vExtref ;
		int iBasicScore = 0 ;


		iTemp = strPage.find ( strPreURL ) + strPreURL.size () ;			// Find URL

		while ( '\"' != strPage [ iTemp ] )
			strURL += strPage [ iTemp ++ ] ;
		

		
		iTemp = strPage.find ( strPreBody ) + strPreBody.size () ;			// Find body section and count word
		
		iBasicScore = iGetBasicScore ( strPage.substr ( iTemp , strPage.find ( "</body>" ) - iTemp ) , word ) ;
		
		
		iTemp = strPage.find ( strPreRef ) + strPreRef.size () ;			// Find external reference
		while ( iTemp != string :: npos )				// If npos, can't find
		{
			int iEndIndex = strPage.find ( "\"" , iTemp ) ;
			
			vExtref.emplace_back ( strPage.substr ( iTemp , iEndIndex - iTemp ) ) ;
			int iNextIndex = strPage.find ( strPreRef , iTemp + 1 ) + strPreRef.size () ;

			if ( iNextIndex <= iTemp )
				break ;
			
			iTemp = iNextIndex ;
		}


		vPageInfo [ i ].strURL = strURL ;
		vPageInfo [ i ].iBasicScore = iBasicScore ;
		vPageInfo [ i ].vExtref = vExtref ;
		vPageInfo [ i ].ldLinkScore = 0 ;
	}
	for ( int i = 0 ; i < iPageSize ; ++i )
	{
		if ( ldMaxScore < vPageInfo [ i ].iBasicScore )
		{
			ldMaxScore = vPageInfo [ i ].iBasicScore ;
			answer = i ;
		}

		int iExtrefSize = vPageInfo [ i ].vExtref.size () ;

		for ( int j = 0 ; j < iExtrefSize ; ++j )
		{
			for ( int k = 0 ; k < iPageSize ; ++k )
			{
				if ( 0 == vPageInfo [ i ].vExtref [ j ].compare ( vPageInfo [ k ].strURL ) )
				{
					vPageInfo [ k ].ldLinkScore += ( double ) vPageInfo [ i ].iBasicScore / iExtrefSize ;		// If long double, one more case failed.

					if ( ldMaxScore < vPageInfo [ k ].iBasicScore + vPageInfo [ k ].ldLinkScore )
					{
						ldMaxScore = vPageInfo [ k ].iBasicScore + vPageInfo [ k ].ldLinkScore ;
						answer = k ;
					}
				}
			}
		}
	}

	return answer ;
}