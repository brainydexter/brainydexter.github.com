#ifndef ROT_GAMEGL_H
#define ROT_GAMEGL_H

#include "HUD.h"

#include "TankMgr.h"
#include <QGLWidget>

class Terrain;
class QGLWidget;

// This is the inherited from QGLWidget and setups the Init,render GL. It also processes Keyboard/user input
class GameGL : public QGLWidget
{
	Q_OBJECT

public:
	GameGL(QWidget* parent = 0);
	void Initialize();
	void ReInitialize();

	~GameGL(void);

signals:
	void GameOver(int status);

	public slots:
	void GameCompleted( int status );
	void setNum_AI_Players(int);

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

	void updateGL();
	void keyPressEvent(QKeyEvent* k);

	void mouseMoveEvent(QMouseEvent* evnt);

protected:
	TankMgr* m_pTankMgr;
	Terrain* m_pTerrain;

	HUD* m_pHUD;
};

#endif