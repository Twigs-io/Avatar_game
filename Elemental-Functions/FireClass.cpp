#include "Person.cpp"

#ifndef FIRE
#define FIRE

using namespace std;
class FireClass : public Person{
    private:
        int special_procked =0;
    public:
        FireClass() : Person(){
            special_procked = 0;
        }
        FireClass(int Defence, string dodge, string basic_attack, string special_attack) : Person(Defence, dodge, basic_attack, special_attack){
        }
        bool dodge() override{

            bool dodged = (rand()%100) <75;
            return dodged;
        }
        int basic_attack(const string bending) override{
            double defence = get_defense();
            if(bending == "Water"){
                if(special_procked > 0){
                    special_procked--;
                    return 10+rand()%5;
                }
                return 8+rand()%2;
            }
            if(bending == "Earth"){
                if(special_procked > 0){
                    special_procked--;
                    return 8+rand()%5;
                }
                return 6+rand()%2;
            }
            if(bending == "Fire"){   
                if(special_procked > 0){
                    special_procked--;
                    return 11+rand()%5;
                }
                return 9+rand()%2;
            }
            if(bending == "Air"){
                if(special_procked > 0){
                    special_procked--;
                    return 14+rand()%5;     
                }
                return 12+rand()%2;
            }
            if(special_procked > 0){
                    special_procked--;
                    return 15+rand()%5;
            }    
            return 13+rand()%2;
        }

        int special_attack() override{
            special_procked = 2;
            return 18+rand()%5;
        }
};

#endif