#pragma once

#include "GameStateWidget.h"

class QTimer;
class QLabel;

class Intro : public GameStateWidget
{
public:
	Intro(void);
	~Intro(void);

protected:
	QTimer* m_pTimer;
	QLabel* m_pLabel;
};
