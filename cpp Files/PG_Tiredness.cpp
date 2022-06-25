#include <vector>
#include <algorithm>

using std :: vector ;

int iDungeonSize ;
bool brgUsed [ 8 ] ;
vector < int > * vpTemp ;

int iDFS ( int iCurrentTiredness )
{
	int iAnswer = 0 ;

	for ( int i = 0 ; i < iDungeonSize ; ++i )
	{
		if ( ( ! brgUsed [ i ] ) && ( vpTemp [ i ] [ 0 ] <= iCurrentTiredness ) )
		{
			brgUsed [ i ] = true ;
			iAnswer = std :: max ( iAnswer , iDFS ( iCurrentTiredness - vpTemp [ i ] [ 1 ] ) + 1 ) ;
			brgUsed [ i ] = false ;
		}
	}

	return iAnswer ;
}

int solution ( int k , vector < vector < int > > dungeons )
{
	int answer = -1 ;
	vpTemp = dungeons.data () ;
	iDungeonSize = dungeons.size () ;
	std :: fill ( brgUsed , brgUsed + iDungeonSize , false ) ;



	return iDFS ( k ) ;
}

int main ()
{
	vector < vector < int > > dun = {{80,20},{50,40},{30,10}} ;

	int i = solution ( 80 , dun ) ;

	return 0 ;
}