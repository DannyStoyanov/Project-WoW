#include "race.h"
#include "hero.h"
#include<iostream>
#include<string>
using namespace std;
void Hero::copyHero(unsigned long long lvlData,long long killsData, double currHpData){
    level=lvlData;
    kills=killsData;
    currentHp=currHpData;
}
void Hero::delHero(){

}
Hero::Hero(string nameData, double hpData, double strengthData, double intellectData,unsigned long long lvlData, long long killsData, double strStartPoints, double intStartPoints): Race(nameData,hpData,strengthData,intellectData){
    copyHero(lvlData,killsData,hpData);
    startStrenghtPts=strStartPoints;
    startIntellectPts=intStartPoints;
}
Hero::Hero(const Hero& otherHero): Race(otherHero){
    copyHero(otherHero.level,otherHero.kills,otherHero.currentHp);
    startStrenghtPts=otherHero.startStrenghtPts;
    startIntellectPts=otherHero.startIntellectPts;
}
Hero& Hero::operator=(const Hero & otherHero){
    if(this!=&otherHero){
        Race::operator=(otherHero);
        delHero();
        copyHero(otherHero.level,otherHero.kills,otherHero.currentHp);
    }
    return *this;
}
Hero::~Hero(){
    delHero();
}
bool Hero::isDead(){
    if((*this).getHp()<=0)return true;
    else return false;
}
void Hero::LevelUp(){
    this->setHp(this->getHp()+this->getHp()*0.3);
    this->setCurrentHp(this->getHp());
    this->setStrength(this->getStrength()+this->startStrenghtPts/3);
    this->setIntellect(this->getIntellect()+this->startIntellectPts/3);
    this->level++;
}
void Hero::killEnemy(){
    this->kills++;
    if (this->kills >= pow(2, this->level)) {
        LevelUp();
    }
}
void Hero::setCurrentHp(double currHpData){
    currentHp=currHpData;
}
unsigned long long Hero::getLevel() const{
    return level;
}
long long Hero::getKills() const{
    return kills;
}
double Hero::getCurrentHp() const{
    return currentHp;
}
void Hero::print() const{
    cout<<"Name:"<<(*this).getName()<<endl;
    cout<<"Hp:"<<(*this).getCurrentHp()<<endl;
    cout<<"Strength:"<<(*this).getStrength()<<endl;
    cout<<"Intellect:"<<(*this).getIntellect()<<endl;
    cout<<"Level:"<<(*this).getLevel()<<endl;
    cout<<"Kills:"<<(*this).getKills()<<endl;
}
void Hero::setLevel(int levelData){
    this->level=levelData;
}
