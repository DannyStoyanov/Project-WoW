#include "race.h"
#include<iostream>
using namespace std;
void Race::copyRace(string nameData, double hpData, double strengthData, double intellectData){
    name=nameData;
    hp=hpData;
    strength=strengthData;
    intellect=intellectData;
}
void Race::delRace(){

}
Race::Race(string nameData, double hpData, double strengthData, double intellectData){
    copyRace(nameData,hpData,strengthData,intellectData);
}
Race::Race(const Race& otherRace){
    copyRace(otherRace.name,otherRace.hp,otherRace.strength,otherRace.intellect);
}
Race& Race::operator=(const Race & otherRace){
    if(this!=&otherRace){
        delRace();
        copyRace(otherRace.name,otherRace.hp,otherRace.strength,otherRace.intellect);
    }
    return *this;
}
Race::~Race(){
    delRace();
}
void Race::setName(string nameData){
    name=nameData;
}
void Race::setHp(double hpData){
    hp=hpData;
}
void Race::setStrength(double strengthData){
    strength=strengthData;
}
void Race::setIntellect(double intellectData){
    intellect=intellectData;
}
string Race::getName() const{
    return name;
}
double Race::getHp() const{
    return hp;
}
double Race::getStrength() const{
    return strength;
}
double Race::getIntellect() const{
    return intellect;
}


