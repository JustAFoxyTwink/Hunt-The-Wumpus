/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef GOLD_H
#define GOLD_H

#include "event.h"

class Gold : public Event {
    private:
        bool isGold;
    public:
        Gold() : Event() {isGold = true;};

        virtual void percept();
        virtual void encounter(Adventurer &a);
        virtual bool isNull() const;
};

#endif