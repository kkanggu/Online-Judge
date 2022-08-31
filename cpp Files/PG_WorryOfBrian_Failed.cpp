#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <sstream>

using std :: vector ;
using std :: string ;
using std :: unordered_map ;
using std :: pair ;
using std :: make_pair ;

vector < pair < char , int > > vSmallLetter ;

string strEraseWrongBlank ( string strTarget )
{
	string strReturn = "" ;
	std :: stringstream ss ( strTarget ) ;
	string strTemp ;



	while ( ss >> strTemp )
	{
		strReturn += strTemp ;
		strReturn += " " ;
	}

	if ( ' ' == strReturn [ strReturn.size () - 1 ] )
		return strReturn.substr ( 0 , strReturn.size () - 1 ) ;
	return strReturn ;
}

string strAdoptRule2 ( string sentence , pair < char , int > pLetterInfo )
{
	int iStringSize = sentence.size () ;
	const char * cpString = sentence.data () ;
	int iStartIndex = -1 ;
	int iEndIndex = 0 ;



	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		char cTemp = cpString [ i ] ;

		if ( cTemp == pLetterInfo.first )
		{
			if ( -1 == iStartIndex )
				iStartIndex = i ;
			else
			{
				iEndIndex = i ;

				break ;
			}
		}
	}

	if ( ( ( ' ' == cpString [ iStartIndex + 1 ] ) || ( ' ' == cpString [ iEndIndex - 1 ] ) )
		|| ( iStartIndex + 1 == iEndIndex ) )
		return "" ;
	else
	{
		sentence [ iStartIndex ] = ' ' ;
		sentence [ iEndIndex ] = ' ' ;
	}

	return sentence ;
}

string strAdoptRule1 ( string sentence , pair < char , int > pLetterInfo )
{
	int iCount = 0 ;
	int iStringSize = sentence.size () ;
	const char * cpString = sentence.data () ;
	int iStartIndex = -1 ;
	int iEndIndex = 0 ;
	string strOriginWord = " " ;
	
	
	
	for ( int i = 1 ; i < iStringSize - ( pLetterInfo.second << 1 ) + 1 ; ++i )
	{
		char cTemp = cpString [ i ] ;
		
		if ( cTemp == pLetterInfo.first )
		{
			iStartIndex = i - 1 ;
			iEndIndex = i + ( pLetterInfo.second << 1 ) - 1 ;
			strOriginWord += cpString [ iStartIndex ] ;
			
			if ( ( ' ' == cpString [ iStartIndex ] ) || ( ' ' == cpString [ iEndIndex ] ) )		// This must be not ' '
				return "" ;
			
			for ( int j = i + 2 ; j <= iEndIndex ; j += 2 )
			{
				strOriginWord += cpString [ j - 1 ] ;
				
				if ( cpString [ j ] != cTemp )
					return "" ;								// Small letter exist at weird place
			}
			
			strOriginWord += cpString [ iEndIndex ] ;
			strOriginWord += " " ;

			if ( ( 0 != iStartIndex ) && ( iEndIndex != iStringSize - 1 )
			&& ( cpString [ iStartIndex - 1 ] == cpString [ iEndIndex + 1 ] )
			&& ( 'a' <= cpString [ iStartIndex - 1 ] ) && ( cpString [ iStartIndex - 1 ] <= 'z' ) )
			{
				-- iStartIndex ;
				++ iEndIndex ;
				int iVectorSize = vSmallLetter.size () ;

				for ( int i = 0 ; i < iVectorSize ; ++i )
				{
					if ( cpString [ iStartIndex ] == vSmallLetter [ i ].first )
					{
						vSmallLetter [ i ].second = 0 ;

						break ;
					}
				}
			}
			
			return sentence.substr ( 0 , iStartIndex ) + strOriginWord + sentence.substr ( iEndIndex + 1 , iStringSize - iEndIndex ) ;
		}
	}
	
	return "" ;
}

string strGetOriginSentence ( string sentence )
{
	int iStringSize = sentence.size () ;
	int iProcessSize = vSmallLetter.size () ;



	for ( int i = 0 ; i < iProcessSize ; ++i )
	{
		int iSmallLetterCount = vSmallLetter [ i ].second ;
		
		
		if ( ( 2 != iSmallLetterCount ) && ( 0 != iSmallLetterCount ) )
		{
			sentence = strAdoptRule1 ( sentence , vSmallLetter [ i ] ) ;
			
			if ( 0 == sentence.size () )			// If can't adopt rule 1
				return "invalid" ;
		}
	}
	for ( int i = 0 ; i < iProcessSize ; ++i )
	{
		int iSmallLetterCount = vSmallLetter [ i ].second ;
		
		
		if ( 2 == iSmallLetterCount )
		{
			sentence = strAdoptRule2 ( sentence , vSmallLetter [ i ] ) ;
			
			if ( 0 == sentence.size () )			// If can't adopt rule 1
				return "invalid" ;
		}
	}
	
	return sentence ;
}

string solution ( string sentence )
{
	int iStringSize = sentence.size () ;
	const char * cpString = sentence.data () ;
	string answer = "" ;
	unordered_map < char , int > umSmallLetterCount ;
	
	
	
	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		char cTemp = * cpString ++ ;
		
		if ( ( 'a' <= cTemp ) && ( cTemp <= 'z' ) )
			++ umSmallLetterCount [ cTemp ] ;
		
		if ( ' ' == cTemp )						// This sentence must not contain blank
			return "invalid" ;
	}
	for ( auto iter : umSmallLetterCount )
	{
		vSmallLetter.emplace_back ( make_pair ( iter.first , iter.second ) ) ;
	}
	
	
	answer = strGetOriginSentence ( sentence ) ;
	
	return strEraseWrongBlank ( answer ) ;
}