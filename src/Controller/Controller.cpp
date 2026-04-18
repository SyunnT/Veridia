#include "Controller.h"

Controller::Controller(QObject* parent)
    : QObject(parent)
    , m_view(new View)
{
    m_view->show();
}

Controller::~Controller()
{
    delete m_view;
}
