#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

class Wumpus : public Event {
    private:

    public:
        Wumpus(const int &x, const int &y) : Event(x, y) {};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;

        void wakeUp(Adventurer &a);
};

#endif