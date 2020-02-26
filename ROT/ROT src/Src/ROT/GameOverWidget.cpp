#include "GameOverWidget.h"

#include <QTimer>
#include <QLabel>

GameOverWidget::GameOverWidget(QWidget* parent)
: QWidget(parent)
{
	m_pLabel = new QLabel(" Game Not completed yet ", this);
	
	timer = new QTimer(this);
	timer->setSingleShot(true);
	connect( timer, SIGNAL(timeout()), this, SIGNAL(done()) );

	
}

GameOverWidget::~GameOverWidget(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Game status updated. </summary>
///
/// <remarks>	Priyank, 2/5/2010. </remarks>
///
/// <param name="status">	The status. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GameOverWidget::GameStatusUpdated(int status)
{
	std::string strr = status == 1 ? " won " : " lost ";

	if( status == 1)
		m_pLabel->setPixmap( QPixmap("./images/menu/winner.png") );
	else
		m_pLabel->setPixmap( QPixmap("./images/menu/loser.png") );

	//m_pLabel->setText( QString(" Player").append(strr.c_str()) );

	timer->start(2000);

	emit active();
}

