#include <iostream>
#include <string>
#include "Player.h"
#include "ReadnW.h"
using namespace std;

int main() {
//Player(name, starting position, role on team)
    Player player("Michael", "Backcourt", "Spiker");
    
    cout << "Let the battle begin!" << endl;


    cout << player.get_name() << " wins!" << endl;

    cout << player.get_name() << " wins!" << endl;



//     ReadnW rw1;
//     rw1.writeFile("te");
//     rw1.inFile("te");
    
    
    return 0;

    
    }
