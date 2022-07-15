#include <vector>
#include <cmath>

using std :: vector ;

vector < int > solution ( long long begin , long long end )
{
    vector < int > answer ( end - begin + 1 , 0 ) ;
    int * ipAnswer = answer.data () ;
    int iPrimeSize = 1 ;



    for ( int i = begin ; i <= end ; ++i )
    {
        if ( 1 == i )
        {
            ipAnswer [ 0 ] = 0 ;

            continue ;
        }

        ipAnswer [ i - begin ] = 1 ;

        for ( int j = 2 ; j * j <= i ; ++j )
        {
            if ( ( 0 == i % j ) && ( i / j <= 10000000 ) )
            {
                ipAnswer [ i - begin ] = i / j ;
                
                break ;
            }
        } 
    }


    return answer ;
}

int main ()
{
    vector < int > v = solution ( 53334902, 53334903 ) ;
}