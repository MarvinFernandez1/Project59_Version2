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
        if (team1[6]->attemptServe()) {
                action = true;
            }
            else {
                action = false;
                continue; // Go back to the beginning of the outer loop for the next point
            }

        // dig team 2:
            // determine where setter is
            int positionSetter = 0;
            for(int i=0; i < 5; i++)    {
                if(team2[i]->getRole() == "Setter") {
                    positionSetter = i;
                }
            }
            
            // if setter in position 3, 4, 5: (another backcourt player (3, 4, 5) must dig first)
            switch (positionSetter) {
                case 3: // player 4 digs
                    if (team2[4]->attemptDig()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;

                case 4: // player 5 digs
                    if (team2[5]->attemptDig()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;

                case 5: // player 4 digs
                    if (team2[4]->attemptDig()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;
            }            

            // if setter in position 0,1,2 (generate a number between 3,4,5 to decide which backcourt player digs)
            switch (positionSetter)   {
                case 0: case 1: case 2:     // player 3,4 or 5 digs
                int randomPosition = 0;
                randomPosition = (rand() % 3) + 3;  // need num between 3 and 5
                if(team2[randomPosition]->attemptDig()) {
                    action = true;
                }
                else {
                action = false;
                continue;}
                break;
            }

        // set team 2
        if (team2[positionSetter]->attemptSet()) {
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
                    if (team2[1]->attemptSpike()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;

                case 1: // player 0 spikes
                    if (team2[0]->attemptSpike()) {
                        action = true;
                    }
                    else {
                        action = false;
                        continue;
                    }
                    break;

                case 2: // player 1 spikes
                    if (team2[1]->attemptSpike()) {
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
                if(team2[randomPosition]->attemptSpike()) {
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
