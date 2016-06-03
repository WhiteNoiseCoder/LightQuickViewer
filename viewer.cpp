#include "viewer.h"
#include "parameters.h"

#include <QDebug>

Viewer::Viewer(QObject* parent): QObject(parent)
{
    connect(&follower, &Follower::changed, [&](){ shower.update(); });
}

void Viewer::show(int argc, char *argv[])
{
    Parameters parameters(argc, argv);
    parameters.parse();
    if(parameters.isHelpTarget)
    {
        parameters.printHelp();
        return;
    }
    follower.setAllDirectoryWatch(parameters.isAllPath);
    follower.add(parameters.pathString());
    shower.setPatch(parameters.pathUrl());
    shower.start();
}
