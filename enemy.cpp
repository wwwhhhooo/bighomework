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
    this->e_image.load(":/image/enemy.png");
    pa->drawPixmap(this->e_posx,this->e_posy,50,50,this->e_image);
}
void Enemy::move(){
    this->e_posx=this->e_posx-1;
}
void Enemy::set(int x, int y, int blood){
    this->e_posx=x;
    this->e_posy=y;
    this->_blood=blood;


}
void Enemy::onAttack(){
    this->_blood-=DTower::getAttack();
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
