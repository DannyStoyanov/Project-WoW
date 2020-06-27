#ifndef MAGE_H
#define MAGE_H
#include<iostream>
#include "hero.h"
using namespace std;

class Mage:public Hero{
private:
    short mana;
    void copyMage(short);
    void delMage();
public:
    Mage(string = "");
    Mage(const Mage&);
    ~Mage();
    Mage& operator=(const Mage&);

    short getMana() const;
    double Attack();
    double Defend();
    void print() const;
};

#endif // MAGE_H
