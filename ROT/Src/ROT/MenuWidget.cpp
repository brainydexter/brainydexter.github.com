#include "MenuWidget.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MenuWidget::MenuWidget(QWidget* parent)
{
	QVBoxLayout* layout = new QVBoxLayout();
	this->setLayout(layout);

	m_pLabel = new QLabel("Game Menu", this);
	m_pResume_Play_Button = new QPushButton("Resume Game", this);
	m_pPlay_Button = new QPushButton("New Game", this);
	m_pOptions_Button = new QPushButton("Game Options", this);
	m_pHelp_Button = new QPushButton("Help", this);
	m_pQuit_Button = new QPushButton("Quit Game", this);

	layout->addWidget( m_pLabel );
	layout->addWidget( m_pPlay_Button);
	layout->addWidget( m_pOptions_Button);
	layout->addWidget( m_pHelp_Button);
	layout->addWidget( m_pQuit_Button );

	m_pResume_Play_Button->hide();

	m_pLabel->setStyleSheet("background: url(./images/menu/screen.png)");
}

MenuWidget::~MenuWidget(void)
{
}
