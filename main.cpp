#include "shower.h"
#include "viewer.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Viewer viewer;
    viewer.show(argc, argv);

    return a.exec();
}
