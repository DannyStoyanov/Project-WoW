#ifndef GOBLIN_H
#define GOBLIN_H
#include "monster.h"
class Goblin:virtual public Monster{
public:
    Goblin(string = "");
    Goblin(const Goblin&);
    ~Goblin();
    Goblin& operator=(const Goblin&);

    virtual double Attack();
    virtual double Defend();
    void print() const;
};

#endif // GOBLIN_H
