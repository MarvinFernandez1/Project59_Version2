#include <iostream> 
#include <string>
#include "Skill.h"
using namespace std;

Skill::Skill() {
    this->serveAbility = 0;
    this->digAbility = 0;
    this->setAbility = 0;
    this->spikeAbility = 0;
}
Skill::Skill(int serveAbility, int digAbility, int setAbility, int spikeAbility) {
    this->serveAbility = serveAbility;
    this->digAbility = digAbility;
    this->setAbility = setAbility;
    this->spikeAbility = spikeAbility;
}
int Skill::get_serveAbility () {return serveAbility;}
int Skill::get_digAbility () {return digAbility;}
int Skill::get_setAbility () {return setAbility;}
int Skill::get_spikeAbility () {return spikeAbility;}

void Skill::set_serveAbility (int serveAbility) {
    this->serveAbility = serveAbility;
}
void Skill::set_digAbility (int digAbility) {
    this->digAbility = digAbility;
}
void Skill::set_setAbility (int setAbility) {
    this->setAbility = setAbility;
}
void Skill::set_spikeAbility (int spikeAbility) {
    this->spikeAbility = spikeAbility;
}
bool Skill::attemptServe (int serveAbility) {
    
}
virtual bool attemptDig (int digAbility);
virtual bool attemptSet (int setAbility);
virtual bool attemptSpike (int spikeAbility);