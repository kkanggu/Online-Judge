#include <vector>
#include <string>
#include <stack>

using std :: vector ;
using std :: string ;
using std :: stack ;

struct dLinkNode
{
	int iIndex ;
	dLinkNode * pPrev ;
	dLinkNode * pNext ;
	
	dLinkNode ( int iIndex , dLinkNode * pPrev , dLinkNode * pNext )
		: iIndex ( iIndex ) , pPrev ( pPrev ) , pNext ( pNext ) {}
} ;

string solution ( int n , int k , vector < string > cmd )
{
	string answer = "" ;
	int iCommandSize = cmd.size () ;
	dLinkNode * pRoot = new dLinkNode ( -1 , NULL , NULL ) ;
	dLinkNode * pNode = pRoot ;
	dLinkNode * pTemp = pNode ;
	stack < dLinkNode * > sDelete ;
	
	
	
	for ( int i = 0 ; i < n ; ++i )
	{
		dLinkNode * pNew = new dLinkNode ( i , pTemp , NULL ) ;
		pTemp -> pNext = pNew ;
		pTemp = pNew ;
	}
	pNode = pRoot ;
	for ( int i = 0 ; i <= k ; ++i )
		pNode = pNode -> pNext ;
	
	for ( int i = 0 ; i < iCommandSize ; ++i )
	{
		string strCommand = cmd [ i ] ;
		
		if ( 'D' == strCommand [ 0 ] )
		{
			int iCount = stoi ( strCommand.substr ( 2 ) ) ;
			
			for ( int j = 0 ; j < iCount ; ++j )
				pNode = pNode -> pNext ;
		}
		else if ( 'U' == strCommand [ 0 ] )
		{
			int iCount = stoi ( strCommand.substr ( 2 ) ) ;
			
			for ( int j = 0 ; j < iCount ; ++j )
				pNode = pNode -> pPrev ;
		}
		else if ( 'C' == strCommand [ 0 ] )
		{
			sDelete.push ( pNode ) ;
			pTemp = pNode ;
			
			if ( pNode -> pNext )
				pNode = pNode -> pNext ;
			else
				pNode = pNode -> pPrev ;
			
			if ( pTemp -> pNext )		// Not the end
			{
				pTemp -> pNext -> pPrev = pTemp -> pPrev ;
			}
			if ( pTemp -> pPrev )		// Not the begin
			{
				pTemp -> pPrev -> pNext = pTemp -> pNext ;
			}
			
			if ( pTemp == pRoot )
				pRoot = pRoot -> pNext ;
		}
		else
		{
			dLinkNode * pNew = sDelete.top () ;
			
			if ( pNew -> pPrev )		// Not the Head
				pNew -> pPrev -> pNext = pNew ;
			if ( pNew -> pNext )		// Not the tail
				pNew -> pNext -> pPrev = pNew ;
						
			sDelete.pop () ;
		}
	}
	
	pNode = pRoot -> pNext ;
	for ( int i = 0 ; i < n ; ++i )
	{
		if ( ! pNode || ( i < pNode -> iIndex ) )
			answer += 'X' ;
		else
		{
			answer += 'O' ;
			pNode = pNode -> pNext ;
		}
	}
	
	
	return answer ;
}