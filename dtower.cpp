#include "dtower.h"
#include"player.h"
int DTower::_cost=500;

int DTower::_firerate=1000/*ms*/;
DTower::DTower(int x, int y, int cb, int mb,  int range, int degree, int attack)
{
    this->d_posx=x;
    this->d_posy=y;
    this->_currentBlood=cb;
    this->_maxBlood=mb;
    this->_range=range;
    this->_degree=degree;
    this->_attack=attack;
    Player::dollarMinus();
    this->_image.load(":/image/tower.jpg");
}
bool DTower::canBuy(){
    if(Player::Getdollar()>=_cost)
        return true;
    else return false;
}
void DTower::show(QPainter *pa){
    pa->setPen(QPen(Qt::red));
    int x,y;
    x=this->d_posx-this->_range/2+towerPosition::getWidth()/2;
    y=this->d_posy-this->_range/2+towerPosition::getHeight()/2;
    pa->drawEllipse(x,y,this->_range,this->_range);
    pa->drawText(QRect(this->d_posx-20,this->d_posy-20,100,20),QString("%1/%2").arg(this->_currentBlood).arg(this->_maxBlood));
    pa->drawPixmap(this->d_posx,this->d_posy,50,50,this->_image);
}
void DTower::updating(){
    if(this->_degree==1){
        this->_degree++;
        this->_range+=100;
        this->_maxBlood+=1000;
        this->_currentBlood=this->_maxBlood;
        Player::diamondMinus();
        this->_image.load(":/image/towerx.jpg");
    }
    else if(this->_degree==2){
        this->_degree++;
        this->_attack+=150;
        this->_maxBlood+=1000;
        this->_currentBlood=this->_maxBlood;
        Player::diamondMinus();
        this->_image.load(":/image/Towerz.jpg");
    }
}
