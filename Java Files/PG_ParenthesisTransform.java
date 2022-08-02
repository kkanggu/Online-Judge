public class PG_ParenthesisTransform
{
	public boolean isRightParenthesis ( String strParenthesis )
	{
		int iStringLength = strParenthesis.length () ;
		int iCount = 0 ;



		for ( int i = 0 ; i < iStringLength ; ++i )
		{
			if ( '(' == strParenthesis.charAt ( i ) )
				++ iCount ;
			else
				-- iCount ;

			if ( iCount < 0 )
				return false ;
		}

		return 0 == iCount ;
	}

	public String strGetTransformedString ( String strParenthesis )
	{
		int iCount = 0 ;
		int iStringLength = strParenthesis.length () ;
		String strFormer = strParenthesis ;
		String strLatter ;
		String strReturn = "" ;



		if ( isRightParenthesis ( strParenthesis ) )
			return strParenthesis ;

		for ( int i = 0 ; i < iStringLength ; ++i )
		{
			if ( '(' == strParenthesis.charAt ( i ) )
				++ iCount ;
			else
				-- iCount ;

			if ( 0 == iCount )
			{
				strFormer = strParenthesis.substring ( 0 , i + 1 ) ;

				break ;
			}
		}

		strLatter = strParenthesis.substring ( strFormer.length () , iStringLength ) ;

		if ( isRightParenthesis ( strFormer ) )
			strReturn = strFormer + strGetTransformedString ( strLatter ) ;
		else
		{
			strReturn += '(' + strGetTransformedString ( strLatter ) + ')' ;

			iStringLength = strFormer.length () ;
			for ( int i = 1 ; i < iStringLength - 1 ; ++i )
			{
				strReturn += ( '(' != strFormer.charAt ( i ) ) ? '(' : ')' ;
			}
		}


		return strReturn ;
	}

	public String solution ( String p )
	{
		String answer = p ;



		while ( ! isRightParenthesis ( answer ) )
		{
			answer = strGetTransformedString ( answer ) ;
		}


		return answer ;
	}
}
