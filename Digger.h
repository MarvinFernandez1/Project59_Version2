#ifndef DIGGER_H
#define DIGGER_H
#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

class Digger : public Skill {
    public:
    Digger();
    int attemptServe();
    int attemptDig ();
    int attemptSet ();
    int attemptSpike ();
};
#endif //DIGGER_H