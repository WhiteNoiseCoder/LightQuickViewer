#include "parameters.h"

Parameters::Parameters(int argc, char *argv[]): count(argc), arguments(argv)
{

}

void Parameters::parse()
{
    if(count != 2) throw(QString("bad agruments. need path"));
    path = arguments[1];
}

QUrl Parameters::pathUrl()
{
    return QUrl::fromLocalFile(path);
}

QString Parameters::pathString()
{
    return path;
}

