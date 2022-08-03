import java.util.Arrays;

public class PG_Hash
{
	public boolean solution ( String [] phone_book )
	{
		int iStringLength = phone_book.length ;
		String strFormer ;
		String strLatter = phone_book [ 0 ] ;
		int iFormerLength ;
		int iLatterLength = strLatter.length () ;


		Arrays.sort ( phone_book ) ;

		for ( int i = 1 ; i < iStringLength ; ++i )
		{
			strFormer = strLatter ;
			iFormerLength = iLatterLength ;
			strLatter = phone_book [ i ] ;
			iLatterLength = strLatter.length () ;

			if ( ( iFormerLength <= iLatterLength )												// Latter must >= former
					&& ( strFormer.equals ( strLatter.substring ( 0 , iFormerLength ) ) ) )		// Former is substr of latter
				return false ;
		}


		return true ;
	}
}
