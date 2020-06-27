#include "deathknight.h"

DeathKnight::DeathKnight(string nameData):Monster(nameData), Goblin(nameData), Dragonkin(nameData){
    this->currentAttack=false;
}
DeathKnight::DeathKnight(const DeathKnight& other): Monster(other), Goblin(other),Dragonkin(other){
    this->currentAttack=other.currentAttack;
}
DeathKnight& DeathKnight::operator=(const DeathKnight & other){
    if(this!=&other){
        Goblin::operator=(other);
        Dragonkin::operator=(other);
        this->currentAttack=other.currentAttack;
    }
    return *this;
}
DeathKnight::~DeathKnight(){}

double DeathKnight::Attack(){
    if(!currentAttack){
        return Goblin::Attack();
    }
    else return Dragonkin::Attack();
}
double DeathKnight::Defend(){
    return Dragonkin::Defend();
}
void DeathKnight::print() const{
    Monster::print();
    cout<<endl;
}
