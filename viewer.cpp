#include "viewer.h"

#include <QDebug>

Viewer::Viewer(QObject* parent): QObject(parent)
{
    connect(&follower, &Follower::changed, [](){qDebug()<<"changed";});
}

void Viewer::show()
{
    //FIXME: need change path to real user parameter
    QString path = "C:/warehouse/Projects/Qt/ScenarioEditor/EffectThumb.qml";

    follower.add(path);
    shower.setPatch(QUrl::fromLocalFile(path));
    shower.start();
}
