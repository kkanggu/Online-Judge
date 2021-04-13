#include <iostream>
#pragma warning(disable:4996)

using std :: cin ;
using std :: cout ;

int main ()
{
	int iNum = 0 ;
	int irgElectricWire [ 501 ] = { 0 , } ;				// [ n ], n+1 is left position, and [ n ] + 1 is right position
	int irgSeq [ 100 ] = { 0 , } ;						// [ n ], n+1 is sequence length and [ n ] is the last num of sequence. Ascending
	int iMax = 100 ;
	int iLoopCnt = 0 ;



	cin >> iNum ;

	std :: fill_n ( irgSeq , 100 , 1001 ) ;

	{
		int iLeftNum = 0 ;
		int iRightNum = 0 ;


		for ( int i = 0 ; i < iNum ; ++i )
		{
			scanf ( "%d %d" , & iLeftNum , & iRightNum ) ;

			irgElectricWire [ iLeftNum ] = iRightNum ;
		}
	}
	{
		int i = 1 ;


		while ( iNum != iLoopCnt )																							// Ascending Check
		{
			if ( irgElectricWire [ i ] )																					// If wire exist
			{
				if ( ( irgElectricWire [ i ] ) && ( irgSeq [ 0 ] > irgElectricWire [ i ] ) )								// Electric wire is valid and lower efficient data exist, Ascending
				{
					irgSeq [ 0 ] = irgElectricWire [ i ] ;
				}

				for ( int j = 2 ; j < i + 1 ; ++j )
				{
					if ( ( irgSeq [ j - 2 ] < irgElectricWire [ i ] ) && ( irgSeq [ j - 1 ] > irgElectricWire [ i ] ) )		// Ascending
					{
						irgSeq [ j - 1 ] = irgElectricWire [ i ] ;
					}
				}

				++ iLoopCnt ;
			}

			++i ;
		}
	}
	for ( int i = 0 ; i < 100 ; ++i )
	{
		if ( 1001 == irgSeq [ i ] ) 
		{
			iMax = iNum - i ;																	// If true, then iMax = Electric wire - Overlapping wire
			
			break ;
		}
	}


	cout << iMax ;
	
	
	
	
	
	
	
	
	
	
	//int iNum = 0 ;
	//int irgElectricWire [ 501 ] = { 0 , } ;				// [ n ], n+1 is left position, and [ n ] + 1 is right position
	//int irgSeq [ 2 ] [ 100 ] = { 0 , } ;				// [] [ n ], n+1 is sequence length and [ n ] is the last num of sequence. Ascending
	//int iMax = 100 ;									// [ 0 ] [] mean ascending, [ 1 ] [] mean descending.
	//int iLoopCnt = 0 ;



	//cin >> iNum ;

	//std :: fill_n ( irgSeq [ 0 ] , 100 , 1001 ) ;

	//{
	//	int iLeftNum = 0 ;
	//	int iRightNum = 0 ;


	//	for ( int i = 0 ; i < iNum ; ++i )
	//	{
	//		scanf ( "%d %d" , & iLeftNum , & iRightNum ) ;

	//		irgElectricWire [ iLeftNum ] = iRightNum ;
	//	}
	//}
	//{
	//	int i = 1 ;


	//	while ( iNum != iLoopCnt )																					// Ascending Check
	//	{
	//		if ( irgElectricWire [ i ] )																					// If wire exist
	//		{
	//			if ( ( irgElectricWire [ i ] ) && ( irgSeq [ 0 ] [ 0 ] > irgElectricWire [ i ] ) )							// Electric wire is valid and lower efficient data exist, Ascending
	//			{
	//				irgSeq [ 0 ] [ 0 ] = irgElectricWire [ i ] ;
	//			}

	//			for ( int j = 2 ; j < i + 1 ; ++j )
	//			{
	//				if ( ( irgSeq [ 0 ] [ j - 2 ] < irgElectricWire [ i ] ) && ( irgSeq [ 0 ] [ j - 1 ] > irgElectricWire [ i ] ) )		// Ascending
	//				{
	//					irgSeq [ 0 ] [ j - 1 ] = irgElectricWire [ i ] ;
	//				}
	//			}

	//			++ iLoopCnt ;
	//		}

	//		++i ;
	//	}

	//	while ( iLoopCnt )																							// Ascending Check
	//	{
	//		if ( irgElectricWire [ i ] )																					// If wire exist
	//		{
	//			if ( ( irgElectricWire [ i ] ) && ( irgSeq [ 1 ] [ 0 ] < irgElectricWire [ i ] ) )							// Electric wire is valid and lower efficient data exist, Descending
	//			{
	//				irgSeq [ 1 ] [ 0 ] = irgElectricWire [ i ] ;
	//			}

	//			for ( int j = i ; j > 1 ; --j )
	//			{
	//				if ( ( irgSeq [ 1 ] [ j - 2 ] > irgElectricWire [ i ] ) && ( irgSeq [ 1 ] [ j - 1 ] < irgElectricWire [ i ] ) )		// Descending
	//				{
	//					irgSeq [ 1 ] [ j - 1 ] = irgElectricWire [ i ] ;
	//				}
	//			}

	//			-- iLoopCnt ;
	//		}

	//		--i ;
	//	}
	//}
	//for ( int i = 0 ; i < 100 ; ++i )
	//{
	//	if ( ( 1001 == irgSeq [ 0 ] [ i ] ) && ( 0 == irgSeq [ 1 ] [ i ] ) )
	//	{
	//		iMax = iNum - i ;																	// If true, then iMax = Electric wire - Overlapping wire
	//		
	//		break ;
	//	}
	//}


	//cout << iMax ;


	return 0 ;
}