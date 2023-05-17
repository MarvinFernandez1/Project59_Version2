#ifndef DIGGER_H
#define DIGGER_H
#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

class Digger : public Skill {
    public:
    Digger();
    Digger(string name, int startPosition, string role, int serveAbility, int digAbility, int setAbility, int spikeAbility);
    bool attemptDig ();
    bool attemptSet ();
    bool attemptSpike ();
};
#endif //DIGGER_H