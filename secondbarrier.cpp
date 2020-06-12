#include "secondbarrier.h"
#include "ui_secondbarrier.h"

SecondBarrier::SecondBarrier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondBarrier)
{
    ui->setupUi(this);
    this->game2.initWorld();
    timerEP=startTimer(10000);
    timerEM=startTimer(100);
    timer0=startTimer(20);
    timerFire=startTimer(DTower::getFirerate());
    timerbu=startTimer(300);
}

SecondBarrier::~SecondBarrier()
{
    delete ui;


}
void SecondBarrier::showWay(QPainter *p){
    p->setPen(QPen(Qt::black));
    int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    x1=this->game2.getPos()[0].getPosX()-50;
    y1=this->game2.getPos()[0].getPosY()+towerPosition::getHeight()+30;
    x2=this->game2.getPos()[2].getPosX();
    y2=y1;
    x3=x2;
    y3=y1+120;
    x4=x1;
    y4=y3;
    x5=x4;
    y5=y4+120;
    x6=x2;
    y6=y5;
    p->drawLine(x1,y1,x2,y2);
    p->drawLine(x2,y2,x3,y3);
    p->drawLine(x3,y3,x4,y4);
    p->drawLine(x4,y4,x5,y5);
    p->drawLine(x5,y5,x6,y6);
}
void SecondBarrier::drawWave(QPainter *p){
    p->setPen(QPen(Qt::red));
    p->drawText(QRect(400,5,100,25),QString("WAVE:%1").arg(Enemy::getProduce()));
}
void SecondBarrier::drawDollar(QPainter *p){
    p->setPen(QPen(Qt::red));
    p->drawText(QRect(30,5,100,25),QString("DOLLAR:%1").arg(Player::Getdollar()));
}
void SecondBarrier::drawDiamond(QPainter *p){
    p->setPen(QPen(Qt::red));
    p->drawText(QRect(200,5,150,25),QString("DIAMOND:%1").arg(Player::Getdiamond()));
}
void SecondBarrier::paintEvent(QPaintEvent *e){
    QPainter*pa;
    pa=new QPainter();
    pa->begin(this);
    this->drawWave(pa);
    this->drawDiamond(pa);
    this->drawDollar(pa);
    this->showWay(pa);
    this->game2.show(pa);
    foreach(DTower tow,tower){
        tow.show(pa);
    }
    foreach(EnemyX*emy,enemy){
        emy->enemyShow(pa);
    }
    foreach(Bullet*b,bul){
        b->show(pa);
    }
    pa->end();
    delete pa;
}
void SecondBarrier::mousePressEvent(QMouseEvent *e){
    int x=e->pos().x();
    int y=e->pos().y();
    int n=game2.getPos().size();
    for(int i=0;i<n;i++){
        if(DTower::canBuy() && this->game2.getPos()[i].containmouse(x,y) && this->game2.getPos()[i].canPlace()){
            this->game2.getPos()[i].setTower();
            int cx,cy;
            cx=this->game2.getPos()[i].getPosX();
            cy=this->game2.getPos()[i].getPosY();
            DTower tow(cx,cy);
            this->tower.push_back(tow);
            update();
            break;
        }
    }
}

void SecondBarrier::EnemyProduce(){
    int x,y;
    x=this->game2.getPos()[0].getPosX()-50;
    y=this->game2.getPos()[0].getPosY()+towerPosition::getHeight()+10;
    EnemyX*enm=new EnemyX;
    enm->set(x,y);
    enemy.push_back(enm);
    update();
}
void SecondBarrier::EnemyMove(){
    foreach(EnemyX*emy,enemy){
        emy->move();
    }
    update();
}
void SecondBarrier::timerEvent(QTimerEvent *event){
    if(event->timerId()==timerEP){
        this->EnemyProduce();
        if(EnemyX::getProduce()==10){
            killTimer(timerEP);
        }
    }
    if(event->timerId()==timerEM){
        this->EnemyMove();
    }
    if(event->timerId()==timer0){
        this->loseOrWin();
        if(this->islose()){
            killTimer(timer0);
        }
        if(Enemy::getProduce()==10&&Enemy::getCount()==0){
            killTimer(timer0);
        }
    }
    if(event->timerId()==timerFire){
        foreach (DTower tow,tower) {
               foreach (EnemyX*em, enemy) {
                  int x=tow.getx()+towerPosition::getWidth()/2;
                  int y=tow.gety()+towerPosition::getHeight()/2;
                  double d=sqrt((1.0*x-em->getX()-25)*(x-em->getX()-25)+(1.0*y-em->getY()-25)*(y-em->getY()-25));
                  if(d<tow.getRange()/2){
                      em->onAttack();
                      Bullet*b=new Bullet(x,y,em->getX(),em->getY());
                      this->bul.push_back(b);
                      update();
                      break;
                  }
               }
           }
        vector<EnemyX*>::iterator it;
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

void SecondBarrier::loseOrWin(){
    if(Enemy::getProduce()==10&&Enemy::getCount()==0){
        DialogWin*dialog1=new DialogWin;
        this->hide();
        dialog1->show();
    }
    if(this->islose()){
        DialogLose*dialog2=new DialogLose;
        this->hide();
        dialog2->show();
    }
}
bool SecondBarrier::islose(){
    foreach(EnemyX*emy,enemy){
        if(emy->getX()>705&&emy->getY()>=400){
            return true;
        }
    }
    return false;
}













