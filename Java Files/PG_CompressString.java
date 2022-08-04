import java.io.FileReader;
import java.util.Map;

public class PG_CompressString
{
	public static int solution ( String s )
	{
		int iStringLength = s.length () ;
		int answer = iStringLength ;
		int iCompressLength ;



		for ( iCompressLength = 1 ; iCompressLength <= ( iStringLength >> 1 ) ; ++ iCompressLength )
		{
			int iCnt = 0 ;
			int iRepeatCount = 1 ;
			String strTarget = s.substring ( 0 , iCompressLength ) ;

			for ( int i = iCompressLength ; i < iStringLength ; i += iCompressLength )
			{
				String strTemp = s.substring ( i , ( i + iCompressLength <= iStringLength ) ? i + iCompressLength: iStringLength ) ;

				if ( strTarget.equals ( strTemp ) )
					++ iRepeatCount ;
				else
				{
					if ( 1 < iRepeatCount )
					{
						iCnt += Integer.toString ( iRepeatCount ).length () ;
						iRepeatCount = 1 ;
					}

					iCnt += iCompressLength ;
					strTarget = strTemp ;
				}
			}

			if ( 1 < iRepeatCount )
				iCnt += Integer.toString ( iRepeatCount ).length () + iCompressLength ;
			else
				iCnt += strTarget.length () ;


			answer = Math.min ( answer , iCnt ) ;
		}


		return answer ;
	}

	public static void main ( String[] args )
	{
		int i = solution ( "abcabcaecaecae" ) ;
	}
}
