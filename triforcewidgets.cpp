#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <cmath>
#include <QGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include "math.h"
#include <QDebug>
#include "triforcewidgets.h"
#include <QAction>
#include <QShortcut>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

triforcewidgets::triforcewidgets(QWidget *parent)
    : QGLWidget(parent){}

void triforcewidgets::initializeGL()
    {

    glClearColor (0.1568, 0.1333, 0.5607, 0.0);
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
        timer->start(20);

    glShadeModel(GL_FLAT);

    glEnable(GL_DEPTH_TEST);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    }

void triforcewidgets::resizeGL(int w, int h)
    {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt ( 0, 0, 5, 0, 0, 0, 0, 1, 0 );

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_pos[] = {x1, y1, z1, w1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightf (GL_LIGHT0, GL_SPOT_CUTOFF,50.);
    glPopMatrix();
    }

typedef struct materialStruct {
  GLfloat ambient[5];
  GLfloat diffuse[5];
  GLfloat specular[5];
  GLfloat shininess;
} materialStruct;

static materialStruct yellow =
{
    {0.12f, 0.12f, 0.012f, 0.6f},
    {0.614, 0.4, 0.04, 0.5f},
    {0.7f, 0.63f, 0.063f, 0.6f },
    76.8f
};

void triforcewidgets::playPause()
{
    if(playingscene == true) {
       timer->stop();
       playingscene = false;

    } else {
       timer->start();
       playingscene = true;

    }
}

void triforcewidgets::pyramid()
    {
        materialStruct* p_front = &yellow;

        glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
        glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);

        glRotated(0,2,0,0);
        glBegin(GL_POLYGON);

        // Center point of the triangles
        glVertex3f(0, 1, 0);

        // Base of each triangle
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glNormal3f(1,0,0);

        glColor3f(1.0,1.0,0.0);
        glVertex3f(-0.5, 0,  0.5);
        glVertex3f( 0.5, 0,  0.5);

        glNormal3f(1,1,0);

        glColor3f(0.0,0.0,1.0);
        glVertex3f( 0.5, 0, 0.5);
        glVertex3f( 0.5, 0, -0.5);

        glNormal3f(0,1,1);

        glColor3f(0.0,1.0,1.0);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);

        glEnd();
    }

void triforcewidgets::pyramid2()
    {
        materialStruct* p_front = &yellow;

        glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

        glRotated(0,2,0,0);
        glBegin(GL_POLYGON);

        // Center point of the triangles
        glVertex3f(-0.5, 0, 0.5);

        // Base of each triangle
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, 0);

        glNormal3f(1,0,0);

        glColor3f(1.0,1.0,0.0);
        glVertex3f(-1,-1, 1);
        glVertex3f(0,-1, 1);

        glNormal3f(1,1,0);

        glColor3f(0.0,0.0,1.0);
        glVertex3f(0,-1, 1);
        glVertex3f(0,-1, 0);

        glNormal3f(0,1,1);

        glColor3f(0.0,1.0,1.0);
        glVertex3f(0, -1, 0);
        glVertex3f(-1, -1, 0);

        glEnd();
    }
void triforcewidgets::pyramid3()
    {
        materialStruct* p_front = &yellow;

        glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

        glRotated(0,2,0,0);
        glBegin(GL_POLYGON);

        // Center point of the triangles
        glVertex3f(-0.5, 0, -0.5);

        // Base of each triangle
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, -1, 0);

        glNormal3f(1,0,0);

        glColor3f(1.0,1.0,0.0);
        glVertex3f(-1,-1, 0);
        glVertex3f(0,-1, 0);

        glNormal3f(1,1,0);

        glColor3f(0.0,0.0,1.0);
        glVertex3f(0,-1, 0);
        glVertex3f(0,-1, -1);

        glNormal3f(0,1,1);

        glColor3f(0.0,1.0,1.0);
        glVertex3f(0, -1, -1);
        glVertex3f(-1, -1, -1);

        glEnd();
    }

