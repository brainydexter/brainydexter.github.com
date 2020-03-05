#include "StdAfx.h"
#include "PhysicsMgr.h"

#include "Bullet.h"
#include "TankMgr.h"
#include "Tank.h"

#include "Terrain.h"

PhysicsMgr& PhysicsMgrInstance() {
	static PhysicsMgr instance;

	return instance;
}

PhysicsMgr::PhysicsMgr(void)
{
}

PhysicsMgr::~PhysicsMgr(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Can bullet move from its current posn with the given velocity. </summary>
///
/// <remarks>	Priyank, 12/26/2009. </remarks>
///
/// <param name="a_Bullet">	[in,out] a bullet. </param>
/// <param name="a_Vel">	[in,out] a vel. </param>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int PhysicsMgr::CanBulletMove(Bullet& a_Bullet, glm::vec2&a_Vel)
{
	glm::vec2 posn = a_Bullet.GetPosn() + a_Vel;

	int hit = 1; // 1 = no hit, hit < 0 => collision!
	
	// tank - bullet interaction
	std::list<Tank*>::iterator tank_it = m_pTankMgr->begin();

	for( ; tank_it != m_pTankMgr->end(); tank_it ++) {
		Tank* l_Tank = *tank_it;

		if (l_Tank == a_Bullet.GetTankParent() )
			continue;

		glm::vec2 a_posn = l_Tank->GetPosn();
		a_posn.x += TURRET_OFFSET_X;

		if( abs( posn.x - a_posn.x ) < 40 && abs( posn.y - a_posn.y ) < 40 ) {
			//std::cout << "\n Hit! \n ";
			m_pTankMgr->RegisterHit( l_Tank, &a_Bullet );
			//return -2;
			hit = -2;
			break;
		}
	}
	
	// check for terrain collision only if the bullet did not hit the tank
	// if the destination pixel is not transparent => collision
	// also check only if bullet is within the screen
	float SH2 = ScreenHeight * 0.5;

	// if it goes below the ground
	if( posn.y < -SH2 )
	{
		hit = -1;
		return hit;
	}

	
	if ( (hit > 0) && ( posn.y < SH2 ) && qAlpha(m_pTerrain->GetForegroundColor4ScreenCoords( posn)) > 0 ) {
		m_pTerrain->AddCrater(a_Bullet.GetPosn() );
		
		//return -1;	//collided
		hit = -1;
	}

	// if bullet collided with anything, make sure all tanks are leveled on the ground
	if( hit < 0 ) {
		m_pTerrain->PlaceTanksOnGround( *m_pTankMgr );
	}
	
	return hit;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Register terrain. </summary>
///
/// <remarks>	Priyank, 12/26/2009. </remarks>
///
/// <param name="a_pTerrain">	[in,out] If non-null, a p terrain. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void PhysicsMgr::RegisterTerrain(Terrain*a_pTerrain)
{
	m_pTerrain = a_pTerrain;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Explode bullet. </summary>
///
/// <remarks>	Priyank, 12/30/2009. </remarks>
///
/// <param name="a_pBullet">	[in,out] If non-null, a p bullet. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void PhysicsMgr::ExplodeBullet(Bullet*a_pBullet)
{
	m_pTerrain->AddCrater(a_pBullet->GetPosn() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Register tank manager. </summary>
///
/// <remarks>	Priyank, 1/23/2010. </remarks>
///
/// <param name="a_pTankMgr">	[in,out] If non-null, manager for a p tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void PhysicsMgr::RegisterTankMgr(TankMgr* a_pTankMgr)
{
	m_pTankMgr = a_pTankMgr;
}

