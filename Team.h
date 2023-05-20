#ifndef TEAM_H
#define TEAM_H
#include <iostream> 
#include <string>
#include "Player.h"
using namespace std;

class Team {
    protected: // added to branch 2 to test
    Player** squad;
    int numPlayers;
    string name;
    int index;

    public:
    Team();
    Team(string name);
    Player* getPlayer(int index);
    bool addPlayer(Player* playerInput);
    void teamStats();
    ~Team();

    int getIndex();
    void setIndex(int indexInput);
    void setPlayer(int index, Player* playerSelected);
};
#endif