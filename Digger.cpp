#include <iostream> 
#include <string>
#include "Digger.h"
using namespace std;

Digger::Digger () {
    this->serveAbility = serveAbility;
    this->digAbility = digAbility;
    this->setAbility = setAbility;
    this->spikeAbility = spikeAbility;
}
//Diggers receive a +5 bonus out of 100 for digAbility
int Digger::attemptDig () {
    this->digAbility+5;
}
int Digger::attemptSet () {

}
int Digger::attemptSpike () {

}