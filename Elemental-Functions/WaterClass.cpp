#include "Person.cpp"

#ifndef Water_CPP
#define Water_CPP

using namespace std;
class WaterClass: public Person{
    public:

        WaterClass():Person(){}
        WaterClass(int Defence, string dodge, string basic_attack, string special_attack) : Person(Defence, dodge, basic_attack, special_attack){}
        bool dodge() override{
            bool dodged = (rand()%100) <75;
            return dodged;
        }
        int basic_attack(string bending) override{
            if(bending == "Water"){
                return 9+rand()%5;
            }
            if(bending == "Earth"){
                return 6+rand()%5;
            }
            if(bending == "Fire"){   
                return 12+rand()%5;
            }
            if(bending == "Air"){
                return 9+rand()%5;
            }
            return 13+rand()%5;
        }
        int special_attack() override{
            add_health(20);
            return 0;
        }
};
#endif