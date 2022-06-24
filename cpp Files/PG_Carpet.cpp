#include <vector>
#include <cmath>

using std :: vector ;

vector < int > solution ( int brown , int yellow )
{
	vector < int > answer ;
	int iArea = brown + yellow ;
	int iHeight = sqrt ( iArea ) ;
	int iWidth = 0 ;



	for ( ; iHeight > 0 ; -- iHeight )
	{
		iWidth = iArea / iHeight ;

		if ( ( iArea == iWidth * iHeight ) && ( yellow == ( ( iWidth - 2 ) * ( iHeight - 2 ) ) ) )
		{
			break ;
		}
	}

	answer.emplace_back ( iWidth ) ;
	answer.emplace_back ( iHeight ) ;


	return answer ;
}

int main ()
{
	vector < int > s = solution ( 10 , 2 ) ;
}