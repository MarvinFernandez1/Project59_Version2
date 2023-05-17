#ifndef GAME_H
#define GAME_H
#include <iostream> 
#include <string>
using namespace std;

class Game {
    protected:
    int scoreTeam1;
    int scoreTeam2;
    bool gameOn;
    string oppositionDifficulty;
    int winPoints;
    Team* team1;
    Team* team2;
    
    public:
    Game();
    Game(int winPoints, string oppositionDifficulty);
    void Start_game(Team enteredTeam, Team presetTeam);
    void play();
    void printScore();

    void setScoreTeam1(int scoreTeam1);
    void setScoreTeam2(int scoreTeam2);
    int getScoreTeam1();
    int getScoreTeam2();
};
#endif
