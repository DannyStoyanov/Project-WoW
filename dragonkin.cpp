#include "dragonkin.h"
Dragonkin::Dragonkin(string nameData):Monster(nameData,30,1,1){
    this->specialDefence=0;
}
Dragonkin::Dragonkin(const Dragonkin& other):Monster(other){
    this->specialDefence=other.specialDefence;
};
Dragonkin& Dragonkin::operator=(const Dragonkin & other){
    if(this!=&other){
         Monster::operator=(other);
         this->specialDefence=other.specialDefence;
    }
    return *this;
}
Dragonkin::~Dragonkin(){}

bool Dragonkin::isNextDefenceSpecial() const{
    if(specialDefence==3)return true;
    else return false;
}

double Dragonkin::Attack(){
double damage=8;
return damage;
}
double Dragonkin::Defend(){
    this->specialDefence++;
    double defence=this->getHp();
    if(isNextDefenceSpecial()){
        defence=defence+100;
        specialDefence=0;
    }
    return defence;
}
void Dragonkin::print() const{
    Monster::print();
    if(isNextDefenceSpecial())cout<<"Is next defence special:"<<"Yes"<<endl<<endl;
    else cout<<"Is next defence special:"<<"No"<<endl<<endl;
}
