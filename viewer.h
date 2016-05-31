#ifndef VIEWER_H
#define VIEWER_H

#include "follower.h"

#include <QObject>



class Viewer : public QObject
{
    Q_OBJECT
public:
    Viewer(QObject* parent = nullptr);

    void show();
private:
    Follower follower;
};

#endif // VIEWER_H
