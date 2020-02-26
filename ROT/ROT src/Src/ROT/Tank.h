#ifndef ROT_TANK_H
#define ROT_TANK_H

class GameGL;
class TankMgr;
class Bullet;

extern float TURRET_OFFSET_X;
extern float TURRET_OFFSET_Y;

class Tank
{
public:
	Tank(GameGL* a_pGameGL, TankMgr* a_ParentTankMgr);
	virtual ~Tank(void);

	void Initialize();
	void Render();

	virtual void Update();
	virtual void UpdateInput(QKeyEvent *kEvent);

	int FireBullet();
	void DeleteBullet();

	int TakeHit( float a_Dmg );

	void ClaimFrag( Tank* a_pTank);

	// Access the Posn
	const glm::vec2 &GetPosn(void) const	{ return(m_Posn);	};
	void SetPosn(const int x, const int y)		{ m_Posn = glm::vec2(x,y);	};

	std::size_t GetWidth() const { return 80; }

	// Access the Power
	float GetPower(void) const	{ return(m_Power);	};

	// Access the Rotation Angle in degrees
	float GetRotAngle(void) const		{ return(m_RotAngle);		};

		// Access the Health
	float GetHealth(void) const		{ return(m_Health);		};

	// Access the FragCount
	const std::size_t &GetFragCount(void) const		{ return(m_FragCount);		};

protected:
	GameGL* m_pGameGL;
	TankMgr* m_pParentTankMgr;

	glm::vec2 m_Posn;

	float m_Power;			// power between 0 & 100; with which the bullet is to be fired
	float m_RotAngle;		// in degrees

	float m_Health;
	std::size_t m_FragCount;

	Bullet* m_pBullet;

	GLuint m_TexID;
};

class PlayerTank : public Tank
{
public:
	PlayerTank(GameGL* a_pGameGL, TankMgr* a_ParentTankMgr);
	~PlayerTank(void);

	virtual void UpdateInput(QKeyEvent *kEvent);
	virtual void Update();

protected:
	bool m_Fired;
};

class AITank : public Tank
{
	enum TankState {
		NotFired = 0,
		Firing = 1,
		Fired =2};
public:
	AITank(GameGL* a_pGameGL, TankMgr* a_ParentTankMgr);
	~AITank(void);

	virtual void Update();

protected:
	int Think();
protected:
	TankState m_TankState;
	QTimer m_Timer;

	float m_TgtRotAngle;

};
#endif