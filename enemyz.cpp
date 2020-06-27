#include "enemyz.h"

Enemyz::Enemyz()
{

}
void Enemyz::enemyShow(QPainter *pa){
    pa->setPen(QPen(Qt::red));
    pa->drawText(QRect(this->e_posx-15,this->e_posy-20,100,20),QString("%1/%2").arg(this->_blood).arg(this->mblood));
    this->e_image.load(":/image/enemyz.jpg");
    pa->drawPixmap(this->e_posx,this->e_posy,50,50,this->e_image);
}
void Enemyz::move(){
    if(this->e_posx<685&&this->e_posy<220){
        this->e_posx+=2;
    }
    if(this->e_posx>=685&&this->e_posy<280){
        this->e_posy+=2;
    }
    if(this->e_posx>40&&this->e_posy>=280&&this->e_posy<400){
        this->e_posx-=2;
    }
    if(this->e_posx<=40&&this->e_posy<400){
        this->e_posy+=2;
    }
    if(this->e_posy>=400) {
        this->e_posx+=2;
    }
}
void Enemyz::set(int x, int y, int blood){
    this->e_posx=x;
    this->e_posy=y;
    this->_blood=blood;
    this->mblood=blood;
}
