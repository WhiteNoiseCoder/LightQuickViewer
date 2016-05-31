#include "shower.h"

Shower::Shower()
{
}

void Shower::setPatch(const QUrl &path)
{
    this->path = path;
}

void Shower::start()
{
    if(path.isEmpty()) throw("empty path");
    quickView.setSource(path);
    quickView.show();
}
