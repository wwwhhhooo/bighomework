#include "enemy.h"
#include"dtower.h"
#include<player.h>
int Enemy::enemyCount=0;
int Enemy::enemyProduce=0;
int Enemy::_indiamond=250;
int Enemy::_indollar=400;
Enemy::Enemy()
{
    enemyCount++;
    enemyProduce++;
}
void Enemy::enemyShow(QPainter *pa){
    pa->setPen(QPen(Qt::red));
    pa->drawText(QRect(this->e_posx-15,this->e_posy-20,100,20),QString("%1/%2").arg(this->_blood).arg(this->mblood));
    this->e_image.load(":/image/enemy.jpg");
    pa->drawPixmap(this->e_posx,this->e_posy,50,50,this->e_image);
}
void Enemy::move(){
    this->e_posx=this->e_posx-1;
}
void Enemy::set(int x, int y, int blood){
    this->e_posx=x;
    this->e_posy=y;
    this->_blood=blood;
    this->mblood=blood;
}
void Enemy::onAttack(int attack){
    this->_blood-=attack;
}
bool Enemy::die(){
    if(this->_blood<=0){
        enemyCount--;
        Player::diamondPlus();
        Player::dollarPlus();
        return true;
    }
    else return false;
}
