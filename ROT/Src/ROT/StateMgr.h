#pragma once
#include <QStackedWidget>

class Intro;
class Menu;
class Over;

class StateMgr : public QStackedWidget 
{
	Q_OBJECT

public:
	StateMgr( QWidget * parent = 0 );
	~StateMgr(void);

	public slots:
		void MenuWidgetSlot();
		void OverWidgetSlot();
		//void 

protected:
	Intro* m_pIntroWidget;
	Menu* m_pMenuWidget;
	Over* m_pOverWidget;
};
