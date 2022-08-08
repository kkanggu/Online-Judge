#include <vector>
#include <utility>

using std :: vector ;
using std :: pair ;
using std :: make_pair ;

void rotateKey ( vector < pair < int , int > > & vKey , int iKeySize )			// Rotate 90 degree to counterclock
{
	int iKeyCount = vKey.size () ;
	
	
	
	for ( int i = 0 ; i < iKeyCount ; ++i )
	{
		pair < int , int > pTemp = vKey [ i ] ;
		vKey [ i ] = make_pair ( iKeySize - pTemp.second - 1 , pTemp.first ) ;
	}
}

bool bIsKeyFitToLock ( vector < pair < int , int > > & vKey , vector < vector < int > > & vLock , int iLockCount , int iKeySize )
{
	int iKeyCount = vKey.size () ;
	int iLockSize = vLock.size () ;
	int iKeyFitCount = 0 ;
	
	
	
	for ( int i = - iKeySize + 1 ; i < iLockSize ; ++i )
	{
		for ( int j = - iKeySize + 1 ; j < iLockSize ; ++j )
		{
			iKeyFitCount = 0 ;
			
			
			for ( int k = 0 ; k < iKeyCount ; ++k )
			{
				int iX = vKey [ k ].first + i ;
				int iY = vKey [ k ].second + j ;
				
				if ( ( iX < 0 ) || ( iY < 0 ) || ( iLockSize <= iX ) || ( iLockSize <= iY ) )
					continue ;
				
				if ( 1 == vLock [ iX ] [ iY ] )
					break ;
				
				++ iKeyFitCount ;
			}
			
			if ( iLockCount == iKeyFitCount )
				return true ;
		}
	}
	
	
	return false ;
}

bool solution ( vector < vector < int > > key , vector < vector < int > > lock )
{
	int iKeySize = key.size () ;
	int iLockSize = lock.size () ;
	int iLockCount = 0 ;
	vector < pair < int , int > > vKeyCoordinate ;
	
	
	
	for ( int i = 0 ; i < iKeySize ; ++i )
	{
		int * ipTemp = key [ i ].data () ;
		
		for ( int j = 0 ; j < iKeySize ; ++j )
		{
			if ( 1 == * ipTemp ++ )
			{
				vKeyCoordinate.emplace_back ( make_pair ( i , j ) ) ;
			}
		}
	}
	for ( int i = 0 ; i < iLockSize ; ++i )
	{
		int * ipTemp = lock [ i ].data () ;
		
		for ( int j = 0 ; j < iLockSize ; ++j )
		{
			if ( 0 == * ipTemp ++ )
			{
				++ iLockCount ;
			}
		}
	}
	
	for ( int i = 0 ; i < 4 ; ++i )
	{
		if ( bIsKeyFitToLock ( vKeyCoordinate , lock , iLockCount , iKeySize ) )
			return true ;
		
		rotateKey ( vKeyCoordinate , iKeySize ) ;
	}
	
	
	return false ;
}