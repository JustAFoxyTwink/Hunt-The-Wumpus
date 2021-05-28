/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "event.h"

Event::Event() {
}

void Event::percept() {
}

void Event::encounter(Adventurer &a) {
    cout << "You enter an empty room.\n";
}

bool Event::isNull() const {
    //cout << "null\n";
    return true;
}