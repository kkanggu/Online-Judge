#include <string>
#include <vector>
#include <unordered_map>

using std :: vector ;
using std :: string ;
using std :: unordered_map ;

struct nodeInfo
{
	int iIncome ;
	int iParentIndex ;
} ;

void distributeIncome ( vector < nodeInfo > & vNode , int iIndex , int iAmount )
{
	if ( -1 == iIndex )
		return ;
	
	int iDistributeIncome = iAmount * 0.1 ;
	vNode [ iIndex ].iIncome += iAmount - iDistributeIncome ;
	
	if ( 0 < iDistributeIncome )
		distributeIncome ( vNode , vNode [ iIndex ].iParentIndex , iDistributeIncome ) ;
}

vector < int > solution ( vector < string > enroll , vector < string > referral , vector < string > seller , vector < int > amount )
{
	int iUserSize = enroll.size () ;
	int iSellerSize = seller.size () ;
	vector < int > answer ;
	vector < nodeInfo > vNode ;
	unordered_map < string , int > umUserIndex ;		// < user name , user index >
	
	
	
	umUserIndex [ "-" ] = -1 ;
	for ( int i = 0 ; i < iUserSize ; ++i )
	{
		umUserIndex [ enroll [ i ] ] = i ;
		int iParentIndex = umUserIndex [ referral [ i ] ] ;
				
		vNode.push_back ( { 0 , iParentIndex } ) ;
	}
	
	for ( int i = 0 ; i < iSellerSize ; ++i )
	{
		int iIndex = umUserIndex [ seller [ i ] ] ;
		vNode [ iIndex ].iIncome += amount [ i ] * 90 ;
		distributeIncome ( vNode , vNode [ iIndex ].iParentIndex , amount [ i ] * 10 ) ;
	}
	
	for ( int i = 0 ; i < iUserSize ; ++i )
	{
		answer.emplace_back ( vNode [ i ].iIncome ) ;
	}
	
	
	return answer ;
}