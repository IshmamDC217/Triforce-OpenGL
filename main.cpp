#include "triforcewidgets.h"
#include <QApplication>
#include <QVBoxLayout>
#include "triforcewindow.h"

int main(int argc, char *argv[])
    {
    // create the application
    QApplication app(argc, argv);
    // create a master widget
        triforcewindow *window = new triforcewindow(NULL);

    // resizes window
    window->resize(900, 700);

    // shows label
    window->show();

    // start it running
    app.exec();
    //	delete controller;
    delete window;

    // return to caller
    return 0;
    }
