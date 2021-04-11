#include <iostream>
#pragma warning(disable:4996)

using std :: cin ;
using std :: cout ;

int iTripleMaxValue ( int & i1 , int & i2 , int & i3 ) ;

int main ()
{
	int iNum = 0 ;
	int iInput = 0 ;
	int irgWineMax [ 2 ] [ 3 ] = { 0 , } ;						// It means I taste 0, 1, 2 wines in a row recently.
	int iMax = 0 ;



	cin >> iNum ;


	for ( int i = 0 ; i < iNum ; ++i )							// Calculate max wine
	{
		cin	>> iInput ;

		for ( int j = 0 ; j < 3 ; ++j )
		{
			irgWineMax [ 0 ] [ j ] = irgWineMax [ 1 ] [ j ] ;
		}

		irgWineMax [ 1 ] [ 0 ] = iTripleMaxValue ( irgWineMax [ 0 ] [ 0 ] , irgWineMax [ 0 ] [ 1 ] , irgWineMax [ 0 ] [ 2 ] ) ;
		irgWineMax [ 1 ] [ 1 ] = irgWineMax [ 0 ] [ 0 ] + iInput ;
		irgWineMax [ 1 ] [ 2 ] = irgWineMax [ 0 ] [ 1 ] + iInput ;
	}


	iMax = iTripleMaxValue ( irgWineMax [ 1 ] [ 0 ] , irgWineMax [ 1 ] [ 1 ] , irgWineMax [ 1 ] [ 2 ] ) ;

	cout << iMax ;


	return 0 ;
}

int iTripleMaxValue ( int & i1 , int & i2 , int & i3 )
{
	if ( ( i1 >= i2 ) && ( i1 >= i3 ) )
		return i1 ;
	else if ( ( i1 <= i3 ) && ( i2 <= i3 ) )
		return i3 ;
	else
		return i2 ;
}