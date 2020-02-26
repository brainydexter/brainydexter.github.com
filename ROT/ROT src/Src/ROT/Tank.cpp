#include "StdAfx.h"

#include "GameGL.h"
#include "Tank.h"

#include "Bullet.h"
#include <typeinfo>

float TURRET_OFFSET_X = 40;
float TURRET_OFFSET_Y = 16;

Tank::Tank(GameGL* a_pGameGL, TankMgr* a_ParentTankMgr) : m_RotAngle(75), m_Power(1270.0f), m_pBullet(0), m_Health(100), m_FragCount(0)
{
	m_pGameGL = a_pGameGL;
	m_pParentTankMgr = a_ParentTankMgr;

}

Tank::~Tank(void)
{
	glDeleteTextures(1, &m_TexID);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Renders this object. </summary>
///
/// <remarks>	Test, 12/21/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Tank::Render(void)
{
	glBindTexture(GL_TEXTURE_2D, m_TexID);

	glPushMatrix();

	if(m_pBullet)
		m_pBullet->Render();

		glTranslatef(m_Posn.x, m_Posn.y, 0);
		
		glEnable(GL_TEXTURE_2D);
		//drawing tank
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);	glVertex2f(0.0, 0.0);
			glTexCoord2f(1.0, 0.0);	glVertex2f(GetWidth(), 0.0);
			glTexCoord2f(1.0, 1.0);	glVertex2f(GetWidth(), 32);
			glTexCoord2f(0.0, 1.0);	glVertex2f(0.0, 32);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		// drawing cannon
		glTranslatef( TURRET_OFFSET_X, TURRET_OFFSET_Y, 0 );
		glRotatef(m_RotAngle, 0, 0, 1.0f);
		glBegin(GL_LINES);			
			glVertex3f(0,0,0); glVertex3f(25.5f, 0, 0);

		glEnd();

	glPopMatrix();

	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the tank (texture is loaded in the memory). </summary>
///
/// <remarks>	Test, 12/22/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Tank::Initialize(void)
{
	/*QImage img = QImage( QString("./images/cannon.png"));

	QColor color = img.pixel(5,5);

	std::cout << img.hasAlphaChannel() << " " << img.format() << "\n";
	std::cout << color.red() << " " << color.green() << " " << color.blue() << " " << color.alpha() << " " << qAlpha(img.pixel(5,5) ) <<"\n" ;
	color = img.pixel(9,7);
	std::cout << color.red() << " " << color.green() << " " << color.blue() << " " << color.alpha() << " " << qAlpha(img.pixel(9,7) ) << "\n";*/

	//m_TexID = m_pGameGL->bindTexture(	QImage(QString("./images/carriage.png")),	GL_TEXTURE_2D);		// generates, makes current texture current and uploads to video memory by calling:
																									// glGenTextureID(), glBindTexture(), glTexImage2D() && sets up some environment variables
																									// http://qt.nokia.com/doc/4.6/qglcontext.html#bindTexture

	m_TexID = m_pGameGL->bindTexture(	QPixmap(QString("./images/carriage.png")),	GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the tank. </summary>
///
/// <remarks>	Test, 12/22/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Tank::Update(void)
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the tank based on the input. </summary>
///
/// <remarks>	Test, 12/22/2009. </remarks>
///
/// <param name="kEvent">	[in,out] If non-null, the event. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Tank::UpdateInput(QKeyEvent *kEvent)
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Fire bullet</summary>
///
/// <remarks>	Priyank, 12/23/2009. </remarks>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int Tank::FireBullet(void)
{
	// ensures player can only fire once especially if the player has already fired
	if( !m_pBullet) {
		m_pBullet = new Bullet(this);
		
		glm::vec2 l_FiringPosn = m_Posn;
		l_FiringPosn.x += TURRET_OFFSET_X;
		l_FiringPosn.y += TURRET_OFFSET_Y * 2;

		m_pBullet->Fire(l_FiringPosn, m_Power, m_RotAngle);
	}

	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Deletes a bullet. </summary>
///
/// <remarks>	Priyank, 12/26/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Tank::DeleteBullet(void)
{
	m_pBullet = 0;
	delete m_pBullet;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the input described by kEvent for Player Tank. </summary>
///
/// <remarks>	Priyank, 12/31/2009. </remarks>
///
/// <param name="kEvent">	[in,out] If non-null, the event. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void PlayerTank::UpdateInput(QKeyEvent *kEvent)
{
	float amt = 10.0f;

	switch(kEvent->key() ) 
	{
		// Rotating the turret
		case Qt::Key_Right:
			m_RotAngle -= amt;		//clockwise => -ve angle
			break;

		case Qt::Key_Left:
			m_RotAngle += amt;		// anti-clockwise => +ve angle
			break;

			// calibrating power exerted 
		case Qt::Key_Up:
			m_Power += amt;
			break;

		case Qt::Key_Down:
			m_Power--;
			break;

		// Moving the tank
		/*case Qt::Key_A:
			m_Posn.x -= (amt * 0.1f);
			break;

		case Qt::Key_D:
			m_Posn.x += (amt * 0.1f);
			break;*/

		// Firing a Bullet
		case Qt::Key_Space:
			m_Fired = true;
			FireBullet();
			break;

		case Qt::Key_R:
			m_pParentTankMgr->PlayNextTurn();
			m_pParentTankMgr->Retreat_Tank(this);
			break;
	}

	//clamping turret between 0 and 180 degrees
	if ( m_RotAngle < 0 )
		m_RotAngle = 0;
	else if( m_RotAngle > 180.0f )
		m_RotAngle = 180.0f;

	//clamping the power exerted to be always greater than 0
	if ( m_Power < 0 )
		m_Power = 1.0f;

	m_pParentTankMgr->StateSetChanged();
	m_pParentTankMgr->NotifyObservers();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Priyank, 12/31/2009. </remarks>
///
/// <param name="a_pGameGL">	[in,out] If non-null, a p game gl. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

PlayerTank::PlayerTank(GameGL* a_pGameGL, TankMgr* a_ParentTankMgr) 
: Tank(a_pGameGL, a_ParentTankMgr), m_Fired(false)
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Priyank, 12/31/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

PlayerTank::~PlayerTank(void)
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates this object. </summary>
///
/// <remarks>	Priyank, 1/6/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void PlayerTank::Update(void)
{
	if( m_Fired ) {
		if( !m_pBullet){
			m_Fired = false;
			m_pParentTankMgr->PlayNextTurn();
		}
		else
			m_pBullet->Update();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Priyank, 1/6/2010. </remarks>
///
/// <param name="a_pGameGL">		[in,out] If non-null, a p game gl. </param>
/// <param name="a_ParentTankMgr">	[in,out] If non-null, manager for a parent tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

AITank::AITank(GameGL*a_pGameGL, TankMgr*a_ParentTankMgr)
: Tank(a_pGameGL, a_ParentTankMgr)
{
	m_TankState = NotFired;

	m_TgtRotAngle = 3000; // arbit value signifying its not set yet
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates this object. </summary>
///
/// <remarks>	Priyank, 1/6/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void AITank::Update(void)
{
	switch(m_TankState) {
		case NotFired:
			{
				if( !m_Timer.isActive()) {
					m_Timer.start( 2500 );
					m_Timer.setSingleShot(true);
				}
				//Think();
				//FireBullet();

				m_TankState = Think() == 1 ? Firing : NotFired;
				break;
			}

		case Firing:
			{
				if( !m_pBullet)
					m_TankState = Fired;
				else
					m_pBullet->Update();

				break;
			}

		case Fired:
			{
				if( !m_Timer.isActive() ) {
					m_TankState = NotFired;
					m_pParentTankMgr->PlayNextTurn();
				}

				break;
			}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Priyank, 1/6/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

AITank::~AITank(void)
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Thinks this object. </summary>
///
/// <remarks>	Priyank, 1/6/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

int AITank::Think(void)
{
	// select a tank to hit (should be one time) => get destination position to hit
	// find the angle and velocity with which to launch
	// calibrate angle with inaccuracy

	//fireBullet gets called from update(), so dont call it here

	//Select the tank position to hit
	Tank* l_Tank = *(m_pParentTankMgr->begin() );
	glm::vec2 l_Destination = l_Tank->GetPosn();

	//std::cout << "\n" << m_Posn.y << " Target ht: " << l_Destination.y;

	// find the angle and velocity with which to launch
	// The Range and maximum height that the tanks have to clear is known. Based on this, the angle and velocity required should be calculated
	// http://hyperphysics.phy-astr.gsu.edu/Hbase/traj.html#tra13
	// http://tutor4physics.com/projectilemotion.htm
	float l_Range = ( l_Destination.x - m_Posn.x );
	float l_Height = 100.0f;//( l_Destination.y - m_Posn.y ); //100.0f; // should be found from terrain

	//m_RotAngle = atan2(l_Destination.y - m_Posn.y, l_Destination.x - m_Posn.y);
	//float diff = 0;

	if( m_TgtRotAngle == 3000 ) // tgt angle is not set yet 
	{
		m_TgtRotAngle = atan( l_Height * 4.0f/l_Range);
		m_TgtRotAngle *= 57.2957795f;		// converting to degrees 
		
		if( m_TgtRotAngle < 0 )
				m_TgtRotAngle = 180 + m_TgtRotAngle;
	}
		float diff = m_TgtRotAngle - m_RotAngle;

		if ( abs( m_TgtRotAngle - m_RotAngle) > 0.002) {
			m_RotAngle += diff * 0.5;

			return 0;
		}
		else {
			m_TgtRotAngle = 3000; // signifying that the tgt angle is not set

			m_Power = sqrt ( ( abs(l_Range) * G )/ abs( sin(2 * m_RotAngle) ) );

			m_Power *= 10;
			//m_RotAngle *= 57.2957795f;		// converting to degrees

			//if( m_RotAngle < 0 )
				//m_RotAngle = 180 + m_RotAngle;

			FireBullet();
			return 1;
		}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Increase frag count for this tank</summary>
///
/// <remarks>	Priyank, 1/29/2010. </remarks>
///
/// <param name="a_pTank">	[in,out] If non-null, a p tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Tank::ClaimFrag(Tank*a_pTank)
{
	m_FragCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take hit. </summary>
///
/// <remarks>	Priyank, 1/29/2010. </remarks>
///
/// <param name="a_Dmg">	a dmg. </param>
///
/// <returns>	Remaining Health. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int Tank::TakeHit(float a_Dmg)
{
	m_Health -= a_Dmg;
	return m_Health;
}

