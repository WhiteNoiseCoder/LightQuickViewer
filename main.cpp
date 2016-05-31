#include "shower.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Shower shower;
    shower.start();

    return a.exec();
}
