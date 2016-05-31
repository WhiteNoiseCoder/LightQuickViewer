#include "shower.h"

Shower::Shower()
{

}

void Shower::start()
{
    quickView.setSource(QUrl::fromLocalFile("C:/warehouse/Projects/Qt/ScenarioEditor/MainForm.ui.qml"));
    quickView.show();
}
