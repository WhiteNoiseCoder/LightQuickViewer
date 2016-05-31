#ifndef SHOWER_H
#define SHOWER_H

#include <QQuickView>

class Shower
{
public:
    Shower();

    void start();
private:
    QQuickView quickView;
};

#endif // SHOWER_H
