#ifndef SPIKER_H
#define SPIKER_H
#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

class Spiker : public Skill {
    public:
    Spiker ();
    int attemptDig ();
    int attemptSet ();
    int attemptSpike ();
};
#endif //SPIKER_H