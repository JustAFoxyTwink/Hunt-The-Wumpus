/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "common.hpp"
#include "room.h"
#include "escape.h"
#include "gold.h"
#include "pit.h"
#include "bats.h"
#include "wumpus.h"
#include "adventurer.h"

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Game {
    private:
        vector<vector<Room>> cave;
        Adventurer *player;
        Escape *escape;
        Gold *gold;
        Wumpus *wumpus;
        Pit *pit;
        Bats *bats;
        bool debug;

        int 
        escapeX,
        escapeY,
        goldX,
        goldY,
        wumpusX,
        wumpusY,
        pit1X,
        pit1Y,
        pit2X,
        pit2Y,
        bats1X,
        bats1Y,
        bats2X,
        bats2Y,
        side;

        void setEvents(vector<vector<Room>> &c, const int &side, Adventurer *a);
        Room getRandRoom(vector<vector<Room>> &c) const;
        void setOutStrings(const string &hB, const string &vB, const string &pB, const string &bB, const string &eB, const string &gB, const string &piB, const string &wB, string &s1and5, string &s2and4, string &s3) const;
        Direction getAction(bool &fireArrow);
    public:
        Game(const int &side, Adventurer *a, bool d);
        ~Game();

        void playGame();
        void showCave() const;
        void fireArrowD(Direction d);
};

#endif