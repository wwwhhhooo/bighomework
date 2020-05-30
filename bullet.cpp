#include "bullet.h"

Bullet::Bullet(int x, int y)
{
    this->_x=x;
    this->_y=y;
}
void Bullet::show(QPainter *pa){
    pa->setPen(QPen(Qt::blue));
    pa->setBrush(QBrush(Qt::blue));
    pa->drawEllipse(this->_x,this->_y,3,3);

}
void Bullet::move(int x, int y){
    this->_x=x;
    this->_y=y;
}
