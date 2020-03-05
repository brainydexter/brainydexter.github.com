#pragma once

#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
public:
	MyGLWidget(void);
	~MyGLWidget(void);

	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

	void updateGL();

private:
	int m_ID;
};
