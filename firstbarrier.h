#ifndef FIRSTBARRIER_H
#define FIRSTBARRIER_H

#include <QMainWindow>
#include"world1.h"
#include"towerposition.h"
#include"dtower.h"
#include<iostream>
#include<QPainter>
#include<QPixmap>
#include<QMouseEvent>
#include<QTimerEvent>
#include<QTimer>
#include"enemy.h"
#include"player.h"
#include"dialogwin.h"
#include"dialoglose.h"


namespace Ui {
class FirstBarrier;
}

class FirstBarrier : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstBarrier(QWidget *parent = 0);
    ~FirstBarrier();
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent*e);
    void showWay(QPainter*p);
    void EnemyProduce();
    void EnemyMove();
    void drawWave(QPainter*p);
    void drawDollar(QPainter*p);
    void drawDiamond(QPainter*p);
    void loseOrWin();
    bool islose();
    void choseEnemy();
    void mouseDoubleClickEvent(QMouseEvent*e);

private slots:
    void timerEvent(QTimerEvent *event);

private:
    Ui::FirstBarrier *ui;
    World1 _game1;
    vector<DTower*> tower;
    vector<Enemy*> enemy;
    vector<Bullet*> bul;
    DialogWin*dialog1;
    DialogLose*dialog2;
    int timerEP;//��ʱ���˵Ĳ���
    int timerEM;//��ʱ���˵��ƶ�
    int timer0;//ÿ20ms���һ����Ϸ��Ӯ
    int timerFire;//��������
    int timerbu;//�ӵ��ƶ�����
};

#endif // FIRSTBARRIER_H
