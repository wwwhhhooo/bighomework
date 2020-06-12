#include "dialoglose.h"
#include "ui_dialoglose.h"

DialogLose::DialogLose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLose)
{
    ui->setupUi(this);
}

DialogLose::~DialogLose()
{
    delete ui;
}

void DialogLose::on_buttonBox_accepted()
{
    this->close();
    delete this;
}
