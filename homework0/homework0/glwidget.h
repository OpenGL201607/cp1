#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtWidgets/QWidget>
#include "ui_glwidget.h"
#include <QtGui>
#include <QtCore>
#include <QtOpenGL>
class GLWidget : public QGLWidget
{
	Q_OBJECT

public:
	GLWidget(QGLWidget *parent = 0);
	~GLWidget();
	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);

private:
	Ui::GLWidgetClass ui;
};

#endif // GLWIDGET_H
