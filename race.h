#ifndef RACE_H
#define RACE_H
#include<iostream>
using namespace std;

class Race{
private:
    string name;
    double hp;
    double strength;
    double intellect;
    void copyRace(string, double, double, double);
    void delRace();
public:
    Race(string = "", double = 100, double = 0, double = 0);
    Race(const Race&);
    Race& operator=(const Race&);
    virtual ~Race();

    virtual double Attack() = 0;
    virtual double Defend() = 0;

    //friend ostream& operator<<(const ostream&, const Race&);
    void setName(string);
    void setHp(double);
    void setStrength(double);
    void setIntellect(double);
    string getName() const;
    double getHp() const;
    double getStrength() const;
    double getIntellect() const;
};

#endif // RACE_H
