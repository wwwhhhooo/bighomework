#include "secondbarrier.h"
#include "ui_secondbarrier.h"
#include<typeinfo>

SecondBarrier::SecondBarrier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondBarrier)
{
    ui->setupUi(this);
    this->game2.initWorld();
    timerEPz=startTimer(10000);
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
    x1=this->game2.getPos()[0]->getPosX()-50;
    y1=this->game2.getPos()[0]->getPosY()+towerPosition::getHeight()+30;
    x2=this->game2.getPos()[2]->getPosX();
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
    foreach(DTower *tow,tower){
        tow->show(pa);
    }
    foreach(Enemy*emy,enemy){
        emy->enemyShow(pa);
    }
    foreach(Bullet*b,bul){
        b->show(pa);
    }
    foreach(EmyBullet*b,emybul){
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
        if(DTower::canBuy() && this->game2.getPos()[i]->containmouse(x,y) && this->game2.getPos()[i]->canPlace()){
            this->game2.getPos()[i]->setTower();
            int cx,cy;
            cx=this->game2.getPos()[i]->getPosX();
            cy=this->game2.getPos()[i]->getPosY();
            DTower* tow=new DTower(cx,cy);
            this->tower.push_back(tow);
            update();
            break;
        }
        if(Player::Getdiamond()>=600&&this->game2.getPos()[i]->containmouse(x,y) && !this->game2.getPos()[i]->canPlace()){
            vector<DTower*>::iterator it;
            it=tower.begin();
            while(it!=tower.end()){
                if((*it)->getx()==this->game2.getPos()[i]->getPosX()&&(*it)->gety()==this->game2.getPos()[i]->getPosY()&&(*it)->getdegree()<3){
                    (*it)->updating();
                    break;
                }
                else it++;
            }
            break;
        }
    }
}
void SecondBarrier::mouseDoubleClickEvent(QMouseEvent *e){
    int x=e->pos().x();
    int y=e->pos().y();
    int n=game2.getPos().size();
    for(int i=0;i<n;i++){
        if(this->game2.getPos()[i]->containmouse(x,y) && !this->game2.getPos()[i]->canPlace()){
            vector<DTower*>::iterator it;
            it=tower.begin();
            while(it!=tower.end()){
                if((*it)->getx()==this->game2.getPos()[i]->getPosX()&&(*it)->gety()==this->game2.getPos()[i]->getPosY()){
                    delete (*it);
                    it=tower.erase(it);
                    Player::sell();
                    this->game2.getPos()[i]->reset();
                    break;
                }
                else it++;
            }
            break;
        }
    }
}

void SecondBarrier::EnemyMove(){
    foreach(Enemy*emy,enemy){
        emy->move();
    }
    update();
}
void SecondBarrier::EnemyzProduce(){
    int x,y;
    x=this->game2.getPos()[0]->getPosX()-50;
    y=this->game2.getPos()[0]->getPosY()+towerPosition::getHeight()+10;
    Enemyz*enm=new Enemyz;
    enm->set(x,y);
    enemy.push_back(enm);
    update();
}

void SecondBarrier::timerEvent(QTimerEvent *event){

    if(event->timerId()==timerEPz){
        if(Enemy::getProduce()==10){
            killTimer(timerEPz);
        }
        else{
             this->EnemyzProduce();
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
        foreach (DTower *tow,tower) {
               foreach (Enemy*em, enemy) {
                  int x=tow->getx()+towerPosition::getWidth()/2;
                  int y=tow->gety()+towerPosition::getHeight()/2;
                  double d=sqrt((1.0*x-em->getX()-25)*(x-em->getX()-25)+(1.0*y-em->getY()-25)*(y-em->getY()-25));
                  if(d<tow->getRange()/2){
                      em->onAttack(tow->getAttack());
                      Bullet*b=new Bullet(x,y,em->getX(),em->getY());
                      this->bul.push_back(b);
                      EmyBullet*b1=new EmyBullet(em->getX(),em->getY(),x,y);
                      this->emybul.push_back(b1);
                      tow->onattack(100);
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
        vector<DTower*>::iterator it2;
        it2=tower.begin();
        while(it2!=tower.end()){
            if( (*it2)->isDead()){
                int n=game2.getPos().size();
                for(int i=0;i<n;i++){
                    if(this->game2.getPos()[i]->getPosX()==(*it2)->getx()&&this->game2.getPos()[i]->getPosY()==(*it2)->gety()){
                        this->game2.getPos()[i]->reset();
                        break;
                    }
                }
                delete (*it2);
                it2=tower.erase(it2);

            }
            else it2++;
        }
    }


    if(event->timerId()==timerbu){
        foreach (Bullet*bl, bul) {
           bl->move();
           update();
        }
        foreach(EmyBullet*bl,emybul){
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
        vector<EmyBullet*>::iterator it1;
        it1=emybul.begin();
        while(it1!=emybul.end()){
            if((*it1)->ifmove()){
                delete (*it1);
                it1=emybul.erase(it1);

            }
            else it++;
        }
    }
}

void SecondBarrier::loseOrWin(){
    if(Enemy::getProduce()==10&&Enemy::getCount()==0){
        dialog1=new DialogWin;
        this->hide();
        dialog1->show();
    }
    if(this->islose()){
        dialog2=new DialogLose;
        this->hide();
        dialog2->show();
    }
}
bool SecondBarrier::islose(){
    foreach(Enemy*emy,enemy){
        if(emy->getX()>705&&emy->getY()>=400){
            return true;
        }
    }
    return false;
}













