#include <iostream> 
#include <string>
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

// create opposing team
void Game::createOpposingTeam()  {
    // Create preset players with fixed skill levels
    Player* player1 = new Setter("Opposing Player 1", 0, "Setter", 80, 70, 60, 50);
    Player* player2 = new Digger("Opposing Player 2", 1, "Digger", 70, 60, 80, 50);
    Player* player3 = new Spiker("Opposing Player 3", 2, "Spiker", 60, 50, 70, 80);
    Player* player4 = new Digger("Opposing Player 4", 3, "Digger", 70, 80, 60, 50);
    Player* player5 = new Digger("Opposing Player 5", 4, "Digger", 60, 70, 80, 50);
    Player* player6 = new Spiker("Opposing Player 6", 5, "Spiker", 50, 60, 70, 80);

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
    
    // add players individually to team1
    team1->addPlayer(enteredTeam->getPlayer(0));

    team1->addPlayer(enteredTeam->getPlayer(1));

    team1->addPlayer(enteredTeam->getPlayer(2));

    team1->addPlayer(enteredTeam->getPlayer(3));

    team1->addPlayer(enteredTeam->getPlayer(4));
    
    team1->addPlayer(enteredTeam->getPlayer(5));  // DOES

    
    //list starting Lineup
    cout << "Starting Lineup: " << endl;
    cout << team1->getPlayer(0)->get_name() << "    "  << team1->getPlayer(1)->get_name() << "    " << team1->getPlayer(2)->get_name() << endl;
    cout << team1->getPlayer(5)->get_name() << "    "  << team1->getPlayer(4)->get_name() << "    " << team1->getPlayer(3)->get_name() << endl;
}


// play function - simulates a game by running through sequence of actions - NEED TO CHANGE SCORES AFTER ACTION
void Game::play(){ 

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
        if (team1->getPlayer(3)->attemptDig()) {    // change to SERVE
                action = true;
        }
            else {
                setScoreTeam2(getScoreTeam2()+1);
                cout << team1->getPlayer(3)->get_name() << " hit the net!" << endl;
                action = false;
                continue; // Go back to the beginning of the outer loop for the next point
            }

        // dig team 2:
            // determine where setter is
            int positionSetter = 0;
            for(int i=0; i < 5; i++)    {
                if(team2->getPlayer(i)->get_role() == "Setter") {
                    positionSetter = i;
                    break;
                }
            }
            
            // if setter in position 3, 4, 5: (another backcourt player (3, 4, 5) must dig first)
            switch (positionSetter) {
                case 3: // player 4 digs
                    if (team2->getPlayer(4)->attemptDig()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;

                case 4: // player 5 digs
                    if (team2->getPlayer(3)->attemptDig()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;

                case 5: // player 4 digs
                    if (team2->getPlayer(4)->attemptDig()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;
            }            

            // if setter in position 0,1,2 (generate a number between 3,4,5 to decide which backcourt player digs)
            int randomPosition = 0;
            switch (positionSetter)   {
                case 0: case 1: case 2:     // player 3,4 or 5 digs
                randomPosition = (rand() % 3) + 3;  // need num between 3 and 5
                if(team2->getPlayer(randomPosition)->attemptDig()) {
                    action = true;
                }
                else {
                action = false;
                continue;}
                break;
            }

        // set team 2
        if (team2->getPlayer(positionSetter)->attemptSet()) {
            action = true;
        }
        else {
            action = false;
            continue; // Go back to the beginning of the outer loop for the next point
        }

        // spike team 2
            // if setter in position 0, 1, 2: (another frontcourt player () must spike first)
            switch (positionSetter) {
                case 0: // player 1 spikes
                    if (team2->getPlayer(1)->attemptSpike()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;

                case 1: // player 0 spikes
                    if (team2->getPlayer(0)->attemptSpike()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;

                case 2: // player 1 spikes
                    if (team2->getPlayer(1)->attemptSpike()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;
            }

            // if setter in position 3, 4, 5: (any frontcourt player () can spike first)
            switch (positionSetter)    {
                case 3: case 4: case 5:     // player 3,4 or 5 digs
                randomPosition = (rand() % 3) + 3;  // need num between 0 and 2
                if(team2->getPlayer(randomPosition)->attemptSpike()) {
                    action = true;
                }
                else {
                action = false;
                continue;}
                break;
            }

        cout << "End of Point" << endl;
    }            
        // still need to IMPLEMENT THE FOLLOWING
        // AFTER EVERY ACTION FAIL - INCREMENT THE SCORE OF OPPOSING TEAM:
        // rotate after point finishes

        // change team that is serving

        // print score

        return;
    }

}

//     READ AND WRITE CODEBELOW
    //takes input and creates a new file that can be opened
// void .H::NewFile(string newFileName){
//     cout<<"Enter desired text\n";
//     cin>>input;
//     ofstream outFile(newFileName);
//     outFile << input; //input what you want to put into new file
//     outFile.close();
// }
    
    //function that creates file
// void .H::ReadFile(string file){
//     ifstream inFile(file);
//     if(inFile.is_open()){
//         while(getline (inFile,readFile)){
//         cout<< readFile <<endl;
//     }
//     inFile.close();
//     }
//     else{
//         cout << "unable to open file" << endl; 
//     }
// }
    
//        public:
    //sets data members
//     string fileName;
//     string newFileName;
//     string readFile;
//     string input;
