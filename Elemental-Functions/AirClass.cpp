#include "Person.cpp"

#ifndef Air
#define Air
using namespace std;

class AirClass : public Person{
    private:
        int special_procked =0;
    public:
        AirClass() : Person(){
            special_procked = 0;
        }
        AirClass(int Defence, string dodge, string basic_attack, string special_attack) : Person(Defence, dodge, basic_attack, special_attack){
            special_procked = 0;
        }
        bool dodge() override{            
            if(special_procked > 0){
                special_procked--;
                return 1;
            }
            bool dodged = (rand()%100)<85;
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
            special_procked = 2;
            return 1;
        }
};


#endif