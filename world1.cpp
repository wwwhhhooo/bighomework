#include "world1.h"
#include<iostream>
#include<QMediaPlayer>

World1::World1()
{

}
void World1::initWorld1(){
    towerPosition pos1(100,100);
    towerPosition pos2(160,100);
    towerPosition pos3(220,100);
    towerPosition pos4(280,100);
    towerPosition pos5(100,220);
    towerPosition pos6(160,220);
    towerPosition pos7(220,220);
    towerPosition pos8(280,220);
    this->pos.push_back(pos1);
    this->pos.push_back(pos2);
    this->pos.push_back(pos3);
    this->pos.push_back(pos4);
    this->pos.push_back(pos5);
    this->pos.push_back(pos6);
    this->pos.push_back(pos7);
    this->pos.push_back(pos8);
    QMediaPlayer*player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/battle.mp3"));
    player->setVolume(50);
    player->play();

}
void World1::show(QPainter *painter){
    int n=this->pos.size();
    for(int i=0;i<n;i++){
        this->pos[i].show(painter);
    }
}
