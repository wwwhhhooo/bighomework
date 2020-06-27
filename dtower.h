#ifndef DTOWER_H
#define DTOWER_H
#include<QPainter>
#include"player.h"
#include"world1.h"
#include"enemy.h"
#include<vector>
#include<bullet.h>
#include<QPixmap>

using namespace std;
class DTower
{
public:
    DTower(int x, int y, int cb=3000, int mb=3000, int range=200,int degree=1,int attack=300);
    bool isDead(){
        if(this->_currentBlood<=0){
            return true;
        }
        else return false;
    }
    static bool canBuy();
    void onattack(int a){this->_currentBlood-=a;}
    void show(QPainter*pa);
    void setPos(int x,int y){this->d_posx=x;this->d_posy=y;}
    int getx()const{return this->d_posx;}
    int gety()const{return this->d_posy;}
    static int getCost(){return _cost;}
    int getAttack()const{return this->_attack;}
    static int getFirerate(){return _firerate;}
    int getRange()const{return this->_range;}
    void updating();
    int getdegree()const{return this->_degree;}

private:
    int _currentBlood,_maxBlood,_range;
    int d_posx,d_posy,_degree,_attack;
    QPixmap _image;
    static int _cost,_firerate;
};

#endif // DTOWER_H
