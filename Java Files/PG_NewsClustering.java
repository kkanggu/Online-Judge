import java.util.HashMap;
import java.util.regex.Pattern;

class Pair
{
	public int first ;
	public int second ;

	Pair ( int first , int second )
	{
		this.first = first ;
		this.second = second ;
	}
}

public class PG_NewsClustering
{
	public static int solution ( String str1 , String str2 )
	{
		HashMap < String , Pair > hmStringSet = new HashMap<> () ;
		int iLength = str1.length () ;
		int iIntersectionSize = 0 ;
		int iUnionSize = 0 ;



		for ( int i = 0 ; i < iLength - 1 ; ++i )
		{
			String strTemp = str1.substring ( i , i + 2 ).toLowerCase () ;

			if ( Pattern.matches ( "^[a-zA-Z]*$" , strTemp ) )
			{
				Pair pTemp = hmStringSet.get ( strTemp ) ;

				if ( null == pTemp )
				{
					pTemp = new Pair ( 1 , 0 ) ;
					hmStringSet.put ( strTemp , pTemp ) ;
				}
				else
				{
					++ pTemp.first ;
					hmStringSet.replace ( strTemp , pTemp ) ;
				}
			}
		}
		iLength = str2.length () ;
		for ( int i = 0 ; i < iLength - 1 ; ++i )
		{
			String strTemp = str2.substring ( i , i + 2 ).toLowerCase () ;

			if ( Pattern.matches ( "^[a-zA-Z]*$" , strTemp ) )
			{
				Pair pTemp = hmStringSet.get ( strTemp ) ;

				if ( null == pTemp )
				{
					pTemp = new Pair ( 0 , 1 ) ;
					hmStringSet.put ( strTemp , pTemp ) ;
				}
				else
				{
					++ pTemp.second ;
					hmStringSet.replace ( strTemp , pTemp ) ;
				}
			}
		}


		for ( Pair pValue : hmStringSet.values () )
		{
			iUnionSize += Math.max ( pValue.first , pValue.second ) ;
			iIntersectionSize += Math.min ( pValue.first , pValue.second ) ;
		}


		if ( 0 == iUnionSize )
			return 65536 ;

		return iIntersectionSize * 65536 / iUnionSize ;
	}
	public static void main ( String[] args )
	{
		int i = solution ( "aa1+aa2" , "AAAA12") ;
	}
}