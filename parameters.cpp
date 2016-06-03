#include "parameters.h"

Parameters::Parameters(int argc, char *argv[]): count(argc), arguments(argv)
{

}

void Parameters::parse()
{
    if(count < 2 || count > 3) throw(QString("bad agruments. need path"));
    for(int i = 1; i < count; i++)
    {
         if(arguments[i][0] == '-')
         {
             if(arguments[i] == "-a")
             {
                isAllPath = true;
             }
         }
         else
         {
             path = arguments[i];
         }
    }
    if(path.isEmpty()) throw(QString("bad agruments. need path"));
}

QUrl Parameters::pathUrl()
{
    return QUrl::fromLocalFile(path);
}

QString Parameters::pathString()
{
    return path;
}

