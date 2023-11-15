#include "Person.cpp"
#ifndef NON_BENDER
#define NON_BENDER
using namespace std;
class NON_BENDERClass: public Person{
    public:
        NON_BENDERClass():Person(){}
        NON_BENDERClass(int Defence, string dodge, string basic_attack, string special_attack) : Person(Defence, dodge, basic_attack, special_attack){
        }
        bool dodge() override{
            bool dodged = (rand()%100) <85;
            return dodged;
        }
        int basic_attack(const string bending) override{
            return 10+rand()%5;
        }
        int special_attack() override{
            return basic_attack("water") + 2;
        }
};

#endif