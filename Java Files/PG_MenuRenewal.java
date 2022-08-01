import java.util.*;

public class PG_MenuRenewal
{
	Map < String , Integer > mapPermutation ;
	int iMax ;

	public void getPermutation ( String strOrigin , int iMaxLength , int iCurrentLength , int iIndex , boolean [] brgUsed , int iCourseIndex )
	{
		int iStringLength = strOrigin.length () ;

		if ( iMaxLength == iCurrentLength )
		{
			String strPermutation = "" ;

			for ( int i = 0 ; i < iStringLength ; ++i )
			{
				if ( brgUsed [ i ] )
					strPermutation += strOrigin.charAt ( i ) ;
			}

			if ( null == mapPermutation.get ( strPermutation ) )
				mapPermutation.put ( strPermutation , 1 ) ;
			else
				mapPermutation.replace ( strPermutation , mapPermutation.get ( strPermutation ) + 1 ) ;

			iMax = Math.max ( iMax , mapPermutation.get ( strPermutation ) ) ;
		}

		for ( int i = iIndex ; i < iStringLength ; ++i )
		{
			if ( iStringLength - i < iMaxLength - iCurrentLength )
			{
				break ;
			}
			if ( ! brgUsed [ i ] )
			{
				brgUsed [ i ] = true ;
				getPermutation ( strOrigin , iMaxLength , iCurrentLength + 1 , i + 1 , brgUsed , iCourseIndex ) ;
				brgUsed [ i ] = false ;
			}
		}
	}

	public String [] solution ( String [] orders , int [] course )
	{
		List < String > answer = new ArrayList <> () ;
		int iOrderLength = orders.length ;
		int iCourseLength = course.length ;
		mapPermutation = new HashMap <> () ;



		for ( int i = 0 ; i < iOrderLength ; ++i )
		{
			char [] crgTemp = orders [ i ].toCharArray () ;
			Arrays.sort ( crgTemp ) ;
			orders [ i ] = String.valueOf ( crgTemp ) ;
		}
		for ( int j = 0 ; j < iCourseLength ; ++j )
		{
			boolean [] brgUsed = new boolean [ 20 ] ;
			iMax = 0 ;


			for ( int i = 0 ; i < iOrderLength ; ++i )
			{
				getPermutation ( orders [ i ] , course [ j ] , 0 , 0 , brgUsed , j ) ;
			}

			for ( String strKey : mapPermutation.keySet () )
			{
				if ( iMax < 2 )
					break ;
				if ( iMax == mapPermutation.get ( strKey ) )
					answer.add ( strKey ) ;
			}

			mapPermutation.clear () ;
		}

		String [] strAnswer = answer.toArray ( new String [ answer.size () ] ) ;
		Arrays.sort ( strAnswer ) ;


		return strAnswer ;
	}
}
