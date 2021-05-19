#ifndef PIT_H
#define PIT_H

#include "event.h"

class Pit : public Event {
    private:

    public:
        Pit(const int &x, const int &y) : Event(x, y) {};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;
};

#endif