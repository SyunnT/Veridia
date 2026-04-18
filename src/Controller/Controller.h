#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "View.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller() override;

private:
    View *m_view;
};

#endif // CONTROLLER_H
