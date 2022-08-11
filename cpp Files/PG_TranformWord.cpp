#include <string>
#include <vector>
#include <algorithm>

using std :: vector ;
using std :: string ;

int iAnswer ;

bool bCanTransform ( const char * cpSource , const char * cpDestination , int iStringSize )
{
	int iCount = 0 ;
	
	
	
	for ( int i = 0 ; i < iStringSize ; ++i )
	{
		if ( * cpSource ++ != * cpDestination ++ )
		{
			++ iCount ;
			
			if ( 2 == iCount )
				return false ;
		}
	}
	
	return 1 == iCount ? true : false ;
}

void findMinimumWordTransform ( string strTarget , vector < string > vWord , string strWord , int iCount )
{
	if ( iAnswer <= iCount )						// Current is not best
		return ;
	if ( 0 == strTarget.compare ( strWord ) )
	{
		iAnswer = iCount ;
		
		return ;
	}
	
	int iWordSize = vWord.size () ;
	int iStringSize = strWord.size () ;
	
	
	for ( int i = 0 ; i < iWordSize ; ++i )
	{
		if ( 0 == vWord [ i ].size () )			// Already used this string
			continue ;
		
		if ( bCanTransform ( strWord.data () , vWord [ i ].data () , iStringSize ) )
		{
			string strNextWord = vWord [ i ] ;
			vWord [ i ] = "" ;
			findMinimumWordTransform ( strTarget, vWord , strNextWord , iCount + 1 ) ;	
			vWord [ i ] = strNextWord ;
		}
	}
}

int solution ( string begin , string target , vector < string > words )
{
	iAnswer = 51 ;
	
	
	
	if ( words.end () == std :: find ( words.begin () , words.end () , target ) )
		return 0 ;
	
	
	findMinimumWordTransform ( target , words , begin , 0 ) ;	
	
	
	return 51 != iAnswer ? iAnswer : 0 ;
}