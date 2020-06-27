#ifndef WORLD2_H
#define WORLD2_H
#include"world1.h"
#include"dtower.h"
#include"towerposition.h"
#include<QPainter>
#include<vector>
#include<string>
class World2 : public World1
{
public:
    World2();
    ~World2();
    void initWorld();
};

#endif // WORLD2_H
