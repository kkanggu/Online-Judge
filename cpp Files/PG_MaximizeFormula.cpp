#include <string>
#include <vector>
#include <algorithm>

using std :: string ;
using std :: vector ;

long long llCalc ( long long llTemp1 , long long llTemp2 , char cOperator )
{
	if ( '+' == cOperator )
		return llTemp1 + llTemp2 ;
	if ( '-' == cOperator )
		return llTemp1 - llTemp2 ;
	return llTemp1 * llTemp2 ;
}

long long llGetFormulaResult ( char cpOperator [] , vector < long long > vNum , vector < char > vOperator )
{
	long long llAnswer = 0 ;
	int iSize = vNum.size () ;



	for ( int i = 0 ; ( i < 3 ) && ( 1 < iSize ) ; ++i )
	{
		for ( int j = 0 ; j < iSize - 1 ; ++j )
		{
			if ( vOperator [ j ] == cpOperator [ i ] )
			{
				vNum [ j + 1 ] = llCalc ( vNum [ j ] , vNum [ j + 1 ] , vOperator [ j ] ) ;
				vNum.erase ( vNum.begin () + j ) ;
				vOperator.erase ( vOperator.begin () + j ) ;
				-- iSize ;
				--j ;
			}
		}
	}

	llAnswer = vNum [ 0 ] ;

	return ( llAnswer >= 0 ) ? llAnswer : llAnswer * -1 ;
}

long long solution ( string expression )
{
	long long answer = 0 ;
	vector < long long > vNum ;
	vector < char > vOperator ;
	int iLen = expression.size () ;
	int iIndex = 0 ;
	char cdrgOperator [ 6 ] [ 3 ] = { { '+' , '-' , '*' } ,
									  { '+' , '*' , '-' } ,
									  { '-' , '+' , '*' } ,
									  { '-' , '*' , '+' } ,
									  { '*' , '+' , '-' } ,
									  { '*' , '-' , '+' } } ;


	
	for ( int i = 1 ; i < iLen ; ++i )
	{
		if ( ( '+' == expression [ i ] ) || ( '-' == expression [ i ] ) || ( '*' == expression [ i ] ) )
		{
			vNum.emplace_back ( std :: stoll ( expression.substr ( iIndex , i - iIndex ) ) ) ;
			vOperator.emplace_back ( expression [ i ] ) ;
			iIndex = i + 1 ;
		}
	}
	vNum.emplace_back ( std :: stoll ( expression.substr ( iIndex , iLen - iIndex) ) ) ;


	for ( int i = 0 ; i < 6 ; ++i )
	{
		answer = std :: max ( answer , llGetFormulaResult ( cdrgOperator [ i ] , vNum , vOperator ) ) ;
	}

	
	return answer ;
}

int main ()
{
	long long ans = solution ( "100-200*300-500+20" ) ;
}