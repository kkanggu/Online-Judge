#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using std :: vector ;
using std :: string ;

bool bCompare ( int iNum1 , int iNum2 )
{
	char crgNum1 [ 5 ] = { 0 , } ;
	char crgNum2 [ 5 ] = { 0 , } ;
	char crgTemp1 [ 9 ] = { 0 , } ;
	char crgTemp2 [ 9 ] = { 0 , } ;



	sprintf ( crgNum1 , "%d" , iNum1 ) ;					// itoa not supported at Programmers
	sprintf ( crgTemp1 , "%d" , iNum1 ) ;
	sprintf ( crgNum2 , "%d" , iNum2 ) ;
	sprintf ( crgTemp2 , "%d" , iNum2 ) ;


	if ( atoi ( strcat ( crgTemp1 , crgNum2 ) ) > atoi ( strcat ( crgTemp2 , crgNum1 ) ) )			// strcat edit dest, so I made another 2 char array
		return true ;

	return false ;
}

string solution ( vector < int > numbers )
{
	string answer = "" ;
	int * ipTemp = numbers.data () ;



	std :: sort ( numbers.begin () , numbers.end () , bCompare ) ;

	if ( 0 == ipTemp [ 0 ] )												// If Biggest number is 0, then return must be "0" instead "00000...."
		return "0" ;

	for ( int i = 0 ; i < numbers.size () ; ++i )
	{
		answer += std :: to_string ( ipTemp [ i ] ) ;
	}


	return answer ;
}

int main ()
{
//	vector < int > n1 = { 6 , 10 , 2 } ;
	vector < int > n1 = { 3 , 30 , 34 , 5 , 9 } ;

	string s = solution ( n1 ) ;

	return 0 ;
}