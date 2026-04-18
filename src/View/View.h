#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "view_global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class VIEW_EXPORT View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View() override;

private:
    Ui::View *m_ui;
};

#endif // VIEW_H
