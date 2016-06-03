#include "parameters.h"

#include <QDebug>

Parameters::Parameters(int argc, char *argv[]): count(argc), arguments(argv)
{

}

void Parameters::printHelp()
{
    qInfo() << "[options] <qml file path>";
    qInfo() << "Options:";
    qInfo() << "\t-h\tthis help";
    qInfo() << "\t-a\twatch all target directory";
}

void Parameters::parse()
{
    for(int i = 1; i < count; i++)
    {

        if(arguments[i][0] == '-')
        {
            QString argI = arguments[i];
            if(argI == "-a")
            {
                isAllPath = true;
            }
            else if(argI == "-h")
            {
                isHelpTarget = true;
            }
        }
        else
        {
            path = arguments[i];
        }
    }
    if(!isHelpTarget)
    {
        if(path.isEmpty()) throw(QString("Error: Run with parameter -h for get help"));
    }
}

QUrl Parameters::pathUrl()
{
    return QUrl::fromLocalFile(path);
}

QString Parameters::pathString()
{
    return path;
}

