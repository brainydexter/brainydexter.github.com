#include "StdAfx.h"

#include "GameGL.h"

#include "Terrain.h"
//#include "Tank.h"


GameGL::GameGL(QWidget* parent)
: QGLWidget(parent)
{
	m_pTankMgr = new TankMgr(this);
	m_pHUD = new HUD(this, m_pTankMgr);
	makeCurrent();
	m_pTerrain = new Terrain(this);
}

GameGL::~GameGL(void)
{
	delete m_pTerrain;
}

void GameGL :: initializeGL()
{
	//if( !getGLExtensionFunctions().resolve(this->context() )){
	//	QMessageBox::critical(0, "OpenGL features missing",
	//		"Failed to resolve OpenGL functions required to run this demo.\n"
	//		"The program will now exit.");

	//	return;

	//}

	// Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);//.50f, 1.0f );
         
    // Draw everything as wire frame
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//setMouseTracking(true);
}

void GameGL :: resizeGL(int w, int h)
{
	h = h==0 ? 1 : h;

	glViewport(0,0,w,h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 1.0, 1000.0);
	//gluOrtho2D(-(w * 0.5), w * 0.5, -(h * 0.5), h * 0.5 );
	glOrtho(-(w * 0.5), w * 0.5, -(h * 0.5), h * 0.5, 1.0, 1000.0 );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GameGL :: paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

		// translating along the z axis a bit to make it look 2D
		//glTranslatef(0,0, -750.0f);
		glTranslatef(0,0, -1.0f);

		m_pTerrain->Render();
		m_pTankMgr->Render();

		//glPushMatrix();
		//		glColor3f(1.0f,0,0);

		//		//glTranslatef(0,0, -10.0f);
		//		glRotatef( -25, 0, 0, 1.0f);
		//		glBegin(GL_LINES);			
		//			glVertex3f(0,0,0); glVertex3f(40, 0, 0);
		//			glVertex3f(0,0,0); glVertex3f(0, 0, 300);
		//			glVertex3f(0,0,0); glVertex3f(0, 100, 0);
		//		glEnd();

		//		glColor3f(1.0f, 1.0f, 1.0f);
		//glPopMatrix();

	glPopMatrix();

	m_pHUD->Render();

}

void GameGL::Initialize()
{
	QTimer *timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()), this, SLOT(updateGL()));
	timer->start(1);

	m_pTankMgr->Initialize();

	m_pTerrain->Initialize();

	m_pTerrain->InitializeTanks( *m_pTankMgr);
	m_pTerrain->CreateForeground();

	m_pHUD->Initialize();
}


void GameGL :: keyPressEvent(QKeyEvent *kEvent)
{
   static float amt = 10.1f;

	switch(kEvent->key() ) 
	{
	//case Qt::Key_Question:
	//	mp_Camera->ToString() ;
	//	break;

	//case Qt::Key_Right:
	//	mp_Camera->MoveRight(amt);
	//	break;

	//case Qt::Key_Left:
	//	mp_Camera->MoveRight(-amt);
	//	break;

	//case Qt::Key_Up:
	//	mp_Camera->MoveForward(-amt);
	//	break;

	//case Qt::Key_Down:
	//	mp_Camera->MoveForward(amt);
	//	break;

	//case Qt::Key_W:
	//	mp_Camera->RotateAroundX(-amt);
	//	break;

	//case Qt::Key_S:
	//	mp_Camera->RotateAroundX(amt);
	//	break;

	//case Qt::Key_A:
	//	mp_Camera->RotateAroundY(-amt);
	//	break;

	//case Qt::Key_D:
	//	mp_Camera->RotateAroundY(amt);
	//	break;

	//case Qt::Key_Q:
	//	mp_Camera->RotateAroundZ(-amt);
	//	break;

	//case Qt::Key_E:
	//	mp_Camera->RotateAroundZ(amt);
	//	break;

	//case Qt::Key_G:
	//	mp_Camera->MoveUp(amt);
	//	break;

	//case Qt::Key_B:
	//	mp_Camera->MoveUp(-amt);
	//	break;

	case Qt::Key_Escape:
		//QApplication::quit();
		emit GameOver(0);
		break;
	//	
	//case Qt::Key_Plus:
	//       amt += 0.5f;
	//       break;

	//case Qt::Key_Minus:
	//       amt -= 0.5f;
	//       break;


	default: 
		QGLWidget::keyPressEvent(kEvent);
		break;
	}

	m_pTankMgr->UpdateInput(kEvent);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the framework </summary>
///
/// <remarks>	Test, 12/22/2009. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GameGL::updateGL(void)
{
	m_pTankMgr->Update();

	QGLWidget::updateGL();
}

void GameGL::mouseMoveEvent(QMouseEvent* evnt) {
	//QPoint pt = evnt->pos();

	//std::cout << "\n" << pt.x() << " " << pt.y();

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Game completed. </summary>
///
/// <remarks>	Priyank, 2/5/2010. </remarks>
///
/// <param name="status">	The status. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GameGL::GameCompleted(int status)
{
	emit GameOver(status);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Re initialize. </summary>
///
/// <remarks>	Priyank, 2/11/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GameGL::ReInitialize(void)
{
	delete m_pTankMgr;
	delete m_pHUD;
	delete m_pTerrain;

	m_pTankMgr = new TankMgr(this);
	m_pHUD = new HUD(this, m_pTankMgr);
	m_pTerrain = new Terrain(this);

	this->Initialize();

	/*m_TankMgr.clear();

	TankMgr l_TM (this);
	m_TankMgr = l_TM;

	Tank* l_pTank = m_TankMgr.GetCurrentTank();

	m_pHUD->SetTankMgr(&m_TankMgr);

	delete m_pTerrain;
	m_pTerrain = new Terrain(this);

	m_TankMgr.Initialize();

	m_pTerrain->Initialize();

	m_pTerrain->InitializeTanks(m_TankMgr);
	m_pTerrain->CreateForeground();

	m_pHUD->Initialize();*/
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets the number of ai players. </summary>
///
/// <remarks>	Priyank, 2/12/2010. </remarks>
///
/// <param name="">	The. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void GameGL::setNum_AI_Players(int val)
{
	NUM_PLAYERS = val;
}

