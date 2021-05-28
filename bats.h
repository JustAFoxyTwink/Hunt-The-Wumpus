/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef BATS_H
#define BATS_H

#include "event.h"

class Bats : public Event {
    private:

    public:
        Bats() : Event() {};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;
};

#endif