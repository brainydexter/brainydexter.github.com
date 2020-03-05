#include "Intro.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include <QStateMachine>
#include <QFinalState>
#include <QTimer>

#include <QFile>
Intro::Intro(void)
{
	// setting up widget and layout
	QVBoxLayout* layout = new QVBoxLayout();

	m_pLabel = new QLabel(this);
	layout->addWidget( m_pLabel );

	this->setLayout(layout);

	// QTimer
	m_pTimer = new QTimer(this);
	connect(m_pTimer, SIGNAL(timeout()), m_pTimer, SLOT(start()) );

	// setting up state machine
	// states
	QStateMachine* machine = new QStateMachine(this);
	QState* intro_logo = new QState();
	QState* intro_rating = new QState();
	QState* intro_screen = new QState();
	QFinalState* intro_done = new QFinalState();

	// adding to machine
	machine->addState( intro_logo );
	machine->addState( intro_rating );
	machine->addState( intro_screen );
	machine->addState( intro_done );

	machine->setInitialState(intro_logo);

	// transitions
	intro_logo->addTransition(m_pTimer, SIGNAL(timeout() ), intro_rating );
	intro_rating->addTransition(m_pTimer, SIGNAL(timeout() ), intro_screen );
	intro_screen->addTransition(m_pTimer, SIGNAL(timeout() ), intro_done );

	// state-properties
	intro_logo->assignProperty(m_pLabel, "pixmap", QPixmap("./images/menu/logo.png") );
	intro_rating->assignProperty(m_pLabel, "pixmap", QPixmap("./images/menu/rating.png"));
	intro_screen->assignProperty(m_pLabel, "pixmap", QPixmap("./images/menu/screen.png"));

	connect( machine, SIGNAL( finished() ), this, SIGNAL(done() ) );
	machine->start();

	m_pTimer->start(3500);
	
}

Intro::~Intro(void)
{
}
