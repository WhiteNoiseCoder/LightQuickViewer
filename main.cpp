#include "shower.h"
#include "viewer.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Viewer viewer;
    if(viewer.show(argc, argv) == Viewer::SHOWED)
    {
        return a.exec();
    }
    return 0;
}
