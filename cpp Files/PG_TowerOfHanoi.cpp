#include <vector>
#include <stack>

using std :: vector ;
using std :: stack ;

vector < vector < int > > vAnswer ;
stack < int > vStack [ 3 ] ;

void recursiveHanoi ( int iCurrent , int iCount , int iTarget , int iEmpty )
{
	if ( 1 == iCount )
	{
		int iSize = vStack [ iCurrent ].top () ;
		vStack [ iCurrent ].pop () ;
		vStack [ iTarget ].emplace ( iSize ) ;

		vAnswer.push_back ( { iCurrent + 1 , iTarget + 1 } ) ;

		return ;
	}

	recursiveHanoi ( iCurrent , iCount - 1 , iEmpty , iTarget ) ;
	recursiveHanoi ( iCurrent , 1 , iTarget , iEmpty ) ;
	recursiveHanoi ( iEmpty , iCount - 1 , iTarget , iCurrent ) ;
}

vector < vector < int > > solution ( int n )
{
	for ( int i = n ; i > 0 ; --i )
	{
		vStack [ 0 ].emplace ( i ) ;
	}


	recursiveHanoi ( 0 , n , 2 , 1 ) ;

	return vAnswer ;
}

int main ()
{
	vector < vector < int > > v = solution ( 2 ) ;
}