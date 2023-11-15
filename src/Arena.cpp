#include "../header/Arena.h"
#include <iostream>
#include <random>

using namespace std;

Arena::Arena() {
    int randomNum = rand() % 4;
    if(randomNum==0){
        arenasName = "Fire Nation";
    }
    else if(randomNum==1){
        arenasName = "Water Nation";
    }
    else if(randomNum==2){
        arenasName = "Air Nation";
    }
    else{
        arenasName = "Earth Nation";
    }
    timeTillNextArena = 5;
}
string Arena::getArenaName(){
    return arenasName;
}
int Arena::getTimeTillNextArena() {
    return timeTillNextArena;
}

void Arena::DecreaseTimeTillNextArena() {
    timeTillNextArena--;
    if(timeTillNextArena == 0){
        changeArena();
        timeTillNextArena = 5;
    }
}

void Arena::changeArena() {
    if(arenasName =="Fire Nation"){
        arenasName = "Water Nation";
    }
    else if(arenasName =="Water Nation"){
        arenasName = "Air Nation";
    }
    else if(arenasName =="Air Nation"){
        arenasName = "Earth Nation";
    }
    else if(arenasName =="Earth Nation"){
        arenasName = "Fire Nation";
    }
}