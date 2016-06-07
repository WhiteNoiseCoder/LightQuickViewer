#include "follower.h"

#include <QDir>
#include <chrono>
#include <thread>

Follower::Follower()
{
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &Follower::onChanged);
}

void Follower::add(const QString& path)
{
    if(!_isAllDirectoryWatch)
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

void Follower::onChanged(const QString &path)
{
    QFileInfo checkFile(path);
    while(!checkFile.exists())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    emit changed();
    watcher.addPath(path);
}
