#include <vector>
#include <cmath>
#include <stdio.h>

using std :: vector ;

vector < int > vQueenPlace ;
int * ipQueen ;
int iSize ;

bool bIsPromising ( int iQueenPlacedBefore , int iIndex )
{
	for ( int i = 0 ; i < iQueenPlacedBefore ; ++i )
	{
		if ( ( iIndex == ipQueen [ i ] ) || ( iQueenPlacedBefore - i == abs ( iIndex - ipQueen [ i ] ) ) )
			return false ;
	}
	
	return true ;
}

int iGetQueen ( int iNextPlace )
{
	int iReturn = 0 ;
	
	
	
	if ( iNextPlace == iSize )
		return 1 ;
	
	for ( int i = 0 ; i < iSize ; ++i )
	{
		if ( bIsPromising ( iNextPlace , i ) )
		{
			ipQueen [ iNextPlace ] = i ;
			iReturn += iGetQueen ( iNextPlace + 1 ) ;
		}
	}
	
	return iReturn ;
}

int solution ( int n )
{
	vQueenPlace.resize ( n ) ;
	ipQueen = vQueenPlace.data () ;
	iSize = n ;
	int iAnswer = 0 ;
	
	
	
	for ( int i = 0 ; i < ( n + 1 ) >> 1 ; ++i )
	{
		ipQueen [ 0 ] = i ;
		
		int iTemp = iGetQueen ( 1 ) << 1 ;
		
		if ( ( 1 == ( n & 1 ) ) && ( n >> 1 == i ) )
			iTemp >>= 1 ;
		
		iAnswer += iTemp ;
	}
	
	return iAnswer ;
}