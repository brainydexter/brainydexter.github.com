#ifndef ROT_TANKMGR_H
#define ROT_TANKMGR_H

class Tank;
class GameGL;
class Bullet;

#include "Observable.h"

class TankMgr : public std::list<Tank*>, public Observable
{
public:
	TankMgr(GameGL* a_pGameGL);
	~TankMgr(void);

	TankMgr(const TankMgr& a_rTankMgr);
	TankMgr& TankMgr::operator = ( TankMgr& a_rTankMgr);

	void Initialize();
	void Render();

	void Update();
	void UpdateInput(QKeyEvent *kEvent);

	void PlayNextTurn();

	void RegisterHit(Tank* a_pTank, Bullet* a_pBullet);
	void KillTank( Tank* a_pPrey, Tank* a_pHunter);
	void Retreat_Tank( Tank* a_pPrey);

	Tank* GetCurrentTank();

	bool CheckifGameisOver();
protected:
	GameGL* m_pGameGL;
	std::list<Tank*>::iterator m_ppCurrentTank;
	//TankMgr::iterator m_ppCurrentTank;
};

#endif