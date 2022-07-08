#include <vector>

using std :: vector ;

int * ipAnswer ;
vector < int > * vArr ;

void recursiveQuad ( int iX , int iY , int iSize )
{
	bool bSplit = false ;
	int iCheck = vArr [ iX ] [ iY ] ;
	int iHalf = iSize >> 1 ;



	if ( 1 == iSize )
	{
		++ ipAnswer [ iCheck ] ;

		return ;
	}

	for ( int i = iX ; ( i < iX + iSize ) && ! bSplit ; ++i )
	{
		for ( int j = iY ; j < iY + iSize ; ++j )
		{
			if ( iCheck != vArr [ i ] [ j ] )
			{
				bSplit = true ;

				break ;
			}
		}
	}

	if ( bSplit )
	{
		recursiveQuad ( iX , iY , iHalf ) ;
		recursiveQuad ( iX , iY + iHalf , iHalf ) ;
		recursiveQuad ( iX + iHalf , iY , iHalf ) ;
		recursiveQuad ( iX + iHalf , iY + iHalf , iHalf ) ;
	}
	else
	{
		++ ipAnswer [ iCheck ] ;
	}
}

vector < int > solution ( vector < vector < int > > arr )
{
	vector < int > answer ( 2 , 0 ) ;
	ipAnswer = answer.data () ;
	vArr = arr.data () ;



	recursiveQuad ( 0 , 0 , arr.size () ) ;


	return answer ;
}

int main ()
{
	vector < int > v = solution ( {{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}} ) ;
}