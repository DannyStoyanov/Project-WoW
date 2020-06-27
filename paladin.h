#ifndef PALADIN_H
#define PALADIN_H
#include<iostream>
#include "hero.h"
using namespace std;

class Paladin:public Hero{
private:
    short powerfulAtt;
    void copyPaladin(short);
    void delPaladin();
public:
    Paladin(string = "");
    Paladin(const Paladin&);
    ~Paladin();
    Paladin& operator=(const Paladin&);

    bool isPowerfulAtt() const;
    double Attack();
    double Defend();
    void print() const;
};

#endif // PALADIN_H
