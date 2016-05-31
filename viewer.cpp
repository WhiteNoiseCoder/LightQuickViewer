#include "viewer.h"

#include <QDebug>

Viewer::Viewer(QObject* parent): QObject(parent)
{
    connect(&follower, &Follower::changed, [](){qDebug()<<"changed";});
}

void Viewer::show()
{
    //FIXME: need change path to real user parameter
    follower.add("C:/warehouse/Projects/Qt/ScenarioEditor/EffectThumb.qml");
}

