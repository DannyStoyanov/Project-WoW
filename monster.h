#ifndef MONSTER_H
#define MONSTER_H
#include<iostream>
#include "race.h"
using namespace std;


class Monster:public Race{
private:

public:
    Monster(string = "", double = 100, double = 1, double = 1);
    Monster(const Monster&);
    Monster& operator=(const Monster&);
    virtual ~Monster();

    bool isDead();
    virtual double Attack() = 0;
    virtual double Defend() = 0;
    void print() const;
};

#endif // MONSTER_H
