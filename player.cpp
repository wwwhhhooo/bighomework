#include "player.h"
#include"dtower.h"
#include"enemy.h"

Player::Player()
{

}
int Player::_diamond=500;
int Player::_dollar=1500;
void Player::dollarMinus(){
    _dollar-=DTower::getCost();
}
void Player::dollarPlus(){
    _dollar+=Enemy::getdollar();
}
void Player::diamondPlus(){
    _diamond+=Enemy::getdiamond();
}
void Player::diamondMinus(){
    _diamond-=600;
}
void Player::sell(){
    _dollar+=250;
}
