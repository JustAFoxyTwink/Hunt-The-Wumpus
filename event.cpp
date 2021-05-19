#include "event.h"

Event::Event(const int &x, const int &y) {
    posX = x;
    posY = y;
}

void Event::percept() {
}

void Event::encounter(Adventurer &a) {
    cout << "You enter an empty room.\n";
}

bool Event::isNull() const {
    return true;
}

void Event::getPos(int &x, int &y) {
    x = posX;
    y = posY;
}