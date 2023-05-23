#include <iostream> 
#include <string>
#include <cstdlib>  // header for srand() and rand()
#include <ctime>    // header for time()
#include <stdexcept>    // header for exception handling
#include <fstream>
#include "Game.h"
#include "Team.h"
#include "Setter.h"
#include "Spiker.h"
#include "Digger.h"
using namespace std;

// default constructor 
Game::Game()    {
    this->scoreTeam1 = 0;
    this->scoreTeam2 = 0;
    this->gameOn = false;
    this->oppositionDifficulty = "easy";
    this->winPoints = 1; 
    this->team1 = new Team();
    this->team2 = new Team();
}

// set constructor
Game::Game(int winPoints, string oppositionDifficulty)  {
    this->scoreTeam1 = 0;
    this->scoreTeam2 = 0;
    this->gameOn = false;
    this->oppositionDifficulty = oppositionDifficulty;
    this->winPoints = winPoints;
    this->team1 = new Team();
    this->team2 = new Team(); 
}

// destructor
Game::~Game()   {
    delete team1;
    delete team2;
}

// setters and getters
void Game::setScoreTeam1(int scoreTeam1)  {
        this->scoreTeam1 = scoreTeam1;
    }

void Game::setScoreTeam2(int scoreTeam2)  {
        this->scoreTeam2 = scoreTeam2;
    }

int Game::getScoreTeam1()   {return scoreTeam1;}
int Game::getScoreTeam2()   {return scoreTeam2;}

void Game::setOppDifficulty(string diff)    {
    this->oppositionDifficulty = diff;
}

string Game::getOppDifficulty() {
    return oppositionDifficulty;
}

// create opposing team
void Game::createOpposingTeam()  {
    int skillLvl = 0;

try {
    if (getOppDifficulty() == "easy") {
        skillLvl = 55;
    } else if (getOppDifficulty() == "medium") {
        skillLvl = 75;
    } else if (getOppDifficulty() == "hard") {
        skillLvl = 93;
    } else {
        throw std::runtime_error("Invalid input for opposing team difficulty");
    }
} 
catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    std::exit(1);  // Terminate the program
}

    // Create preset players with fixed skill levels
    Player* player1 = new Setter("Opposing Player 1", 0, "Setter", skillLvl, skillLvl, skillLvl, skillLvl);
    Player* player2 = new Digger("Opposing Player 2", 1, "Digger", skillLvl, skillLvl, skillLvl, skillLvl);
    Player* player3 = new Spiker("Opposing Player 3", 2, "Spiker", skillLvl, skillLvl, skillLvl, skillLvl);
    Player* player4 = new Digger("Opposing Player 4", 3, "Digger", skillLvl, skillLvl, skillLvl, skillLvl);
    Player* player5 = new Digger("Opposing Player 5", 4, "Digger", skillLvl, skillLvl, skillLvl, skillLvl);
    Player* player6 = new Spiker("Opposing Player 6", 5, "Spiker", skillLvl, skillLvl, skillLvl, skillLvl);

    // Add the players to the opposing team
    team2->addPlayer(player1);
    team2->addPlayer(player2);
    team2->addPlayer(player3);
    team2->addPlayer(player4);
    team2->addPlayer(player5);
    team2->addPlayer(player6);
}


// start game - initialise two teams in seperate arrays
void Game::Start_game(Team* enteredTeam) {

    // CHECK 6 PLAYERS ON USER TEAM
    try {
        if (enteredTeam->getIndex() != 6)
            throw std::runtime_error("MUST ADD 6 PLAYERS TO USER TEAM TO START GAME!");
    }

    catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    std::exit(1);  // Terminate the program
    }
    
    // add players individually to team1 (ONLY ADD PLAYERS IF not nullptr)
    for (int i = 0; i < 6; i++) {
        if(enteredTeam->getPlayer(i) != nullptr)    {
             team1->addPlayer(enteredTeam->getPlayer(i));
        }
    }

    //list starting Lineup
    cout << "Starting Lineup: " << endl;
    cout << team1->getPlayer(0)->get_name() << "    "  << team1->getPlayer(1)->get_name() << "    " << team1->getPlayer(2)->get_name() << endl;
    cout << team1->getPlayer(5)->get_name() << "    "  << team1->getPlayer(4)->get_name() << "    " << team1->getPlayer(3)->get_name() << endl;

    // list team stats:
    cout << "Team Stats: " << endl;
    team1->teamStats();
}


