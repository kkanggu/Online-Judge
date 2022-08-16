#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using std :: string ;
using std :: vector ;
using std :: unordered_map ;
using std :: tolower ;

struct pageInfo
{
	int iIndex ;
	vector < string > vExtref ;
	int iBasicScore ;
	double dLinkScore ;
} ;

int iGetBasicScore ( string strBody , string strWord )
{
    int iWordStartIndex = -1 ;
    int iBodySize = strBody.size () ;
    int iWordSize = strWord.size () ;
    int iCount = 0 ;
    
    
    std :: transform ( strBody.begin () , strBody.end () , strBody.begin () , [] ( unsigned char ch ) { return std :: tolower ( ch ) ; } ) ;

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
	double dMaxScore = 0 ;
    int iPageSize = pages.size () ;
    unordered_map < string , pageInfo > umReference ;           // < URL , < index , Vector of external reference >

    
    
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


		iTemp = strPage.find ( strPreURL ) + strPreURL.size () ;            // Find URL

		while ( '\"' != strPage [ iTemp ] )
			strURL += strPage [ iTemp ++ ] ;
		

        
		iTemp = strPage.find ( strPreBody ) + strPreBody.size () ;          // Find body section and count word
		
		iBasicScore = iGetBasicScore ( strPage.substr ( iTemp , strPage.find ( "</body>" ) - iTemp ) , word ) ;
        
        
        iTemp = strPage.find ( strPreRef ) + strPreRef.size () ;            // Find external reference
        while ( iTemp != string :: npos )           // If npos, can't find
        {
            int iEndIndex = strPage.find ( "\"" , iTemp ) ;
            
            vExtref.emplace_back ( strPage.substr ( iTemp , iEndIndex - iTemp ) ) ;
            int iNextIndex = strPage.find ( strPreRef , iTemp + 1 ) + strPreRef.size () ;

			if ( iNextIndex <= iTemp )
				break ;
			
			iTemp = iNextIndex ;
        }


		pageInfo newInfo = { i , vExtref , iBasicScore , 0 } ;

        umReference [ strURL ] = newInfo ;
    }
    for ( auto iter = umReference.begin () ; iter != umReference.end () ; ++ iter )     // Update link score
    {
		iter -> second ;
        pageInfo currentInfo = iter -> second ;
        int iExtrefSize = currentInfo.vExtref.size () ;
        
        for ( int i = 0 ; i < iExtrefSize ; ++i )
        {
            if ( umReference.count ( currentInfo.vExtref [ i ] ) )
            {
                pageInfo tempInfo = umReference [ currentInfo.vExtref [ i ] ] ;
                
                umReference [ currentInfo.vExtref [ i ] ].dLinkScore += tempInfo.iBasicScore / ( double ) iExtrefSize ;

				dMaxScore = std :: max ( dMaxScore , tempInfo.iBasicScore + umReference [ currentInfo.vExtref [ i ] ].dLinkScore ) ;
            }
        }
    }
    for ( auto iter = umReference.begin () ; iter != umReference.end () ; ++ iter )     // Find best score
    {
        pageInfo currentInfo = iter -> second ;

        if ( dMaxScore == currentInfo.iBasicScore + currentInfo.dLinkScore )
		{
			answer = currentInfo.iIndex ;

			break ;
		}
    }
    
    return answer ;
}

int main ()
{
	int i = solution ( "blind", {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"} ) ;
}