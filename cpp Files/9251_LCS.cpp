#include <iostream>
#pragma warning(disable:4996)

#define LENGTH_MAX 1000

using std :: string ;
using std :: cin ;
using std :: cout ;

int main ()
{
//	int irgLCS [ LENGTH_MAX + 1 ] [ LENGTH_MAX + 1 ] = { 0 , } ;
	int ** idpLCS = new int * [ LENGTH_MAX + 1 ] ;
	string str1 ;
	string str2 ;
	int iMax = 0 ;



	for ( int i = 0 ; i < LENGTH_MAX + 1 ; ++i )
	{
		idpLCS [ i ] = new int [ LENGTH_MAX ] ;
	}
	for ( int i = 0 ; i < LENGTH_MAX + 1 ; ++i )
	{
		idpLCS [ i ] [ 0 ] = 0 ;
		idpLCS [ 0 ] [ i ] = 0 ;
	}

	cin >> str1 ;
	cin >> str2 ;

	for ( int i = 0 ; i < str1.size () ; ++i )
	{
		for ( int j = 0 ; j < str2.size () ; ++j )
		{
			if ( str1 [ i ] == str2 [ j ] )
			{
				idpLCS [ i + 1 ] [ j + 1 ] = idpLCS [ i ] [ j ] + 1 ;

				if ( iMax < idpLCS [ i + 1 ] [ j + 1 ] )
					iMax = idpLCS [ i + 1 ] [ j + 1 ] ;
			}
			else
			{
				if ( idpLCS [ i + 1 ] [ j ] > idpLCS [ i ] [ j + 1 ] )
					idpLCS [ i + 1 ] [ j + 1 ] = idpLCS [ i + 1 ] [ j ] ;
				else
					idpLCS [ i + 1 ] [ j + 1 ] = idpLCS [ i ] [ j + 1 ] ;
			}
		}
	}


	cout << iMax ;
	
	
	for ( int i = 0 ; i < LENGTH_MAX ; ++i )
	{
		delete [] idpLCS [ i ] ;
	}

	delete [] idpLCS ;

	return 0 ;
}