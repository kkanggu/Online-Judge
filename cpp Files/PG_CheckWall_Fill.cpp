#include <vector>
#include <algorithm>

using std :: vector ;
using std :: min ;

int iAnswer ;
int iWeakSize ;
int iDistSize ;
int iWallSize ;

void calculateMinimumFriend ( vector < int > & vWeak , vector < int > & vDist , vector < int > vWeakMap , vector < bool > vDistChecked ,
							int iDistStartIndex , int iWeakStartIndex )
{
    if ( ( iDistStartIndex == iDistSize ) || ( iAnswer <= iDistStartIndex + 1 ) )   // Already used all friend or current is not best
        return ;


    int iCurrentDist = vDist [ iDistStartIndex ] + 1 ;
	int iWeakPosition = vWeak [ iWeakStartIndex ] ;

	if ( iWeakPosition + iCurrentDist < iWallSize )
		std :: fill ( vWeakMap.begin () + iWeakPosition , vWeakMap.begin () + iWeakPosition + iCurrentDist , 0 ) ;
	else
	{
		std :: fill ( vWeakMap.begin () + iWeakPosition , vWeakMap.end () , 0 ) ;
		std :: fill ( vWeakMap.begin () , vWeakMap.begin () + iCurrentDist - ( iWallSize - iWeakPosition ) , 0 ) ;
	}

	if ( 0 == * std :: max_element ( vWeakMap.begin () , vWeakMap.end () ) )
	{
        iAnswer = min ( iAnswer , iDistStartIndex + 1 ) ;

		return ;
	}
    
    for ( int i = 0 ; i < iWeakSize ; ++i )
    {
        if ( 0 == vWeakMap [ vWeak [ i ] ] )       // Don't have to start here
            continue ;
        
        calculateMinimumFriend ( vWeak , vDist , vWeakMap , vDistChecked , iDistStartIndex + 1 , i ) ;        
    }
}

int solution ( int n , vector < int > weak , vector < int > dist )
{
    iAnswer = 10 ;
    iWeakSize = weak.size () ;
    iDistSize = dist.size () ;
    vector < int > vWeakMap ( n , 0 ) ;
    vector < bool > vDistChecked ( iDistSize , false ) ;
    iWallSize = n ;
    
    

	for ( int i = 0 ; i < iWeakSize ; ++i )
	{
		vWeakMap [ weak [ i ] ] = 1 ;
	}
	
	std :: sort ( dist.begin () , dist.end () , [] ( int & a , int & b ) { return a > b ; } ) ;
    
    for ( int i = 0 ; i < iWeakSize ; ++i )
    {
        calculateMinimumFriend ( weak , dist , vWeakMap , vDistChecked , 0 , i ) ;        
    }
    
    
    
    return 10 != iAnswer ? iAnswer : -1 ;
}