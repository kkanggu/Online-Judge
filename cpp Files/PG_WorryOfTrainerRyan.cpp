#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using std :: vector ;
using std :: map ;

void placeUser ( int iX , int iY , int iDistance , int iLockerSize , int idrgPlace [] [ 10 ] )
{
	for ( int i = iX - iDistance ; i < iX + iDistance ; ++i )
	{
		for ( int j = iY - iDistance ; j < iY + iDistance ; ++j )
		{
			if ( ( i < 0 ) || ( iLockerSize <= i ) )		// Need to change i, so break
				break ;
			if ( ( j < 0 ) || ( iLockerSize <= j ) || ( iDistance <= abs ( i - iX ) + abs ( j - iY ) ) )
				continue ;
			
			idrgPlace [ i ] [ j ] = -1 ;
		}
	}
	
	idrgPlace [ iX ] [ iY ] = 1 ;
}

bool bCanPlaceCustomers ( int iLockerSize , int iCustomerSize , int iDistance )
{
	int idrgPlace [ 10 ] [ 10 ] ;			// 1 Placed, -1 in distance , 0 empty
	int iCnt = 0 ;
	
	
	
	for ( int k = 0 ; k < iLockerSize >> 1 ; ++k )
	{
		std :: fill ( * idrgPlace , * ( idrgPlace + iLockerSize ) , 0 ) ;
		std :: fill ( * idrgPlace , * idrgPlace + k , -1 ) ;
		iCnt = 0 ;

		for ( int i = 0 ; i < iLockerSize ; ++i )
		{
			for ( int j = 0 ; j < iLockerSize ; ++j )
			{
				if ( 0 == idrgPlace [ i ] [ j ] )
				{
					placeUser ( i , j , iDistance , iLockerSize , idrgPlace ) ;
					
					++ iCnt ;
					
					if ( iCnt == iCustomerSize )
						return true ;
				}
			}
		}
	}
	
	
	for ( int i = 0 ; i < iLockerSize ; ++i )
	{
		for ( int j = 0 ; j < iLockerSize ; ++j )
		{
			if ( 0 == idrgPlace [ i ] [ j ] )
			{
				placeUser ( i , j , iDistance , iLockerSize , idrgPlace ) ;
				
				++ iCnt ;
				
				if ( iCnt == iCustomerSize )
					return true ;
			}
		}
	}
	
	return false ;
}

int solution ( int n , int m , vector < vector < int > > timetable )
{
	int answer = 1 ;
	int iLeft = 2 ;
	int iRight = ( n - 1 ) << 1 ;
	int iMid ;
	int iMaxCustomer = 0 ;
	int iCurrentCustomer = 0 ;
	map < int , int > mPeopleAddAtTime ;
	map < int , int > mPeopleRemoveAtTime ;
	
	
	
	for ( int i = 0 ; i < m ; ++i )
	{
		++ mPeopleAddAtTime [ timetable [ i ] [ 0 ] ] ;
		++ mPeopleRemoveAtTime [ timetable [ i ] [ 1 ] ] ;
	}
	auto iterAdd = mPeopleAddAtTime.begin () ;
	auto iterRemove = mPeopleRemoveAtTime.begin () ;
	while ( iterAdd != mPeopleAddAtTime.end () && iterRemove != mPeopleRemoveAtTime.end () )
	{
		if ( iterAdd -> first <= iterRemove -> first )
		{
			iCurrentCustomer += iterAdd -> second ;
			iMaxCustomer = std :: max ( iMaxCustomer , iCurrentCustomer ) ;
			++ iterAdd ;
		}
		else
		{
			iCurrentCustomer -= iterRemove -> second ;
			++ iterRemove ;
		}
	}
	for ( ; iterAdd != mPeopleAddAtTime.end () ; ++ iterAdd )
	{
		iCurrentCustomer += iterAdd -> second ;
		iMaxCustomer = std :: max ( iMaxCustomer , iCurrentCustomer ) ;
	}
	
	
	if ( iMaxCustomer <= 1 )
		return 0 ;
	
	while ( iLeft <= iRight )
	{
		iMid = ( iLeft + iRight ) >> 1 ;
		
		if ( bCanPlaceCustomers ( n , iMaxCustomer , iMid ) )
		{
			answer = iMid ;
			iLeft = iMid + 1 ;
		}
		else
			iRight = iMid - 1 ;
	}
	
	
	return answer ;
}

int main ()
{
	int s = solution ( 4 , 5 , {{1140,1200},{1150,1200},{1100,1200},{1210,1300},{1220,1280}} ) ;
}