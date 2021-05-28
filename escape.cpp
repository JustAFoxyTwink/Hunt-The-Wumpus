/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "escape.h"

void Escape::percept() {
}

void Escape::encounter(Adventurer &a) {
    cout << "You enter the room with the escape rope. Enter e to leave the cave.\n";
}

bool Escape::isNull() const {
    //cout << "not null\n";
    return false;
}