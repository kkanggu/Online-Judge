import java.util.Stack;

public class PG_RemovePair
{
	public int solution ( String s )
	{
		int iStringLength = s.length () ;
		Stack < Character > sPairCheck = new Stack <> () ;



		if ( 1 == ( iStringLength & 1 ) )		// Odd
			return 0 ;

		for ( int i = 0 ; i < iStringLength ; ++i )
		{
			char cCurrent = s.charAt ( i ) ;

			if ( ( sPairCheck.empty () ) || ( sPairCheck.peek () != cCurrent ) )
				sPairCheck.add ( cCurrent ) ;
			else
				sPairCheck.pop () ;
		}

		return sPairCheck.empty () ? 1 : 0 ;
	}
}
