#include "adventurer.h"

Adventurer::Adventurer(const int &x, const int &y) {
    posX = x;
    posY = y;
}

void Adventurer::getPos(int &x, int &y) {
    x = posX;
    y = posY;

    alive = true;
}

void Adventurer::kill() {
    alive = false;
}

bool Adventurer::isAlive() {
    return alive;
}