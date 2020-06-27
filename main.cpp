#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <istream>
#include <iomanip>
#include <cstring>
#include "race.h"
#include "hero.h"
#include "warrior.h"
#include "mage.h"
#include "paladin.h"
#include "goblin.h"
#include "dragonkin.h"
#include "deathknight.h"
#include "player.h"
using namespace std;
const int MAX_SIZE= rand() % 5 +  3; // using it for map colums and rows
const int MAX_SIZE_COLUMNS=MAX_SIZE;
const int MAX_SIZE_ROWS=MAX_SIZE;
int getFileLength(string fileName){
    int size;
    char symbol;
    int counter=0;
    fstream tempFile(fileName,ios::in);
    while(!tempFile.eof()){
        tempFile.get(symbol);
        if(symbol=='\n')counter++; // getting size of the player's list registered
    }
    size=counter;
    tempFile.close();
    return size-1;
}
void safeProgress(string fileName,string fileName2, Player& player){
    // need rework, isnt working properly!
    fstream f1(fileName, ios::in);
    fstream f2(fileName2, ios::out);
    int size = getFileLength(fileName);
    string tempData;
    double tepmNumb;
    for (int i=0;i<size;i++) {
        f1>>tempData;
        if(tempData==player.getNickname()){
            f2<<player.getNickname()<<" "<<player.getPassword()<<" "<<player.getHero()->getName()<<" "<<player.getHero()->getCurrentHp()<<" "<<player.getHero()->getStrength()<<" "<<player.getHero()->getIntellect()<<" "<<player.getHero()->getLevel()<<'\n';
        }
        else {
            f2<<tempData<<" ";
            f1>>tempData;
            f2<<tempData<<" ";
            for(int i=0;i<6;i++){
            f1>>tepmNumb;
            f2<<tepmNumb<<" ";
            }
            f2<<'\n';
        }
    }
    f1.close();
    f2.close();
}
void printAllHeroes(string fileName){
    //Player tempPlayer;
    int size=getFileLength(fileName);
    fstream tempFile(fileName,ios::in);
    string tempTextData;
    double tempNumbData;
    cout<<"O^----- Heroes*List -----^O" <<endl;
    for (int i=0;i<size;i++) {
         tempFile>>tempTextData;
         cout<<"Owner:"<<tempTextData<<endl;
         tempFile>>tempTextData;
         tempFile>>tempTextData;
         cout<<"Hero's name:"<<tempTextData<<endl;
         tempFile>>tempNumbData;
         cout<<"Current hp:"<<tempNumbData<<endl;
         tempFile>>tempNumbData;
         cout<<"Strength:"<<tempNumbData<<endl;
         tempFile>>tempNumbData;
         cout<<"Intellect:"<<tempNumbData<<endl;
         tempFile>>tempNumbData;
         cout<<"Level:"<<tempNumbData<<endl;
    cout<<"-------- oooo*oooo --------" <<endl;
    }
}
void setPlayer(string fileName, Player& currPlayer){
    int size=getFileLength(fileName);
    string tempNick,tempPass,tempTextData;
    double tempNumbData;
    fstream tempFile(fileName,ios::in);
    for(int i=0;i<size*6;i++){
        tempFile>>tempNick;
        if(tempNick==currPlayer.getNickname()){
            tempFile>>tempPass;
            if(tempPass==currPlayer.getPassword()){
                tempFile>>tempTextData;
                currPlayer.getHero()->setName(tempTextData);
                tempFile>>tempNumbData;
                currPlayer.getHero()->setCurrentHp(tempNumbData);
                tempFile>>tempNumbData;
                currPlayer.getHero()->setStrength(tempNumbData);
                tempFile>>tempNumbData;
                currPlayer.getHero()->setIntellect(tempNumbData);
                tempFile>>tempNumbData;
                currPlayer.getHero()->setLevel((int)tempNumbData);
                break;
            }
        }
    }
    tempFile.close();
}
bool isGameOver(Monster*** arr){
    for (int i=0;i<MAX_SIZE;i++) {
        for (int j=0;j<MAX_SIZE;j++) {
            if(arr[i][j]!=nullptr)return false; // nullptr means no monster on the current place
        }
    }
    return true;
}
void printAllPlayers(string fileName){
    string tempNick,tempData;
    int size=getFileLength(fileName);
    fstream tempFile(fileName,ios::in);
    cout<<"O^----- Player*List -----^O" <<endl;
    for(int i=0;i<size;i++){
        tempFile>>tempNick;
        cout<<"Nick:"<<tempNick<<endl;
        for(int i=0;i<6;i++)
            tempFile>>tempData; // skipping player's password,hero's name,hp,strength,intellect and level
    }
    cout<<"O^------ oooo*oooo ------^O" <<endl;
    tempFile.close();
}
void printMap(Monster*** arr){
    for (int i=0;i<MAX_SIZE;i++) {
        for (int j=0;j<MAX_SIZE;j++) {
            if(arr[i][j]==nullptr){
                cout<<setw(15)<<"---------"<<" ";
            }
            else{
                 cout<<setw(15)<<arr[i][j]->getName()<<" "; // Printing Monster's name on the current place
            }
        }
        cout<<endl;
    }
}
void printMainMenu(){
    system("cls");
    cout <<setw(0)<< "O^-------- Main*Menu --------^O" <<endl;
    cout <<setw(0)<< "|)   (1): Create account     |)" <<endl;
    cout <<setw(0)<< "(|   (2): Log in             (|" <<endl;
    cout <<setw(0)<< "|)   (3): Play               |)" <<endl;
    cout <<setw(0)<< "(|   (4): Print all Heroes   (|" <<endl;
    cout <<setw(0)<< "|)   (5): Show hero's info   |)" <<endl;
    cout <<setw(0)<< "(|   (6): Show all players   (|" <<endl;
    cout <<setw(0)<< "(|   (7): Exit               (|" <<endl;
    cout <<setw(0)<< "O^-------- oooo*oooo --------^O" <<endl;
}
bool isCorrectMove(int pos[2]){
    return ((pos[0]>=0)&&(pos[0]<MAX_SIZE)&&(pos[1]>=0)&&(pos[1]<MAX_SIZE));
}
void Update(Monster*** arr,int pos[2]){
    printMap(arr);
    cout<<"|)---------------------------(|"<<endl;
    cout<<"(|Your are on position:["<<pos[0]<<"]["<<pos[1]<<"]|)"<<endl;
    cout<<"|)---------------------------(|"<<endl;
    cout <<setw(0)<< "O^------ Actin ------^O" <<endl;
    cout <<setw(0)<< "|)    (1): Up        |)" <<endl;
    cout <<setw(0)<< "(|    (2): Down      (|" <<endl;
    cout <<setw(0)<< "|)    (3): Left      |)" <<endl;
    cout <<setw(0)<< "(|    (4): Right     (|" <<endl;
    cout <<setw(0)<< "|)    (5): Exit      |)" <<endl;
    cout <<setw(0)<< "O^------ oo*oo ------^O" <<endl;
}
bool isCorrectLogIn(string fileName,string nameData, string passData, Player& player){
    int size=getFileLength(fileName);
    string tempNick,tempPass,tempData;
    fstream tempFile(fileName,ios::in);
    for(int i=0;i<size;i++){
        tempFile>>tempNick;
        if(tempNick==nameData){ // checking Name
            tempFile>>tempPass;
            if(tempPass==passData){ // checking Password
                player.setNickname(tempNick);
                player.setPassword(tempPass);
                return true;
            }
            for(int i=0;i<5;i++)
             tempFile>>tempData; // skipping player's hero name, hp, strength, intellect, level
        }
        else{
            tempFile>>tempPass; // skipping player's password
            for(int i=0;i<5;i++)
             tempFile>>tempData; // skipping player's hero name, hp, strength, intellect, level
        }
    }
    cout<<"Wrong name or password!"<<endl;
    system("PAUSE");
    tempFile.close();
    return false;
}
bool isExistingPlayer(string fileName,string nameData){
    string tempNick,tempData;
    int size=getFileLength(fileName);
    fstream tempFile(fileName,ios::in);
    for(int i=0;i<size;i++){
        tempFile>>tempNick;
        if(tempNick==nameData){ //checking Name
            return true;
        }
        else{
            for(int i=0;i<6;i++)
             tempFile>>tempData; // skipping player's hero name, hp, strength, intellect, level
        }
    }
    tempFile.close();
    return false;
}
void newPlayer(){
    Player player;
    system("cls");
    int choise;
    string tempName,tempPass,tempHeroName;
     cout<<"O^------------- Creating*Account --------^O"<<endl;
    cout<<"Name:"<<endl;
    cin>>tempName;
    cout<<"Password:"<<endl;
    cin>>tempPass;
    if(isExistingPlayer("accounts.txt",tempName)==true){ // checking wether the acc exists!
        cout<<"This account already exists! Create new or log in."<<endl;
        return;
    }
    system("cls");
    cout<<"Your hero's name:"<<endl;
    cin>>tempHeroName;
    cout<<"Choose your Hero:"<<endl;
    cout << "(1): Mage" << endl;
    cout << "(2): Warrior" << endl;
    cout << "(3): Paladin" << endl;
    cin>>choise;
    bool correct=false;
    while(!correct){
        if(choise==1){
            player.setHero(new Mage(tempHeroName)); // setting player's hero to be Mage
            player.setNickname(tempName); // setting player's nickname
            player.setPassword(tempPass); // setting player's password
            correct=true;
        } else if(choise==2){
            player.setHero(new Warrior(tempHeroName)); // setting player's hero to be Warrior
            player.setNickname(tempName); // setting player's nickname
            player.setPassword(tempPass); // setting player's password
            correct=true;
        } else if(choise == 3){
            player.setHero(new Paladin(tempHeroName)); // setting player's hero to be Paladin
            player.setNickname(tempName); // setting player's nickname
            player.setPassword(tempPass); // setting player's password
            correct=true;
        }
        else {
            cout<<"ERROR! You have selected an invalid choice. Try again." <<endl;
            cin>>choise;
        }
    }
    fstream tempFile("accounts.txt",ios::app);
    tempFile<<player.getNickname()<<" "<<player.getPassword()<<" "<<player.getHero()->getName()<<" "<<player.getHero()->getCurrentHp()<<" "<<player.getHero()->getStrength()<<" "<<player.getHero()->getIntellect()<<" "<<player.getHero()->getLevel()<<'\n';
    tempFile.close(); // saving player to the database "accounts.txt"

    cout<<"You have created your account successfully!"<<endl;
    cout<<"O^------------- ooooo*ooooo -------------^O"<<endl;
}
void createMap(Monster*** arr){
    // filling our array with Monsters:
    for (int i=0;i<MAX_SIZE;i++) {
        for (int j=0;j<MAX_SIZE;j++) {
            int random= rand() % 4 +  1; // random number between 1-4
            // 1 - Goblin, 2 - Dragonkin, 3 - Death Knight, 4 - nothing, filling our map with them
            switch (random) {
                case 1:{
                    arr[i][j]=new Goblin("Goblin");
                    break;
                }
                case 2:{
                    arr[i][j]=new Dragonkin("Dragonkin");
                    break;
                }
                case 3:{
                    arr[i][j]=new DeathKnight("DeathKnight");
                    break;
                }
                case 4:{
                    arr[i][j]=nullptr;
                    break;
                }
            }
        }
    }
}
bool Battle(Hero& MyHero, Monster& enemy){
    bool isBattleWon=false;
    bool endOfBattle=false;
    while(endOfBattle==false)
        {
            if(MyHero.Attack()>=enemy.Defend()){
               MyHero.killEnemy();
               endOfBattle=true;
               isBattleWon = true;
            }
            else enemy.setHp(enemy.getHp()-MyHero.Attack()); // formula

            if(typeid(enemy)==typeid(Goblin)){ //Goblin is using enemy's characteristic - intellect
                if((enemy.Attack()+0.1*MyHero.getIntellect())>=MyHero.Defend()){
                    endOfBattle=MyHero.isDead();
                    isBattleWon = false;
                }
                else MyHero.setCurrentHp(MyHero.getCurrentHp()-enemy.Attack()+0.1*MyHero.getIntellect()); // formula
            }

            else  {
                if(enemy.Attack()>=MyHero.Defend()){
                    endOfBattle=MyHero.isDead();
                    isBattleWon = false;
                    }
                else MyHero.setCurrentHp(MyHero.getCurrentHp()-enemy.Attack()); // more formules
            }
        }
        return isBattleWon;
}
void game(Player& currPlayer){
    srand(time(NULL));
    // creating array of pointers for our map:
    Monster*** map=new Monster**[MAX_SIZE];
    for (int i=0;i<MAX_SIZE;i++) {
        map[i]=new Monster*[MAX_SIZE];
    }
    createMap(map);
    int choise=0;
    int currentPos[2]; // Player's hero current position
    currentPos[0]=0;
    currentPos[1]=0;
    system("cls");
    Update(map,currentPos);
    cin>>choise;
    while(choise!=5){
        system("cls");
        switch (choise){
        case 1:{
            currentPos[0]--;
            if(isCorrectMove(currentPos)){
                if(map[currentPos[0]][currentPos[1]]==nullptr){
                    cout<<"Empty place, no enemies around!"<<endl;
                }
                else {
                    cout<<"THE BATTLE IS ABOUT TO BEGGIN!"<<endl;
                    if(Battle(*(currPlayer.getHero()),*(map[currentPos[0]][currentPos[1]]))){
                        cout<<"V I C T O R Y !"<<endl;
                        map[currentPos[0]][currentPos[1]]=nullptr;
                    }
                    else{
                        cout<<"D E F E A T !"<<endl<<"GAME OVER!";
                        system("PAUSE");
                        return;
                    }
                }
            }
            else {
                currentPos[0]++;
                cout<<"Incorrect move! "<<currentPos[0]<<","<<currentPos[1]<<endl;
            }
            break;
        }
        case 2:{
            currentPos[0]++;
            if(isCorrectMove(currentPos)){
                if(map[currentPos[0]][currentPos[1]]==nullptr){
                    cout<<"Empty place, no enemies around!"<<endl;
                }
                else {
                    cout<<"THE BATTLE IS ABOUT TO BEGGIN!"<<endl;
                    if(Battle(*(currPlayer.getHero()),*(map[currentPos[0]][currentPos[1]]))){
                        cout<<"V I C T O R Y !"<<endl;
                        map[currentPos[0]][currentPos[1]]=nullptr;
                    }
                    else{
                        cout<<"D E F E A T !"<<endl<<"GAME OVER!";
                        system("PAUSE");
                        return;
                    }
                }
            }
            else{
                currentPos[0]--;
                cout<<"Incorrect move! "<<currentPos[0]<<","<<currentPos[1]<<endl;
            }
            break;
        }
        case 3:{
            currentPos[1]--;
            if(isCorrectMove(currentPos)){
                if(map[currentPos[0]][currentPos[1]]==nullptr){
                    cout<<"Empty place, no enemies around!"<<endl;
                }
                else {
                    cout<<"THE BATTLE IS ABOUT TO BEGGIN!"<<endl;
                    if(Battle(*(currPlayer.getHero()),*(map[currentPos[0]][currentPos[1]]))){
                        cout<<"V I C T O R Y !"<<endl;
                        map[currentPos[0]][currentPos[1]]=nullptr;
                    }
                    else{
                        cout<<"D E F E A T !"<<endl<<"GAME OVER!";
                        system("PAUSE");
                        return;
                    }
                }
            }
            else{
                currentPos[1]++;
                cout<<"Incorrect move! "<<currentPos[0]<<","<<currentPos[1]<<endl;
            }
            break;
        }
        case 4:{
            currentPos[1]++;
            if(isCorrectMove(currentPos)){
                if(map[currentPos[0]][currentPos[1]]==nullptr){
                    cout<<"Empty place, no enemies around!"<<endl;
                }
                else {
                    cout<<"THE BATTLE IS ABOUT TO BEGGIN!"<<endl;
                    if(Battle(*(currPlayer.getHero()),*(map[currentPos[0]][currentPos[1]]))){
                        cout<<"V I C T O R Y !"<<endl;
                        map[currentPos[0]][currentPos[1]]=nullptr;
                    }
                    else{
                        cout<<"D E F E A T !"<<endl<<"GAME OVER!";
                        system("PAUSE");
                        return;
                    }
                }
            }
            else{
                currentPos[1]--;
                cout<<"Incorrect move! "<<currentPos[0]<<","<<currentPos[1]<<endl;
            }
            break;
        }
        case 5:{
            for (int i=0;i<MAX_SIZE;i++) {
                delete[] map[i];
            }
            delete[] map;
            break;
        }
        default:
            std::cout << "ERROR! You have selected an invalid choice." << std::endl;
            break;
        }
        if(isGameOver(map)){
            cout<<"- ! & & & Y O U    W I N & & & ! -"<<endl;
            system("PAUSE");
            for (int i=0;i<MAX_SIZE;i++) {
                delete[] map[i];
            }
            delete[] map;
            return;
        }
        Update(map,currentPos);
        cin>>choise;
    }
}
void mainMenu(Player& currPlayer, string fileName){
    bool isPlayerLogged=false;
    int myChoice = 0;
    printMainMenu();
    while(myChoice!=7){
        cin >> myChoice;
        switch(myChoice)
        {
        case 1:{
            system("cls");
            newPlayer();
            system("PAUSE");
            break;
        }
        case 2:{
            system("cls");
            string tempName,tempPass;
            cout<<"Name:";
            cin>>tempName;
            cout<<"Passwod:";
            cin>>tempPass;
            if(isCorrectLogIn(fileName,tempName,tempPass,currPlayer)){
                setPlayer(fileName, currPlayer);
                cout<<"Logged in successfully!"<<endl;
                isPlayerLogged=true;
                system("PAUSE");
            }
            break;
        }
        case 3:{
            system("cls");
            string tempName,tempPass;
            if(isPlayerLogged!=true){
                cout<<"Name:";
                cin>>tempName;
                cout<<"Passwod:";
                cin>>tempPass;
                if(isCorrectLogIn(fileName,tempName,tempPass,currPlayer)){
                    isPlayerLogged=true;
                    game(currPlayer);
                    //safeProgress(fileName,currPlayer);
                }
            }
            else {
                 game(currPlayer);
                 //safeProgress(fileName,currPlayer);
            }
            printMainMenu();
            break;
        }
        case 4:{
            system("cls");
            printAllHeroes(fileName);
            system("PAUSE");
            printMainMenu();
            break;
        }
        case 5:{
            system("cls");
            cout<<"O^----- Player*Info -----^O" <<endl;
            cout<<"Player:"<<currPlayer.getNickname()<<endl;
            currPlayer.getHero()->print();
            cout<<"O^------ oooo*oooo ------^O" <<endl;
            system("PAUSE");
            break;
        }
        case 6:{
            system("cls");
            printAllPlayers(fileName);
            system("PAUSE");
            break;
        }
        case 7:{
            break;
        }
        default:
            std::cout << "ERROR! You have selected an invalid choice." << std::endl;
            break;
        }
        printMainMenu();
    }
}
int main()
{
    //fstream f("accounts.txt",ios::out);
    //f.close();
    string fileName="accounts.txt";
    Mage guestHero("Mage");
    Player Guest(&guestHero,"Guest","Guest");
    mainMenu(Guest,fileName);
    return 0;
}
