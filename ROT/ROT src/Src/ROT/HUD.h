#ifndef ROT_HUD_H
#define ROT_HUD_H

class GameGL;
class TankMgr;
class Tank;

#include "Observer.h"

#include "StdAfx.h"
struct TankInfo {
public:
	TankInfo() { }

	void UpdateInfo( Tank* a_pTank);

	QString m_Name, m_Power, m_Angle, m_Health, m_Frags;
	glm::vec2 m_TankPosn;
};


class HUD : public Observer
{
public:
	HUD(GameGL* a_pGameGL, TankMgr* a_pTankMgr);
	~HUD(void);

	void SetTankMgr( TankMgr* a_pTankMgr );
	
	void UpdateState();

	void Initialize();
	void Render();

protected:
	GameGL* m_pGameGL;
	
	TankInfo m_pTankInfo;
	TankMgr* m_pTankMgr;
};


#endif