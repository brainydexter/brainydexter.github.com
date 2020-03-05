#include "StdAfx.h"
#include "Menu.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QSignalMapper>
//#include <QGraphicsView>

#include "MyGLWidget.h"
#include "GameGL.h"
#include "GameOverWidget.h"
#include "MenuWidget.h"

#include "OptionsWidget.h"

Menu::Menu(void)
{
	m_pGameGL = 0;

	m_pMenuWidget = new MenuWidget();

	QStackedWidget::addWidget(m_pMenuWidget);
	
	//connect( m_pMenuWidget->GetOptions_Button(), SIGNAL(clicked()), m_pMenuWidget->GetHelp_Button(), SLOT( show() ) );

	connect(m_pMenuWidget->GetQuit_Button(), SIGNAL(clicked()), this, SIGNAL(done()) );

	// setup play button (signal mapper)
	// connect to sinalMapper => SLOT(map())
	// remove the old game glwidget
	// add the new game glwidget

	// setting up signal mapper
	m_pSignalMapper = new QSignalMapper(this);
	m_pSignalMapper->setMapping( m_pMenuWidget->GetPlay_Button(), QStackedWidget::addWidget( GameWidget() ) );
	m_pSignalMapper->setMapping( m_pMenuWidget->GetOptions_Button(), this->addWidget( GameOptionsWidget()) );
	m_pSignalMapper->setMapping( m_pMenuWidget->GetHelp_Button(), this->addWidget( GameHelpWidget()) );

	connect( m_pMenuWidget->GetPlay_Button(), SIGNAL( clicked() ), m_pSignalMapper, SLOT( map() ) ); 
	connect( m_pMenuWidget->GetOptions_Button(), SIGNAL( clicked() ), m_pSignalMapper, SLOT( map() ) ); 
	connect( m_pMenuWidget->GetHelp_Button(), SIGNAL( clicked() ), m_pSignalMapper, SLOT( map() ) );

	//connect ( m_pSignalMapper, SIGNAL(mapped(QWidget*)), this, SLOT( setCurrentWidget (QWidget*) ) );
	connect ( m_pSignalMapper, SIGNAL(mapped(int)), this, SLOT( setCurrentIndex (int) ) );

	m_pGameOverWidget = new GameOverWidget();

	QStackedWidget::addWidget( m_pGameOverWidget );

	connect( m_pGameOverWidget, SIGNAL (active()), this, SLOT( GameOverWidgt() ) );
	connect(m_pGameGL, SIGNAL(GameOver(int)), m_pGameOverWidget, SLOT( GameStatusUpdated(int) ) );
	connect( m_pGameOverWidget, SIGNAL (done()), this, SLOT( MainMenuWidget() ) );
	connect( m_pGameOverWidget, SIGNAL (done()), this, SLOT( ReInitialize_Menu() ) );

	connect( m_pOptionsWidget->GetSpinBox(), SIGNAL( valueChanged(int) ), m_pGameGL, SLOT( setNum_AI_Players(int) ) );
}

Menu::~Menu(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Game widget. </summary>
///
/// <remarks>	Priyank, 2/3/2010. </remarks>
///
/// <returns>	null if it fails, else. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

QWidget* Menu::GameWidget(void)
{
	if ( !m_pGameGL){
		m_pGameGL = new GameGL(this);
		m_pGameGL->Initialize();
	}

	return m_pGameGL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Game options widget. </summary>
///
/// <remarks>	Priyank, 2/3/2010. </remarks>
///
/// <returns>	null if it fails, else. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

QWidget* Menu::GameOptionsWidget(void)
{
	
	/*QWidget* gameOptionsWidget = new QWidget();
	QLabel* label = new QLabel("Game Options", gameOptionsWidget);

	QVBoxLayout* layout = new QVBoxLayout();
	
	gameOptionsWidget->setLayout(layout);*/
	m_pOptionsWidget = new OptionsWidget();

	return m_pOptionsWidget;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Game help widget. </summary>
///
/// <remarks>	Priyank, 2/3/2010. </remarks>
///
/// <returns>	null if it fails, else. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

QWidget* Menu::GameHelpWidget(void)
{
	QLabel* label = new QLabel ( );
	label->setPixmap( QPixmap("./images/menu/help.png") );

	return label ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Adds a widget. </summary>
///
/// <remarks>	Priyank, 2/3/2010. </remarks>
///
/// <param name="widget">	[in,out] If non-null, the widget. </param>
///
/// <returns>	The calculated widget. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int Menu::addWidget(QWidget *widget)
{
	QWidget* enclosingWidget = new QWidget();
	QVBoxLayout* layout = new QVBoxLayout();	

	QPushButton* backButton = new QPushButton("Back to Main Menu", enclosingWidget);

	layout->addWidget(widget);
	layout->addWidget(backButton);

	enclosingWidget->setLayout(layout);

	connect(backButton, SIGNAL(clicked()), this, SLOT( MainMenuWidget()) );

	return QStackedWidget::addWidget(enclosingWidget);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Main menu widget. </summary>
///
/// <remarks>	Priyank, 2/3/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MainMenuWidget(void)
{
	this->setCurrentWidget( m_pMenuWidget );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Game over widget. </summary>
///
/// <remarks>	Priyank, 2/5/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu::GameOverWidgt(void)
{
	this->setCurrentWidget( m_pGameOverWidget );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> when the game is over, menu needs to be re-initialized with a new glwidget instance. </summary>
///
/// <remarks>	Priyank, 2/11/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu::ReInitialize_Menu(void)
{
	m_pGameGL->ReInitialize();
}

