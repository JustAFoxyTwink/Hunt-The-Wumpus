#include "wumpus.h"

void Wumpus::percept() {
    cout << "You smell a terrible stench.\n";
}

void Wumpus::encounter(Adventurer &a) {
    cout << "You entered the room with the Wumpus in it!\n";
    wakeUp(a);
}

bool Wumpus::isNull() const {
    return false;
}

void Wumpus::wakeUp(Adventurer &a) {
    cout << "The Wumpus wakes up!\n";

    int x1, x2, y1, y2;
    a.getPos(x1, y1);
    getPos(x2, y2);

    if (x1 == x2 && y1 == y2) {
        cout << "The Wumpus gobbles you up angrily!\n";
        a.kill();
    }
}