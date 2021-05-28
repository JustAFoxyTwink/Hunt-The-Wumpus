/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef PIT_H
#define PIT_H

#include "event.h"

class Pit : public Event {
    private:

    public:
        Pit() : Event() {};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;
};

#endif