#include "glwidget.h"
#define PI 3.1415927
GLWidget::GLWidget(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
	setGeometry(200,100,680,480);
	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(-0.3, 0.3, -0.6);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.0f);
    glEnd();

    glLoadIdentity();
    glTranslatef(0.3f,0.3f,0.0f); 
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.2f, 0.2f, 0.0f); 
    glVertex3f( 0.2f, 0.2f, 0.0f); 
    glVertex3f( 0.2f, -0.2f, 0.0f); 
    glVertex3f(-0.2f, -0.2f, 0.0f); 
    glEnd(); 

    glLoadIdentity();
    glTranslatef(0.0f, -0.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    GLint circle_points = 100, i = 0;
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < circle_points; i++ )
    {
        double angle = 2*PI*i/circle_points;
        glVertex3d(0.2*cos(angle), 0.2*sin(angle), 0);
    }
    glEnd();
}

void GLWidget::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}