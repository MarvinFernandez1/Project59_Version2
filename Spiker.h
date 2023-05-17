#ifndef SPIKER_H
#define SPIKER_H
#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

class Spiker : public Skill {
    public:
    Spiker ();
    Spiker(string name, int startPosition, string role, int serveAbility, int digAbility, int setAbility, int spikeAbility);
    bool attemptDig ();
    bool attemptSet ();
    bool attemptSpike ();
};
#endif //SPIKER_H