#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <QFileSystemWatcher>


class Follower : public QObject
{
    Q_OBJECT
public:
    Follower();

    void add(const QString& path);
private:
    QFileSystemWatcher watcher;
signals:
    void changed();
};

#endif // FOLLOWER_H
