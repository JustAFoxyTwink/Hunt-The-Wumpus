#include "gold.h"

void Gold::percept() {
    cout << "You see a glimmer nearby.\n";
}

void Gold::encounter(Adventurer &a) {

}

bool Gold::isNull() const {
    return false;
}