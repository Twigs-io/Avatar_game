#include <iostream>
#include <string>

#ifndef ARENA_H
#define ARENA_H

using namespace std;

class Arena{
    private:
        string arenasName;
        int timeTillNextArena;
    public:
        Arena();
        string getArenaName();
        int getTimeTillNextArena();
        void changeArena();
        void DecreaseTimeTillNextArena();
};
#endif