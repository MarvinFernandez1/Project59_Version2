#include <iostream>
#include <string>
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
    Player* P1 = new Digger("Michael",0, "Digger", 92, 93, 93 ,20);
    Player* P2 = new Setter("Kien",3,"Setter",93,93,60,93);
    Player* P3 = new Spiker("Jokic",5,"Spiker",93,93,93,93);
    Player* P4 = new Digger("Lebron",1,"Digger",93,62,93,93);
    Player* P5 = new Spiker("Wilt",2,"Spiker",93,93,93,93);
    Player* P6 = new Spiker("Marvin",4,"Spiker",93,93,93,93);


    // create team
    Team t1("Bin Chickens");
    Team* userTeam = &t1;

    t1.addPlayer(P1);
    t1.addPlayer(P2);
    t1.addPlayer(P3);
    t1.addPlayer(P4);
    t1.addPlayer(P5);
    t1.addPlayer(P6);   // NEED TO CHECK THAT 6 PLAYERS ARE ON A TEAM -- FOR 0-5 check for nullptr, if so, unable to run simulation
    t1.addPlayer(P2);   // shows that only 6 players can be added to a team
    

    // prepare game
    Game round1(10,"hard");
    round1.createOpposingTeam();  
    round1.Start_game(userTeam);

    // simulate game
    round1.play();


    
    // delete players
    delete P1;
    delete P2;
    delete P3;
    delete P4;
    delete P5;
    delete P6;


    return 0;
    
    /*
    if(player.attemptServe())   {
    cout << player.get_name() << " wins!" << endl;
    }
    else(
        cout << player.get_name() << " loses!" << endl;
    )
    */
}