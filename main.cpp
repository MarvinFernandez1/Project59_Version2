#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

int main() {
//Player(name, starting position, role on team)
    Player player("Michael", 2, "Spiker");
    
    cout << "Let the battle begin!" << endl;

    cout << player.get_name() << " wins!" << endl;    
}