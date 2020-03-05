#include "StdAfx.h"
#include "TankMgr.h"

#include "Tank.h"
#include "PhysicsMgr.h"

#include "Bullet.h"
#include "GameGL.h"
#include <typeinfo>

extern std::size_t NUM_PLAYERS;
extern std::size_t NUM_HUMAN_PLAYERS;

TankMgr::TankMgr(GameGL* a_pGameGL)
{
	m_pGameGL = a_pGameGL;

	for(int i = 0; i <  NUM_HUMAN_PLAYERS; i++) {
		PlayerTank* l_pTank = new PlayerTank(m_pGameGL, this);
		this->push_back( l_pTank );

		//PhysicsMgrInstance().RegisterTank( (l_pTank) );
	}

	for(int i = 0; i <  NUM_PLAYERS; i++) {

		AITank* l_pTank = new AITank(m_pGameGL, this);
		this->push_back( l_pTank );

		//PhysicsMgrInstance().RegisterTank( (l_pTank) );
	}

	m_ppCurrentTank = this->begin();

	PhysicsMgrInstance().RegisterTankMgr(this);
}

TankMgr::~TankMgr(void)
{
	//this->clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes this object. </summary>
///
/// <remarks>	Priyank, 12/31/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankMgr::Initialize(void)
{
	TankMgr::iterator it;

	for( it = this->begin(); it != this->end(); it++) 
		(*it)->Initialize();

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Renders all the tanks in the list </summary>
///
/// <remarks>	Priyank, 12/31/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankMgr::Render(void)
{
	TankMgr::iterator it;

	for( it = this->begin(); it != this->end(); it++) 
		(*it)->Render();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the input described by kEvent. </summary>
///
/// <remarks>	Priyank, 12/31/2009. </remarks>
///
/// <param name="kEvent">	[in,out] If non-null, the event. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankMgr::UpdateInput(QKeyEvent *kEvent)
{
	Tank* l_pCurrentTank = *m_ppCurrentTank;

	l_pCurrentTank->UpdateInput( kEvent);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates this object. </summary>
///
/// <remarks>	Priyank, 12/31/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankMgr::Update(void)
{
	(*m_ppCurrentTank)->Update();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Play next turn. </summary>
///
/// <remarks>	Priyank, 1/6/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankMgr::PlayNextTurn(void)
{

	m_ppCurrentTank++;

	// trying to make a circular iterator
	if( m_ppCurrentTank == this->end() )
		this->m_ppCurrentTank = this->begin();

	StateSetChanged();
	NotifyObservers();
		
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Returns the current selected tank. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
///
/// <returns>	null if it fails, else the current tank. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

Tank* TankMgr::GetCurrentTank(void)
{
	return *m_ppCurrentTank;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Register bullet hit to this tank. </summary>
///
/// <remarks>	Priyank, 1/29/2010. </remarks>
///
/// <param name="a_pTank">		[in,out] If non-null, a p tank. </param>
/// <param name="a_pBullet">	[in,out] If non-null, a p bullet. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankMgr::RegisterHit(Tank* a_pTank, Bullet* a_pBullet)
{
	float l_HealthLeft = a_pTank->TakeHit( a_pBullet->GetDamage() );

	if( l_HealthLeft <= 0 )
		KillTank( a_pTank, a_pBullet->GetTankParent() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Kill prey tank by hunter tank. </summary>
///
/// <remarks>	Priyank, 1/29/2010. </remarks>
///
/// <param name="a_pPrey">		[in,out] If non-null, a p prey. </param>
/// <param name="a_pHunter">	[in,out] If non-null, a p hunter. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankMgr::KillTank(Tank*a_pPrey, Tank*a_pHunter)
{
	// increase frag count for hunter
	// remove prey from tank mgr
	// check to see if there is only one player left => Game over

	a_pHunter->ClaimFrag( a_pPrey );
	
	Retreat_Tank( a_pPrey );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Checkif gameis over. </summary>
///
/// <remarks>	Priyank, 2/5/2010. </remarks>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool TankMgr::CheckifGameisOver(void)
{
	bool playerWon = false;

	// if only one player is left!
	if( this->size() == 1 ) {
		//std::cout << "Game Over!";

		// check if it is the player / AI that is left
		Tank* l_pTank = *(this->begin());
		std::string name = typeid(*l_pTank).name();

		if ( name.compare("class PlayerTank") == 0 ){
			playerWon = true;
			// notify playerwon
			m_pGameGL->GameCompleted(1);

			return true;
		}
		else {
			playerWon = false;
			// notify player lost
			m_pGameGL->GameCompleted(0);

			return true;
		}
	}

	// if control reaches here, more than one player is left
	// now, if no human player exists..game should exit, saying game lost

	// finding if any human player is left
	int numHuman = 0;
	std::list< Tank* >::iterator tank_it;

	for( tank_it = this->begin(); tank_it != this->end(); tank_it ++ ) {
		Tank* l_pTank = *(this->begin());
		std::string name = typeid(*l_pTank).name();

		if ( name.compare("class PlayerTank") == 0 ){
			// human player found ! => exit and continue playing game
			numHuman++;
			return false;
		}
	}

	// control reaches here => no human player left => end game with player(s) lost
	playerWon = false;
	// notfiy player lost
	m_pGameGL->GameCompleted(0);

	return true;
}

TankMgr& TankMgr::operator =( TankMgr &a_rTankMgr) {

	if( this != &a_rTankMgr) {
		this->std::list<Tank*>::operator= (a_rTankMgr);
		m_ppCurrentTank =  a_rTankMgr.begin();
	}

	return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Retreat tank. </summary>
///
/// <remarks>	Priyank, 2/12/2010. </remarks>
///
/// <param name="a_pPrey">	[in,out] If non-null, a p prey. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankMgr::Retreat_Tank(Tank*a_pPrey)
{
	this->remove( a_pPrey );

	CheckifGameisOver();
}

