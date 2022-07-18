#include <vector>

using std :: vector ;

vector < int > solution ( int n , long long k )
{
    vector < int > answer ;
    vector < int > vNumberList ;
    long long llFactorial = 1 ;



    for ( int i = 1 ; i < n ; ++i )
    {
        vNumberList.emplace_back ( i ) ;
        llFactorial *= i ;
    }
    vNumberList.emplace_back ( n ) ;

    for ( int i = n - 1 ; i >= 1 ; --i )
    {
        int iIndex = ( k - 1 ) / llFactorial ;
        k -= iIndex * llFactorial ;
        llFactorial /= i ;

        answer.emplace_back ( vNumberList [ iIndex ] ) ;
        vNumberList.erase ( vNumberList.begin () + iIndex ) ;
    }
    answer.emplace_back ( vNumberList [ 0 ] ) ;


    return answer ;
}

int main ()
{
    //vector < int > v = solution ( 20 , 2432902008176640000 ) ;
    vector < int > v = solution ( 4 , 11 ) ;
}