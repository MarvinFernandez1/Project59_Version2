#include <iostream> 
#include <string>
#include <chrono>
#include <thread>
#include "Team.h"
#include "Player.h"
#include "Skill.h"
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

void Team::setIndex(int indexInput)   {
    this->index = indexInput;
}

bool Team::addPlayer(Player* playerInput)   {
    Skill* skill = dynamic_cast<Skill*>(playerInput);
    if (skill->get_serveAbility() >= 0 && skill->get_serveAbility() <= 95 && 
        skill->get_digAbility() >= 0 && skill->get_digAbility() <= 95 && 
        skill->get_setAbility() >= 0 && skill->get_setAbility() <= 95 && 
        skill->get_spikeAbility() >= 0 && skill->get_spikeAbility() <= 95) {
        if(getIndex() < numPlayers+1)  {
            squad[getIndex()] = skill;
            setIndex(getIndex() + 1);
            cout << skill->get_name() << " added to the lineup!" << endl;
            return true;
        }
        cout << "Too Many Players!" << endl;
    }else {
        cout<< "Invalid skill level for " <<skill->get_name() << endl;
    }
    return false;
}

Player* Team::getPlayer(int index)  {
    if (index >= 0 && index <= numPlayers) {
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
    cout << "Team Serve Ability: " << totalServe/5 << endl;
    cout << "Team Dig Ability: " << totalDig/5 << endl;
    cout << "Team Set Ability: " << totalSet/5 << endl;
    cout << "Team Spike Ability: " << totalSpike/5 << endl;
}

// Team destructor
Team::~Team() {
    delete[] squad;
}

void Team::setPlayer(int index, Player* playerSelected)   {
    squad[index] = playerSelected;
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