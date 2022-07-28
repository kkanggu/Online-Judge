#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

using std :: string ;
using std :: vector ;
using std :: pair ;
using std :: make_pair ;
using std :: unordered_set ;

vector < pair < int , int > > vPathUsingInteger ;
vector < int > vDestination ;
vector < int > vVisitCheck ;
int iTicketSize ;

void getDestination ( int iStart , int iCnt )
{
		if ( iCnt == iTicketSize )
		{
				vDestination.emplace_back ( iStart ) ;
				
				return ;
		}
		
		
		int * ipTicket = vVisitCheck.data () ;
		pair < int , int > * pTicket = vPathUsingInteger.data () ;
		
		for ( int i = 0 ; i < iTicketSize ; ++i )
		{
				if ( ( 0 == * ipTicket ) && ( iStart == pTicket -> first ) )
				{
						* ipTicket = 1 ;
						getDestination ( pTicket -> second , iCnt + 1 ) ;
						* ipTicket = 0 ;
						
						if ( ! vDestination.empty () )
						{
								vDestination.emplace_back ( iStart ) ;
								
								return ;
						}
				}
				else if ( iStart < ( * pTicket ).first )						// From here, no ticket available
				{
						return ;
				}
				
				++ ipTicket ;
				++ pTicket ;
		}
}

vector < string > solution ( vector < vector < string > > tickets )
{
		vector < string > answer ;
		iTicketSize = tickets.size () ;
		vVisitCheck.resize ( iTicketSize , 0 ) ;
		
		
		for ( int i = 0 ; i < iTicketSize ; ++i )					// Convert to int
		{
				string strTicket = tickets [ i ] [ 0 ] ;
				int iStart = ( strTicket [ 0 ] - 'A' ) * 26 * 26 + ( strTicket [ 1 ] - 'A' ) * 26 + ( strTicket [ 2 ] - 'A' ) ;
				strTicket = tickets [ i ] [ 1 ] ;
				int iEnd = ( strTicket [ 0 ] - 'A' ) * 26 * 26 + ( strTicket [ 1 ] - 'A' ) * 26 + ( strTicket [ 2 ] - 'A' ) ;
				
				vPathUsingInteger.emplace_back ( make_pair ( iStart , iEnd ) ) ;
		}
		
		std :: sort ( vPathUsingInteger.begin () , vPathUsingInteger.end () , [] ( pair < int , int > & a , pair < int , int > & b )
								 {
										 if ( a.first < b.first )
												 return true ;
										 else if ( ( a.first == b.first ) && ( a.second < b.second ) )
												 return true ;
										 
										 return false ;
								 } ) ;
		
		getDestination ( ( 'I' - 'A' ) * 26 * 26 + ( 'C' - 'A' ) * 26 + ( 'N' - 'A' ) , 0 ) ;
		
		
		int iAirportSize = vDestination.size () ;
		int * ipDestination = vDestination.data () ;
		
		for ( int i = iAirportSize - 1 ; i >= 0 ; --i )				// vDestination is reverse order
		{
				string strTemp = "" ;
				
				strTemp += ipDestination [ i ] / ( 26 * 26 ) + 'A' ;
				strTemp += ipDestination [ i ] / 26 % 26 + 'A' ;
				strTemp += ipDestination [ i ] % 26 + 'A' ;
				
				answer.emplace_back ( strTemp ) ;
		}
		
		
		return answer ;
}