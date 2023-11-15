#include "Person.cpp"

#ifndef Earth
#define Earth
using namespace std;
class EarthClass: public Person{
    public:
        EarthClass():Person(){}
        EarthClass(int Defence, string dodge, string basic_attack, string special_attack) : Person(Defence, dodge, basic_attack, special_attack){
        }
        bool dodge() override{
            bool dodged = (rand()%100) <55;
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
                return 9+rand()%5;
            }
            if(bending == "Air"){
                return 9+rand()%5;
            }
            return 13+rand()%5;
        }
        int special_attack() override{
            set_defense(150);
            return 0;
        }
};


#endif