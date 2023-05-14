#include <iostream> 
#include <string>
#include "Game.h"
using namespace std;

// default constructor 
Game::Game()    {
    this->scoreTeam1 = 0;
    this->scoreTeam2 = 0;
    this->gameOn = false;
    this->oppositionDifficulty = "easy"
    this->winPoints = 1;
}

// set constructor
Game::Game(int winPoints, string oppositionDifficulty)  {
    this->scoreTeam1 = 0;
    this->scoreTeam2 = 0;
    this->gameOn = false;
    this->oppositionDifficulty = oppositionDifficulty;
    this->winPoints = winPoints;
}

// start game - initialise two teams in seperate arrays
void Game::Start_game(Team enteredTeam, Team presetTeam)    {
    this->team1 = enteredTeam;
    this->team2 = presetTeam;
}

// play function - simulates a game by running through sequence of actions
while(scoreTeam1 < winPoints && scoreTeam2 < winPoints) {
    
    // simulate one point
    int servingTeamIndex = 0;   // team 1 scores first
    bool action = true;

    while(action == true) {
        Team* servingTeam = 
    }

}
