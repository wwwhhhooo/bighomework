#ifndef EMYBULLET_H
#define EMYBULLET_H

#include"bullet.h"

class EmyBullet:public Bullet
{
public:
    EmyBullet(int sx, int sy,int ex,int ey,bool hasmove=false);
    void show(QPainter*pa);
};

#endif // EMYBULLET_H
