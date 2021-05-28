/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#include "game.h"

Game::Game(const int &side, Adventurer *a, bool d) {
    cave.resize(side);
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cave[i].push_back(Room(i, j));
        }
    }

    this->player = a;
    this->side = side;
    this->debug = d;
    setEvents(cave, side, player);
}

Game::~Game() {
    delete escape;
    delete gold;
    delete wumpus;
    delete pit;
    delete bats;
}

void Game::setEvents(vector<vector<Room>> &c, const int &side, Adventurer *a) {
    int x, y;

    escape = new Escape();
    gold = new Gold();
    wumpus = new Wumpus();
    pit = new Pit();
    bats = new Bats();

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, escape);
    a->setPos(x, y);
    escapeX = x;
    escapeY = y;

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, gold);
    goldX = x;
    goldY = y;

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, wumpus);
    wumpusX = x;
    wumpusY = y;

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, pit);
    pit1X = x;
    pit1Y = y;

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, pit);
    pit2X = x;
    pit2Y = y;

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, bats);
    bats1X = x;
    bats1Y = y;

    getRandRoom(c).getPos(x, y);
    c[x][y] = Room(x, y, bats);
    bats2X = x;
    bats2Y = y;
}

Room Game::getRandRoom(vector<vector<Room>> &c) const {
    int randX, randY;
    bool t;
    
    do {
        randX = rand() % c.size();
        randY = rand() % c.size();
        t = c[randX][randY].getEvent()->isNull();
    } while (!t);

    return c[randX][randY];
}

void Game::setOutStrings(const string &hB, const string &vB, const string &pB, const string &bB, const string &eB, const string &gB, const string &piB, const string &wB, string &s1and5, string &s2and4, string &s3) const {
    int aX, aY;
    player->getPos(aX, aY);

    for (int j = 0; j < cave.size(); j++) {
        s1and5 = "";
        s2and4 = "";
        s3 = "";
        for (int i = 0; i < cave.size(); i++) {
            s1and5 += hB;
            s2and4 += vB;

            if (i == aX && j == aY)
                s3 += pB;
            else if (i == escapeX && j == escapeY && debug)
                s3 += eB;
            else if (i == goldX && j == goldY && debug)
                s3 += gB;
            else if (i == wumpusX && j == wumpusY && debug) 
                s3 += wB;
            else if (((i == pit1X && j == pit1Y) || (i == pit2X && j == pit2Y)) && debug)
                s3 += piB;
            else if (((i == bats1X && j == bats1Y) || (i == bats2X && j == bats2Y)) && debug)
                s3 += bB;
            else 
                s3 += vB;
        }
        s1and5 += '*';
        s2and4 += '|';
        s3 += '|';

        cout
        << s1and5 << endl << s2and4 << endl << s3 << endl << s2and4 << endl;
    }
    cout << s1and5 << endl;
}

Direction Game::getAction(bool &fireArrow) {
    char input[3];
    cin.clear();
    cin.ignore(1, '\n');
    
    do {
        cout << "Enter action: ";
        cin.get(input, 3);

        if ((input[0] != 'w' && input[0] != 'a' && input[0] != 's' && input[0] != 'd' && input[0] != 'e' && input[0] != ' ') || 
        (input[0] == ' ' && input[1] != 'w' && input[1] != 'a' && input[1] != 's' && input[1] != 'd') || cin.fail()) {
            cout << "Invalid action. Enter again.\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    } while ((input[0] != 'w' && input[0] != 'a' && input[0] != 's' && input[0] != 'd' && input[0] != 'e' && input[0] != ' ') || 
        (input[0] == ' ' && input[1] != 'w' && input[1] != 'a' && input[1] != 's' && input[1] != 'd') || cin.fail());

    int i;
    if (input[0] == ' ') {
        fireArrow = true;

        i = 1;
    }
    else {
        fireArrow = false;
        i = 0;
    }

    switch (input[i])
    {
    case 'w':
        return NORTH;
        break;

    case 'a':
        return WEST;
        break;

    case 's':
        return SOUTH;
        break;

    case 'd':
        return EAST;
        break;

    case 'e':
        return OUT;
        break;
    
    default:
        break;
    }
    
}

void Game::playGame() {
    do {
        showCave();

        int pX, pY;
        player->getPos(pX, pY);

        cave[pX][pY].getEvent()->encounter(*player);

        if (cave[pX][pY].getEvent() == bats) {
            getRandRoom(cave).getPos(pX, pY);
            player->setPos(pX, pY);
            showCave();
        }
        
        if (player->isAlive()) {
            if (pX < side - 1)
            cave[pX + 1][pY].getEvent()->percept();
            if (pX > 0)
            cave[pX - 1][pY].getEvent()->percept();
            if (pY < side - 1)
            cave[pX][pY + 1].getEvent()->percept();
            if (pY > 0)
            cave[pX][pY - 1].getEvent()->percept();

            bool fireArrow;
            Direction d = getAction(fireArrow);

            if (fireArrow) {
                if (player->fireArrow()) {
                    fireArrowD(d);
                }
                else
                    cout << "Can't fire arrow, you don't have any.\n";
            }
            else 
                player->move(d, side);
        }
        

    } while (player->isAlive() && !player->isEscaped());
}

void Game::showCave() const {
    string 
    horizontalBreak = "*---",
    verticalBreak = "|   ",
    playerBreak = "| * ",
    batBreak = "| B ",
    escapeBreak = "| E ",
    goldBreak = "| G ",
    pitBreak = "| P ",
    wumpusBreak = "| W ",
    s1and5,
    s2and4,
    s3;

    setOutStrings(horizontalBreak, verticalBreak, playerBreak, batBreak, escapeBreak, goldBreak, pitBreak, wumpusBreak, s1and5, s2and4, s3);
}

void Game::fireArrowD(Direction d) {
    int x, y;
    player->getPos(x, y);
    bool move = false;

    switch (d)
    {
    case NORTH:
        for (int i = y; i >= 0; i--)
            if (cave[x][i].getEvent() == wumpus && wumpus->alive()) {
                wumpus->kill();
            }
        break;

    case SOUTH:
        for (int i = y; i < side; i++)
            if (cave[x][i].getEvent() == wumpus && wumpus->alive()) {
                wumpus->kill();
            }
        break;

    case WEST:
        for (int i = x; i >= 0; i--)
            if (cave[i][y].getEvent() == wumpus && wumpus->alive()) {
                wumpus->kill();
            }
        break;

    case EAST:
        for (int i = x; i < side; i++)
            if (cave[i][y].getEvent() == wumpus && wumpus->alive()) {
                wumpus->kill();
            }
        break;
    
    default:
        break;
    }

    if (wumpus->alive())
        move = wumpus->wakeUp();

    if (move) {
        cave[wumpusX][wumpusY] = Room(wumpusX, wumpusY);
        getRandRoom(cave).getPos(wumpusX, wumpusY);
        cave[wumpusX][wumpusY] = Room(wumpusX, wumpusY, wumpus);
    }
}