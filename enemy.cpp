#include "enemy.h"
#include"dtower.h"
int Enemy::enemyCount=0;
int Enemy::enemyProduce=0;
Enemy::Enemy()
{
    enemyCount++;
    enemyProduce++;
}
void Enemy::enemyShow(QPainter *pa){
    this->e_image.load(":/image/enemy.png");
    pa->drawPixmap(this->e_posx,this->e_posy,50,50,this->e_image);
}
void Enemy::move(){
    this->e_posx=this->e_posx-1;
}
void Enemy::set(int x, int y, int blood, int indollar, int indiamond){
    this->e_posx=x;
    this->e_posy=y;
    this->_blood=blood;

    this->_indollar=indollar;
    this->_indiamond=indiamond;
}
