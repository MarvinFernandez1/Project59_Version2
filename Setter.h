#ifndef SETTER_H
#define SETTER_H
#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

class Setter : public Skill {
    public:
    Setter ();
    bool attemptDig ();
    bool attemptSet ();
    bool attemptSpike ();
};
#endif //SETTER_H