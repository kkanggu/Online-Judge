import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;



public class OJ_12015_LIS2
{
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		int iN = Integer.parseInt ( br.readLine () ) ;
		StringTokenizer st = new StringTokenizer ( br.readLine () ) ;
		Vector < Integer > v = new Vector < Integer> () ;
		int iTemp = 0 ;
		int iLeft = 0 ;
		int iRight = 0 ;
		int iIndex = 0 ;
		int iValue = 0 ;
		
		
		
		v.add ( Integer.parseInt ( st.nextToken () ) ) ;
		
		for ( int i = 1 ; i < iN ; ++i )
		{
			iTemp = Integer.parseInt ( st.nextToken () ) ;
			
			if ( iTemp < v.lastElement () )
			{
				iLeft = 0 ;
				iRight = v.size () - 1 ;
				
				while ( iLeft <= iRight )
				{
					iIndex = ( iLeft + iRight ) / 2 ;
					
					if ( v.get ( iIndex ) < iTemp )
					{
						iLeft = iIndex + 1;
					}
					else
					{
						iRight = iIndex - 1 ;
						iValue = iIndex ;
					}
				}
				
				v.set ( iValue , iTemp ) ;
			}
			else if ( v.lastElement () < iTemp )
			{
				v.add ( iTemp ) ;
			}
		}
		
		System.out.println ( v.size () ) ;
	}
}