// play function - simulates a game by running through sequence of actions - NEED TO CHANGE SCORES AFTER ACTION
void Game::play(){ 

std::srand(std::time(0));

while(scoreTeam1 < winPoints && scoreTeam2 < winPoints) {
    
    // set which teams serves first
    int servingTeamIndex = 0;   // team 1 serves first
    int receivingTeamIndex = 1; // team 2 receives first 
    bool action = true;

    while(action == true) {
        // retrieve serving and receiving teams        
        Team* servingTeam = this->team1;
        Team* receivingTeam = this->team2;
        
        // run through actions


        // serve team 1
        if (team1->getPlayer(3)->attemptServe()) {    // change to SERVE
                action = true;
        }
            else {
                setScoreTeam2(getScoreTeam2()+1);
                cout << team1->getPlayer(3)->get_name() << " hit the net!" << endl;
                action = false;
                continue; // Go back to the beginning of the outer loop for the next point
            }

       
        // RALLY
        bool rallyAction = true;
        
        while(rallyAction == true)  {
        // determine setter position of team 1
        int positionSetter1 = 0;
            for(int i=0; i < 6; i++)    {
                if(team1->getPlayer(i)->get_role() == "Setter") {
                    positionSetter1 = i;
                    break;
                }
            }

        // determine where setter is
        int positionSetter2 = 0;
            for(int i=0; i < 6; i++)    {
                if(team2->getPlayer(i)->get_role() == "Setter") {
                    positionSetter2 = i;
                    break;
                }
            }
        
        
        // dig team 2:
        int randomPosition = 0;
            
            // if setter in position 3, 4, 5: (another backcourt player (3, 4, 5) must dig first)
            switch (positionSetter2) {
                case 3: // player 4 or 5 digs 
                    if (team2->getPlayer((rand() % 2) + 4)->attemptDig()) {
                        action = true;
                    }
                    else {
                        setScoreTeam1(getScoreTeam1()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;

                case 4: // player 3 or 5 digs
                    if (team2->getPlayer(((rand() % 2)*2) + 3)->attemptDig()) {
                        action = true;
                    }
                    else {
                        setScoreTeam1(getScoreTeam1()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;

                case 5: // player 3 or 4 digs
                    if (team2->getPlayer((rand() % 2) + 3)->attemptDig()) {
                        action = true;
                    }
                    else {
                        setScoreTeam1(getScoreTeam1()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;
            }            

            // if setter in position 0,1,2 (generate a number between 3,4,5 to decide which backcourt player digs)
            switch (positionSetter2)   {
                case 0: case 1: case 2:     // player 3,4 or 5 digs
                randomPosition = (rand() % 3) + 3;  // need num between 3 and 5
                if(team2->getPlayer(randomPosition)->attemptDig()) {
                    action = true;
                }
                else {
                setScoreTeam1(getScoreTeam1()+1);
                rallyAction = false;
                action = false;
                continue;}
                break;
            }

        // set team 2
        if (team2->getPlayer(positionSetter2)->attemptSet()) {
            action = true;
        }
        else {
            setScoreTeam1(getScoreTeam1()+1);
            rallyAction = false;
            action = false;
            continue; // Go back to the beginning of the outer loop for the next point
        }

        // spike team 2
            // if setter in position 0, 1, 2: (another frontcourt player () must spike first)
            switch (positionSetter2) {
                case 0: // player 1 or 2 spikes
                    if (team2->getPlayer((rand() % 2) + 1)->attemptSpike()) {
                        action = true;
                    }
                    else {
                        setScoreTeam1(getScoreTeam1()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;

                case 1: // player 0 or 2 spikes
                    if (team2->getPlayer(((rand() % 2)*2))->attemptSpike()) {
                        action = true;
                    }
                    else {
                        setScoreTeam1(getScoreTeam1()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;

                case 2: // player 0 or 1 spikes
                    if (team2->getPlayer(rand() % 2)->attemptSpike()) {
                        action = true;
                    }
                    else {
                        setScoreTeam1(getScoreTeam1()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;
            }

            // if setter in position 3, 4, 5: (any frontcourt player () can spike first)
            switch (positionSetter2)    {
                case 3: case 4: case 5:     // player 3,4 or 5 digs
                randomPosition = (rand() % 3);  // need num between 0 and 2
                if(team2->getPlayer(randomPosition)->attemptSpike()) {
                    action = true;
                }
                else {
                setScoreTeam1(getScoreTeam1()+1);
                rallyAction = false;
                action = false;
                continue;}
                break;
            }

        // dig team 1

        // if setter in position 3, 4, 5: (another backcourt player (3, 4, 5) must dig first)
            switch (positionSetter1) {
                case 3: // player 4 or 5 digs
                    if (team1->getPlayer((rand() % 2) + 4)->attemptDig()) {
                        action = true;
                    }
                    else {
                        setScoreTeam2(getScoreTeam2()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;

                case 4: // player 3 or 5 digs
                    if (team1->getPlayer(((rand() % 2)*2) + 3)->attemptDig()) {
                        action = true;
                    }
                    else {
                        setScoreTeam2(getScoreTeam2()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;

                case 5: // player 3 or 4 digs
                    if (team1->getPlayer((rand() % 2) + 3)->attemptDig()) {
                        action = true;
                    }
                    else {
                        setScoreTeam2(getScoreTeam2()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;
            }  

        // if setter in position 0,1,2 (generate a number between 3,4,5 to decide which backcourt player digs)
            switch (positionSetter1)   {
                case 0: case 1: case 2:     // player 3,4 or 5 digs
                randomPosition = (rand() % 3) + 3;  // need num between 3 and 5
                if(team1->getPlayer(randomPosition)->attemptDig()) {
                    action = true;
                }
                else {
                setScoreTeam2(getScoreTeam2()+1);
                rallyAction = false;
                action = false;
                continue;}
                break;
            }

        // set team 1
        if (team1->getPlayer(positionSetter1)->attemptSet()) {
            action = true;
        }
        else {
            setScoreTeam2(getScoreTeam2()+1);
            rallyAction = false;
            action = false;
            continue; // Go back to the beginning of the outer loop for the next point
        }

        // spike team 1
            // if setter in position 0, 1, 2: (another frontcourt player () must spike first)
            switch (positionSetter1) {
                case 0: // player 1 or 2 spikes
                    if (team1->getPlayer((rand() % 2) + 1)->attemptSpike()) {
                        action = true;
                    }
                    else {
                        setScoreTeam2(getScoreTeam2()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;

                case 1: // player 0 OR 2 spikes
                    if (team1->getPlayer(((rand() % 2)*2))->attemptSpike()) {
                        action = true;
                    }
                    else {
                        setScoreTeam2(getScoreTeam2()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;

                case 2: // player 0 or 1  spikes
                    if (team1->getPlayer((rand() % 2))->attemptSpike()) {
                        action = true;
                    }
                    else {
                        setScoreTeam2(getScoreTeam2()+1);
                        rallyAction = false;
                        action = false;
                        continue;
                    }
                    break;
            }

            // if setter in position 3, 4, 5: (any frontcourt player () can spike first)
            switch (positionSetter1)    {
                case 3: case 4: case 5:     // player 3,4 or 5 digs
                randomPosition = (rand() % 3);  // need num between 0 and 2
                if(team1->getPlayer(randomPosition)->attemptSpike()) {
                    action = true;
                }
                else {
                setScoreTeam2(getScoreTeam2()+1);
                rallyAction = false;
                action = false;
                continue;}
                break;
            }

        }

    }            
        
        // print score
        cout << "Score:" << getScoreTeam1() << ":" << getScoreTeam2() << endl;

        // ROTATE 
        Player* temp = team1->getPlayer(0);  // Store the first element in a temporary variable
        
        for (int i = 0; i < 5; i++) {
        team1->setPlayer(i, team1->getPlayer(i+1));
        }

        team1->setPlayer(5,temp); // Place the temporary player at the end of the array

        cout << "Rotating Lineup: " << endl;
        cout << team1->getPlayer(0)->get_name() << "    "  << team1->getPlayer(1)->get_name() << "    " << team1->getPlayer(2)->get_name() << endl;
        cout << team1->getPlayer(5)->get_name() << "    "  << team1->getPlayer(4)->get_name() << "    " << team1->getPlayer(3)->get_name() << endl;

    }

    cout << "End of Game!" << endl;

    return;

}

void Game::outputGameStats(string fileCondition)    {
    // WRITE TO A FILE
    try {
    if (fileCondition == "yes") {
    ofstream myfile;
    myfile.open ("gameStats.txt");

    // Digs
    myfile << "Game Statistics:" << endl;
    myfile << "# of successful actions - # of attempted actions " << endl;
    
    myfile << "Serves:" << endl;
    for(int i = 0; i < 6; i++)  {
        myfile << team1->getPlayer(i)->get_name() << ":" << team1->getPlayer(i)->get_successfulServes() << "-" << team1->getPlayer(i)->get_attemptServes() << endl;
    }
    
    myfile << "Digs:" << endl;
    for(int i = 0; i < 6; i++)  {
        myfile << team1->getPlayer(i)->get_name() << ":" << team1->getPlayer(i)->get_successfulDigs() << "-" << team1->getPlayer(i)->get_attemptDigs() << endl;
    }

    myfile << "Sets:" << endl;
    for(int i = 0; i < 6; i++)  {
        myfile << team1->getPlayer(i)->get_name() << ":" << team1->getPlayer(i)->get_successfulSets() << "-" << team1->getPlayer(i)->get_attemptSets() << endl;
    }

    myfile << "Spikes:" << endl;
    for(int i = 0; i < 6; i++)  {
        myfile << team1->getPlayer(i)->get_name() << ":" << team1->getPlayer(i)->get_successfulSpikes() << "-" << team1->getPlayer(i)->get_attemptSpikes() << endl;
    }

    myfile.close();
    
    } 
    
    else if (fileCondition == "no") {
    cout << "Game Statistics:" << endl;
    cout << "# of successful actions - # of attempted actions " << endl;
    
    cout << "Serves:" << endl;
    for(int i = 0; i < 6; i++)  {
        cout << team1->getPlayer(i)->get_name() << ":" << team1->getPlayer(i)->get_successfulServes() << "-" << team1->getPlayer(i)->get_attemptServes() << endl;
    }
    
    cout << "Digs:" << endl;
    for(int i = 0; i < 6; i++)  {
        cout << team1->getPlayer(i)->get_name() << ":" << team1->getPlayer(i)->get_successfulDigs() << "-" << team1->getPlayer(i)->get_attemptDigs() << endl;
    }

    cout << "Sets:" << endl;
    for(int i = 0; i < 6; i++)  {
        cout << team1->getPlayer(i)->get_name() << ":" << team1->getPlayer(i)->get_successfulSets() << "-" << team1->getPlayer(i)->get_attemptSets() << endl;
    }

    cout << "Spikes:" << endl;
    for(int i = 0; i < 6; i++)  {
        cout << team1->getPlayer(i)->get_name() << ":" << team1->getPlayer(i)->get_successfulSpikes() << "-" << team1->getPlayer(i)->get_attemptSpikes() << endl;
        }
    }
     
    else {
        throw std::runtime_error("Invalid input for writing to file");
    }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        std::exit(1);  // Terminate program
    }
}

