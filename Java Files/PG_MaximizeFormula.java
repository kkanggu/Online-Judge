import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class PG_MaximizeFormula
{
	public long lGetSingleFormula ( long lNumber1 , long lNumber2 , char cOperation )
	{
		if ( '+' == cOperation )
			return lNumber1 + lNumber2 ;
		else if ( '-' == cOperation )
			return lNumber1 - lNumber2 ;
		return lNumber1 * lNumber2 ;
	}

	public long lGetFormula ( List < Long > lOriginNumbers , List < Character > lOriginOperations , char[] crgPriority )
	{
		int iOperationSize = lOriginOperations.size () ;
		List < Long > lNumbers = new ArrayList < Long > () ;
		List < Character > lOperations = new ArrayList < Character > () ;



		for ( int i = 0 ; i < iOperationSize + 1 ; ++i ) lNumbers.add ( lOriginNumbers.get ( i ) ) ;
		for ( int i = 0 ; i < iOperationSize ; ++i ) lOperations.add ( lOriginOperations.get ( i ) ) ;

		for ( int i = 0 ; i < 3 ; ++i )
		{
			for ( int j = 0 ; j < iOperationSize ; ++j )
			{
				if ( crgPriority [ i ] == lOperations.get ( j ) )
				{
					lNumbers.set ( j + 1 , lGetSingleFormula ( lNumbers.get ( j ) , lNumbers.get ( j + 1 ) , crgPriority [ i ] ) ) ;
					lNumbers.remove ( j ) ;
					lOperations.remove ( j ) ;
					--j ;
					-- iOperationSize ;
				}
			}
		}


		return Math.abs ( lNumbers.get ( 0 ) ) ;
	}

	public long solution ( String expression )
	{
		long answer = 0 ;
		char [] [] cdrgOperationPriority = { { '+' , '-' , '*' } ,
											 { '+' , '*' , '-' } ,
											 { '-' , '+' , '*' } ,
											 { '-' , '*' , '+' } ,
											 { '*' , '+' , '-' } ,
											 { '*' , '-' , '+' } } ;
		List < Long > lNumbers = new ArrayList < Long > () ;
		List < Character > lOperations = new ArrayList < Character > () ;
		StringTokenizer st = new StringTokenizer ( expression , "+-*" ) ;
		int iExpressionSize = expression.length () ;



		while ( st.hasMoreTokens () )
		{
			lNumbers.add ( Long.parseLong ( st.nextToken () ) ) ;
		}
		for ( int i = 0 ; i < iExpressionSize ; ++i )
		{
			if ( ( '+' == expression.charAt ( i ) ) || ( '-' == expression.charAt ( i ) ) || ( '*' == expression.charAt ( i ) ) )
			{
				lOperations.add ( expression.charAt ( i ) ) ;
			}
		}


		for ( int i = 0 ; i < 6 ; ++i )
		{
			answer = Math.max ( answer , lGetFormula ( lNumbers , lOperations , cdrgOperationPriority [ i ] ) ) ;
		}


		return answer ;
	}
}
