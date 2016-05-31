#ifndef SHOWER_H
#define SHOWER_H

#include <QQuickView>

class Shower
{
public:
    Shower();
    void setPatch(const QUrl& path);

    void start();
private:
    QQuickView quickView;
    QUrl path;
};

#endif // SHOWER_H
