#include <vector>

using std :: vector ;

int * ipTemp ;
int * ipInfo ;
int * ipAnswer ;
int iMaxGap ;

void Score ()
{
	int iGap = 0 ;

	for ( int i = 0 ; i < 11 ; ++i )
	{
		if ( 0 == ipTemp [ i ] + ipInfo [ i ] )
			continue ;

		iGap += ( ipTemp [ i ] > ipInfo [ i ] ) ? 10 - i : i - 10 ;
	}

	if ( iGap < iMaxGap )
		return ;

	if ( iMaxGap < iGap )
	{
		for ( int i = 0 ; i < 11 ; ++i )
		{
			ipAnswer [ i ] = ipTemp [ i ] ;
		}

		iMaxGap = iGap ;
	}
	else
	{
		for ( int i = 10 ; i >= 0 ; --i )
		{
			if ( ipTemp [ i ] < ipAnswer [ i ] )			// Answer is better, ignore this
				return ;
			else if ( ipTemp [ i ] > ipAnswer [ i ] )		// Current is better, update
				break ;
		}
		for ( int i = 0 ; i < 11 ; ++i )
		{
			ipAnswer [ i ] = ipTemp [ i ] ;
		}
	}
}

void DFS ( int iIndex , int iArrowLeft )
{
	if ( ( 0 == iArrowLeft ) || ( 11 == iIndex ) )
	{
		ipTemp [ 10 ] += iArrowLeft ;
		Score () ;
		ipTemp [ 10 ] = 0 ;

		return ;
	}

	if ( ipInfo [ iIndex ] + 1 <= iArrowLeft )				// Take this score
	{
		ipTemp [ iIndex ] = ipInfo [ iIndex ] + 1 ;
		
		DFS ( iIndex + 1 , iArrowLeft - ipTemp [ iIndex ] ) ;

		ipTemp [ iIndex ] = 0 ;
		ipTemp [ 10 ] = 0 ;
	}
	
	DFS ( iIndex + 1 , iArrowLeft ) ;						// Ignore this score
	ipTemp [ 10 ] = 0 ;
}

vector < int > solution ( int n , vector < int > info )
{
	vector < int > answer ( 11 , 0 ) ;
	vector < int > vTemp ( 11 , 0 ) ;
	int iSum = 0 ;



	ipTemp = vTemp.data () ;
	ipInfo = info.data () ;
	ipAnswer = answer.data () ;
	iMaxGap = 0 ;

	for ( int i = 0 ; i < 11 ; ++i )
	{
		iSum += ( 0 != ipInfo [ i ] ) ? ipInfo [ i ] : 0 ;
	}
	DFS ( 0 , n ) ;

	if ( 0 == iMaxGap )
		return { -1 } ;


	return answer ;
}

int main ()
{
	//vector < int > v = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } ;
	//vector < int > answer = solution ( 5 , v ) ;
	//vector < int > v = { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 } ;
	//vector < int > answer = solution ( 10 , v ) ;
	vector < int > v = { 0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1 } ;
	vector < int > answer = solution ( 9 , v ) ;
}