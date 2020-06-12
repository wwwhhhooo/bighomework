#ifndef SECONDBARRIER_H
#define SECONDBARRIER_H

#include <QMainWindow>
#include"world2.h"
#include"towerposition.h"
#include"dtower.h"
#include<iostream>
#include<QPainter>
#include<QPixmap>
#include<QMouseEvent>
#include<QTimerEvent>
#include<QTimer>
#include"player.h"
#include"dialogwin.h"
#include"dialoglose.h"
#include"enemyx.h"
#include<vector>

namespace Ui {
class SecondBarrier;
}

class SecondBarrier : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondBarrier(QWidget *parent = 0);
    ~SecondBarrier();
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

private slots:
    void timerEvent(QTimerEvent *event);


private:
    Ui::SecondBarrier *ui;
    World2 game2;
    vector<DTower> tower;
    vector<EnemyX*> enemy;
    vector<Bullet*> bul;
    int timerEP;//计时敌人的产生
    int timerEM;//计时敌人的移动
    int timer0;//每20ms检测一下游戏输赢
    int timerFire;//攻击速率
    int timerbu;//子弹移动速率
};

#endif // SECONDBARRIER_H
