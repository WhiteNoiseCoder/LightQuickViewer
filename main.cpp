#include "shower.h"
#include "viewer.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Shower shower;
    shower.start();

    Viewer viewer;
    viewer.show();

    return a.exec();
}
