#include "StdAfx.h"
#include "HUD.h"

#include "GameGL.h"
#include "TankMgr.h"

#include "Tank.h"

HUD::~HUD(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
///
/// <param name="a_pGameGL">	[in,out] If non-null, a p game gl. </param>
/// <param name="a_pTankMgr">	[in,out] If non-null, manager for a p tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

HUD::HUD(GameGL*a_pGameGL, TankMgr*a_pTankMgr)
: Observer( a_pTankMgr ), m_pGameGL( a_pGameGL ), m_pTankMgr( a_pTankMgr )
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the HUD with a given Tank from TankMgr. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void HUD::Initialize(void)
{
	m_pTankInfo.UpdateInfo( m_pTankMgr->GetCurrentTank() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Renders the current selected tank from the TankMgr. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void HUD::Render(void)
{
	//const glm::vec2& a_ScreenPosn = m_pTank->GetPosn();
	glm::vec2& a_ScreenPosn = m_pTankInfo.m_TankPosn;

	int SW2 = ScreenWidth/2;
	int SH2 = ScreenHeight/2;

	glm::vec2 retPosn;

	retPosn.x = a_ScreenPosn.x + SW2;
	retPosn.y = a_ScreenPosn.y - SH2;

	retPosn.y *= -1;

	//m_pGameGL->renderText(retPosn.x + 250, retPosn.y , "Tank" );

	// Power and rotation
	m_pGameGL->renderText( 0.8 * ScreenWidth, 0.1 * ScreenHeight, QString("Power: ").append( m_pTankInfo.m_Power ) );
	m_pGameGL->renderText( 0.8 * ScreenWidth, 0.15 * ScreenHeight, QString("Rotation: " ).append( m_pTankInfo.m_Angle ) );

	// Frags & Health
	m_pGameGL->renderText( 0.2 * ScreenWidth, /*1.055 */ 0.1 * ScreenHeight, QString( "Frags: " ).append( m_pTankInfo.m_Frags ) );
	m_pGameGL->renderText( 0.4 * ScreenWidth, /*1.055*/ 0.1 * ScreenHeight, QString( "Health: " ).append( m_pTankInfo.m_Health ) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates a state. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void HUD::UpdateState(void)
{
	m_pTankInfo.UpdateInfo( m_pTankMgr->GetCurrentTank() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the information described by a_pTank. </summary>
///
/// <remarks>	Priyank, 1/28/2010. </remarks>
///
/// <param name="a_pTank">	[in,out] If non-null, a p tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void TankInfo::UpdateInfo(Tank*a_pTank) { 
	m_Name = "Tank";

	m_Power = QString::number( a_pTank->GetPower() );
	m_Angle = QString::number( a_pTank->GetRotAngle() );

	m_Health = QString::number( a_pTank->GetHealth() );
	m_Frags = QString::number( a_pTank->GetFragCount() );

	m_TankPosn = a_pTank->GetPosn();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets a tank manager. </summary>
///
/// <remarks>	Priyank, 2/11/2010. </remarks>
///
/// <param name="a_pTankMgr">	[in,out] If non-null, manager for a p tank. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void HUD::SetTankMgr(TankMgr*a_pTankMgr)
{
	m_pTankMgr = a_pTankMgr;
}

