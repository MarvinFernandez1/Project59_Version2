#include <iostream> 
#include <string>
#include <random>
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

//Determine 
bool Skill::attemptServe (int serveAbility) {
    
    // create array of probability
    int serveArray[100] = {0};
    int serveSkill = serveAbility;
    for(int i = 0; i < serveSkill - 1; i++) {
        serveArray[i] = 1;
    }

    // generate a rand num between 0-99
    int randomNum = rand() % 100;

    // determine if sucessful
    if(serveArray[randomNum] == 1) {
        set_attemptServes(get_attemptServes()+1);
        set_successfulServes(get_attemptServes()+1);
        return true;
    }
    
    if(serveArray[randomNum] == 0)  {
        set_attemptServes(get_attemptServes()+1);
        return false;
    }

    return false;
}
bool Skill::attemptDig (int digAbility) {
    return 0;
}
bool Skill::attemptSet (int setAbility) {
    return 0;
}
bool Skill::attemptSpike (int spikeAbility) {
    return 0;
}