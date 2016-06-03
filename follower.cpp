#include "follower.h"

#include <QDir>

Follower::Follower()
{
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &Follower::changed);
}

void Follower::add(const QString& path)
{
    if(_isAllDirectoryWatch)
    {
        watcher.addPath(path);
    }
    else
    {
        QFileInfoList allFilesList = QDir(QFileInfo(path).absolutePath()).entryInfoList(QStringList() << "*.qml", QDir::Files);
        QStringList allFilesPathList;
        std::for_each(allFilesList.begin(), allFilesList.end(), [&](const QFileInfo& file){allFilesPathList << file.absoluteFilePath();});

        watcher.addPaths(allFilesPathList);
    }
}

bool Follower::isAllDirectoryWatch() const
{
    return _isAllDirectoryWatch;
}

void Follower::setAllDirectoryWatch(bool value)
{
    _isAllDirectoryWatch = value;
}
