/*********************************************************************
** Program Filename: hunt_the_wumpus.cpp
** Author: Evan Garrison
** Date: 05/23/2021
** Description: main driver file for Hunt the Wumpus program
** Input: directions from the user for the adventurer, parameters for
** the game.
** Output: Current status of the game
*********************************************************************/

#include <iostream>

#include "common.hpp"
#include "event.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"
#include "room.h"
#include "adventurer.h"
#include "game.h"

using namespace std;

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int sides; 
    bool debug;

    if (argc != 3) {
        cout << "Incorrect # of command line parameters entered.\n";

        sides = getInputInBounds("Enter number of sides for the cave(min 4, max 50): ", 4, 50);
        debug = getInput("Launch the game in debug mode? (0-no, 1-yes): ");
    }
    else {
        if (atoi(argv[1]) < 4 || atoi(argv[1]) > 50) {
            cout << "Invalid number of sides entered.\n";
            sides = getInputInBounds("Enter number of sides for the cave(min 4, max 50): ", 4, 50);
        }
        else {
            sides = atoi(argv[1]);
        }

        if (string(argv[2]) != "true" && string(argv[2]) != "false") {
            cout << "Invalid input for debug mode.\n";
            debug = getInputInBounds("Launch the game in debug mode? (0-no, 1-yes): ", 0, 1);
        }
        else {
            if (string(argv[2]) == "true")
                debug = true;
            else
                debug = false;
        }
    }

    Adventurer *user = new Adventurer();

    Game game(sides, user, debug);
    int loop;

    //do {
        game.playGame();
    //} while (loop == 0);

    delete user;
}