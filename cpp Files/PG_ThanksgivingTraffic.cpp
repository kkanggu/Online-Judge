#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>

using std :: vector ;
using std :: string ;
using std :: max ;
using std :: pair ;
using std :: make_pair ;

int solution ( vector < string > lines )
{
	int answer = 0 ;
	int iLineSize = lines.size () ;
	vector < pair < int , int > > vTimeInfo ;
	
	
	
	for ( int i = 0 ; i < iLineSize ; ++i )
	{
		string strTemp = lines [ i ] ;
		strTemp [ strTemp.size () - 1 ] = '\0' ;
		std :: stringstream ss ( strTemp ) ;
		
		ss >> strTemp ;			// Date is useless
		ss >> strTemp ;			// Get end time
		int iEndTime = ( strTemp [ 0 ] - '0' ) * 36000000 + ( strTemp [ 1 ] - '0' ) * 3600000 + ( strTemp [ 3 ] - '0' ) * 600000 + ( strTemp [ 4 ] - '0' ) * 60000 + ( strTemp [ 6 ] - '0' ) * 10000 + ( strTemp [ 7 ] - '0' ) * 1000 + ( strTemp [ 9 ] - '0' ) * 100 + ( strTemp [ 10 ] - '0' ) * 10 + ( strTemp [ 11 ] - '0' ) ;
		
		ss >> strTemp ;			// Get process time
		int iProcessTime = stod ( strTemp ) * 1000 ;
		
		vTimeInfo.emplace_back ( iEndTime - iProcessTime + 1 , iEndTime ) ;
	}
	
	int iInfoSize = vTimeInfo.size () ;
	std :: sort ( vTimeInfo.begin () , vTimeInfo.end () , [] ( pair < int , int > & p1 , pair < int , int > & p2 ) { return p1.second < p2.second ; } ) ;
	
	
	for ( int i = 0 ; i < iInfoSize ; ++i  )
	{
		int iCurrentEndTime = vTimeInfo [ i ].second ;
		int iCount = 1 ;
		
		for ( int j = i + 1 ; j < iInfoSize ; ++j )
		{
			if ( vTimeInfo [ j ].first <= iCurrentEndTime + 999 )
				++ iCount ;
		}
		
		
		answer = max ( answer , iCount ) ;
	}
	
	
	return answer ;
}