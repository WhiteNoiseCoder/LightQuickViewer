#include "viewer.h"
#include "parameters.h"

#include <QDebug>

Viewer::Viewer(QObject* parent): QObject(parent)
{
    connect(&follower, &Follower::changed, [&](){ shower.update(); });
}

Viewer::ShowStatus Viewer::show(int argc, char *argv[])
{
    try
    {
        Parameters parameters(argc, argv);
        parameters.parse();
        if(parameters.isHelpTarget)
        {
            parameters.printHelp();
            return NOT_SHOWED;
        }
        follower.setAllDirectoryWatch(parameters.isAllPath);
        follower.add(parameters.pathString());
        shower.setPatch(parameters.pathUrl());
        shower.start();
        return SHOWED;
    }
    catch(const QString& error)
    {
        qCritical() << error;
        return NOT_SHOWED;
    }
    catch(...)
    {
        qCritical() << "Unknown error";
        return NOT_SHOWED;
    }
}
