import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PG_OpenChat
{
	public static String [] solution ( String[] record )
	{
		String [] answer = {} ;
		int iRecordLength = record.length ;
		Map < String , String > mUserName = new HashMap <> () ;
		List < String > lUserInOut = new ArrayList <> () ;



		for ( int i = 0 ; i < iRecordLength ; ++i )
		{
			String [] strSplit = record [ i ].split ( "\\s" ) ;

			if ( strSplit [ 0 ].equals ( "Enter" ) )
			{
				if ( null == mUserName.get ( strSplit [ 1 ] ) )
					mUserName.put ( strSplit [ 1 ] , strSplit [ 2 ] ) ;
				mUserName.replace ( strSplit [ 1 ] , strSplit [ 2 ] ) ;
				lUserInOut.add ( '1' + strSplit [ 1 ] ) ;
			}
			else if ( strSplit [ 0 ].equals ( "Leave" ) )
				lUserInOut.add ( '0' + strSplit [ 1 ] ) ;
			else
				mUserName.replace ( strSplit [ 1 ] , strSplit [ 2 ] ) ;
		}

		int iListLength = lUserInOut.size () ;
		answer = new String [ iListLength ] ;
		for ( int i = 0 ; i < iListLength ; ++i )
		{
			String strTemp = lUserInOut.get ( i ) ;

			if ( '1' == strTemp.charAt ( 0 ) )			// Enter
				answer [ i ] = mUserName.get ( strTemp.substring ( 1 , strTemp.length () ) ) + "님이 들어왔습니다." ;
			else											// Enter
				answer [ i ] = mUserName.get ( strTemp.substring ( 1 , strTemp.length () ) ) + "님이 나갔습니다." ;
		}


		return answer ;
	}

	public static void main ( String[] args )
	{
		String [] s = solution ( new String[] {"Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" }) ;
	}
}