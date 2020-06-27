#include "race.h"
#include "monster.h"
#include<iostream>
#include<string>
Monster::Monster(string nameData, double hpData, double strengthData, double intellectData):Race(nameData,hpData,strengthData,intellectData){

}
Monster::Monster(const Monster& other):Race(other){

}
Monster& Monster::operator=(const Monster &other){
    if(this!=&other){
        Race::operator=(other);
    }
    return *this;
}
Monster::~Monster(){
}
bool Monster::isDead(){
    if(this->getHp()<=0)return true;
    else return false;
}
void Monster::print() const{
    cout<<"Name:"<<(*this).getName()<<endl;
    cout<<"Hp:"<<(*this).getHp()<<endl;
    cout<<"Strength:"<<(*this).getStrength()<<endl;
    cout<<"Intellect:"<<(*this).getIntellect()<<endl;
}
