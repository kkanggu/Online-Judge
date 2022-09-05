#include <vector>
#include <algorithm>

using std :: vector ;
using std :: max_element ;
using std :: min ;

int iGetMaxCross ( int iStart , int iEnd , int iChange , vector < int > & vStone , int iGap )
{
	int iReturn ;
	int iTargetGap = ( 1 == iStart ) ? -1 : iGap ;
	
	
	
	if ( 1 == iStart )
		iReturn = * max_element ( vStone.begin () , vStone.begin () + iGap ) ;
	else
		iReturn = * max_element ( vStone.end () - iGap , vStone.end () ) ;
		
	
	for ( int i = iStart ; i != iEnd ; i += iChange )
	{
		if ( vStone [ i + iTargetGap ] == iReturn )
			iReturn = min ( iReturn , * max_element ( vStone.begin () + i , vStone.begin () + i + iGap ) ) ;
	}
	
	return iReturn ;
}

int solution ( vector < int > stones , int k )
{
	int iStoneSize = stones.size () ;
	int iPlusMinusCount = 0 ;
	
	
	
	for ( int i = 1 ; i < iStoneSize ; ++i )
	{
		if ( stones [ i - 1 ] < stones [ i ] )
			++ iPlusMinusCount ;
		else if ( stones [ i - 1 ] > stones [ i ] )
			-- iPlusMinusCount ;
	}
	
	
	if ( iPlusMinusCount >= 0 )
		return iGetMaxCross ( 1 , iStoneSize - k + 1 , 1 , stones , k ) ;
	else
		return iGetMaxCross ( iStoneSize - k - 1 , -1 , -1 , stones , k ) ;
}