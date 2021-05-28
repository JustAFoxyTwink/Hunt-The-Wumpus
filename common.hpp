/*********************************************************************
** Program Filename: common.hpp
** Author: Evan Garrison
** Date: 05/23/2021
** Description: file with common functions and types needed by multiple
** other classes
*********************************************************************/

#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <string>

using namespace std;

/**
 * Direction type used by classes to determine directions.
 **/
enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    OUT
};

/*********************************************************************
** Function: getInput
** Description: template for getting input from the user with a prompt
** Parameters: prompt - the prompt for the user
** Pre-Conditions: caller doesn't have user input
** Post-Conditions: caller has been returned user input
*********************************************************************/ 
template <typename T=int>
T getInput(string prompt) {
    T input;

    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please try again.\n";
        }

        cout << prompt;
        cin >> input;
    } while (cin.fail());

    return input;
}

/*********************************************************************
** Function: getInputInBounds
** Description: template for getting input from the user with a prompt,
** within bounds
** Parameters: prompt - the prompt for the user, lB - lowerBound, uB - upperBound
** Pre-Conditions: caller doesn't have user input
** Post-Conditions: caller has been returned user input
*********************************************************************/ 
template <typename T1>
T1 getInputInBounds(string prompt, T1 lB, T1 uB) {
    T1 input;

    do {
        input = getInput(prompt);

        if (input < lB || input > uB)
            cout << "Invalid input. Please try again.\n";
    } while (input < lB || input > uB);

    return input;
}

#endif