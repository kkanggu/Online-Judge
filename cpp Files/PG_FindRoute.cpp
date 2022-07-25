#include <vector>
#include <algorithm>

using std :: vector ;

struct treeNode
{
	int iX ;
	int iLevel ;
	int iIndex ;
	treeNode * pLeft ;
	treeNode * pRight ;

	treeNode ( int iX , int iLevel , int iIndex ) : iX ( iX ) , iLevel ( iLevel ) , iIndex ( iIndex )
	{
		pLeft = NULL ;
		pRight = NULL ;
	}
} ;

bool bCompare ( treeNode & a , treeNode & b )
{
	if ( a.iLevel > b.iLevel )
		return true ;
	else if ( a.iLevel == b.iLevel )
		return a.iX < b.iX ;
	
	return false ;
}

treeNode * findRoot ( treeNode * pTarget , treeNode * pRoot )
{
	if ( pTarget -> iX < pRoot -> iX )
	{
		if ( NULL == pRoot -> pLeft )
			return pRoot ;
		
		return findRoot ( pTarget , pRoot -> pLeft ) ;
	}
	if ( pRoot -> iX < pTarget -> iX )
	{
		if ( NULL == pRoot -> pRight )
			return pRoot ;
		
		return findRoot ( pTarget , pRoot -> pRight ) ;
	}
	
	return NULL ;
}


void getPreOrder ( treeNode * pNode , vector < int > * answer )
{
	if ( NULL == pNode )
		return ;
	
	answer -> emplace_back ( pNode -> iIndex ) ;
	getPreOrder ( pNode -> pLeft , answer ) ;
	getPreOrder ( pNode -> pRight , answer ) ;
}

void getPostOrder ( treeNode * pNode , vector < int > * answer )
{
	if ( NULL == pNode )
		return ;
	
	getPostOrder ( pNode -> pLeft , answer ) ;
	getPostOrder ( pNode -> pRight , answer ) ;
	answer -> emplace_back ( pNode -> iIndex ) ;
}

vector < vector < int > > solution ( vector < vector < int > > nodeinfo )
{
	vector < vector < int > > answer ( 2 ) ;
	int iNodeSize = nodeinfo.size () ;
	vector < treeNode > vNode ;
	int iCurrentLevel ;
	int iParentIndex = 0 ;
	treeNode * pNode ;
	
	
	
	for ( int i = 0 ; i < iNodeSize ; ++i )				// Move int to treeNode
	{
		vNode.emplace_back ( nodeinfo [ i ] [ 0 ] , nodeinfo [ i ] [ 1 ] , i + 1 ) ;
	}
	std :: sort ( vNode.begin () , vNode.end () , bCompare ) ;
	
	iCurrentLevel = vNode [ 1 ].iLevel ;
	pNode = vNode.data () ;
	for ( int i = 1 ; i < iNodeSize ; ++i )				// Add child
	{
		if ( iCurrentLevel != pNode [ i ].iLevel )		// Different level, update
		{
			for ( int j = iParentIndex + 1 ; j < i ; ++j )
			{
				if ( iCurrentLevel == pNode [ j ].iLevel )
				{
					iCurrentLevel = pNode [ i ].iLevel ;
					
					break ;
				}
			}
		}
		
		treeNode * pParent = findRoot ( pNode + i , pNode ) ;

		if ( pNode [ i ].iX < pParent -> iX )			// Add to left
			pParent -> pLeft = pNode + i ;
		else if ( pParent -> iX < pNode [ i ].iX )		// Add to right
			pParent -> pRight = pNode + i ;
	}
	
	getPreOrder ( pNode , answer.data () ) ;
	getPostOrder ( pNode , answer.data () + 1 ) ;
	
	
	return answer ;
}