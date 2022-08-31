#include <string>
#include <vector>

using std :: string ;
using std :: vector ;

string strGetRule1 ( string & strAnswer , int iStartIndex , int iCount )
{
	string strReturn = "" ;
	
	for ( int i = 0 ; i < iCount + 1 ; ++i )
	{
		strReturn += strAnswer [ iStartIndex + ( i << 1 ) - 1 ] ;

		if ( ' ' == strReturn [ i ] )											// Empty space must not be here
			return "invalid" ;
		if ( ( 'a' <= strReturn [ i ] ) && ( strReturn [ i ] <= 'z' ) )			// Small letter must not be here
			return "invalid" ;
	}
	
	return strReturn ;
}
			
bool bAdoptRule1 ( string & strAnswer , char cTarget , int iCount )
{
	int iStringSize = strAnswer.size () ;
	int iStartIndex = -1 ;
	int iFormerIndex ;
	int iCheckCount = 0 ;
	
	
	
	for ( int i = 0 ; ( i < iStringSize ) && ( iCheckCount < iCount ); ++i )
	{
		if ( cTarget == strAnswer [ i ] )
		{
			if ( -1 == iStartIndex )
			{
				iStartIndex = i ;
				iFormerIndex = i ;
			}
			else
			{
				if ( 2 != i - iFormerIndex )		// Gap must be 2
					return false ;
				else
					iFormerIndex = i ;
			}
			
			++ iCheckCount ;
		}
		else if ( ( -1 != iStartIndex ) && ( ( 'A' > strAnswer [ i ] ) || ( strAnswer [ i ] > 'Z' ) ) )
			return false ;
	}
	
	if ( ( 0 == iStartIndex ) || ( iFormerIndex + 1 == iStringSize ) )		// Must letter at front and back
		return false ;
	if ( ( ( 'A' > strAnswer [ iStartIndex - 1 ] ) || ( strAnswer [ iStartIndex - 1 ] > 'Z' ) )
	  || ( ( 'A' > strAnswer [ iFormerIndex + 1 ] ) || ( strAnswer [ iFormerIndex + 1 ] > 'Z' ) ) )
	  	return false ;

	string strRule1 = strGetRule1 ( strAnswer , iStartIndex , iCount ) ;

	if ( 0 == strRule1.compare ( "invalid" ) )		// Found empty space or small letter, can't adopt rule1
		return false ;

	
	strAnswer = strAnswer.substr ( 0 , iStartIndex - 1 ) + "." + strGetRule1 ( strAnswer , iStartIndex , iCount ) + "." + strAnswer.substr ( iFormerIndex + 2 , iStringSize - iFormerIndex - 2 ) ;

	return true ;
}

bool bAdoptRule2 ( string & strAnswer , char cTarget , vector < int > & vAlphabetCount )
{
	vAlphabetCount [ cTarget - 'a' ] = 0 ;
	int iStartIndex = -1 ;
	int iEndIndex = -1 ;
	int iLeftDotIndex = -1 ;
	int iRightDotIndex = -1 ;
	int iStringSize = strAnswer.size () ;



	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		if ( cTarget == strAnswer [ i ] )
		{
			if ( -1 == iStartIndex )
				iStartIndex = i ;
			else
			{
				iEndIndex = i ;

				break ;
			}
		}
		else if ( ( -1 != iStartIndex ) && ( '.' == strAnswer [ i ] ) )
		{
			if ( ( -1 == iLeftDotIndex ) && ( iStartIndex + 1 == i ) )
				iLeftDotIndex = i ;
			else if ( ( -1 != iLeftDotIndex ) && ( -1 == iRightDotIndex ) )
				iRightDotIndex = i ;
			else																// Other condition not exist
				return false ;
		}
		else if ( ( -1 != iStartIndex ) && ( ' ' == strAnswer [ i ] ) )											// Empty space must not be here
			return false ;
		else if ( ( -1 != iStartIndex ) && ( 'a' <= strAnswer [ i ] ) && ( strAnswer [ i ] <= 'z' ) )			// This must be rule1, or wrong string
		{
			vAlphabetCount [ strAnswer [ i ] - 'a' ] = 0 ;

			if ( ! bAdoptRule1 ( strAnswer , strAnswer [ i ] , 2 ) )			// If false, can't adopt rule1
				return false ;
			
			i -= 2 ;
		}
	}

	if ( iStartIndex + 1 == iEndIndex )
		return false ;
	if ( ( -1 != iLeftDotIndex ) && ( ( -1 == iRightDotIndex )
									|| ( iRightDotIndex + 1 != iEndIndex ) ) )
		return false ;

	strAnswer = strAnswer.substr ( 0 , iStartIndex ) + " " + strAnswer.substr ( iStartIndex + 1 , iEndIndex - iStartIndex - 1 ) + " " + strAnswer.substr ( iEndIndex + 1 , iStringSize - iEndIndex - 1 ) ;

	return true ;
}

string strRemoveSpace ( string strAnswer )
{
	string strReturn = "" ;
	int iEmptySpaceIndex = -1 ;
	int iStringSize = strAnswer.size () ;



	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		if ( ( 'a' <= strAnswer [ i ] ) && ( strAnswer [ i ] <= 'z' ) )
			return "invalid" ;
		else if ( ( -1 == iEmptySpaceIndex ) && ( ( ' ' == strAnswer [ i ] ) || ( '.' == strAnswer [ i ] ) ) )
		{
			iEmptySpaceIndex = i ;
		}
		else if ( ( 'A' <= strAnswer [ i ] ) && ( strAnswer [ i ] <= 'Z' ) )
		{
			if ( 0 < iEmptySpaceIndex )
			{
				strReturn += ' ' ;
			}
			
			iEmptySpaceIndex = -1 ;
			strReturn += strAnswer [ i ] ;
		}
	}

	return strReturn ;
}

string solution ( string sentence )
{
	string answer = sentence ;
	vector < int > vAlphabetCount ( 26 , 0 ) ;
	int iSentenceSize = sentence.size () ;
	const char * cpSentence = sentence.data () ;
	
	
	
	for ( int i = 0 ; i < iSentenceSize ; ++i )
	{
		if ( ( 'a' <= cpSentence [ i ] ) && ( cpSentence [ i ] <= 'z' ) )			// Small letter
		{
			++ vAlphabetCount [ cpSentence [ i ] - 'a' ] ;
		}
		else if ( ' ' == cpSentence [ i ] )		// Empty space must be deleted
			return "invalid" ;
	}
	
	for ( int i = 0 ; i < 26 ; ++i )
	{
		if ( ( 0 != vAlphabetCount [ i ] ) && ( 2 != vAlphabetCount [ i ] ) )		// Only rule 1
		{
			if ( ! bAdoptRule1 ( answer , 'a' + i , vAlphabetCount [ i ] ) )		// If false, can't adopt rule1
				return "invalid" ;
		}
	}
	for ( int i = 0 ; i < 26 ; ++i )
	{
		if ( 2 == vAlphabetCount [ i ] )
		{
			if ( ! bAdoptRule2 ( answer , 'a' + i , vAlphabetCount ) )				// If false, can't adopt rule2
				return "invalid" ;
		}
	}
	
	return strRemoveSpace ( answer ) ;
}