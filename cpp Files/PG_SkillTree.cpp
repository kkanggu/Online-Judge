#include <string>
#include <vector>
#include <unordered_map>

using std :: string ;
using std :: vector ;
using std :: unordered_map ;

int solution ( string skill , vector < string > skill_trees )
{
	int iAnswer = 0 ;
	int iLen = skill.length () ;
	int iTreeCount = skill_trees.size () ;
	const char * cpTemp = skill.data () ;
	unordered_map < char , int > umOrder ;



	for ( int i = 0 ; i < iLen ; ++i )
	{
		umOrder [ cpTemp [ i ] ] = i + 1 ;
	}
	for ( int i = 0 ; i < iTreeCount ; ++i )
	{
		iLen = skill_trees [ i ].size () ;
		int iMapValue = 0 ;
		cpTemp = skill_trees [ i ].data () ;

		for ( int j = 0 ; j < iLen ; ++j )
		{
			if ( 0 != umOrder [ cpTemp [ j ] ] )
			{
				if ( iMapValue + 1 == umOrder [ cpTemp [ j ] ] )
					++ iMapValue ;
				else
				{
					-- iAnswer ;

					break ;
				}
			}
		}

		++ iAnswer ;
	}


	return iAnswer ;
}

int main ()
{
	int i = solution ( "CBD" , {"BACDE", "CBADF", "AECB", "BDA"} ) ;
}