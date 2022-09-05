#include <vector>
#include <algorithm>

using std :: vector ;
using std :: max ;
using std :: min ;

bool bCanCrossBridge ( vector < int > & vStone , int iGap , int iLength )
{
    int iCount = 0 ;
    int iStoneSize = vStone.size () ;
    
    
    
    for ( int i = 0 ; i < iStoneSize ; ++i )
    {
        if ( vStone [ i ] < iLength )
        {
            ++ iCount ;
            
            if ( iCount == iGap )
                return false ;
        }
        else
            iCount = 0 ;
    }
    
    
    return true ;
}

int solution ( vector < int > stones , int k )
{
    int iLeft = 0 ;
    int iRight = 2e8 ;
    int iMid ;
    int iAnswer = 2e8 ;
    
    
    while ( iLeft <= iRight )
    {
        iMid = ( iLeft + iRight ) >> 1 ;
        
        if ( bCanCrossBridge ( stones , k , iMid ) )
        {
            iLeft = iMid + 1 ;
            iAnswer = iMid ;
        }
        else
        {
            iRight = iMid - 1 ;
        }
    }
    
    
    return iAnswer ;
}