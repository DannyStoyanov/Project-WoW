#include "goblin.h"
Goblin::Goblin(string nameData):Monster(nameData,10,1,1){}
Goblin::Goblin(const Goblin& other):Monster(other){}
Goblin& Goblin::operator=(const Goblin& other){
    if(this!=&other){
        Monster::operator=(other);
    }
    return *this;
}
Goblin::~Goblin(){}

double Goblin::Attack(){
double damage=3;
return damage;
}
double Goblin::Defend(){
return this->getHp();
}
void Goblin::print() const{
    Monster::print();
    cout<<endl;
}
