#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std :: string ;
using std :: vector ;
using std :: unordered_map ;

int iRowLen ;
int iColumnLen ;
vector < string > * vpOrigin ;
vector < string > vCandidate ;

bool bCompare ( string & str1 , string & str2 )
{
	return str1.size () < str2.size () ;
}

void DFS ( string * strpTemp , int iColumnIndex )
{
	vector < string > vpTemp ;
	bool bCandidate = true ;
	int iReturn = 0 ;


	if ( iColumnIndex == iColumnLen )						// This is not candidate key
		return ;


	unordered_map < string , int > tempMap ;

	for ( int i = 0 ; i < iRowLen ; ++i )
	{
		vpTemp.emplace_back ( strpTemp [ i ] ) ;
		vpTemp [ i ] += vpOrigin [ i ] [ iColumnIndex ] ;

		if ( 2 == ++ tempMap [ vpTemp [ i ] ] )				// Add and check. If 2, then it's not candidate key
		{
			bCandidate = false ;
		}
	}

	vpTemp.emplace_back ( strpTemp [ iRowLen ] ) ;			// Store column list
	vpTemp [ iRowLen ] += iColumnIndex + 1 ;

	if ( bCandidate )
	{
		vCandidate.emplace_back ( vpTemp [ iRowLen ] ) ;
	}
	else
	{
		DFS ( vpTemp.data () , iColumnIndex + 1 ) ;			// Not found, keep finding
	}

	DFS ( strpTemp , iColumnIndex + 1 ) ;					// Check candidate key except current column
}

int solution ( vector < vector < string > > relation )
{
	iRowLen = relation.size () ;
	iColumnLen = relation [ 0 ].size () ;
	vpOrigin = relation.data () ;
	string str ;

	str.resize ( iRowLen ) ;


	DFS ( NULL , 0 ) ;		// DFS


	std :: sort ( vCandidate.begin () , vCandidate.end () , bCompare ) ;
	int iCnt = 0 ;

	for ( int i = 0 ; i < vCandidate.size () ; ++i )		// Eliminate overlapped candidate key
	{
		for ( int j = 0 ; j < vCandidate.size () ; ++j )
		{
			if ( i == j )
				continue ;

			iCnt = 0 ;

			for ( int k = 0 ; k < vCandidate [ i ].size () ; ++k )
			{
				if ( string :: npos != vCandidate [ j ].find ( vCandidate [ i ] [ k ] ) )
				{
					++ iCnt ;
				}
			}

			if ( iCnt == vCandidate [ i ].size () )
			{
				vCandidate.erase ( vCandidate.begin () + j ) ;
				--j ;
			}
		}
	}

	return vCandidate.size () ;
}

int main ()
{
//	vector < vector < string > > rel = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}} ;
	vector < vector < string > > rel = { {"a","1","aaa","c","ng"},
										{"a","1","bbb","e","g"},
										{"c","1","aaa","d","ng"},
										{"d","2","bbb","d","ng"}};
	int i = solution ( rel ) ;
}