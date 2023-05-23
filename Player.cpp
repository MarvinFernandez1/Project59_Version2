#include <iostream> 
#include <string>
#include "Player.h"
using namespace std;


//Default Constructor
Player::Player () {
    this->name = "No Name";
    this->startPosition = 0;
    this->role = "No Role";
}

//Set Contructor
Player::Player (string name, int startPosition, string role) {
    this->name = name;
    this->startPosition = startPosition;
    this->role = role;
}

//Getting Variables
string Player::get_name() {return name;}
int Player::get_startPosition () {return startPosition;}
string Player::get_role () {return role;}

int Player::get_attemptServes() {return attemptServes;}
int Player::get_attemptDigs() {return attemptDigs;}
int Player::get_attemptSets() {return attemptSets;}
int Player::get_attemptSpikes() {return attemptSpikes;}
int Player::get_successfulServes() {return successfulServes;}
int Player::get_successfulDigs() {return successfulDigs;}
int Player::get_successfulSets() {return successfulSets;}
int Player::get_successfulSpikes() {return successfulSpikes;}

//Setting Variables
void Player::set_startPosition(int startPosition) {
    this->startPosition = startPosition;
}
void Player::set_role(string role) {
    this->role = role;
}
void Player::set_attemptServes (int attemptServes) {
    this->attemptServes = attemptServes;
}
void Player::set_attemptDigs (int attemptDigs) {
    this->attemptDigs = attemptDigs;
}
void Player::set_attemptSets (int attemptSets) {
    this->attemptSets = attemptSets;
}
void Player::set_attemptSpikes (int attemptSpikes){
    this->attemptSpikes = attemptSpikes;
}
void Player::set_successfulServes (int successfulServes) {
    this->successfulServes = successfulServes;
}
void Player::set_successfulDigs (int successfulDigs) {
    this->successfulDigs = successfulDigs;
}
void Player::set_successfulSets (int successfulSets) {
    this->successfulSets = successfulSets;
}
void Player::set_successfulSpikes (int successfulSpikes) {
    this->successfulSpikes = successfulSpikes;
}



