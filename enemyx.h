#ifndef ENEMYX_H
#define ENEMYX_H
#include"enemy.h"

class EnemyX : public Enemy
{
public:
    EnemyX();
    ~EnemyX(){}
    void set(int x, int y, int blood=7000);
    void move();
};

#endif // ENEMYX_H
