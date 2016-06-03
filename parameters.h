#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QUrl>

class Parameters
{
public:
    Parameters(int argc, char *argv[]);

    void parse();

    QUrl pathUrl();
    QString pathString();
private:
    int count;
    char **arguments;

    QString path;
};

#endif // PARAMETERS_H
