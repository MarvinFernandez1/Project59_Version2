#ifndef GAME_H
#define GAME_H
#include <iostream> 
#include <string>
#include "Team.h"
using namespace std;

class Game {
    protected:
    int scoreTeam1;
    int scoreTeam2;
    bool gameOn;
    string oppositionDifficulty;
    int winPoints;
    
    
    public:
    Team* team1;
    Team* team2;
    Game();
    Game(int winPoints, string oppositionDifficulty);
    ~Game();
    void Start_game(Team* enteredTeam);
    void play();
    void printScore();
    void createOpposingTeam();

    void setScoreTeam1(int scoreTeam1);
    void setScoreTeam2(int scoreTeam2);
    int getScoreTeam1();
    int getScoreTeam2();
};
#endif
