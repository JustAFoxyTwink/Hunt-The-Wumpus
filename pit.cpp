/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "pit.h"

void Pit::percept() {
    cout << "You feel a breeze.\n";
}

void Pit::encounter(Adventurer &a) {
    cout << "You fell into a pit and died!\n";
    a.kill();
}

bool Pit::isNull() const {
    //cout << "not null\n";
    return false;
}