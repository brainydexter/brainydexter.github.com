#pragma once
#include <QStackedWidget>
#include "GameStateWidget.h"

class QSignalMapper;
class GameGL;
class GameOverWidget;
class MenuWidget;

class OptionsWidget;

class Menu : public QStackedWidget
{
	Q_OBJECT

public:
	Menu(void);
	~Menu(void);

	int 	addWidget ( QWidget * widget );
signals:
	void done();

	public slots:
		void MainMenuWidget();
		void GameOverWidgt();
		void ReInitialize_Menu();

protected:
	QWidget* GameWidget();
	QWidget* GameOptionsWidget();
	QWidget* GameHelpWidget();

protected:
	QSignalMapper* m_pSignalMapper;
	MenuWidget* m_pMenuWidget;

	QWidget* m_pGameOverWidget;
	GameGL* m_pGameGL;
	OptionsWidget* m_pOptionsWidget;

};
