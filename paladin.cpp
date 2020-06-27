#include "paladin.h"

void Paladin::copyPaladin(short attackData){
    powerfulAtt=attackData;
}
void Paladin::delPaladin(){

}
Paladin::Paladin(string nameData):Hero(nameData,100,9,6,0,0,9,6){
    powerfulAtt=0;
}
Paladin::Paladin(const Paladin& otherPaladin): Hero(otherPaladin){
    copyPaladin(otherPaladin.powerfulAtt);
}
Paladin::~Paladin(){
    delPaladin();
}
Paladin& Paladin::operator=(const Paladin & otherPaladin){
    if(this!=&otherPaladin){
        Hero::operator=(otherPaladin);
        delPaladin();
        copyPaladin(otherPaladin.powerfulAtt);
    }
    return *this;
}
bool Paladin::isPowerfulAtt() const{
    if(powerfulAtt==3)return true;
    else return false;
}
double Paladin::Attack(){
    double damage=this->getStrength()*0.5+this->getIntellect()*0.5;
    if(isPowerfulAtt()){
        damage=damage+(damage*50)/100;
        powerfulAtt=0;
    }
    powerfulAtt++;
    return damage;
}
double Paladin::Defend(){
    return this->getCurrentHp();
}
void Paladin::print() const{
    Hero::print();
    if(isPowerfulAtt())cout<<"Is next attack powerful:"<<"Yes"<<endl<<endl;
    else cout<<"Is next attack powerful:"<<"No"<<endl<<endl;
}
