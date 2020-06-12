#ifndef DIALOGWIN_H
#define DIALOGWIN_H

#include <QDialog>

namespace Ui {
class DialogWin;
}

class DialogWin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWin(QWidget *parent = 0);
    ~DialogWin();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogWin *ui;
};

#endif // DIALOGWIN_H
