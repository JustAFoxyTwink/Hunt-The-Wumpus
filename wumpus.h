/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

class Wumpus : public Event {
    private:
        bool isAlive;
    public:
        Wumpus() : Event() {isAlive = true;};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;

        bool wakeUp();
        void kill();
        bool alive();
};

#endif