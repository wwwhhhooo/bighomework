#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H

#include<QPainter>
#include<QPixmap>



class towerPosition
{
public:
    towerPosition(int x,int y, bool canplace=true);
    bool canPlace() const {return _canplace;}
    void setTower(){this->_canplace=false;}
    void reset(){this->_canplace=true;}
    void show(QPainter*pa);
    bool containmouse(int x,int y);
    int getPosX()const{return this->_posX;}
    int getPosY()const{return this->_posY;}
    static int getHeight(){return height;}
    static int getWidth(){return width;}
private:
    int _posX,_posY;
    bool _canplace;
    static int height,width;
    QPixmap _image;
};

#endif // TOWERPOSITION_H
