#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QImage>
#include<QPixmap>
#include<QTime>
#include"startwindow.h"
#include"world1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_Begin_released();
    void my_show_slot();

private:
    Ui::MainWindow *ui;
    StartWindow*w0;

};

#endif // MAINWINDOW_H
