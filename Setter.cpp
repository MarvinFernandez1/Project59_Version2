#include <iostream> 
#include <string>
#include "Setter.h"
using namespace std;

//Create object setter to use with functions
Setter setter;

Setter::Setter () {
    this->serveAbility = 0;
    this->digAbility = 0;
    this->setAbility = 0;
    this->spikeAbility = 0;
}

Setter::Setter(string name, int startPosition, string role, int serveAbility, int digAbility, int setAbility, int spikeAbility) {
    this->name = name;
    this->startPosition = startPosition;
    this->role = role;
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

    // if dig successful
    if(digArray[randomNum] == 1) {
        set_attemptDigs(get_attemptDigs()+1);
        set_successfulDigs(get_attemptDigs()+1);
        cout << setter.get_name() << " digged successfully!" << endl;
        return true;
    }
    // if dig not successful
    if(digArray[randomNum] == 0)  {
        set_attemptDigs(get_attemptDigs()+1);
        cout << setter.get_name() << " did not dig successfully." << endl;
        return false;
    }
    return false;
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

    // if set successful
    if(setArray[randomNum] == 1) {
        set_attemptSets(get_attemptSets()+1);
        set_successfulSets(get_attemptSets()+1);
        cout << setter.get_name() << " set successfully!" << endl;
        return true;
    }
    // if set not successful
    if(setArray[randomNum] == 0)  {
        set_attemptSets(get_attemptSets()+1);
        cout << setter.get_name() << " did not set successfully." << endl;
        return false;
    }
    return false;
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

    // if spike successful
    if(spikeArray[randomNum] == 1) {
        set_attemptSpikes(get_attemptSpikes()+1);
        set_successfulSpikes(get_attemptSpikes()+1);
        cout << setter.get_name() << " spiked successfully!" << endl;
        return true;
    }
    // if spike not successful
    if(spikeArray[randomNum] == 0)  {
        set_attemptSpikes(get_attemptSpikes()+1);
        cout << setter.get_name() << " did not spike successfully." << endl;
        return false;
    }
    return false;
}