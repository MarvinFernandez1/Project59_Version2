#ifndef SKILL_H
#define SKILL_H
#include <iostream> 
#include <string>
using namespace std;

#include "Player.h"

class Skill : public Player {
    protected:
    //Virtual ability of each skill (out of 100)
    int serveAbility;
    int digAbility;
    int setAbility;
    int spikeAbility;

    public:
    Skill();
    Skill(int serveAbility, int digAbility, int setAbility, int spikeAbility);
    int get_serveAbility ();
    int get_digAbility ();
    int get_setAbility ();
    int get_spikeAbility ();
    void set_serveAbility (int serveAbility);
    void set_digAbility (int digAbility);
    void set_setAbility (int setAbility);
    void set_spikeAbility (int spikeAbility);
    bool attemptServe (int serveAbility);
    virtual bool attemptServe (int serveAbility);
    virtual bool attemptDig (int digAbility);
    virtual bool attemptSet (int setAbility);
    virtual bool attemptSpike (int spikeAbility);

};

#endif