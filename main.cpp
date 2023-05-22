#include <iostream>
#include <string>
#include <stdexcept>
#include "Player.h"
#include "Skill.h"
#include "Digger.h"
#include "Setter.h"
#include "Spiker.h"
#include "Team.h"
#include "Game.h"

using namespace std;

int main() {
// Enter Players to Play (name, starting position, role on team, serveSkill, digSkill, setSkill, spikeSkill)
    // skill level is valid between 1 and 95!
    Player* P1 = new Digger("Michael",0, "Digger", 90, 85, 85 ,90);
    Player* P2 = new Spiker("Kien",3,"Spiker",94,92,92,85);
    Player* P3 = new Spiker("Jokic",5,"Spiker",85,85,85,85);
    Player* P4 = new Digger("Lebron",1,"Digger",85,87,85,85);
    Player* P5 = new Spiker("Wilt",2,"Spiker",85,85,85,85);
    Player* P6 = new Setter("Marvin",4,"Setter",85,85,85,85);
    Player* P7 = new Spiker("Joe Biden",4,"Spiker",95,95,95,95);

    // create team name in string
    Team team1("Bin Chickens");
    Team* userTeam = &team1;

    // Players are added to a team (ADD AT LEAST 6 PLAYERS TO A TEAM to simulate)
    team1.addPlayer(P1);
    team1.addPlayer(P2);
    team1.addPlayer(P3);
    team1.addPlayer(P4);
    team1.addPlayer(P5);
    team1.addPlayer(P6);   // Exception Handling to check 6 players must be on a team
    team1.addPlayer(P7);   // shows that only 6 players can be added to a team
    

    // Preparing the Game - 
    Game round1(7,"easy"); // difficulties: easy, medium, hard
    round1.createOpposingTeam();  
    round1.Start_game(userTeam);

    // simulate game
    round1.play();

    // INPUT FROM USER - Do you wish to save your team stats to a file?
    string fileCondition;
    cout << "Do you want to save your game stats? (yes or no)" << endl;
    cin >> fileCondition;

    // show game stats - yes or no
    round1.outputGameStats(fileCondition);

    // delete players to free memory on the heap
    delete P1;
    delete P2;
    delete P3;
    delete P4;
    delete P5;
    delete P6;

    return 0;
    
}