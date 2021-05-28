/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "bats.h"

void Bats::percept() {
    cout << "You hear winds flapping.\n";
}

void Bats::encounter(Adventurer &a) {
    cout << "You encounter some large bats, they take you to another room!\n";
}

bool Bats::isNull() const {
    //cout << "not null\n";
    return false;
}