#ifndef PLAYER_H
#define PLAYER_H
#include "hero.h"
class Player{
private:
    Hero* hero;
    string nickname;
    string password;
    void copyPlayer(Hero*,string,string);
public:
    Player();
    Player(Hero*,string,string);
    Player(const Player&);
    ~Player();
    Player& operator=(const Player&);
    Hero* getHero() const;
    void setHero(Hero*);
    void setNickname(string);
    void setPassword(string);
    string getNickname() const;
    string getPassword() const;
    static int numberOfPlayers;
};
#endif // PLAYER_H
