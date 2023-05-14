#ifndef PLAYER_H
#define PLAYER_H
#include <iostream> 
#include <string>
using namespace std;

class Player {
    protected:
    //Attributes to get and be set by the user
    string name;
    string startPosition;
    string role;
    int number;
    //Stastics to be measured throughout the game which will be implemented for every player on the court
    int attemptServes;
    int attemptDigs;
    int attemptSets;
    int attemptSpikes;
    int successfulServes;
    int successfulDigs;
    int successfulSets;
    int successfulSpikes;
    
    public:
    //Functions to create the player with their respective name, position and role.
    Player ();
    Player (string name, string startPosition, string role);
    ~Player ();
    string get_name();
    string get_startPosition();
    string get_role();
    void set_startPosition(string startPosition);
    void set_role(string role);

};

#endif // PLAYER_H