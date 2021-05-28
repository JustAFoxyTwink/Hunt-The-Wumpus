/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef ADVENTURER_H
#define ADVENTURER_H

#include "common.hpp"

class Adventurer {
    private:
        int posX, posY, arrows;
        bool alive, hasGold, escaped;
    public:
        Adventurer();

        void getPos(int &x, int &y);
        void setPos(int x, int y);
        int getArrows() const;
        bool fireArrow();
        void move(Direction d, int side);
        void kill();
        bool isAlive();
        bool checkGold() const;
        void pickupGold();
        bool isEscaped() const;
        void escape();
};

#endif