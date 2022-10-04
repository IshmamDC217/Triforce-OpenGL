#ifndef __GL_POLYGON_WINDOW_H__
#define __GL_POLYGON_WINDOW_H__ 1

#include <QGLWidget>
#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include "triforcewidgets.h"
#include <QMouseEvent>

class triforcewindow: public QWidget
    {
    public:
    triforcewindow(QWidget *parent);
    ~triforcewindow();

    // visual hierarchy
    // menu bar
    QMenuBar *menuBar;
        // file menu
        QMenu *fileMenu;
            // quit action
            QAction *actionQuit;

    // window layout
    QGridLayout  *windowLayout;

    // beneath that, the main widget
    triforcewidgets *cube_widget;
    QSlider *nVerticesSlider_h;
    // and a light slider for the number of vertices
    QSlider *nVerticesSlider_v1;
    QSlider *nVerticesSlider_v2;
    QSlider *nVerticesSlider_v3;
    QSlider *nVerticesSlider_v4;

    QSlider *rVerticesSlider_r1;
    QSlider *rVerticesSlider_r2;
    QSlider *rVerticesSlider_r3;

    QMouseEvent* playPause;

    void ResetInterface();


    };

#endif
