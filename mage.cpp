#include "race.h"
#include "hero.h"
#include "mage.h"

void Mage::copyMage(short manaData){
    mana=manaData;
}
void Mage::delMage(){

}
Mage::Mage(string nameData):Hero(nameData,100,4,11,0,0,4,11){
    mana=100;
}
Mage::Mage(const Mage& otherMage): Hero(otherMage){
    copyMage(otherMage.mana);
}
Mage::~Mage(){
    delMage();
}
Mage& Mage::operator=(const Mage & otherMage){
    if(this!=&otherMage){
        Hero::operator=(otherMage);
        delMage();
        copyMage(otherMage.mana);
    }
    return *this;
}
short Mage::getMana() const{
    return mana;
}
double Mage::Attack(){
    double damage = this->getIntellect()+(this->getMana()/100)*3;
    if(mana<=10)mana=0;
    else mana-=10;
    return damage;
}
double Mage::Defend(){
    return this->getCurrentHp();
}
void Mage::print() const{
    Hero::print();
    cout<<"Mana:"<<(*this).getMana()<<endl<<endl;
}
