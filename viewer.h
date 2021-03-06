#ifndef VIEWER_H
#define VIEWER_H

#include "follower.h"
#include "shower.h"

#include <QObject>


class Viewer : public QObject
{
    Q_OBJECT
public:
    enum ShowStatus {SHOWED, NOT_SHOWED};
    Viewer(QObject* parent = nullptr);

    ShowStatus show(int argc, char *argv[]);
private:
    Follower follower;
    Shower shower;
};

#endif // VIEWER_H
