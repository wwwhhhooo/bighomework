#ifndef DTOWER_H
#define DTOWER_H
#include<QPainter>
#include"player.h"
#include"world1.h"
#include"enemy.h"
#include<vector>
#include<bullet.h>

using namespace std;
class DTower
{
public:
    DTower(int x, int y, int cb=3000, int mb=3000, int range=200);
    bool isDead(){
        if(this->_currentBlood<=0){
            return true;
        }
        else return false;
    }
    static bool canBuy();
    void die();
    void show(QPainter*pa);
    void setPos(int x,int y){this->d_posx=x;this->d_posy=y;}
    int getx(){return this->d_posx;}
    int gety(){return this->d_posy;}
    static int getCost(){return _cost;}
    static int getAttack(){return _attack;}
    static int getFirerate(){return _firerate;}
    int getRange(){return _range;}

protected:
    int _currentBlood,_maxBlood,_range;
    int d_posx,d_posy;
    static int _cost,_attack,_firerate;
};

#endif // DTOWER_H
