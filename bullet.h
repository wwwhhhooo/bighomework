#ifndef BULLET_H
#define BULLET_H
#include<QPainter>

class Bullet
{
public:
    Bullet(int x,int y);
    void move(int x,int y);
    void show(QPainter*pa);

private:
    int _x,_y;

};

#endif // BULLET_H
