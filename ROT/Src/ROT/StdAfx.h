#include <Qt>
#include <QTime>
#include <QTimer>
#include <QApplication>
#include <QPushButton>
#include <QKeyEvent>

#include <QGLWidget>

#include <glm/glm.hpp> //vec, mat
#include <glm/gtc/matrix_transform.hpp> //glm::translate, rotate, scale
#include <glm/gtx/type_ptr.hpp> //for value_ptr

#include <iostream>

extern float PI;
extern float G;		// gravity acceleration = 9.8 m/s2

extern const std::size_t ScreenWidth;
extern const std::size_t ScreenHeight;

extern std::size_t NUM_PLAYERS;
extern std::size_t NUM_HUMAN_PLAYERS;