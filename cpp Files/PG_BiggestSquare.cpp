#include <vector>
#include <algorithm>

using std :: vector ;
using std :: min ;

int solution ( vector < vector < int > > board )
{
    int iMaxSize = 0 ;
    int iHeightSize = board.size () ;
    int iWidthSize = board [ 0 ].size () ;
    vector < vector < int > > vDP ( iHeightSize , vector < int > ( iWidthSize , 0 ) ) ;



    for ( int i = iHeightSize - 1 ; i >= 0 ; --i )
    {
        for ( int j = iWidthSize - 1 ; j >= 0 ; --j )
        {
            if ( 0 == board [ i ] [ j ] )
                vDP [ i ] [ j ] = 0 ;
            else if ( ( i == iHeightSize - 1 ) || ( j == iWidthSize - 1 ) )
                vDP [ i ] [ j ] = 1 ;
            else
                vDP [ i ] [ j ] = min ( vDP [ i ] [ j + 1 ] , min ( vDP [ i + 1 ] [ j ] , vDP [ i + 1 ] [ j + 1 ] ) ) + 1 ;

            iMaxSize = std :: max ( iMaxSize , vDP [ i ] [ j ] ) ;
        }
    }


    return iMaxSize * iMaxSize ;
}

// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <utility>
// 
// using std :: vector ;
// using std :: max ;
// using std :: queue ;
// using std :: pair ;
// using std :: make_pair ;
// 
// int solution ( vector < vector < int > > board )
// {
//     int iHeightSize = board.size () ;
//     int iWidthSize = board [ 0 ].size () ;
//     int iMaxSize = 1 ;
//     queue < pair < int , int > > qCoordinate ;
//     int iLeftSize = 0 ;                         // For parametric search
//     int iRightSize = 0 ;
//     int iMidSize = 0 ;
//     bool bSquareExist = false ;
//     bool bFoundSquare = false ;
// 
// 
// 
//     for ( int i = 0 ; i < iHeightSize ; ++i )       // Find possible max size
//     {
//         for ( int j = 0 ; j < iWidthSize ; ++j )
//         {
//             if ( 0 == board [ i ] [ j ] )
//             {
//                 iRightSize = max ( iRightSize , max ( max ( i - 1 , iHeightSize - i - 1 ) , max ( j - 1 , iWidthSize - j - 1 )  ) ) ;
//             }
//         }
//     }
// 
//     iRightSize = std :: min ( iRightSize , std :: min ( iHeightSize , iWidthSize ) ) ;
//     iLeftSize = 2 ;
//     iMidSize = ( iLeftSize + iRightSize ) / 2 ;
//     
//     while ( iLeftSize <= iRightSize )    // Parametric search
//     {
//         qCoordinate.emplace ( make_pair ( 0 , 0 ) ) ;
// 
//         while ( ! qCoordinate.empty () )
//         {
//             pair < int , int > pCoordinate = qCoordinate.front () ;
//             qCoordinate.pop () ;
//             bSquareExist = true ;
// 
//             if ( ( iHeightSize - pCoordinate.first < iMidSize ) || ( iWidthSize - pCoordinate.second < iMidSize ) )        // Midsize square can't exist
//                 continue ;
// 
//             for ( int i = 0 ; i < iMidSize ; ++i )
//             {
//                 for ( int j = 0 ; j < iMidSize ; ++j )
//                 {
//                     if ( 0 == board [ pCoordinate.first + i ] [ pCoordinate.second + j ] )
//                     {
//                         if ( pCoordinate.first + i + 1 != iHeightSize )                 // Down | Down left
//                             qCoordinate.emplace ( make_pair ( pCoordinate.first + i + 1 , pCoordinate.second ) ) ;
//                         if ( pCoordinate.second + j + 1 != iWidthSize )                // Right | Right up
//                             qCoordinate.emplace ( make_pair ( pCoordinate.first , pCoordinate.second + j + 1 ) ) ;
//         
//                         i = iMidSize ;      // To break loop
//                         bSquareExist = false ;
// 
//                         break ;
//                     }
//                 }
//             }
// 
//             if ( bSquareExist )
//             {
//                 while ( ! qCoordinate.empty () ) qCoordinate.pop () ;
//                 
//                 iMaxSize = iMidSize ;
//                 iLeftSize = iMidSize + 1 ;
//                 iMidSize = ( iLeftSize + iRightSize ) / 2 ;
//             }
//         }
// 
//         if ( ! bSquareExist )       // Can't find square
//         {
//             iRightSize = iMidSize - 1 ;
//             iMidSize = ( iLeftSize + iRightSize ) / 2 ;
//         }
//     }
// 
// 
//     return iMaxSize * iMaxSize ;
// }

int main ()
{
    // int i = solution ( {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}} ) ;
    int i = solution ( {{0, 0, 1, 1}, {1, 1, 1, 1}} ) ;
}