#include <iostream> 
#include <string>
#include "Team.h"
using namespace std;

// default constructor 
Team::Team()    {
    this->numPlayers = 5;
    this->squad = new Player*[numPlayers];
    this->index = 0;
    this->name = "NULL";
}

Team::Team(string name)    {
    this->numPlayers = 5;
    this->squad = new Player*[numPlayers];
    this->index = 0;
    this->name = name;
}

int Team::getIndex()    {
    return index;
}

bool Team::addPlayer(Player* playerInput)   {
    if(index <= numPlayers)  {
        squad[index] = playerInput;
        index++;
        cout << playerInput->get_name() << " added to the lineup!" << endl;
        return true;
    }
    return false;
}

Player* Team::getPlayer(int index)  {
    if (index >= 0 && index < numPlayers) {
        return squad[index];
    }
    return nullptr;
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

// Team destructor
Team::~Team() {
    for (int i = 0; i < numPlayers; i++) {
        delete squad[i];
    }
    delete[] squad;
}

// \\ bool Clinic::add_cage(Cage new_cage){
//  \\    Clinic clinicCages;
//   \\   for (int k=0;k<clinicSize;k++){
//    \\    if (cages[k].name=="" && cages[k].number==0){
//     \\        cages[k].name=new_cage.name;
//      \\         cages[k].number=new_cage.number;
//       \\       break;
//      \\    }
//     \\     else (cages[k].name!="" && cages[k].number!=0);{
//    \\          return 0;
//   \\       }
//  \\   }
// \\    return 1;
//}