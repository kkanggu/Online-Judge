#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std :: vector ;
using std :: string ;
using std :: list ;

vector < int > solution ( vector < string > operations )
{
	vector < int > answer ( 2 , 0 ) ;
	int iStartIndex = -1 ;
	int iOperationSize = operations.size () ;
	int iTemp = 0 ;
	list < int > pqList ;
	
	
	
	for ( int i = 0 ; i < iOperationSize ; ++i )			// Find start index. At this order, queue is empty
	{
		if ( 'D' == operations [ i ] [ 0 ] )
			iTemp = std :: max ( 0 , iTemp - 1 ) ;
		else
			++ iTemp ;
		
		if ( 0 == iTemp )
			iStartIndex = i ;
	}
	for ( int i = iStartIndex + 1 ; i < iOperationSize ; ++i )
	{
		int iValue = stoi ( operations [ i ].substr ( 2 , operations [ i ].size () - 2 ) ) ;
		bool bInsert = true ;
		
		if ( 'I' == operations [ i ] [ 0 ] )
		{
			for ( auto iter = pqList.begin () ; iter != pqList.end () ; ++ iter )
			{
				if ( iValue >= * iter )
				{
					pqList.emplace ( iter , iValue ) ;
					bInsert = false ;
					
					break ;
				}				
			}
			
			if ( bInsert )					// iValue is minimum value
			{
				pqList.emplace_back ( iValue ) ;
			}
			
			continue ;
		}
		
		if ( 1 == iValue )					// Found iStartIndex, so pqList must not empty
			pqList.pop_front () ;
		else
			pqList.pop_back () ;
	}
	
	if ( ! pqList.empty () )
	{
		answer [ 0 ] = pqList.front () ;
		answer [ 1 ] = pqList.back () ;
	}
	
	
	return answer ;
}