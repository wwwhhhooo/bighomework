#include "dialogwin.h"
#include "ui_dialogwin.h"

DialogWin::DialogWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWin)
{
    ui->setupUi(this);
}

DialogWin::~DialogWin()
{
    delete ui;
}

void DialogWin::on_buttonBox_accepted()
{
    this->close();
    delete this;
}
