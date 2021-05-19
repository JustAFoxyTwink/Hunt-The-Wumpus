#ifndef ESCAPE_H
#define ESCAPE_H

#include "event.h"

class Escape : public Event {
    private:

    public:
        Escape(const int &x, const int &y) : Event(x, y) {};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;
};

#endif