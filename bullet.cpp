#include "bullet.h"
#include"dtower.h"
Bullet::Bullet(int sx, int sy, int ex, int ey, bool hasmove)
{
    this->_sx=sx;
    this->_sy=sy;
    this->_ex=ex;
    this->_ey=ey;
    this->dx=sx;
    this->dy=sy;
    this->_hasmove=hasmove;
}
void Bullet::show(QPainter *pa){
    pa->setPen(QPen(Qt::blue));
    pa->setBrush(QBrush(Qt::blue));
    pa->drawEllipse(this->dx,this->dy,20,20);

}
void Bullet::move(){
    this->dx=this->_ex;
    this->dy=this->_ey;
    this->_hasmove=true;
}
