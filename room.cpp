/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "room.h"

Room::Room(const int &x, const int &y) {
    event = new Event();

    posX = x;
    posY = y;
}

Room::Room(const int &x, const int &y, Event *e) {
    event = e;

    posX = x;
    posY = y;
}

Room::~Room() {
    //delete event;
}

Event* Room::getEvent() const {
    return event;
}

void Room::getPos(int &x, int &y) const {
    x = posX;
    y = posY;
}