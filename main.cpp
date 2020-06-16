#include <iostream>
#include "gameWorld/Dungeon.h"
#include "Character.h"
#include "util/StringUtil.h"

using namespace std;
int main() {
    auto *dungeon = new Dungeon;
    Character character(*dungeon);

    cout << "Welcome to the ==DungeonCrawler==! Below you is the map that you can navigate in. D stands for Danger, "
            "B for Bonus and 0 for Empty. Your location is symbolised with - -. Have Fun, Good Luck!" << endl;

    int round = 1;
    while(true){
        dungeon->display(character.getCoordinateX(), character.getCoordinateY());
        string input ="";
        while(!StringUtil::isLegalCommand(input)){
            cout << "Please enter W, A, S or D to move: ";
            cin >> input;
        }

        if(!character.move(input.at(0), dungeon)) {
            cout << "Unfortunately, you died!" << endl;
            break;
        }
        if(dungeon->checkIfEmpty()){
            cout << "Dungeon was emptied! Round " << round << " finished!" << endl;
            dungeon->display(character.getCoordinateX(), character.getCoordinateY());

            cout << "\nDungeon is refilled!" << endl;
            character.displayStats();
            dungeon->reinitialise(round++);
        }
    }

    delete dungeon;
    return 0;
}
