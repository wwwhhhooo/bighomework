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
    void onAttack();
    int getBlood(){return this->_blood;}
    void enemyShow(QPainter*pa);
    virtual void move();
    virtual void set(int x, int y,int blood=5000);
    static int getCount(){return enemyCount;}//��Ϸ���е�����
    static int getProduce(){return enemyProduce;}//��Ϸ���ܹ������ĵ�����
    static int getdollar(){return _indollar;}//ɱ�����˻�õĽ����
    static int getdiamond(){return _indiamond;}//ɱ�����˻�õ���ʯ��
    int getX(){return this->e_posx;}
    int getY(){return this->e_posy;}
    bool die();
protected:
    int _blood,_velocity,_updaterate;
    static int enemyCount,enemyProduce,_indollar,_indiamond;
    int e_posx,e_posy;
    QPixmap e_image;



};

#endif // ENEMY_H
