import java.util.HashMap;
import java.util.Map;

public class PG_Tuple
{
	public int [] solution ( String s )
	{
		int [] answer ;
		String [] strToArray = s.split ( "[\\{\\},]" ) ;
		Map < String , Integer > mTupleCheck = new HashMap <> () ;
		int iStringLength = strToArray.length ;



		for ( int i = 0 ; i < iStringLength ; ++i )
		{
			String strTemp = strToArray [ i ] ;

			if ( strTemp.isEmpty () )
				continue ;

			if ( null == mTupleCheck.get ( strTemp ) )
				mTupleCheck.put ( strTemp , 1 ) ;
			else
				mTupleCheck.replace ( strTemp , mTupleCheck.get ( strTemp ) + 1 ) ;
		}

		int iMapLength = mTupleCheck.size () ;
		answer = new int [ iMapLength ] ;
		for ( String strKey : mTupleCheck.keySet () )
		{
			answer [ iMapLength - mTupleCheck.get ( strKey ) ] = Integer.parseInt ( strKey ) ;
		}


		return answer ;
	}
}