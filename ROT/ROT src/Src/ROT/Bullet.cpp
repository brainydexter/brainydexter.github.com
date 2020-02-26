#include "StdAfx.h"
#include "Bullet.h"

#include "Tank.h"

#include "PhysicsMgr.h"

extern float G;		//gravity acceleration constant

Bullet::Bullet(Tank* a_pTankParent) : m_Tick(0), m_Vel(0), m_Damage(20.0f)
{
	m_pTankParent = a_pTankParent;
}

Bullet::~Bullet(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Fires the bullet from position along the angle by the given power</summary>
///
/// <remarks>	Priyank, 12/23/2009. </remarks>
///
/// <param name="a_Posn">		a posn. </param>
/// <param name="a_Power">		a power. </param>
/// <param name="a_RotAngle">	a rot angle (in degrees). </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Bullet::Fire(const glm::vec2&a_Posn, float a_Power, float a_RotAngle)
{
	m_Tick = 1.0f;

	m_Posn = a_Posn;

	m_Posn.y += 1.0;

	float l_radAngle = 0.01745329f * a_RotAngle;
	m_LaunchingVel.x = cos(l_radAngle);
	m_LaunchingVel.y = sin(l_radAngle);

	m_LaunchingVel = m_LaunchingVel * a_Power;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the bullet. </summary>
///
///				Works like a FSM controlled by the time
///
/// <remarks>	Priyank, 12/23/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Bullet::Update(void)
{
	if( m_Tick == 0)
		return;

	// if control reaches here, bullet has been fired and tick = 1.0; => see Fire()
	m_Vel.x = m_LaunchingVel.x * m_Tick;											//		x = vx * t
	m_Vel.y = (m_LaunchingVel.y * m_Tick) - ( 0.5f * G * m_Tick * m_Tick);			//		y = vy * t - (g*t*t)/2 where v is the original launching velocity

	int canMove = PhysicsMgrInstance().CanBulletMove( *this, glm::core::function::geometric::normalize(m_Vel) );

	if(canMove != 1) {
		//std::cout << "Bullet collided\n";

		// collision explosion here!
		//PhysicsMgrInstance().ExplodeBullet(this);
		m_pTankParent->DeleteBullet();

		return;
	}
	m_Posn = m_Posn + glm::core::function::geometric::normalize(m_Vel);
	m_Tick++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Renders the bullet. </summary>
///
/// <remarks>	Priyank, 12/23/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Bullet::Render(void)
{
	glPushMatrix();
	glColor3f(0.0f,1.0f,0);

		glTranslatef(m_Posn.x, m_Posn.y, 0);
		glBegin(GL_LINES);			
			glVertex3f(0,0,0); glVertex3f(10.2f, 0, 0);

		glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glPopMatrix();
}

