#ifndef WARRIOR_H
#define WARRIOR_H
#include<iostream>
#include "hero.h"
using namespace std;

class Warrior:public Hero{
private:
    short wrath;
    void copyWarrior(short);
    void delWarrior();
public:
    Warrior(string="");
    Warrior(const Warrior&);
    ~Warrior();
    Warrior& operator=(const Warrior&);

    short getWrath() const;
    double Attack();
    double Defend();
    void print() const;
};

#endif // WARRIOR_H
