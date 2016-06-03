#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QUrl>

class Parameters
{
public:
    Parameters(int argc, char *argv[]);

    void parse();
    void printHelp();

    QUrl pathUrl();
    QString pathString();

    bool isAllPath = false;
    bool isHelpTarget = false;
private:
    int count;
    char **arguments;

    QString path;
};

#endif // PARAMETERS_H
