#include "View.h"
#include "ui_View.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::View)
{
    m_ui->setupUi(this);
    setWindowTitle("Veridia");
}

View::~View()
{
    delete m_ui;
}
