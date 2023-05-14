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
    string get_name();
    string get_startPosition();
    string get_role();

    int get_attemptServes();
    int get_attemptDigs();
    int get_attemptSets();
    int get_attemptSpikes();
    int get_successfulServes();
    int get_successfulDigs();
    int get_successfulSets();
    int get_successfulSpikes();

    void set_attemptServes (int attemptServes);
    void set_attemptDigs (int attemptDigs);
    void set_attemptSets (int attemptSets);
    void set_attemptSpikes (int attemptSpikes);
    void set_successfulServes (int successfulServes);
    void set_successfulDigs (int successfulDigs);
    void set_successfulSets (int successfulSets);
    void set_successfulSpikes (int successfulSpikes);

    void set_startPosition(string startPosition);
    void set_role(string role);

};

#endif // PLAYER_H