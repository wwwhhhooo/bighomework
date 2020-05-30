#ifndef ENEMY_H
#define ENEMY_H

#include<QPainter>
#include<QPixmap>
#include<QTimerEvent>
class Enemy
{
public:
    Enemy();
    void onAttack();
    int getBlood(){return this->_blood;}
    void enemyShow(QPainter*pa);
    void move();
    void set(int x, int y,int blood=1000,int indollar=400,int indiamond=250);
    static int getCount(){return enemyCount;}//��Ϸ���е�����
    static int getProduce(){return enemyProduce;}//��Ϸ���ܹ������ĵ�����
    int getX(){return this->e_posx;}
    int getY(){return this->e_posy;}
protected:
    int _blood,_velocity,_indollar,_indiamond,_updaterate;
    static int enemyCount,enemyProduce;
    int e_posx,e_posy;
    QPixmap e_image;



};

#endif // ENEMY_H
