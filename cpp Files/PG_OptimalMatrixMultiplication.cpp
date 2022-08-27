#include <vector>
#include <algorithm>

using std :: vector ;

int iGetDP ( int iStart , int iEnd , vector < vector < int > > & vMatrix , vector < vector < int > > & vDP )
{
	int iMatrixSize = vMatrix.size () ;
	
	
	
	if ( iStart == iEnd )
		return 0 ;
	if ( 0 == vDP [ iStart ] [ iEnd ] )
	{
		vDP [ iStart ] [ iEnd ] = 1e9 ;
		
		for ( int i = iStart ; i < iEnd ; ++i )
		{
			int iLeft = iGetDP ( iStart , i , vMatrix , vDP ) ;
			int iRight = iGetDP ( i + 1 , iEnd , vMatrix , vDP ) ;
			int iMultiply = iLeft + iRight + vMatrix [ iStart ] [ 0 ] * vMatrix [ i ] [ 1 ] * vMatrix [ iEnd ] [ 1 ] ;


			vDP [ iStart ] [ iEnd ] = std :: min ( vDP [ iStart ] [ iEnd ] , iMultiply ) ;
		}
	}
	
	
	return vDP [ iStart ] [ iEnd ] ;
}

int solution ( vector < vector < int > > matrix_sizes )
{
	int answer = 0 ;
	int iMatrixSize = matrix_sizes.size () ;
	vector < vector < int > > vDP ( iMatrixSize - 1 , ( vector < int > ( iMatrixSize , 0 ) ) ) ;
	
	
	
	return iGetDP ( 0 , iMatrixSize - 1 , matrix_sizes , vDP ) ;
}