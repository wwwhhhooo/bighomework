#include "world2.h"
#include<iostream>
#include<QMediaPlayer>
#include<QMediaPlaylist>
World2::World2():World1()
{

}
World2::~World2(){
    vector<towerPosition*>::iterator it;
    it=this->pos.begin();
    while (it!=this->pos.end()) {
        delete (*it);
        it=this->pos.erase(it);
    }
}
void World2::initWorld(){
    towerPosition* pos1=new towerPosition(100,100);
    towerPosition* pos2=new towerPosition(400,100);
    towerPosition* pos3=new towerPosition(700,100);
    towerPosition* pos4=new towerPosition(250,220);
    towerPosition* pos5=new towerPosition(550,220);
    towerPosition* pos6=new towerPosition(250,340);
    towerPosition* pos7=new towerPosition(550,340);
    towerPosition* pos8=new towerPosition(100,460);
    towerPosition* pos9=new towerPosition(400,460);
    towerPosition* pos10=new towerPosition(700,460);
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
    QMediaPlaylist*playlist=new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/sound/PVP.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer*player=new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(50);
    player->play();
}
