#include <vector>
#include <algorithm>

using std :: vector ;
using std :: max ;


int iGetBestSticker ( vector < int > & vSticker , int iStartIndex , int iEndIndex )
{
	vector < int > vTempDP ( 4 , 0 ) ;
	
	
	for ( int i = iStartIndex ; i < iEndIndex ; ++i )
	{
		vTempDP [ 0 ] = vTempDP [ 1 ] ;
		vTempDP [ 1 ] = vTempDP [ 2 ] ;
		vTempDP [ 2 ] = vTempDP [ 3 ] ;
		vTempDP [ 3 ] = max ( vTempDP [ 0 ] , vTempDP [ 1 ] ) + vSticker [ i ] ;
	}
	
	
	return max ( vTempDP [ 2 ] , vTempDP [ 3 ] ) ;
}

int solution ( vector < int > sticker )
{
	int iStickerSize = sticker.size () ;
	
	
	
	if ( 1 == iStickerSize )
		return sticker [ 0 ] ;
	
	
	return max ( iGetBestSticker ( sticker , 0 , iStickerSize - 1 ) , iGetBestSticker ( sticker , 1 , iStickerSize ) ) ;
}