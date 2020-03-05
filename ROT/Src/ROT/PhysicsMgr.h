#ifndef ROT_PHYSICSMGR_H
#define ROT_PHYSICSMGR_H

class Bullet;
class Terrain;
class TankMgr;

class PhysicsMgr
{
public:
	~PhysicsMgr(void);

	void RegisterTerrain(Terrain* a_pTerrain);
	void RegisterTankMgr(TankMgr* a_pTankMgr);

	friend PhysicsMgr& PhysicsMgrInstance();

	int CanBulletMove(Bullet& a_Bullet, glm::vec2& a_Vel);

	void ExplodeBullet(Bullet* a_pBullet);
private:
	PhysicsMgr(void);
	PhysicsMgr( const PhysicsMgr& rhs);

	Terrain* m_pTerrain;
	TankMgr* m_pTankMgr;
};

#endif