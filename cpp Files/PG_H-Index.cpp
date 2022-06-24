#include <vector>
#include <algorithm>

using std :: vector ;

int solution ( vector < int > citations )
{
	int answer = 0 ;
	int * ipTemp ;
	int i = 0 ;
	int iTotal = citations.size () ;
	int iLeft = 0 ;
	int iRight = iTotal - 1 ;
	int iMid = iRight / 2 ;
	int iCnt = 0 ;



	std :: sort ( citations.begin () , citations.end () ) ;

	ipTemp = citations.data () ;

	for ( int i = iRight ; i >= 0 ; --i )
	{
		if ( ipTemp [ i ] > answer )
			++ answer ;
		else
			break ;
	}



//	while ( iLeft < iRight )
//	{
//		int iTemp = ipTemp [ iMid ] ;
//		
//		
//		if ( iTemp <= ( iTotal - iMid ) )		// Can be H-Index
//		{
//			answer = iTemp ; 
//
//			iLeft = iMid + 1 ;
//			iMid = ( iLeft + iRight ) / 2 ;
//
//			continue ;
//		}
//
//		iRight = iMid - 1 ;
//		iMid = ( iLeft + iMid ) / 2 ;
//	}
//
//	answer = std :: max ( answer , iTotal - iMid - 1 ) ;
//	
//	if ( answer < ipTemp [ 0 ] )
//		++ answer ;


	return answer ;
}

int main ()
{
//	vector < int > s = { 3 , 0 , 6 , 1 , 5 } ;
//	vector < int > s1 = { 10 , 10 , 10 , 10 , 10 } ;
//	vector < int > s1 = { 5 , 10 , 10 , 10 , 10 } ;
//	vector < int > s1 = { 6,5,5,5,5,2,1,0 } ;
//	vector < int > s1 = { 0,1,2 } ;
//	vector < int > s1 = { 12,11,10,9,8,1 } ;
//	vector < int > s1 = { 2,2,2,2,2 } ;
//	vector < int > s1 = { 0 } ;
//	vector < int > s1 = { 4,3,3,3,3 } ;
//	vector < int > s1 = { 10, 9, 4, 1, 1 } ;
	vector < int > s1 = { 5,5,5,5 } ;
//	vector < int > s2 = { 0 , 0 , 0 , 0 , 0 } ;

//	int i = solution ( s ) ;
	int i1 = solution ( s1 ) ;
//	int i2 = solution ( s2 ) ;


	return 0 ;
}