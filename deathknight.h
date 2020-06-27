#ifndef DEATHKNIGHT_H
#define DEATHKNIGHT_H
#include "monster.h"
#include "goblin.h"
#include "dragonkin.h"
class DeathKnight:public Goblin, public Dragonkin{
private:
    bool currentAttack;
    // 0 - Goblin's attack, 1 - Dragonkin's attack
public:
    DeathKnight(string = "");
    DeathKnight(const DeathKnight&);
    ~DeathKnight();
    DeathKnight& operator=(const DeathKnight&);

    double Attack();
    double Defend();
    void print() const;
};

#endif // DEATHKNIGHT_H
