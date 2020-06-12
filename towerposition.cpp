#include "towerposition.h"
#include<iostream>
using namespace std;
int towerPosition::height=50;
int towerPosition::width=50;
towerPosition::towerPosition(int x, int y, bool canplace){
    this->_posX=x;
    this->_posY=y;
    this->_canplace=canplace;

}
void towerPosition::show(QPainter *pa){
    this->_image.load(":/image/TDF.png");
    pa->drawPixmap(this->_posX,this->_posY,width,height,this->_image);

}
bool towerPosition::containmouse(int x,int y){
    bool isXhere=this->_posX<x && x<(this->_posX+width);
    bool isYhere=this->_posY<y&&y<(this->_posY+height);
    return isXhere&&isYhere;
}
