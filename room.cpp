#include "room.h"

Room::Room(const int &x, const int &y) {
    event = new Event(x, y);

    posX = x;
    posY = y;
}

Room::Room(const int &x, const int &y, Event e) {
    event = new Event(e);

    posX = x;
    posY = y;
}

Room& Room::operator=(const Room &source) {
    if (&source == this)
        return *this;

    delete event;
    event = new Event{*source.getEvent()};

    source.getPos(posX, posY);

    return *this;
}

Room::~Room() {
    delete event;
}

Event* Room::getEvent() const {
    return event;
}

void Room::getPos(int &x, int &y) const {
    x = posX;
    y = posY;
}