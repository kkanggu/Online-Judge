#include <vector>

using std :: vector ;

vector < vector < int > > solution ( vector < vector < int > > arr1 , vector < vector < int > > arr2 )
{
	int iRow = arr1.size () ;
	int iMiddle = arr1 [ 0 ].size () ;
	int iColumn = arr2 [ 0 ].size () ;
	vector < vector < int > > answer ( iRow ) ;
	int iTemp = 0 ;
	vector < vector < int > > vTransposeOfArr2 ( iColumn ) ;
	
	
	
	for ( int i = 0 ; i < iMiddle ; ++i )			// Transpose
	{
		int * ipTemp = arr2 [ i ].data () ;
		
		for ( int j = 0 ; j < iColumn ; ++j )
		{
			vTransposeOfArr2 [ j ].emplace_back ( ipTemp [ j ] ) ;
		}
	}
	
	for ( int i = 0 ; i < iRow ; ++i )
	{
		int * ipArr1 = arr1 [ i ].data () ;
		
		for ( int j = 0 ; j < iColumn ; ++j )
		{
			int * ipArr2 = vTransposeOfArr2 [ j ].data () ;
			iTemp = 0 ;
			
			for ( int k = 0 ; k < iMiddle ; ++k )
			{
				iTemp += ipArr1 [ k ] * ipArr2 [ k ] ;
			}
			
			answer [ i ].emplace_back ( iTemp ) ;
		}
	}
	
	
	return answer ;
}