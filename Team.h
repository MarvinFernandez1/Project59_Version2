#ifndef TEAM_H
#define TEAM_H
#include <iostream> 
#include <string>
using namespace std;

class Team {
    protected: // added to branch 2 to test
    Player** squad;
    int numPlayers;
    int index;
    string name;

    public:
    Team(string name);
    bool addPlayer(Player* playerInput);
    void teamStats();
    ~Team();
};
#endif