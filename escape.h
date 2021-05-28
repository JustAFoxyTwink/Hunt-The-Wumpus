/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef ESCAPE_H
#define ESCAPE_H

#include "event.h"

class Escape : public Event {
    private:

    public:
        Escape() : Event() {};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;
};

#endif