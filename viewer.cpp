#include "viewer.h"
#include "parameters.h"

#include <QDebug>

Viewer::Viewer(QObject* parent): QObject(parent)
{
    connect(&follower, &Follower::changed, [](){qDebug()<<"changed";});
}

void Viewer::show(int argc, char *argv[])
{
    Parameters parameters(argc, argv);
    parameters.parse();
    follower.add(parameters.pathString());
    shower.setPatch(parameters.pathUrl());
    shower.start();
}
