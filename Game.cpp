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
void Game::play(){ // mic
while(scoreTeam1 < winPoints && scoreTeam2 < winPoints) {
    
    // simulate one point
    int servingTeamIndex = 0;   // team 1 serves first
    bool action = true;

    while(action == true) {
<<<<<<< HEAD
        Team* servingTeam = team1
        // player 6 serves first (back right)
        // team1[6].attemptServe   


        // dig team 2
        // if setter in position 4,5,6 (generate a number between 4,5,6 excluding setter position)
        // if setter in position 1,2,3 (generate a number between 4,5,6 to decide which backcourt player digs)

        // set team 2
        // setter in team 2 attempts to set

        // spiker
        // if setter in position 1,2,3 (generate a number between 1,2,3 to decide which front court player spikes except setter) 
        // if setter in position 4,5,6 (generate a number between 1,2,3 to decide which frontcourt player spikes)
=======
        Team* servingTeam = team1;
    // intj;
    // servingTeam team[j]=attemptServe()
    //j++;
    // while(ball = in){
//         start simming
    } 
    else{
        Team* servingTeam = team2;
    }
>>>>>>> c8e6bbe9c3ca97eaeaefe7de645a57012cfe81f1
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
