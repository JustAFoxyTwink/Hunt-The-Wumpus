/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "gold.h"

void Gold::percept() {
    cout << "You see a glimmer nearby.\n";
}

void Gold::encounter(Adventurer &a) {
    if (isGold) {
        cout << "You found the gold and picked it up!\n";
        isGold = false;
        a.pickupGold();
    }
    else {
        "You enter an empty room.\n";
    }
}

bool Gold::isNull() const {
    //cout << "not null\n";
    return false;
}