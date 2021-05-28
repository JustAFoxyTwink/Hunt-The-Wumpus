/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "adventurer.h"

Adventurer::Adventurer() {
    alive = true;
    hasGold = false;
    arrows = 3;
}

void Adventurer::getPos(int &x, int &y) {
    x = posX;
    y = posY;
}

void Adventurer::setPos(int x, int y) {
    posX = x;
    posY = y;
}

int Adventurer::getArrows() const {
    return arrows;
}

bool Adventurer::fireArrow() {
    if (arrows > 0) {
        arrows--;
        return true;
    }
    else {
        return false;
    }
}

void Adventurer::move(Direction d, int side) {
    switch (d)
    {
    case NORTH:
        if (posY != 0)
        posY--;
        break;

    case EAST:
        if (posX != side - 1)
        posX++;
        break;

    case SOUTH:
        if (posY != side - 1)
        posY++;
        break;

    case WEST:
        if (posX != 0)
        posX--;
        break;
    
    case OUT:
    default:
        escape();
        break;
    }
}

void Adventurer::kill() {
    alive = false;
}

bool Adventurer::isAlive() {
    return alive;
}

bool Adventurer::checkGold() const {
    return hasGold;
}

void Adventurer::pickupGold() {
    hasGold = true;
}

bool Adventurer::isEscaped() const {
    return escaped;
}

void Adventurer::escape() {
    escaped = true;
    cout << "you Escaped the cave!\n";
    if (hasGold)
        cout << "You managed to bring the gold with you!\n";
    else 
        cout << "You didn't get the Gold!\n";
}