#ifndef QTGAMESTATES_H
#define QTGAMESTATES_H

#include <QtGui/QWidget>
#include "ui_qtgamestates.h"

class qtGameStates : public QWidget
{
	Q_OBJECT

public:
	qtGameStates(QWidget *parent = 0, Qt::WFlags flags = 0);
	~qtGameStates();

private:
	Ui::qtGameStatesClass ui;
};

#endif // QTGAMESTATES_H
