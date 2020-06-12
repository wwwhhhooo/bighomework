#include "enemyx.h"

EnemyX::EnemyX():Enemy()
{

}
void EnemyX::move(){
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
void EnemyX::set(int x, int y, int blood){
    this->e_posx=x;
    this->e_posy=y;
    this->_blood=blood;

}
