#include "emybullet.h"

EmyBullet::EmyBullet(int sx, int sy,int ex,int ey,bool hasmove):Bullet(sx,sy,ex,ey,hasmove){}

void EmyBullet::show(QPainter *pa){
    pa->setPen(QPen(Qt::black));
    pa->setBrush(QBrush(Qt::black));
    pa->drawEllipse(this->dx,this->dy,20,20);
}
