#include <vector>

using std :: vector ;

bool bCanUpdate ( vector < vector < int > > & vDP , int iCurrentScore , int iScore , int iSingleOrBull )
{
	if ( vDP.size () <= iCurrentScore + iScore )
		return false ;
	if (  vDP [ iCurrentScore ] [ 0 ] < vDP [ iCurrentScore + iScore ] [ 0 ] + 1 )
		return false ;
	if ( ( vDP [ iCurrentScore ] [ 0 ] == vDP [ iCurrentScore + iScore ] [ 0 ] + 1 )
		&& ( vDP [ iCurrentScore + iScore ] [ 1 ] + iSingleOrBull <= vDP [ iCurrentScore ] [ 1 ] ) )
		return false ;
	
	return true ;
}

vector < int > solution ( int target )
{
	int iThrow = 0 ;
	
	
	
	if ( 1800 <= target )
	{
		iThrow = ( target - 1800 ) / 60 ;
		target -= iThrow * 60 ;
	}
	
	vector < vector < int > > vDP ( target + 1 , vector < int > ( 2 , -1 ) ) ;		// [ iThrow , iSum ]   
	
	for ( int i = 0 ; i < target ; ++i )
	{
		vDP [ i ] [ 0 ] = target ;
	}
	vDP [ target ] [ 0 ] = iThrow ;
	vDP [ target ] [ 1 ] = 0 ;
	
	for ( int i = target - 1 ; i >= 0 ; --i )
	{
		if ( bCanUpdate ( vDP , i , 50 , 1 ) )
		{
			vDP [ i ] [ 0 ] = vDP [ i + 50 ] [ 0 ] + 1 ;
			vDP [ i ] [ 1 ] = vDP [ i + 50 ] [ 1 ] + 1 ;
		}
			
		for ( int iScore = 1 ; iScore <= 20 ; ++iScore )
		{
			for ( int k = 1 ; k <= 3 ; ++k )
			{
				int iSingleOrBull = 1 == k ? 1 : 0 ;
				
				if ( bCanUpdate ( vDP , i , iScore * k , iSingleOrBull ) )
				{
					vDP [ i ] [ 0 ] = vDP [ i + iScore * k ] [ 0 ] + 1 ;
					vDP [ i ] [ 1 ] = vDP [ i + iScore * k ] [ 1 ] + iSingleOrBull ;
				}
			}
		}
	}
	
	
	
	return { vDP [ 0 ] [ 0 ] , vDP [ 0 ] [ 1 ] } ;
}