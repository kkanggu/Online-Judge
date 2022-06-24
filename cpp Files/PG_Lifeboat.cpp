#include <vector>
#include <algorithm>

using std :: vector ;

int solution ( vector < int > people , int limit )
{
	int iAnswer = 0 ;
	int * ipTemp ;
	int iLen = people.size () ;
	int iLeftIndex = 0 ;
	int iRightIndex = iLen - 1 ;
	int iCnt = 0 ;
	
	
	
	std :: sort ( people.begin () , people.end () ) ;
	ipTemp = people.data () ;
	
	while ( iLeftIndex < iRightIndex )
	{
		if ( ipTemp [ iLeftIndex ] + ipTemp [ iRightIndex ] <= limit )			// Min + Max <= limit, save them
		{
			++ iAnswer ;
			++ iLeftIndex ;
			-- iRightIndex ;

			continue ;
		}

		// Min + Max > limit, so max must go

		-- iRightIndex ;
		++ iAnswer ;
	}

	if ( iLeftIndex == iRightIndex )		// One person left
		++ iAnswer ;



	return iAnswer ;
}