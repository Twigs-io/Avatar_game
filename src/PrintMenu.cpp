#include "../header/PrintMenu.h"
#include <iostream>
#include <string>
#include "../header/GameManager.h"
#include "../header/BendingManager.hpp"
#include "../header/BattleManager.h"

void questionUserMother(string userName){
    cout << "We have some questions to ask you " << userName << " before we get started." << endl;
    cout << "First off " << userName << ", which element was your mother able to bend? Please enter either Water, Earth, Fire, Air, or None." << endl;
}
    
void questionUserFather(string userName) { 
    cout << "One more question, " << userName << "." << endl;
    cout << "Which element was your father able to bend? Please enter either Water, Earth, Fire, Air, or None." << endl;
} 

void menuCPU(string player1Name){
    cout << "One more step " << player1Name << ". You'll need a second player to play against, but don't worry, you can face the CPU!" << endl;
    cout << "Please select from the following list of players to face against! Enter only the corresponding number." << endl;
    cout << "1 - Aang - Air Bender" << endl;
    cout << "2 - Katara - Water Bender" << endl;
    cout << "3 - Toph - Earth Bender" << endl;
    cout << "4 - Zuko - Fire Bender" << endl;
    cout << "5 - Sokka - Non Bender" << endl;
    cout << "6 - Random - Randomly selects one of these players" << endl;
}

void playerMenu(string playerName) {
    cout << "What would you like to do, " << playerName << "?" << endl
         << "==============================================================" << endl
         << "|1. (Use) a Move         | 2. Get a (List) of Moves" << endl
         << "|3. Display Your (Stats) | 4. Observe the (Arena)'s Conditions" << endl
         << "|5. (Quit) the Game"<< endl   
         << "==============================================================" << endl
         << "Type in a number or key word in parentheses for your options." << endl;
}

void invalidInput(string playerName) {
    cout << "Looks like you entered an invalid input, " << playerName << "." << endl
         << "Please try again." << endl
         << endl;
}

void playerDamageMsg(string attackingPlayerName, string attackingPlayerAttack, string defendingPlayerName, int defendingPlayerHealth, int damageInt) {
    cout << attackingPlayerName << " uses " << attackingPlayerAttack << "!" << endl
         << defendingPlayerName << " takes " << damageInt << " damage from " << attackingPlayerName << "'s " << attackingPlayerAttack << "!" << endl
         << defendingPlayerName << "'s health is now " << defendingPlayerHealth << "!" << endl
         << endl;
}

void playerDodgeMsg(string attackingPlayer, string defendingPlayer) {
    cout << defendingPlayer << " defends against " << attackingPlayer << "'s attack!" << endl
         << "They take no damage!" << endl
         << endl;
}

void playerDefendingMsg(string activePlayer, string defenseMove) {
    cout << activePlayer << " uses " << defenseMove << "!" << endl
         << "They are in a defensive state and can not attack this turn!" << endl 
         << endl;
}

void outputarena(string arena_name){
    cout << endl << "The arena has changed to " << arena_name << "." << endl << endl;
}