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
//Player(name, starting position, role on team)
    Player* P1 = new Digger("Michael",0, "Digger", 60, 50, 20, 80);
    Player* P2 = new Setter("Kien",3,"Setter",83,76,88,72);
    Player* P3 = new Spiker("Marvin",5,"Spiker",67,23,80,75);
    Player* P4 = new Digger("Lebron",1,"Digger",21,44,23,95);
    Player* P5 = new Spiker("Wilt",2,"Spiker",89,78,40,93);
    Player* P6 = new Spiker("PLAYER6",4,"Spiker",30,30,30,83);


    // create team
    Team t1("Bin Chickens");
    Team* userTeam = &t1;

    t1.addPlayer(P1);
    t1.addPlayer(P2);
    t1.addPlayer(P3);
    t1.addPlayer(P4);
    t1.addPlayer(P5);
    t1.addPlayer(P6);
    t1.addPlayer(P2);
    

    // prepare game
    Game round1(5,"easy");
    round1.createOpposingTeam();  
    round1.Start_game(userTeam); //WHY DOES THIS LINE MAKE THE TERMINAL PAUSE FOR 2 SECONDS BEFORE EXITING? - memory could not be read (SHAQ CANNOT BE READ)

    //

    
    // delete players
    delete P1;
    delete P2;
    delete P3;
    delete P4;
    delete P5;
    delete P6;
    
    
    cout << "Let the battle begin!" << endl;


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