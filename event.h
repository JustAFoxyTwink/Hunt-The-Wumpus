#ifndef EVENT_H
#define EVENT_H

#include "adventurer.h"

#include <iostream>
#include <vector>

using namespace std;

class Event {
    private:
        int posX, posY;
    public:
        Event(const int &x, const int &y);

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;

        void getPos(int &x, int &y);
};

#endif