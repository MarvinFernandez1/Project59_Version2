#ifndef SETTER_H
#define SETTER_H
#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

class Setter : public Skill {
    public:
    Setter();
    int attemptServe();
    int attemptDig ();
    int attemptSet ();
    int attemptSpike ();
};
#endif //SETTER_H
