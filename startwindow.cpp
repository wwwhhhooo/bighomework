#include "startwindow.h"
#include "ui_startwindow.h"
#include"secondbarrier.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_back_clicked()
{
    emit mysignal();
    this->close();
}
void StartWindow::closeEvent(QCloseEvent *event){
    emit mysignal();
}

void StartWindow::on_start_clicked()
{
    FirstBarrier*w1=new FirstBarrier;
    w1->show();
    this->hide();

}

void StartWindow::on_start2_clicked()
{
    SecondBarrier*w2=new SecondBarrier;
    w2->show();
    this->hide();
}
