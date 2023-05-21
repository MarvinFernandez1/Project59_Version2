#ifndef SETTER_H
#define SETTER_H
#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

class Setter : public Skill {
    public:
    Setter ();
    Setter(string name, int startPosition, string role, int serveAbility, int digAbility, int setAbility, int spikeAbility);
    bool attemptServe();
    bool attemptDig ();
    bool attemptSet ();
    bool attemptSpike ();
};
#endif //SETTER_H