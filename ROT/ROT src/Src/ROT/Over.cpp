#include "Over.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

Over::Over(void)
{
	QVBoxLayout* layout = new QVBoxLayout();

	//QLabel* l_Label = new QLabel("Game Over", this);
	QLabel* l_EndScreen = new QLabel(this);
	l_EndScreen->setPixmap( QPixmap("./images/menu/endScreen.png"));

	QPushButton* l_QuitButton = new QPushButton("Quit Game", this);

	//layout->addWidget( l_Label );
	layout->addWidget( l_EndScreen );
	layout->addWidget( l_QuitButton );

	this->setLayout(layout);

	QWidget::connect(l_QuitButton, SIGNAL(clicked()), this, SIGNAL(done()) );
}

Over::~Over(void)
{
}
