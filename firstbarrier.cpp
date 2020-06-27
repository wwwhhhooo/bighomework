#include "firstbarrier.h"
#include "ui_firstbarrier.h"
#include<iostream>
#include<QMessageBox>
#include<cmath>


FirstBarrier::FirstBarrier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstBarrier)
{
    ui->setupUi(this);
    this->_game1.initWorld();


    timerEP=startTimer(10000);
    timerEM=startTimer(100);
    timer0=startTimer(20);
    timerFire=startTimer(DTower::getFirerate());
    timerbu=startTimer(300);

}

FirstBarrier::~FirstBarrier()
{
    delete ui;
}

void FirstBarrier::showWay(QPainter *p){
    p->setPen(QPen(Qt::black));
    int x1,y1,x2,y2;
    x1=(this->_game1.getPos()[0]->getPosX());
    x2=this->_game1.getPos()[3]->getPosX()+towerPosition::getWidth();
    y1=(this->_game1.getPos()[0]->getPosY()+towerPosition::getHeight()+this->_game1.getPos()[4]->getPosY())/2;
    y2=(this->_game1.getPos()[3]->getPosY()+towerPosition::getHeight()+this->_game1.getPos()[7]->getPosY())/2;
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
    p->drawText(QRect(200,5,150,25),QString("DIAMOND:%1").arg(Player::Getdiamond()));
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
    foreach (DTower *tow, tower) {
        tow->show(pa);

    }
    foreach(Enemy *emy,enemy){
        emy->enemyShow(pa);
    }
    foreach(Bullet*bl,bul){
        bl->show(pa);
    }
    pa->end();
    delete pa;
}
void FirstBarrier::mousePressEvent(QMouseEvent *e){
    int x=e->pos().x();
    int y=e->pos().y();
    int n=this->_game1.getPos().size();
    for(int i=0;i<n;i++){
        if(DTower::canBuy() && this->_game1.getPos()[i]->containmouse(x,y) && this->_game1.getPos()[i]->canPlace()){
            this->_game1.getPos()[i]->setTower();
            int cx,cy;
            cx=this->_game1.getPos()[i]->getPosX();
            cy=this->_game1.getPos()[i]->getPosY();
            DTower *tow=new DTower(cx,cy);
            this->tower.push_back(tow);

            update();
            break;
        }
        if(Player::Getdiamond()>=600&&_game1.getPos()[i]->containmouse(x,y) && !this->_game1.getPos()[i]->canPlace()){
            vector<DTower*>::iterator it;
            it=this->tower.begin();
            while (it!=this->tower.end()) {
                if((*it)->getx()==this->_game1.getPos()[i]->getPosX()&&(*it)->gety()==this->_game1.getPos()[i]->getPosY()&&(*it)->getdegree()<3){
                    (*it)->updating();
                    break;
                }
                else it++;
            }
            update();
            break;
        }
    }
}
void FirstBarrier::mouseDoubleClickEvent(QMouseEvent *e){
    int x=e->pos().x();
    int y=e->pos().y();
    int n=this->_game1.getPos().size();
    for(int i=0;i<n;i++){
        if(this->_game1.getPos()[i]->containmouse(x,y)&&!this->_game1.getPos()[i]->canPlace()){
            vector<DTower*>::iterator it;
            it=this->tower.begin();
            while (it!=this->tower.end()) {
                if((*it)->getx()==this->_game1.getPos()[i]->getPosX()&&(*it)->gety()==this->_game1.getPos()[i]->getPosY()){
                    delete (*it);
                    it=this->tower.erase(it);
                    Player::sell();
                    this->_game1.getPos()[i]->reset();
                    break;
                }
            }
            break;
        }
    }
}
void FirstBarrier::EnemyProduce(){
    int x,y;
    x=this->_game1.getPos()[3]->getPosX()+towerPosition::getWidth();
    y=this->_game1.getPos()[3]->getPosY()+towerPosition::getHeight()+15;
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
    if(event->timerId()==timer0){
        this->loseOrWin();
        if(islose()){
            killTimer(timer0);
        }
        if(Enemy::getProduce()==5&&Enemy::getCount()==0){
            killTimer(timer0);
        }
    }
    if(event->timerId()==timerFire){
        foreach (DTower *tow,tower) {
               foreach (Enemy*em, enemy) {
                  int x=tow->getx()+towerPosition::getWidth()/2;
                  int y=tow->gety()+towerPosition::getHeight()/2;
                  double d=sqrt((1.0*x-em->getX())*(x-em->getX())+(1.0*y-em->getY())*(y-em->getY()));
                  if(d<tow->getRange()/2){
                      em->onAttack(tow->getAttack());
                      Bullet*b=new Bullet(x,y,em->getX(),em->getY());
                      this->bul.push_back(b);
                      update();
                      break;
                  }
               }
           }
        vector<Enemy*>::iterator it;
        it=enemy.begin();
        while(it!=enemy.end()){
            if((*it)->die()){
                delete (*it);
                it=enemy.erase(it);

            }
            else
                it++;
        }
    }
    if(event->timerId()==timerbu){
        foreach (Bullet*bl, bul) {
           bl->move();
           update();
        }
        vector<Bullet*>::iterator it;
        it=bul.begin();
        while(it!=bul.end()){
            if((*it)->ifmove()){
                delete (*it);
                it=bul.erase(it);
            }
            else it++;
        }
    }

}
void FirstBarrier::loseOrWin(){
    if(Enemy::getProduce()==5&&Enemy::getCount()==0){
        dialog1=new DialogWin;
        this->hide();
        dialog1->show();
    }
    if(islose()){
        dialog2=new DialogLose;
        this->hide();
        dialog2->show();
    }
}
bool FirstBarrier::islose(){
    foreach(Enemy*em,enemy){
        if(em->getX()<100)
            return true;
    }
    return false;
}



