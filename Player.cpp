#include <iostream> 
#include <string>
#include "Player.h"
using namespace std;


//Getting Variables

//Default Constructor
Player::Player () {
    this->name = "No Name";
    this->startPosition = "No Position";
    this->role = "No Role";
}

//Set Contructor
Player::Player (string name, int startPosition, string role) {
    this->name = name;
    this->startPosition = startPosition;
    this->role = role;
}

string Player::get_name() {return name;}
string Player::get_startPosition () {return startPosition;}
string Player::get_role () {return role;}

//Setting Variables
void Player::set_startPosition(string startPsition) {
    this->startPosition = startPosition;
}
void Player::set_role(string role) {
    this->role = role;
}

//Destructor for Player
Player::~Player() {}

