#include <iostream>
#include <stack>
#pragma warning(disable:4996)

using std :: stack ;

typedef struct Rect
{
	int iIndex ;
	int iHeight ;
} Rect ;

int main ()
{
	int iN = 1 ;
	int iHeight = 0 ;
	long long llTemp = 0 ;
	long long llArea = -1 ;
	stack < Rect > sRect ;
	Rect rectTemp ;



	rectTemp.iHeight = -1 ;

	while ( 0 != iN )
	{
		scanf ( "%d" , & iN ) ;


		if ( 0 == iN )
		{
			break ;
		}

		llArea = -1 ;


		for ( int i = 0 ; i < iN ; ++i )
		{
			scanf ( "%d" , & iHeight ) ;

			while ( rectTemp.iHeight > iHeight )
			{
				llTemp = rectTemp.iHeight * ( i - rectTemp.iIndex ) ;

				if ( llArea < llTemp )
				{
					llArea = llTemp ;
				}

				sRect.pop () ;

				if ( ! sRect.empty () )
				{
					rectTemp = sRect.top () ;
				}
				else
				{
					rectTemp.iHeight = -1 ;
				}
			}

			rectTemp.iIndex = i ;
			rectTemp.iHeight = iHeight ;

			sRect.push ( rectTemp ) ;
		}
		while ( ! sRect.empty () )
		{
			rectTemp = sRect.top () ;

			llTemp = rectTemp.iHeight * ( iN - rectTemp.iIndex ) ;

			if ( llArea < llTemp )
			{
				llArea = llTemp ;
			}

			sRect.pop () ;

			if ( ! sRect.empty () )
			{
				rectTemp = sRect.top () ;
			}
			else
			{
				rectTemp.iHeight = -1 ;
			}
		}
		

		printf ( "%lld\n" , llArea ) ;
	}

	return 0 ;
}