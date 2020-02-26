#ifndef ROT_BULLET_H
#define ROT_BULLET_H

class Tank;

class Bullet
{
public:
	Bullet(Tank* a_pTankParent);
	~Bullet(void);

	void Update();
	void Render();

	void Fire(const glm::vec2& a_Posn, float a_Power, float a_RotAngle);

	// Access the Posn
	const glm::vec2 &GetPosn(void) const	{ return(m_Posn);	};

	// Access the TankParent
	Tank* GetTankParent(void) const		{ return(m_pTankParent);		};

	// Access the Damage
	float GetDamage(void) const		{ return(m_Damage);		};

protected:
	Tank* m_pTankParent;	// parent to which this bullet belongs
	float m_Tick;		// m_Tick = 0 => bullet has not been fired yet

	glm::vec2 m_Posn;
	glm::vec2 m_Vel;

	glm::vec2 m_LaunchingVel;

	float m_Damage;
};

#endif