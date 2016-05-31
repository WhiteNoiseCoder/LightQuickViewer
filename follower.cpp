#include "follower.h"

Follower::Follower()
{
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &Follower::changed);
}

void Follower::add(const QString& path)
{
    watcher.removePaths(watcher.files());
    watcher.addPath(path);
}
