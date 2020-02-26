#pragma once

#include <QWidget>

class GameStateWidget : public QWidget
{
	Q_OBJECT

public:
	GameStateWidget(void);
	~GameStateWidget(void);

signals:
	void done();
};
