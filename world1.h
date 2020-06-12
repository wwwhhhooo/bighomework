#ifndef WORLD1_H
#define WORLD1_H

#include"dtower.h"
#include"towerposition.h"
#include<QPainter>
#include<vector>
#include<string>

using namespace std;

class World1
{
public:
    World1();
    virtual void initWorld();
    void show(QPainter*painter);
    vector<towerPosition> getPos()const {return this->pos;}
protected:
    vector<towerPosition> pos;

};

#endif // WORLD1_H
