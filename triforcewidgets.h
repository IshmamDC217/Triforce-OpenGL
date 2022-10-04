#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>
#include <GL/glu.h>


class triforcewidgets: public QGLWidget
    { //
    Q_OBJECT
    public:
    //Light position
    triforcewidgets(QWidget *parent);
    float x1 = 8.;
    float y1 = 1.;
    float z1 = 20.;
    float w1 = 1.;

    //Rotation Position
    float rx1 = 0.;
    float ry1 = 1.;
    float rz1 = 0.;

    protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    private:
    void pyramid();
    void pyramid2();
    void pyramid3();
    void pyramid4();
    void pyramid5();
    void polygon(int, int, int, int);
    void camera();
    float light_v = 1.;
    bool playingscene = true;
    QTimer* timer;
    float rotVal_ = 2.f;

    private slots:

    public slots:
    // Lighting
    void xax(int x);
    void yax(int y);
    void zax(int z);
    void wax(int w);

    // Rotation
    void l_xax(int x);
    void l_yax(int y);
    void l_zax(int z);

    void playPause();
    void ang();
    };
#endif
