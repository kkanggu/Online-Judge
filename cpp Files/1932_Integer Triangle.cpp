#include <iostream>
#include <sstream>
#pragma warning(disable:4996)

using std :: string ;
using std :: cin ;
using std :: cout ;

int iMaxValue ( int & i1 , int & i2 ) ;

int main ()
{
	int iCnt = 0 ;
	int irgTriangleMax [ 501 ] = { 0 , } ;
	int iInput = 0 ;
	int iMax = 0 ;
	int iTemp1 = 0 ;
	int iTemp2 = 0 ;
	string strInput ;
	string strToken ;



	cin >> iCnt ;
	cin >> irgTriangleMax [ 0 ] ;									// Vertex of triangle
	iMax = irgTriangleMax [ 0 ] ;
	std :: getline ( cin , strInput ) ;								// Refresh buffer (\n)


	for ( int i = 1 ; i < iCnt - 1 ; ++i )									// Do n - 1 lines.
	{
		std :: getline ( cin , strInput ) ;
		std::stringstream stream ( strInput ) ;						// Each line


		iTemp2 = irgTriangleMax [ 0 ] ;								// Move 0 index to Temp
		std :: getline ( stream , strToken , ' ' ) ;
		irgTriangleMax [ 0 ] = std :: stoi ( strToken ) + iTemp2 ;	// 0 Index = Former 0 index + [ 0 ] input

		for ( int j = 1 ; j <= i ; ++j )
		{
			std :: getline ( stream , strToken , ' ' ) ;
			
			iInput = std :: stoi ( strToken ) ;
			iTemp1 = iTemp2 ;										// To save memory, I used 2 temp variables.
			iTemp2 = irgTriangleMax [ j ] ;							// irgTriangleMax [ j ] will be used next loop, so I have to remember the data.
			irgTriangleMax [ j ] = iMaxValue ( iTemp1 , iTemp2 ) + iInput ;
		}
	}
	if ( iCnt > 1 )															// If n > 1, then do n line with checking max value.
	{
		int i = iCnt - 1 ;


		std :: getline ( cin , strInput ) ;
		std::stringstream stream ( strInput ) ;						// Each line


		iTemp2 = irgTriangleMax [ 0 ] ;								// Move 0 index to Temp
		std :: getline ( stream , strToken , ' ' ) ;
		irgTriangleMax [ 0 ] = std :: stoi ( strToken ) + iTemp2 ;	// 0 Index = Former 0 index + [ 0 ] input
		iMax = irgTriangleMax [ 0 ] ;

		for ( int j = 1 ; j < iCnt ; ++j )
		{
			std :: getline ( stream , strToken , ' ' ) ;
			
			iInput = std :: stoi ( strToken ) ;
			iTemp1 = iTemp2 ;
			iTemp2 = irgTriangleMax [ j ] ;
			irgTriangleMax [ j ] = iMaxValue ( iTemp1 , iTemp2 ) + iInput ;

			if ( iMax < irgTriangleMax [ j ] )						// After calculate max value, check and save it to iMax variable.
				iMax = irgTriangleMax [ j ] ;
		}
	}


	cout << iMax ;


	return 0 ;
}

int iMaxValue ( int & i1 , int & i2 )
{
	if ( i1 < i2 )
		return i2 ;
	else
		return i1 ;
}