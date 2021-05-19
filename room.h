#ifndef ROOM_H
#define ROOM_H

#include "event.h"

class Room {
    private:
        Event* event;
        int posX, posY;
    public:
        Room(const int &x, const int &y);
        Room(const int &x, const int &y, Event e);
        Room& operator=(const Room &source);
        ~Room();

        Event* getEvent() const;
        void getPos(int &x, int &y) const;
};

#endif