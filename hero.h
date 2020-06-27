#ifndef HERO_H
#define HERO_H
#include<iostream>
#include "race.h"
using namespace std;

class Hero:public Race{
private:
    unsigned long long level;
    long long kills;
    double currentHp;
    double startStrenghtPts;
    double startIntellectPts;
    void copyHero(unsigned long long, long long, double);
    void delHero();
public:
    Hero(string = "", double = 100, double = 1, double = 1, unsigned long long = 0, long long = 0, double = 1 ,double = 1);
    Hero(const Hero&);
    Hero& operator=(const Hero&);
    virtual ~Hero();

    bool isDead();
    void killEnemy();
    void LevelUp();
    virtual double Attack() = 0;
    virtual double Defend() = 0;

    void setCurrentHp(double);
    void setLevel(int);
    unsigned long long getLevel() const;
    long long getKills() const;
    double getCurrentHp() const;
    void print() const;
};

#endif // HERO_H
