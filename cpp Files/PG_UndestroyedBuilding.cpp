#include <vector>

using std :: vector ;

int solution ( vector < vector < int > > board , vector < vector < int > > skill )
{
	int answer = 0 ;
	int iHeight = board.size () ;
	int iWidth = board [ 0 ].size () ;
	int iSkillSize = skill.size () ;
	vector < vector < int > > vDP ( iHeight , ( vector < int > ( iWidth , 0 ) ) ) ;
	
	
	
	for ( int i = 0 ; i < iSkillSize ; ++i )
	{
		int iDamage = 2 == skill [ i ] [ 0 ] ? 1 : -1 ;
		int iX1 = skill [ i ] [ 1 ] ;
		int iY1 = skill [ i ] [ 2 ] ;
		int iX2 = skill [ i ] [ 3 ] ;
		int iY2 = skill [ i ] [ 4 ] ;
		iDamage *= skill [ i ] [ 5 ] ;
		
		vDP [ iX1 ] [ iY1 ] += iDamage ;
		
		if ( iX2 + 1 < iHeight )
			vDP [ iX2 + 1 ] [ iY1 ] -= iDamage ;
		if ( iY2 + 1 < iWidth )
			vDP [ iX1 ] [ iY2 + 1 ] -= iDamage ;
		if ( ( iX2 + 1 < iHeight ) && ( iY2 + 1 < iWidth ) )
			vDP [ iX2 + 1 ] [ iY2 + 1 ] += iDamage ;
	}
	
	// Sum to right
	for ( int i = 0 ; i < iHeight ; ++i )
	{
		for ( int j = 1 ; j < iWidth ; ++j )
		{
			vDP [ i ] [ j ] += vDP [ i ] [ j - 1 ] ;
		}
	}
	// Sum to Down
	for ( int j = 0 ; j < iWidth ; ++j )
	{
		for ( int i = 1 ; i < iHeight ; ++i )
		{
			vDP [ i ] [ j ] += vDP [ i - 1 ] [ j ] ;
		}
	}
	
	// Sum to right
	for ( int i = 0 ; i < iHeight ; ++i )
	{
		for ( int j = 0 ; j < iWidth ; ++j )
		{
			if ( 0 < board [ i ] [ j ] + vDP [ i ] [ j ] )
				++ answer ;
		}
	}
	
	
	return answer ;
}