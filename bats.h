#ifndef BATS_H
#define BATS_H

#include "event.h"

class Bats : public Event {
    private:

    public:
        Bats(const int &x, const int &y) : Event(x, y) {};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;
};

#endif