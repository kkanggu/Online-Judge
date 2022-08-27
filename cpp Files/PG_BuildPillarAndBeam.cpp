#include <vector>

using std :: vector ;

bool bIsBuildingPossible ( int iX , int iY , int iFrame , vector < vector < int > > & vFrame )
{
	int iSize = vFrame.size () ;



	if ( 1 == iFrame )			// Pillar
	{
		if ( ( 0 == iY ) || ( 1 == ( vFrame [ iX ] [ iY - 1 ] & 1 ) ) )		// Bottom or below pillar exist
			return true ;
		if ( 2 == ( vFrame [ iX ] [ iY ] & 2 ) )							// Pillar at left of beam
			return true ;
		if ( ( 0 != iX ) && ( 2 == ( vFrame [ iX - 1 ] [ iY ] & 2 ) ) )		// Pillar at right of beam
			return true ;
	}
	else if ( 2 == iFrame )		// Beam
	{
		if ( 0 == iY )										// Bottom
			return true ;
		if ( 1 == ( vFrame [ iX ] [ iY - 1 ] & 1 ) )		// left below pillar exist
			return true ;
		if ( 1 == ( vFrame [ iX + 1 ] [ iY - 1 ] & 1 ) )	// Right below pillar exist
			return true ;
		if ( ( 0 != iX ) && ( iX + 2 < iSize ) && ( 2 == ( vFrame [ iX - 1 ] [ iY ] & 2 ) ) && ( 2 == ( vFrame [ iX + 1 ] [ iY ] & 2 ) ) )	// both side beam exist
			return true ;
	}


	return false ;
}

bool bIsBreakingPossible ( int iX , int iY , int iFrame , vector < vector < int > > & vFrame )
{
	int iSize = vFrame.size () ;


	
	vFrame [ iX ] [ iY ] &= ~ iFrame ;

	if ( 1 == iFrame )
	{
		if ( ( iY + 2 < iSize ) && ( 1 == ( vFrame [ iX ] [ iY + 1 ] & 1 ) ) && ! bIsBuildingPossible ( iX , iY + 1 , 1 , vFrame ) )		// Upper pillar exist, can't place
			return false ;
		if ( ( 0 != iX ) && ( 2 == ( vFrame [ iX - 1 ] [ iY + 1 ] & 2 ) ) && ! bIsBuildingPossible ( iX - 1 , iY + 1 , 2 , vFrame ) )		// Left upper beam exist, can't place
			return false ;
		if ( ( iFrame + 1 < iSize ) && ( 2 == ( vFrame [ iX ] [ iY + 1 ] & 2 ) ) && ! bIsBuildingPossible ( iX , iY + 1 , 2 , vFrame ) )	// Right upper beam exist, can't place
			return false ;
	}
	else if ( 2 == iFrame )
	{
		if ( ( iY + 1 < iSize ) && ( 1 == ( vFrame [ iX ] [ iY ] & 1 ) ) && ! bIsBuildingPossible ( iX , iY , 1 , vFrame ) )			// Left upper pillar exist, can't place
			return false ;
		if ( ( iY + 1 < iSize ) && ( 1 == ( vFrame [ iX + 1 ] [ iY ] & 1 ) ) && ! bIsBuildingPossible ( iX + 1 , iY , 1 , vFrame ) )	// Right upper pillar exist, can't place
			return false ;
		if ( ( 0 != iX ) && ( 2 == ( vFrame [ iX - 1 ] [ iY ] & 2 ) ) && ! bIsBuildingPossible ( iX - 1 , iY , 2 , vFrame ) )			// Left beam exist, can't place
			return false ;
		if ( ( iX + 2 < iSize ) && ( 2 == ( vFrame [ iX + 1 ] [ iY ] & 2 ) ) && ! bIsBuildingPossible ( iX + 1 , iY , 2 , vFrame ) )	// Right beam exist, can't place
			return false ;
	}


	return true ;
}

vector < vector < int > > solution ( int n , vector < vector < int > > build_frame )
{
	vector < vector < int > > answer ;
	vector < vector < int > > vFrame ( n + 1 , vector < int > ( n + 1 , 0 ) ) ;		// 0 Nothing, 1 Pillar, 2 Beam
	int iBuildSize = build_frame.size () ;
	
	

	for ( int i = 0 ; i < iBuildSize ; ++i )
	{
		int iX = build_frame [ i ] [ 0 ] ;
		int iY = build_frame [ i ] [ 1 ] ;
		int iFrame = build_frame [ i ] [ 2 ] + 1 ;
		bool bBuild = 1 == build_frame [ i ] [ 3 ] ;


		if ( bBuild && bIsBuildingPossible ( iX , iY , iFrame , vFrame ) )
		{
			vFrame [ iX ] [ iY ] |= iFrame ;
		}
		else if ( ! bBuild )
		{
			if ( ! bIsBreakingPossible ( iX , iY , iFrame , vFrame ) )	// If can break, already broke at bIsBreakingPossible
				vFrame [ iX ] [ iY ] |= iFrame ;						// If cannot, rebuild frame
		}
	}

	for ( int i = 0 ; i < n + 1 ; ++i )
	{
		for ( int j = 0 ; j < n + 1 ; ++j )
		{
			if ( 0 != vFrame [ i ] [ j ] )
			{
				vector < int > vTemp ( 3 ) ;

				vTemp [ 0 ] = i ;
				vTemp [ 1 ] = j ;

				if ( 1 == ( vFrame [ i ] [ j ] & 1 ) )
				{
					vTemp [ 2 ] = 0 ;
					answer.emplace_back ( vTemp ) ;
				}
				if ( 2 == ( vFrame [ i ] [ j ] & 2 ) )
				{
					vTemp [ 2 ] = 1 ;
					answer.emplace_back ( vTemp ) ;
				}
			}
		}
	}
	
	
	return answer ;
}