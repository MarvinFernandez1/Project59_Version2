#include <iostream> 
#include <string>
#include "Setter.h"
using namespace std;

Setter::Setter () {
    this->serveAbility = serveAbility;
    this->digAbility = digAbility;
    this->setAbility = setAbility;
    this->spikeAbility = spikeAbility;
}

bool Setter::attemptDig () {
        
    // create array of probability
    int digArray[100] = {0};
    int digSkill = digAbility;
    for(int i = 0; i < digSkill - 1; i++) {
        digArray[i] = 1;
    }

    // generate a rand num between 0-99
    int randomNum = rand() % 100;

    // determine if sucessful
    if(digArray[randomNum] == 1) {
        set_attemptDigs(get_attemptDigs()+1);
        set_successfulDigs(get_attemptDigs()+1);
        return true;
    }
    
    if(digArray[randomNum] == 0)  {
        set_attemptDigs(get_attemptDigs()+1);
        return false;
    }

}
//
bool Setter::attemptSet () {
// create array of probability
    int setArray[100] = {0};
    //Setters receive a +5 bonus out of 100 for setAbility
    int setSkill = setAbility+5;
    for(int i = 0; i < setSkill - 1; i++) {
        setArray[i] = 1;
    }

    // generate a rand num between 0-99
    int randomNum = rand() % 100;

    // determine if sucessful
    if(setArray[randomNum] == 1) {
        set_attemptSets(get_attemptSets()+1);
        set_successfulSets(get_attemptSets()+1);
        return true;
    }
    
    if(setArray[randomNum] == 0)  {
        set_attemptSets(get_attemptSets()+1);
        return false;
    }

}
bool Setter::attemptSpike () {
// create array of probability
    int spikeArray[100] = {0};
    int spikeSkill = spikeAbility;
    for(int i = 0; i < spikeSkill - 1; i++) {
        spikeArray[i] = 1;
    }

    // generate a rand num between 0-99
    int randomNum = rand() % 100;

    // determine if sucessful
    if(spikeArray[randomNum] == 1) {
        set_attemptSpikes(get_attemptSpikes()+1);
        set_successfulSpikes(get_attemptSpikes()+1);
        return true;
    }
    
    if(spikeArray[randomNum] == 0)  {
        set_attemptSpikes(get_attemptSpikes()+1);
        return false;
    }

}