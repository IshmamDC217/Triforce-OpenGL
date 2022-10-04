#include "triforcewindow.h"
#include <QtWidgets>

triforcewindow::triforcewindow(QWidget *parent)
    : QWidget(parent)
    {
    menuBar = new QMenuBar(this);
    actionQuit = new QAction("&Quit", this);

    QGridLayout *windowLayout = new QGridLayout(this);

    cube_widget = new triforcewidgets(this);

    QWidget *Area = new QWidget();
    Area->setFixedWidth(200);

    QVBoxLayout *layout = new QVBoxLayout();

    // Slider Lighting
    nVerticesSlider_h = new QSlider(Qt::Horizontal);
    nVerticesSlider_v1 = new QSlider(Qt::Horizontal);
    nVerticesSlider_v2 = new QSlider(Qt::Horizontal);
    nVerticesSlider_v3 = new QSlider(Qt::Horizontal);
    nVerticesSlider_v4 = new QSlider(Qt::Horizontal);

    nVerticesSlider_v1->setMinimum(0);
    nVerticesSlider_v1->setMaximum(50);
    nVerticesSlider_v1->setValue(0);
    nVerticesSlider_v1->connect(nVerticesSlider_v1, SIGNAL(valueChanged(int)), cube_widget, SLOT(xax(int)));

    nVerticesSlider_v2->setMinimum(0);
    nVerticesSlider_v2->setMaximum(50);
    nVerticesSlider_v2->setValue(0);
    nVerticesSlider_v2->connect(nVerticesSlider_v2, SIGNAL(valueChanged(int)), cube_widget, SLOT(yax(int)));

    nVerticesSlider_v3->setMinimum(0);
    nVerticesSlider_v3->setMaximum(50);
    nVerticesSlider_v3->setValue(0);
    nVerticesSlider_v3->connect(nVerticesSlider_v3, SIGNAL(valueChanged(int)), cube_widget, SLOT(zax(int)));

    nVerticesSlider_v4->setMinimum(0);
    nVerticesSlider_v4->setMaximum(50);
    nVerticesSlider_v4->setValue(0);
    nVerticesSlider_v4->connect(nVerticesSlider_v4, SIGNAL(valueChanged(int)), cube_widget, SLOT(wax(int)));



    // Slider Rotation
    rVerticesSlider_r1 = new QSlider(Qt::Horizontal);
    rVerticesSlider_r2 = new QSlider(Qt::Horizontal);
    rVerticesSlider_r3 = new QSlider(Qt::Horizontal);

    rVerticesSlider_r1->setMinimum(0);
    rVerticesSlider_r1->setMaximum(50);
    rVerticesSlider_r1->setValue(0);
    rVerticesSlider_r1->connect(rVerticesSlider_r1, SIGNAL(valueChanged(int)), cube_widget, SLOT(l_xax(int)));

    rVerticesSlider_r2->setMinimum(0);
    rVerticesSlider_r2->setMaximum(50);
    rVerticesSlider_r2->setValue(0);
    rVerticesSlider_r2->connect(rVerticesSlider_r2, SIGNAL(valueChanged(int)), cube_widget, SLOT(l_yax(int)));

    rVerticesSlider_r3->setMinimum(0);
    rVerticesSlider_r3->setMaximum(50);
    rVerticesSlider_r3->setValue(0);
    rVerticesSlider_r3->connect(rVerticesSlider_r3, SIGNAL(valueChanged(int)), cube_widget, SLOT(l_zax(int)));

    QLabel *l_v1 = new QLabel("Lighting: x axis");
    QLabel *l_v2 = new QLabel("Lighting: y axis");
    QLabel *l_v3 = new QLabel("Lighting: z axis");
    QLabel *l_v4 = new QLabel("Lighting: xz");

    QLabel *l_r1 = new QLabel("Rotation: x axis");
    QLabel *l_r2 = new QLabel("Rotation: y axis");
    QLabel *l_r3 = new QLabel("Rotation: z axis");

    layout->addWidget(l_v1);
    layout->addWidget(nVerticesSlider_v1);
    layout->addWidget(l_v2);
    layout->addWidget(nVerticesSlider_v2);
    layout->addWidget(l_v3);
    layout->addWidget(nVerticesSlider_v3);
    layout->addWidget(l_v4);
    layout->addWidget(nVerticesSlider_v4);

    layout->addWidget(l_r1);
    layout->addWidget(rVerticesSlider_r1);
    layout->addWidget(l_r2);
    layout->addWidget(rVerticesSlider_r2);
    layout->addWidget(l_r3);
    layout->addWidget(rVerticesSlider_r3);

    Area->setLayout(layout);
    windowLayout->addWidget(Area, 0, 0);
    windowLayout->addWidget(cube_widget, 0, 1);
    } // constructor

triforcewindow::~triforcewindow()
    { // destructor
    delete nVerticesSlider_h;
    delete nVerticesSlider_v1;
    delete nVerticesSlider_v2;
    delete nVerticesSlider_v3;
    delete nVerticesSlider_v4;

    delete rVerticesSlider_r1;
    delete rVerticesSlider_r2;
    delete rVerticesSlider_r3;

    delete cube_widget;
    delete windowLayout;
    delete actionQuit;
//	Delete fileMenu
    delete menuBar;
    } // Destructor

// Resets the interface elements
void triforcewindow::ResetInterface()
    { // ResetInterface()
    nVerticesSlider_h->setMinimum(0);
    nVerticesSlider_h->setMaximum(50);
    nVerticesSlider_v1->setMinimum(0);
    nVerticesSlider_v1->setMaximum(50);
    nVerticesSlider_v2->setMinimum(0);
    nVerticesSlider_v2->setMaximum(50);
    nVerticesSlider_v3->setMinimum(0);
    nVerticesSlider_v3->setMaximum(50);
    nVerticesSlider_v4->setMinimum(0);
    nVerticesSlider_v4->setMaximum(50);

    rVerticesSlider_r1->setMinimum(0);
    rVerticesSlider_r1->setMaximum(50);
    rVerticesSlider_r2->setMinimum(0);
    rVerticesSlider_r2->setMaximum(50);
    rVerticesSlider_r3->setMinimum(0);
    rVerticesSlider_r3->setMaximum(50);


    // Now Force Refresh
    cube_widget->update();
    update();
    } // ResetInterface()


