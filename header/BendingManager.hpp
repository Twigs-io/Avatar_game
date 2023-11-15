#ifndef BendingManager_H
#define BendingManager_H
#include <string>
#include <iostream>
#include "../Elemental-Functions/FireClass.cpp"
#include "../Elemental-Functions/WaterClass.cpp"
#include "../Elemental-Functions/AirClass.cpp"
#include "../Elemental-Functions/EarthClass.cpp"
#include "../Elemental-Functions/non_benderClass.cpp"

using namespace std;

class BendingManager{
    private:
        int bend_index=0;
        Person* benders[5];

    public:
        // Constructor
        // BendingManager();
        BendingManager(string);

        // getters
        string get_attack_names(int);
        void list_attacks();
        int get_defense();
        int get_health();

        // functions
        int Damage(int, string, string, string);
        int basic_Damage(int, string);
        bool Dodge();
        int SpecialAttack(int);
        void TakeDamage(int);
        void add_health(int);

        // destructor
        ~BendingManager();
};

#endif