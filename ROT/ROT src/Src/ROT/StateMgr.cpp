#include "StdAfx.h"
#include "StateMgr.h"

#include <QApplication>
#include "Intro.h"
#include "Menu.h"
#include "Over.h"

StateMgr::~StateMgr(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Priyank, 2/2/2010. </remarks>
///
/// <param name="parent">	[in,out] If non-null, the parent. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

StateMgr::StateMgr(QWidget *parent)
{
	m_pIntroWidget = new Intro();
	m_pMenuWidget = new Menu();
	m_pOverWidget = new Over();

	this->addWidget( m_pIntroWidget );
	this->addWidget( m_pMenuWidget );
	this->addWidget( m_pOverWidget );

	//this->addTransition(m_pIntroWidget, SIGNAL(onExit() ), m_pMenuWidget );

	QStackedWidget::connect(m_pIntroWidget, SIGNAL(done()), this, SLOT( MenuWidgetSlot() ) );
	QStackedWidget::connect(m_pMenuWidget, SIGNAL(done()), this, SLOT( OverWidgetSlot() ) );
	QStackedWidget::connect(m_pOverWidget, SIGNAL(done()), QApplication::instance(), SLOT( quit() ) );

	this->setCurrentWidget( m_pIntroWidget );

	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Menu widget slot. </summary>
///
/// <remarks>	Priyank, 2/2/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void StateMgr::MenuWidgetSlot(void)
{
	this->setCurrentWidget( m_pMenuWidget );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Over widget slot. </summary>
///
/// <remarks>	Priyank, 2/2/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void StateMgr::OverWidgetSlot(void)
{
	this->setCurrentWidget( m_pOverWidget );
}

