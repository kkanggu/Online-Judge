#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std :: vector ;
using std :: unordered_map ;
using std :: priority_queue ;

struct numberInfo
{
	int iCount ;
	vector < int > vIndexList ;
} ;

struct comp
{
	bool operator () ( const numberInfo & n1 , const numberInfo & n2 )
	{
		return n1.iCount < n2.iCount ;
	}
} ;

int solution ( vector < int > a )
{
	int answer = 0 ;
	unordered_map < int , vector < int > > umNumberIndex ;		// < number , vector having index of number
	int iNumberSize = a.size () ;
	priority_queue < numberInfo , vector < numberInfo > , comp > pqNumber ;
	
	
	
	if ( iNumberSize <= 3 )
		return 0 ;
	
	for ( int i = 0 ; i < iNumberSize ; ++i )
	{
		umNumberIndex [ a [ i ] ].emplace_back ( i ) ;
	}
	for ( auto iter = umNumberIndex.begin () ; iter != umNumberIndex.end () ; ++ iter )
	{
		pqNumber.push ( { ( int ) ( iter -> second.size () ) , iter -> second } ) ;
	}
	
	while ( ! pqNumber.empty () )
	{
		numberInfo currentNumber = pqNumber.top () ;
		pqNumber.pop () ;
		
		if ( currentNumber.iCount << 1 <= answer )
			break ;
		
		int iFormerPairIndex = 0 == currentNumber.vIndexList [ 0 ] ? 1 : currentNumber.vIndexList [ 0 ] - 1 ;
		int iCount = 1 ;
		
		
		for ( int i = 1 ; i < currentNumber.iCount ; ++i )
		{
			int iCurrentNumber = currentNumber.vIndexList [ i ] ;
			
			
			if ( iFormerPairIndex == iCurrentNumber )
			{
				continue ;
			}
			else if ( ( iFormerPairIndex + 1 == iCurrentNumber ) || ( currentNumber.vIndexList [ i - 1 ] + 1 == iCurrentNumber ) )
			{
				if ( iCurrentNumber + 1 == currentNumber.vIndexList [ i + 1 ] )
					continue ;
				
				iFormerPairIndex = iCurrentNumber + 1 ;
				
				if ( iFormerPairIndex == iNumberSize )
					break ;
			}
			else
			{
				if ( iCurrentNumber - 1 == currentNumber.vIndexList [ i - 1 ] )
					continue ;
				
				iFormerPairIndex = iCurrentNumber - 1 ;
			}
			
			
			++ iCount ;
		}
		
		answer = std :: max ( answer , iCount << 1 ) ;
	}
	
	
	return answer ;
}