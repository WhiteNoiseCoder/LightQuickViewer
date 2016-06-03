#include "shower.h"

#include <QQmlEngine>

Shower::Shower()
{
}

void Shower::setPatch(const QUrl &path)
{
    this->path = path;
}

void Shower::start()
{
    if(path.isEmpty()) throw(QString("empty path"));
    quickView.setSource(path);
    quickView.show();
}

void Shower::update()
{
    quickView.setSource(QUrl());
    quickView.engine()->clearComponentCache();
    quickView.show();
    quickView.setSource(path);
    quickView.engine()->clearComponentCache();
    quickView.show();
}

