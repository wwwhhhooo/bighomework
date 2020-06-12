#include "world2.h"
#include<iostream>
#include<QMediaPlayer>
World2::World2():World1()
{

}
void World2::initWorld(){
    towerPosition pos1(100,100);
    towerPosition pos2(400,100);
    towerPosition pos3(700,100);
    towerPosition pos4(250,220);
    towerPosition pos5(550,220);
    towerPosition pos6(250,340);
    towerPosition pos7(550,340);
    towerPosition pos8(100,460);
    towerPosition pos9(400,460);
    towerPosition pos10(700,460);
    this->pos.push_back(pos1);
    this->pos.push_back(pos2);
    this->pos.push_back(pos3);
    this->pos.push_back(pos4);
    this->pos.push_back(pos5);
    this->pos.push_back(pos6);
    this->pos.push_back(pos7);
    this->pos.push_back(pos8);
    this->pos.push_back(pos9);
    this->pos.push_back(pos10);
    QMediaPlayer*player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/PVP.mp3"));
    player->setVolume(50);
    player->play();
}
