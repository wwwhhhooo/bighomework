#include "dtower.h"
#include"player.h"
int DTower::_cost=500;
int DTower::_attack=300;
int DTower::_firerate=1000/*ms*/;
DTower::DTower(int x, int y, int cb, int mb,  int range)
{
    this->d_posx=x;
    this->d_posy=y;
    this->_currentBlood=cb;
    this->_maxBlood=mb;
    this->_range=range;
    Player::dollarMinus();
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
}
