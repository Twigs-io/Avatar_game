#include "../header/BendingManager.hpp"
#include <string>

using namespace std;

BendingManager::BendingManager(string bends) {
    FireClass* Fire = new FireClass(100, "Burning Flight", "Fire Blast", "Dragon Breath");
    WaterClass* Waters = new WaterClass(100, "Ice Wall", "Water Whip", "Water Bubble");
    AirClass* Airs = new AirClass(90, "Air Ball", "Air Bullet", "Air Bubble");
    EarthClass* Earths = new EarthClass(120, "Earth Wall", "Rock Bash", "Rock Hard Armor");
    NON_BENDERClass* Non_Benders = new NON_BENDERClass(100, "dodge", "boomerang", "stronger boomerang");

    benders[0] = Fire;
    benders[1] = Waters;
    benders[2] = Airs;
    benders[3] = Earths;
    benders[4] = Non_Benders;

    if(bends == "Fire"){
        bend_index = 0;
    }
    else if(bends ==  "Water"){
        bend_index = 1;
    }
    else if(bends == "Air"){
        bend_index = 2;
    }
    else if(bends == "Earth"){
        bend_index = 3;
    }
    else if(bends == "None"){
        bend_index = 4;
    }
}


int BendingManager::get_defense() {
    return benders[bend_index]->get_defense();
}

int BendingManager::get_health() {
    return benders[bend_index]->get_health();
}

string BendingManager::get_attack_names(int i) {
    return benders[bend_index]->get_attack_names(i);
}

void BendingManager::list_attacks() {
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            cout << "1. Defensive Move: " << get_attack_names(i) << endl;
        }
        if (i == 1) {
            cout << "2. Regular Move: " << get_attack_names(i) << endl;
        }
        if (i == 2) {
            cout << "3. Special Move: " << get_attack_names(i) << endl;
        }
    }
}

int BendingManager::Damage(int defense, string enemy_Bend, string attack_name,string arena) {
    int damage=0;
    int finaldam=0;
    if(attack_name==benders[bend_index]->get_attack_names(0)){}
    else if(attack_name==benders[bend_index]->get_attack_names(1)){
        damage = benders[bend_index]->basic_attack(enemy_Bend);
        int defenceCalc = (static_cast<double>(damage) / static_cast<double>(100)) * (defense / 10);
        finaldam = damage - defenceCalc;
        if (arena == "Fire Nation" && bend_index == 0){
            return finaldam + 3;
        }
        else if (arena == "Water Nation" && bend_index == 1){
            return finaldam + 5;
        }
        else if (arena == "Air Nation" && bend_index == 2){
            return finaldam + 4;
        }
        else if (arena == "Earth Nation" && bend_index == 3){
            return finaldam + 6;
        }
    }
    else if(attack_name==benders[bend_index]->get_attack_names(2)){
        if (arena == "Fire Nation" && bend_index == 0){
            damage = benders[bend_index]->special_attack();
            int defenceCalc = (static_cast<double>(damage) / static_cast<double>(100)) * (defense / 10);
            finaldam = damage - defenceCalc;
            return finaldam + 3;
        }
        else if (arena == "Water Nation" && bend_index == 1){
            damage = benders[bend_index]->special_attack();
            int defenceCalc = (static_cast<double>(damage) / static_cast<double>(100)) * (defense / 10);
            finaldam = damage - defenceCalc;
            return finaldam + 5;
        }
        else if (arena == "Air Nation" && bend_index == 2){
            damage = benders[bend_index]->special_attack();
            int defenceCalc = (static_cast<double>(damage) / static_cast<double>(100)) * (defense / 10);
            finaldam = damage - defenceCalc;
            return finaldam + 4;
        }
        else if (arena == "Earth Nation" && bend_index == 3){
            damage = benders[bend_index]->special_attack();
            int defenceCalc = (static_cast<double>(damage) / static_cast<double>(100)) * (defense / 10);
            finaldam = damage - defenceCalc;
            return finaldam + 6;
        }
        else{
            damage = benders[bend_index]->basic_attack(enemy_Bend);
            int defenceCalc = (static_cast<double>(damage) / static_cast<double>(100)) * (defense / 10);
            finaldam = damage - defenceCalc;
        }
    }
    return finaldam;
}

bool BendingManager::Dodge() {
    return benders[bend_index]->dodge();
}

int BendingManager::SpecialAttack(int defense) {
    int damage=0;
    damage = benders[bend_index]->special_attack();
    int defenseCalc = (static_cast<double>(damage) / static_cast<double>(100)) * (defense / 10);
    return damage - defenseCalc;
}

void BendingManager::TakeDamage(int damage) {
    benders[bend_index]->damage_taken(damage);
}

void BendingManager::add_health(int health) {
    if(benders[bend_index]->get_health() + health > 100)
        benders[bend_index]->add_health(100);
    else
        benders[bend_index]->add_health(benders[bend_index]->get_health() + health);
    benders[bend_index]->add_health(health);
}

//destructor
BendingManager::~BendingManager() {
    for(int i = 0; i < 5; i++){
        delete benders[i];
    }

}
