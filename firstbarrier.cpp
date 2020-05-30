#include "firstbarrier.h"
#include "ui_firstbarrier.h"
#include<iostream>
#include<QMessageBox>


FirstBarrier::FirstBarrier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstBarrier)
{
    ui->setupUi(this);
    this->_game1.initWorld1();


    timerEP=startTimer(10000);
    timerEM=startTimer(100);
}

FirstBarrier::~FirstBarrier()
{
    delete ui;
}
void FirstBarrier::showWay(QPainter *p){
    p->setPen(QPen(Qt::black));
    int x1,y1,x2,y2;
    x1=(this->_game1.getPos()[0].getPosX());
    x2=this->_game1.getPos()[3].getPosX()+towerPosition::getWidth();
    y1=(this->_game1.getPos()[0].getPosY()+towerPosition::getHeight()+this->_game1.getPos()[4].getPosY())/2;
    y2=(this->_game1.getPos()[3].getPosY()+towerPosition::getHeight()+this->_game1.getPos()[7].getPosY())/2;
    p->drawLine(x1,y1,x2,y2);
}
void FirstBarrier::drawWave(QPainter *p){
    p->setPen(QPen(Qt::red));
    p->drawText(QRect(400,5,100,25),QString("WAVE:%1").arg(Enemy::getProduce()));
}
void FirstBarrier::drawDollar(QPainter *p){
    p->setPen(QPen(Qt::red));
    p->drawText(QRect(30,5,100,25),QString("DOLLAR:%1").arg(Player::Getdollar()));
}
void FirstBarrier::drawDiamond(QPainter *p){
    p->setPen(QPen(Qt::red));
    p->drawText(QRect(200,5,100,25),QString("DIAMOND:%1").arg(Player::Getdiamond()));
}
void FirstBarrier::paintEvent(QPaintEvent *e){
    QPainter*pa;
    pa=new QPainter();
    pa->begin(this);
    this->drawWave(pa);
    this->drawDiamond(pa);
    this->drawDollar(pa);
    this->_game1.show(pa);
    this->showWay(pa);
    foreach (DTower tow, tower) {
        tow.show(pa);
    }
    foreach(Enemy *emy,enemy){
        emy->enemyShow(pa);
    }
    pa->end();
    delete pa;
}
void FirstBarrier::mousePressEvent(QMouseEvent *e){
    int x=e->pos().x();
    int y=e->pos().y();
    int n=this->_game1.getPos().size();
    for(int i=0;i<n;i++){
        if(DTower::canBuy()&&this->_game1.getPos()[i].containmouse(x,y)&&!this->_game1.getPos()[i].canPlace()){
            this->_game1.getPos()[i].setTower();
            int cx,cy;
            cx=this->_game1.getPos()[i].getPosX();
            cy=this->_game1.getPos()[i].getPosY();
            DTower tow(cx,cy);
            this->tower.push_back(tow);
            Player::dollarMinus();
            update();
            break;
        }
    }
}
void FirstBarrier::EnemyProduce(){
    int x,y;
    x=this->_game1.getPos()[3].getPosX()+towerPosition::getWidth();
    y=this->_game1.getPos()[3].getPosY()+towerPosition::getHeight()+15;
    Enemy *emy=new Enemy;
    emy->set(x,y);
    this->enemy.push_back(emy);
    update();
}
void FirstBarrier::EnemyMove(){
    foreach (Enemy *em, enemy) {
        em->move();
    }
    update();
}
void FirstBarrier::timerEvent(QTimerEvent *event){
    if(event->timerId()==timerEP){
        this->EnemyProduce();
        if(Enemy::getProduce()==5){
            killTimer(timerEP);
        }
    }
    if(event->timerId()==timerEM){
        this->EnemyMove();

    }
}



