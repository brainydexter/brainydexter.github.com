#pragma once

#include <QWidget>
class QLabel;

class GameOverWidget : public QWidget
{
	Q_OBJECT

public:
	GameOverWidget(QWidget* parent = 0);
	~GameOverWidget(void);

	public slots:
	void GameStatusUpdated(int status);

signals:
	void active();
	void done();

protected:
	QLabel* m_pLabel;
	QTimer* timer;

};
