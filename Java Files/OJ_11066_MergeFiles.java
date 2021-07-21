import java.awt.font.ImageGraphicAttribute;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Vector;



public class OJ_11066_MergeFiles
{
	public static void main ( String[] args ) throws IOException
	{
		BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
		StringTokenizer st ;
		int iN = Integer.parseInt ( br.readLine () ) ;
		int iFiles = 0 ;
		Vector < Integer > vFile = new Vector < Integer > () ;
		int iTime = 0 ;
		int iIndex = 0 ;
		int iTemp = 0 ;
		
		
		
		for ( int i = 0 ; i < iN ; ++i )
		{
			iTime = 0 ;
			iFiles = Integer.parseInt ( br.readLine () ) ;
			st = new StringTokenizer ( br.readLine () ) ;
			
			for ( int j = 0 ; j < iFiles ; ++j )
			{
				vFile.add ( Integer.parseInt ( st.nextToken () ) ) ;
			}
			
			while ( vFile.size () != 1 )
			{
				iTemp = 20001 ;
				
				
				for ( int j = 0 ; j < vFile.size () - 1 ; ++j )
				{
					if ( vFile.get ( j ) + vFile.get ( j + 1 ) < iTemp )
					{
						iTemp = vFile.get ( j ) + vFile.get ( j + 1 ) ;
						iIndex = j ;
					}
				}
				vFile.remove ( iIndex + 1 ) ;
				vFile.remove ( iIndex ) ;
				vFile.insertElementAt ( iTemp , iIndex ) ;
				iTime += iTemp ;
			}
			
			System.out.println ( iTime ) ;
		}
	}
}
