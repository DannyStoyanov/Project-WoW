#ifndef DRAGONKIN_H
#define DRAGONKIN_H
#include "monster.h"
class Dragonkin:virtual public Monster{
private:
    short specialDefence;
public:
    Dragonkin(string = "");
    Dragonkin(const Dragonkin&);
    ~Dragonkin();
    Dragonkin& operator=(const Dragonkin&);

    bool isNextDefenceSpecial() const;
    virtual double Attack();
    virtual double Defend();
    void print() const;
};

#endif // DRAGONKIN_H
