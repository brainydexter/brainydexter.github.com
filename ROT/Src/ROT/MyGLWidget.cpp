#include "MyGLWidget.h"

MyGLWidget::MyGLWidget(void)
{
	makeCurrent();
	m_ID = bindTexture(	QPixmap(QString("./images/carriage.png")),	GL_TEXTURE_2D);
}

MyGLWidget::~MyGLWidget(void)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the gl. </summary>
///
/// <remarks>	Priyank, 2/4/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void MyGLWidget::initializeGL(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//.50f, 1.0f );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Paint gl. </summary>
///
/// <remarks>	Priyank, 2/4/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void MyGLWidget::paintGL(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glTranslatef(0,0, -1.0f);
	//drawTexture(QPointF(), m_ID);
		// render tank
	glBindTexture(GL_TEXTURE_2D, m_ID);

	glPushMatrix();
		glTranslatef(0,0, -1.0f);
	//glTranslatef( -5, 0, 0 );
		//drawing tank
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);	glVertex2f(0.0, 0.0);
			glTexCoord2f(1.0, 0.0);	glVertex2f(80.0, 0.0);
			glTexCoord2f(1.0, 1.0);	glVertex2f(80.0, 32.0);
			glTexCoord2f(0.0, 1.0);	glVertex2f(0.0, 32.0);
		glEnd();
glDisable(GL_TEXTURE_2D);

	//glPopMatrix();

	glPushMatrix();

		// translating along the z axis a bit to make it look 2D
		//glTranslatef(0,0, -750.0f);
		glTranslatef(0,0, -1.0f);

		glPushMatrix();
				glColor3f(1.0f,0,0);

				//glTranslatef(0,0, -10.0f);
				glBegin(GL_LINES);			
					glVertex3f(0,0,0); glVertex3f(50, 0, 0);
					glVertex3f(0,0,0); glVertex3f(0, 0, 50);
					glVertex3f(0,0,0); glVertex3f(0, 50, 0);
				glEnd();

				glColor3f(1.0f, 1.0f, 1.0f);
		glPopMatrix();

	glPopMatrix();

	//renderText(500,100, "Hello world");


}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Resize gl. </summary>
///
/// <remarks>	Priyank, 2/4/2010. </remarks>
///
/// <param name="w">	The width. </param>
/// <param name="h">	The height. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void MyGLWidget::resizeGL(int w, int h)
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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates a gl. </summary>
///
/// <remarks>	Priyank, 2/4/2010. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void MyGLWidget::updateGL(void)
{
	
}

