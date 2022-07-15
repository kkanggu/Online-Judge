int solution ( int n )
{
    int iTemp = n ;
    int iIndex = 0 ;
    int iReturn = 0 ;



    for ( int i = 0 ; i < 31 ; ++i )
    {
        if ( 1 == ( ( n & ( 3 << i ) ) >> i ) )
        {
            iReturn = n + ( 1 << i ) ;
            iIndex = i - 1 ;

            break ;
        }
    }

    iTemp = 0 ;

    for ( int i = iIndex ; i >= 0 ; --i )
    {
        if ( 1 == ( ( iReturn & ( 1 << i ) ) >> i ) )
        {
            ++ iTemp ;
        }
    }


    ++ iIndex ;
    if ( 0 != iTemp )
    {
        iReturn = ( ( iReturn >> iIndex ) << iIndex ) + ( 1 << iTemp ) - 1 ;
    }

    return iReturn ;
}

int main ()
{
    int i = solution ( 78 ) ;
}