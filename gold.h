#ifndef GOLD_H
#define GOLD_H

#include "event.h"

class Gold : public Event {
    private:

    public:
        Gold(const int &x, const int &y) : Event(x, y) {};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;
};

#endif