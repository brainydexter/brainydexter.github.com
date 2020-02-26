#include <Qt>
#include <QApplication>
#include <QPushButton>
#include <QLabel>


#include <QVBoxLayout>
//#include <QStateMachine>
//#include <QFinalState>
#include "StateMgr.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QVBoxLayout* layout = new QVBoxLayout();

	layout->addWidget(new StateMgr);

	QWidget window;
	window.setLayout( layout );
	window.resize(800, 600);

	window.show();
	window.setWindowIcon( QIcon(QPixmap("icon.png") ) );

	return app.exec();
}