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
    Player* P6 = new Spiker("Shaq",4,"Spiker",2,1,1,94);


    // create team
    Team binChickens;

    binChickens.addPlayer(P1);
    binChickens.addPlayer(P2);
    binChickens.addPlayer(P3);
    binChickens.addPlayer(P4);
    binChickens.addPlayer(P5);
    binChickens.addPlayer(P6);
    

    // start game
    //Game round1(5,"easy");




    //

    // delete players
    delete P1;
    delete P2;
    delete P3;
    delete P4;
    delete P5;
    delete P6;


    cout << "Let the battle begin!" << endl;
    
    /*
    if(player.attemptServe())   {
    cout << player.get_name() << " wins!" << endl;
    }
    else(
        cout << player.get_name() << " loses!" << endl;
    )
    */
}