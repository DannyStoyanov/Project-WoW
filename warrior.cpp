#include "race.h"
#include "hero.h"
#include "warrior.h"
void Warrior::copyWarrior(short wrathData){
    wrath=wrathData;
}
void Warrior::delWarrior(){

}
Warrior::Warrior(string nameData): Hero(nameData,100,13,2,0,0,13,2){
    wrath=0;
}
Warrior::Warrior(const Warrior& otherWarrior): Hero(otherWarrior){
    copyWarrior(otherWarrior.wrath);
}
Warrior::~Warrior(){
    delWarrior();
}
Warrior& Warrior::operator=(const Warrior &otherWarrior){
    if(this!=&otherWarrior){
        Hero::operator=(otherWarrior);
        delWarrior();
        copyWarrior(otherWarrior.wrath);
    }
    return *this;
}
short Warrior::getWrath() const{
    return wrath;
}
double Warrior::Attack(){
    double damage=this->getStrength()+this->getIntellect()*0.3;
    wrath+=2;
    return damage;
}
double Warrior::Defend(){
    wrath+=3;
    return this->getCurrentHp();
}
void Warrior::print() const{
    Hero::print();
    cout<<"Wrath:"<<(*this).getWrath()<<endl<<endl;
}


