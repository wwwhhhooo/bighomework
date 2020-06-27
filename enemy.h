#ifndef ENEMY_H
#define ENEMY_H

#include<QPainter>
#include<QPixmap>
#include<QTimerEvent>
class Enemy
{
public:
    Enemy();
    virtual ~Enemy(){}
    void onAttack(int attack);
    int getBlood()const{return this->_blood;}
    virtual void enemyShow(QPainter*pa);
    virtual void move();
    virtual void set(int x, int y,int blood=5000);
    static int getCount(){return enemyCount;}//游戏现有敌人数
    static int getProduce(){return enemyProduce;}//游戏中总共产生的地人数
    static int getdollar(){return _indollar;}//杀死敌人获得的金币数
    static int getdiamond(){return _indiamond;}//杀死敌人获得的钻石数
    int getX()const {return this->e_posx;}
    int getY() const {return this->e_posy;}
    bool die();
protected:
    int _blood,_velocity,_updaterate,mblood;
    static int enemyCount,enemyProduce,_indollar,_indiamond;
    int e_posx,e_posy;
    QPixmap e_image;



};

#endif // ENEMY_H
