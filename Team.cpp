#include <iostream> 
#include <string>
#include "Team.h"
using namespace std;

// default constructor 
Team::Team()    {
    this->numPlayers = 6;
    this->squad = new Player*[numPlayers];
    this->index = 0;
    this->name = "NULL";
}

Team::Team(string name)    {
    this->numPlayers = 6;
    this->squad = new Player*[numPlayers];
    this->index = 0;
    this->name = name;
}

bool Team::addPlayer(Player* playerInput)   {
    if(count < numPlayers)  {
        squad[index] = playerInput;
        index++;
        return true;
    }
    return false;
}

void Team::teamStats()  {
    int totalServe = 0, totalSet = 0, totalDig = 0, totalSpike = 0;
    for (int i = 0; i < numPlayers; i++)    {
        totalServe += squad[i]->get_serveAbility();
        totalSet += squad[i]->get_setAbility();
        totalDig += squad[i]->get_digAbility();
        totalSpike += squad[i]->get_spikeAbility();
    }
    cout << "Team Serve Ability: " << totalServe/6 << endl;
    cout << "Team Dig Ability: " << totalDig/6 << endl;
    cout << "Team Set Ability: " << totalSet/6 << endl;
    cout << "Team Spike Ability: " << totalSpike/6 << endl;
}

// check if need to save team
Team::~Team()   {
    delete[] squad;
}