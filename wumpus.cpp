/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "wumpus.h"

void Wumpus::percept() {
    cout << "You smell a terrible stench.\n";
}

void Wumpus::encounter(Adventurer &a) {
    cout << "You entered the room with the Wumpus in it!\n";
    if (this->alive()) {
        cout << "The Wumpus gobbles you up angrily!\n";
        a.kill();
    }
    else
        cout << "The Wumpus is dead!\n";
}

bool Wumpus::isNull() const {
    //cout << "not null\n";
    return false;
}

bool Wumpus::wakeUp() {
    cout << "The Wumpus wakes up!\n";

    int randInt = rand() % 4;

    if (randInt == 0) {
        cout << "The Wumpus goes back to sleep without moving.\n";
        return false;
    }
    else {
        cout << "The Wumpus moves to a random empty room, then goes back to sleep.\n";
        return true;
    }
}

void Wumpus::kill() {
    isAlive = false;
    cout << "You killed the Wumpus!\n";
}

bool Wumpus::alive() {
    return isAlive;
}