#include <vector>
#include <algorithm>
#include <queue>

using std :: vector ;
using std :: priority_queue ;

struct jobInfo
{
	int iRequestTime ;
	int iUsedTime ;
} ;

struct comp
{
	bool operator () ( jobInfo & first , jobInfo & second )
	{
		return first.iUsedTime > second.iUsedTime ;
	}
} ;

int solution ( vector < vector < int > > jobs )
{
	int answer = 0 ;
	std :: sort ( jobs.begin () , jobs.end () ) ;
	priority_queue < jobInfo , vector < jobInfo > , comp > pqJobs ;
	int iJobIndex = 0 ;
	int iJobSize = jobs.size () ;
	int iTime = 0 ;
	
	
	
	for ( int i = 0 ; i < iJobSize ; ++i )
	{
		for ( ; iJobIndex < iJobSize ; ++ iJobIndex )
		{
			if ( iTime < jobs [ iJobIndex ] [ 0 ] )
				break ;
			
			pqJobs.push ( { jobs [ iJobIndex ] [ 0 ] , jobs [ iJobIndex ] [ 1 ] } ) ;
		}
		
		if ( pqJobs.empty () )
		{
			iTime = jobs [ iJobIndex ] [ 0 ] ;
			-- i ;
		}
		else
		{
			jobInfo currentJob = pqJobs.top () ;
			pqJobs.pop () ;
			iTime += currentJob.iUsedTime ;
			answer += iTime - currentJob.iRequestTime ;
		}
	}
	
	
	return answer / iJobSize ;
}