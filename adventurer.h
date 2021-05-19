#ifndef ADVENTURER_H
#define ADVENTURER_H

class Adventurer {
    private:
        int posX, posY;
        bool alive;
    public:
        Adventurer(const int &x, const int &y);

        void getPos(int &x, int &y);
        void kill();
        bool isAlive();
};

#endif