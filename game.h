#ifndef GAME_H
#define GAME_H

#include "room.h"
#include "escape.h"
#include "gold.h"
#include "pit.h"
#include "bats.h"
#include "wumpus.h"
#include "adventurer.h"

#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Game {
    private:
        vector<vector<Room>> cave;

        void setEvents(vector<vector<Room>> &c, const int &side);
        Room getRandRoom(vector<vector<Room>> &c) const;
    public:
        Game(const int &side);
};

#endif