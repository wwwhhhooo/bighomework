#ifndef BULLET_H
#define BULLET_H
#include<QPainter>
#include<QPropertyAnimation>
class Bullet
{
public:
    Bullet(int sx, int sy,int ex,int ey,bool hasmove=false);
    void move();
    virtual void show(QPainter*pa);
    bool ifmove()const {return this->_hasmove;}
protected:
    int _sx,_sy,_ex,_ey,dx,dy;
    bool _hasmove;
};

#endif // BULLET_H
