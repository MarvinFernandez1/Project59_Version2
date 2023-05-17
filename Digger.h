#ifndef DIGGER_H
#define DIGGER_H
#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

class Digger : public Skill {
    public:
    Digger();
    bool attemptDig ();
    bool attemptSet ();
    bool attemptSpike ();
};
#endif //DIGGER_H