#include "player.h"
#include"dtower.h"

Player::Player()
{

}
int Player::_diamond=500;
int Player::_dollar=1000;
void Player::dollarMinus(){
    _dollar-=DTower::getCost();
}
