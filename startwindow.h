#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include"firstbarrier.h"
#include"secondbarrier.h"

namespace Ui {
class StartWindow;
}
class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

signals:
    void mysignal();
private slots:
    void on_back_clicked();
    void on_start_clicked();

    void on_start2_clicked();

protected:
    virtual void closeEvent(QCloseEvent *event);
private:
    Ui::StartWindow *ui;
    FirstBarrier*w1;
    SecondBarrier*w2;

};
#endif // STARTWINDOW_H
