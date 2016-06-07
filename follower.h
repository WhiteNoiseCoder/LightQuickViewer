#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <QFileSystemWatcher>


class Follower : public QObject
{
    Q_OBJECT
public:
    Follower();

    void add(const QString& path);
    bool isAllDirectoryWatch() const;
    void setAllDirectoryWatch(bool value);

private:
    QFileSystemWatcher watcher;
    bool _isAllDirectoryWatch = false;
private slots:
    void onChanged(const QString &path);
signals:
    void changed();
};

#endif // FOLLOWER_H
