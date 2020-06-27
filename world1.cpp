#include "world1.h"
#include<iostream>
#include<QMediaPlayer>
#include<QMediaPlaylist>


World1::World1()
{

}
World1::~World1(){
    vector<towerPosition*>::iterator it;
    it=this->pos.begin();
    while (it!=this->pos.end()) {
        delete (*it);
        it=this->pos.erase(it);
    }
}
void World1::initWorld(){
    towerPosition* pos1=new towerPosition(100,100);
    towerPosition* pos2=new towerPosition(250,100);
    towerPosition* pos3=new towerPosition(400,100);
    towerPosition* pos4=new towerPosition(550,100);
    towerPosition* pos5=new towerPosition(100,220);
    towerPosition* pos6=new towerPosition(250,220);
    towerPosition* pos7=new towerPosition(400,220);
    towerPosition* pos8=new towerPosition(550,220);
    this->pos.push_back(pos1);
    this->pos.push_back(pos2);
    this->pos.push_back(pos3);
    this->pos.push_back(pos4);
    this->pos.push_back(pos5);
    this->pos.push_back(pos6);
    this->pos.push_back(pos7);
    this->pos.push_back(pos8);
    QMediaPlaylist*playlist=new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/sound/battle.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer*player=new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(50);
    player->play();

}
void World1::show(QPainter *painter){
    int n=this->pos.size();
    for(int i=0;i<n;i++){
        this->pos[i]->show(painter);
    }
}
