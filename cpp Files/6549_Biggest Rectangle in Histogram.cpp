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
	Rect rectTop ;
	Rect rectTemp ;



	rectTop.iHeight = -1 ;

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


			if ( rectTop.iHeight < iHeight )					// Ascending, just push
			{
				rectTop.iIndex = i ;
				rectTop.iHeight = iHeight ;

				sRect.push ( rectTop ) ;
			}
			else if ( rectTop.iHeight > iHeight )				// Descending, 4 5 3 -> 4 3 3 -> 3 3 3.
			{
				while ( rectTop.iHeight > iHeight )
				{
					llTemp = ( long long ) rectTop.iHeight * ( i - rectTop.iIndex ) ;

					if ( llArea < llTemp )
					{
						llArea = llTemp ;
					}

					sRect.pop () ;

					rectTemp.iIndex = rectTop.iIndex ;
					rectTemp.iHeight = iHeight ;

					if ( ! sRect.empty () )
					{
						rectTop = sRect.top () ;
					}
					else
					{
						rectTop.iHeight = -1 ;
					}
				}

				rectTop = rectTemp ;

				sRect.push ( rectTop ) ;
			}
		}
		while ( ! sRect.empty () )								// Calculate remaining ascending rectangles
		{
			rectTop = sRect.top () ;

			llTemp = ( long long ) rectTop.iHeight * ( iN - rectTop.iIndex ) ;

			if ( llArea < llTemp )
			{
				llArea = llTemp ;
			}

			sRect.pop () ;

			if ( ! sRect.empty () )
			{
				rectTop = sRect.top () ;
			}
			else
			{
				rectTop.iHeight = -1 ;
			}
		}
		

		printf ( "%lld\n" , llArea ) ;
	}

	return 0 ;
}