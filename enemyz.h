#ifndef ENEMYZ_H
#define ENEMYZ_H

#include"enemy.h"

class Enemyz : public Enemy
{
public:
    Enemyz();
    ~Enemyz(){}
    void set(int x, int y, int blood=7000);
    void move();
    void enemyShow(QPainter*pa);
};

#endif // ENEMYZ_H
