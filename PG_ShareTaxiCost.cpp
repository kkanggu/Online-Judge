#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>

using std :: vector ;
using std :: pair ;
using std :: make_pair ;
using std :: min ;

int solution ( int n , int s , int a , int b , vector < vector < int > > fares )
{
    int iAnswer = 2e7 ;
    vector < vector < int > > vMinimumLength ( n , vector < int > ( n , 2e7 ) ) ;    // [ i ] [ j ] : Minimum length of i to j
    int iFareSize = fares.size () ;
    
        
    
    for ( int i = 0 ; i < iFareSize ; ++i )
    {
        int * ipTemp = fares [ i ].data () ;
        int iTempStart = * ipTemp ++ - 1;
        int iTempEnd = * ipTemp ++ - 1 ;
        int iTempCost = * ipTemp ++ ;
        
        vMinimumLength [ iTempStart ] [ iTempEnd ] = iTempCost ;
        vMinimumLength [ iTempEnd ] [ iTempStart ] = iTempCost ;
    }
    for ( int i = 0 ; i < n ; ++i )
    {
        vMinimumLength [ i ] [ i ] = 0 ;        
    }
    
    for ( int k = 0 ; k < n ; ++k )
    {
        for ( int i = 0 ; i < n ; ++i )
        {
            for ( int j = 0 ; j < n ; ++j )
            {
                vMinimumLength [ i ] [ j ] = min ( vMinimumLength [ i ] [ j ] , vMinimumLength [ i ] [ k ] + vMinimumLength [ k ] [ j ] ) ;
            }
        }
    }
    for ( int i = 0 ; i < n ; ++i )
    {
        iAnswer = min ( iAnswer , vMinimumLength [ s - 1 ] [ i ] + vMinimumLength [ i ] [ a - 1 ] + vMinimumLength [ i ] [ b - 1 ] ) ;
    }
    
    
    return iAnswer ;
}