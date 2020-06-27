#include "player.h"
#include <string>
int Player::numberOfPlayers = 0;
void Player::copyPlayer(Hero* heroData, string nickData, string passData){
    this->hero=heroData;
    this->nickname=nickData;
    this->password=passData;
}
Player::Player(){
    this->nickname="";
    this->password="";
    numberOfPlayers++;
}
Player::Player(Hero* heroData, string nickData, string passData){
    copyPlayer(heroData,nickData,passData);
    numberOfPlayers++;
}
Player::Player(const Player& other){
    copyPlayer(other.hero,other.nickname,other.password);
}
Player::~Player(){
    numberOfPlayers--;
}
Player& Player::operator=(const Player & other){
    if(this!=&other){
        copyPlayer(other.hero,other.nickname,other.password);
    }
    return *this;
}
Hero* Player::getHero() const{
    return hero;
}
void Player::setHero(Hero* heroData){
    this->hero=heroData;
}
void Player::setNickname(string nicknameData){
    nickname=nicknameData;
}
void Player::setPassword(string passData){
    password=passData;
}
string Player::getNickname() const{
    return nickname;
}
string Player::getPassword() const{
    return password;
}
