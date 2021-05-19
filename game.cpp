#include "game.h"

Game::Game(const int &side) {
    cave.resize(side);
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cave[i].push_back(Room(i, j));
        }
    }

    setEvents(cave, side);
}

void Game::setEvents(vector<vector<Room>> &c, const int &side) {
    int x, y;

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, Escape(x, y));

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, Gold(x, y));

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, Wumpus(x, y));

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, Pit(x, y));

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, Pit(x, y));

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, Bats(x, y));

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, Bats(x, y));
}

Room Game::getRandRoom(vector<vector<Room>> &c) const {
    int randX, randY, t;
    
    do {
        randX = rand() % c.size();
        randY = rand() % c.size();
        t = c[randX][randY].getEvent()->isNull();
    } while (!t);

    return c[randX][randY];
}