#include <iostream>
#include <string>
#include <cstdlib>

#ifndef PERSON
#define PERSON

class Person{
    private:
        int Health = 100;
        int Defence=0;
        std::string attack_names[3];

    public:
        //constructors
        Person(){
            this->Health = 100;
            this->Defence = 100;
            attack_names[0] = " ";
            attack_names[1] = " ";
            attack_names[2] = " ";
        }
        Person(int Defences, std::string dodges, std::string basic_attacks, std::string special_attacks){
            this->Defence = Defences;
            this->attack_names[0] = dodges;
            this->attack_names[1] = basic_attacks;
            this->attack_names[2] = special_attacks;
        }
        
        //getters
        int get_health(){
            return Health;
        }
        int get_defense(){
            return Defence;
        }
        std::string get_attack_names(int index){
            return attack_names[index];
        }

        //setters
         void set_defense(int Defense){
            this->Defence=Defense;
        }

        //damage and health functions
        void damage_taken(int damage){
            this->Health -= damage;
        }
        void add_health(int amount){
            if(this->Health + amount < 100)
                this->Health = this->Health + amount;
            else
                this->Health = 100;
        }

        //pure virtual functions
        virtual bool dodge(){
            return false;
        }
        virtual int basic_attack(const std::string bending)
        {
            return 0;
        }
        virtual int special_attack(){
            return 0;
        }

        //destructor
        virtual ~Person(){};

};

#endif