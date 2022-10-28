#include <vector>
#include <algorithm>

using std :: vector ;

void flipCoin ( vector < vector < int > > & vMap , bool bRow , int iIndex , int iSize )
{
	if ( bRow )
	{
		for ( int j = 0 ; j < iSize ; ++j )
		{
			vMap [ iIndex ] [ j ] = 1 - vMap [ iIndex ] [ j ] ;
		}
	}
	else
	{
		for ( int i = 0 ; i < iSize ; ++i )
		{
			vMap [ i ] [ iIndex ] = 1 - vMap [ i ] [ iIndex ] ;
		}
	}
}

int solution ( vector < vector < int > > beginning , vector < vector < int > > target )
{
	int iAnswer = 0 ;
	int iHeight = beginning.size () ;
	int iWidth = beginning [ 0 ].size () ;
	bool bCanMake = true ;
	
	
	
	for ( int j = 0 ; j < iWidth ; ++j )
	{
		if ( beginning [ 0 ] [ j ] != target [ 0 ] [ j ] )
		{
			flipCoin ( beginning , false , j , iHeight ) ;
			++ iAnswer ;
		}
	}
	for ( int i = 1 ; i < iHeight ; ++i )
	{
		if ( beginning [ i ] [ 0 ] != target [ i ] [ 0 ] )
		{
			flipCoin ( beginning , true , i , iWidth ) ;
			++ iAnswer ;
		}
	}
	for ( int i = 1 ; i < iHeight ; ++i )
	{
		for ( int j = 1 ; j < iWidth ; ++j )
		{
			if ( beginning [ i ] [ j ] != target [ i ] [ j ] )
			{
				bCanMake = false ;
				
				break ;
			}
		}
	}
	
	return bCanMake ? std :: min ( iAnswer , iHeight + iWidth - iAnswer ) : -1 ;
}