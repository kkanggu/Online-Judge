#include <string>

using std :: string ;

bool bIsRightString ( string str )
{
	int iCnt = 0 ;
	int iLen = str.size () ;
	const char * cpTemp = str.data () ;

	for ( int i = 0 ; i < iLen ; ++i )
	{
		if ( '(' == cpTemp [ i ] )
			++ iCnt ;
		else
			-- iCnt ;

		if ( iCnt < 0 )		// ) come first, it's not right string
		{
			return false ;
		}
	}

	return true ;
}

string solution ( string p )
{
    string answer = "" ;
	int iLen = p.size () ;
	const char * cpTemp = p.data () ;
	int iCnt = 0 ;
	int iIndex = 0 ;
	string u ;
	string v ;



	if ( ( 0 == iLen ) || ( bIsRightString ( p ) ) )
		return p ;
	
	for ( int i = 0 ; i < iLen ; ++i )
	{
		if ( '(' == cpTemp [ i ] )
			++ iCnt ;
		else
			-- iCnt ;

		if ( 0 == iCnt )
		{
			u = p.substr ( 0 , i + 1 ) ;		// Divide
			v = p.substr ( i + 1 , iLen ) ;

			break ;
		}
	}

	if ( bIsRightString ( u ) )					// If u is right string, then transform v and return
	{
		return u + solution ( v ) ;
	}

	cpTemp = u.data () ;
	iLen = u.size () ;
	for ( int i = 1 ; i < iLen - 1 ; ++i )
	{
		if ( '(' == cpTemp [ i ] )
			u [ i ] = ')' ;
		else
			u [ i ] = '(' ;
	}

	return "(" + solution ( v ) + ")" + u.substr ( 1 , iLen - 2 ) ;		// u is not right string, so transform all
}



// Below program is BAD PROGRAM
// I fix this BAD PROGRAM into GOOD PROGRAM

// #include <string>
// 
// using std :: string ;
// 
// bool bIsRightString ( string str )
// {
// 	int iCnt = 0 ;
// 	int iLen = str.size () ;
// 	const char * cpTemp = str.data () ;
// 
// 	for ( int i = 0 ; i < iLen ; ++i )
// 	{
// 		if ( '(' == cpTemp [ i ] )
// 			++ iCnt ;
// 		else
// 			-- iCnt ;
// 
// 		if ( iCnt < 0 )		// ) come first, it's not right string
// 		{
// 			return false ;
// 		}
// 	}
// 
// 	return true ;
// }
// 
// string getRightString ( string strInput , int iDivideIndex )		// 0 to iDivideIndex = u // v = iDivideIndex + 1 ~
// {
// 	string strReturn = "" ;
// 	int iLen = strInput.size () ;
// 	int iCnt = 0 ;
// 	const char * cpTemp = strInput.data () ;
// 
// 	if ( 0 == iLen )
// 		return strInput ;
// 
// 	if ( bIsRightString ( strInput.substr ( 0 , iDivideIndex + 1 ) ) )
// 	{
// 		strReturn = strInput.substr ( 0 , iDivideIndex + 1 ) ;
// 
// 		for ( int i = iDivideIndex + 1 ; i < iLen ; ++i )
// 		{
// 			if ( '(' == cpTemp [ i ] )
// 				++ iCnt ;
// 			else
// 				-- iCnt ;
// 
// 			if ( 0 == iCnt )
// 			{
// 				strReturn += getRightString ( strInput.substr ( iDivideIndex + 1 , strInput.size () ) , i - iDivideIndex - 1 ) ;
// 
// 				break ;
// 			}
// 		}
// 	}
// 	else
// 	{
// 		strReturn.push_back ( '(' ) ;
// 
// 		for ( int i = iDivideIndex + 1 ; i < iLen ; ++i )
// 		{
// 			if ( '(' == cpTemp [ i ] )
// 				++ iCnt ;
// 			else
// 				-- iCnt ;
// 
// 			if ( 0 == iCnt )
// 			{
// 				strReturn += getRightString ( strInput.substr ( iDivideIndex + 1 , strInput.size () ) , i - iDivideIndex - 1 ) ;
// 
// 				break ;
// 			}
// 		}
// 
// 		strReturn += ')' ;
// 
// 		for ( int i = 1 ; i < iDivideIndex ; ++i )
// 		{
// 			if ( '(' == cpTemp [ i ] )
// 				strReturn += ')' ;
// 			else
// 				strReturn += '(' ;
// 		}
// 	}
// 
// 
// 	return strReturn ;
// }
// 
// string solution ( string p )
// {
//     string answer = "" ;
// 	int iLen = p.size () ;
// 	const char * cpTemp = p.data () ;
// 	int iCnt = 0 ;
// 	int iIndex = 0 ;
// 
// 	
// 
// 	for ( int i = 0 ; i < iLen ; ++i )
// 	{
// 		if ( '(' == cpTemp [ i ] )
// 			++ iCnt ;
// 		else
// 			-- iCnt ;
// 
// 		if ( 0 == iCnt )
// 		{
// 			answer = getRightString ( p , i ) ;
// 
// 			return answer ;
// 		}
// 	}
// 
// 
// 	answer = getRightString ( p , iLen - 1 ) ;	// Divide into p , empty string
// 
//     return answer ;
// }

int main ()
{
	string str = solution ( ")(" ) ;
//	string str = solution ( "()))((()" ) ;
}