void triforcewidgets::pyramid4()
    {
        materialStruct* p_front = &yellow;

        glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

        glRotated(0,2,0,0);
        glBegin(GL_POLYGON);

        // Center point of the triangles
        glVertex3f(0.5, 0, 0.5);

        // Base of each triangle
        glColor3f(1.0,0.0,0.0);
        glVertex3f(0, -1, 0);
        glVertex3f(0, -1, 1);

        glNormal3f(1,0,0);

        glColor3f(1.0,1.0,0.0);
        glVertex3f(0,-1, 1);
        glVertex3f(1,-1, 1);

        glNormal3f(1,1,0);

        glColor3f(0.0,0.0,1.0);
        glVertex3f(1,-1, 1);
        glVertex3f(1,-1, 0);

        glNormal3f(0,1,1);

        glColor3f(0.0,1.0,1.0);
        glVertex3f(1, -1, 0);
        glVertex3f(0, -1, 0);

        glEnd();
    }
void triforcewidgets::pyramid5()
    {
        materialStruct* p_front = &yellow;

        glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
        glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

        glRotated(0,2,0,0);
        glBegin(GL_POLYGON);

        // Center point of the triangles
        glVertex3f(0.5, 0, -0.5);

        // Base of each triangle
        glColor3f(1.0,0.0,0.0);
        glVertex3f(0, -1, -1);
        glVertex3f(0, -1, 0);

        glNormal3f(1,0,0);

        glColor3f(1.0,1.0,0.0);
        glVertex3f(0,-1, 0);
        glVertex3f(1,-1, 0);

        glNormal3f(1,1,0);

        glColor3f(0.0,0.0,1.0);
        glVertex3f(1,-1, 0);
        glVertex3f(1,-1, -1);

        glNormal3f(0,1,1);

        glColor3f(0.0,1.0,1.0);
        glVertex3f(1, -1, -1);
        glVertex3f(0, -1, -1);

        glEnd();
    }

void triforcewidgets::paintGL()
    {

//    // CUBE (START)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glEnable( GL_CULL_FACE );
    glCullFace ( GL_BACK );

    glPushMatrix();

//Lighting

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_pos[] = {x1, y1, z1, w1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 90.);
    glPopMatrix();

    this->pyramid();
    this->pyramid2();
    this->pyramid3();
    this->pyramid4();
    this->pyramid5();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
        gluLookAt ( -2, 0, -3, 0, 0, 0, 0, 20, 0 );
          glRotatef(rotVal_, rx1, ry1, rz1);

          // update rotation
          rotVal_ += 1.f;

    // flush screen
    glFlush();

    glDisable(GL_TEXTURE_2D);

    }

//Mouse Click (Interaction)
void triforcewidgets::mousePressEvent(QMouseEvent *event)
{
    playPause();
    event->accept();
}
void triforcewidgets::mouseDoubleClickEvent(QMouseEvent *event)
{
    playPause();
    event->accept();
}


//Rotation
void triforcewidgets::l_xax(int x)
{
    if(x != rx1)
    {
        rx1 = x;
        updateGL();
    }
}
void triforcewidgets::l_yax(int y)
{
    if(y != ry1)
    {
        ry1 = y;
        updateGL();
    }
}
void triforcewidgets::l_zax(int z)
{
    if(z != rz1)
    {
        rz1 = z;
        updateGL();
    }
}
void triforcewidgets::ang()
{

    {
        rotVal_ += 2.f;
        this->repaint();
    }
}


//Lighting
void triforcewidgets::xax(int x)
{
    if(x != x1)
    {
        x1 = x;
        updateGL();
    }
}

void triforcewidgets::yax(int y){
    if(y != y1){
        y1 = y;
        updateGL();
    }
}

void triforcewidgets::zax(int z){
    if(z != z1){
        z1 = z;
        updateGL();
    }
}

void triforcewidgets::wax(int w){
    if(w != w1){
        w1 = w;
        updateGL();
    }
}
