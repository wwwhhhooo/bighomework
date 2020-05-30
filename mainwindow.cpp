#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"startwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Begin_released()
{
    w0=new StartWindow;
    w0->show();
    connect(w0,SIGNAL(mysignal()),this,SLOT(my_show_slot()));

    this->hide();
}
void MainWindow::my_show_slot(){
    this->show();
}
