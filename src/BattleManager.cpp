#include "../header/BattleManager.h"
#include "../header/BendingManager.hpp"
#include "../header/GameManager.h"
#include "../header/PrintMenu.h"
#include "../header/Arena.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int firstTurn(GameManager* game) {
    cout << "Now it is time for battle! ";
    int firstTurn = rand()/RAND_MAX; // chooses who will fight first
    if (firstTurn == 0) {
        cout << game->get_P1Name() << " will start first." << endl << endl;
        return 0;
    }
    else {
        cout << game->get_P2Name() << " will start first." << endl << endl;
        return 1;
    }
}

void BattleManager::setBattleName(string name) {
    playerName = name;
}

void BattleManager::setBattleBend(string bend) {
    playerBend = bend;
}

void BattleManager::setBattleAttack(string bendAttack) {
    attack = bendAttack;
}

void BattleManager::setBattleDodge(bool canDodge, bool defenseMode) {
    willDodge = canDodge;
    defenseAttempt = defenseMode;
}

string BattleManager::getBattleName() {
    return playerName;
}

string BattleManager::getBattleBend() {
    return playerBend;
}

string BattleManager::getBattleAttack() {
    return attack;
}

bool BattleManager::getBattleDodge() {
    return willDodge;
}

bool BattleManager::getDefenseAttempt() {
    return defenseAttempt;
}

// void BattleManager::playerMenuTurn(GameManager* game, int playerTurn) {
//     if (playerTurn == 1) {
//         playerMenu(game->get_P1Name());
//     }
//     else {
//         playerMenu(game->get_P2Name());
//     }
// }

void playerChoices(BattleManager* playerProfile, BendingManager* bendProfile, Arena *arenas) {
    string input = "";
    string playerName = playerProfile->getBattleName();
    while (input == "") {
        playerMenu(playerName);
        cin >> input;
        // using a move will stop menu prompt
        if (input == "Use" || input == "USE" || input == "use" || input == "1") {
           useMove(playerProfile, bendProfile, arenas);
           return;
        }
        else if (input == "List" || input == "LIST" || input == "list" || input == "2") {
            cout << endl << "Here are your attacks:" << endl;
            bendProfile->list_attacks();
            input = "";
        }
        else if (input == "Stats" || input == "STATS" || input == "stats" || input == "3") {
            cout << endl << "Here are your current stats: " << endl
                 << "Health: " << bendProfile->get_health() << endl
                 << "Defense: " << bendProfile->get_defense() << endl;
            input = "";
        }
        else if (input == "Arena" || input == "ARENA" || input == "arena" || input == "4") {
            cout << "You are currently fighting in the " << arenas->getArenaName() << "." << endl;
            input = "";
        }
        else if(input == "Quit" || input == "QUIT" || input == "quit" || input == "5") {
            cout << "You have quit the game." << endl;
            exit(0);
        }
        else {
            input = "";
            invalidInput(playerName);
        }
    }
}

void cpuMoves(BattleManager* cpuProfile, BendingManager* cpuBendProfile) {
    int cpusMove = rand() % 3; // choose a move between 0 to 2
    if (cpusMove == 0) {
        cpuProfile->setBattleAttack(cpuBendProfile->get_attack_names(0));
        cpuProfile->setBattleDodge(cpuBendProfile->Dodge(), true);
    }
    else {
        cpuProfile->setBattleAttack(cpuBendProfile->get_attack_names(cpusMove));
    }
}

//void BattleManager::useMove(GameManager* game, BendingManager* currBendPlayer, BattleManager* moveStorage, Arena* arenas, int playerTurn) {
void useMove(BattleManager* playerProfile, BendingManager* bendProfile, Arena* arenas) {
    string moveInput = "";
    while (moveInput == "") {
        bendProfile->list_attacks();
        cout << "Type in the corresponding number to use your move!" << endl
             << "Or type in quit if you changed your mind." << endl;
        cin >> moveInput;
        //defensive move
        if (moveInput == "1") {
            cout << "You use " << bendProfile->get_attack_names(0) << "!" << endl
                 << "You will try to defend yourself this turn." << endl;
            playerProfile->setBattleAttack(bendProfile->get_attack_names(0));
            playerProfile->setBattleDodge(bendProfile->Dodge(), true);
        }
        // regular move
        else if (moveInput == "2") {
            cout << "You use " << bendProfile->get_attack_names(1) << "!" << endl;
            playerProfile->setBattleAttack(bendProfile->get_attack_names(1));
        }
        // special move
        else if (moveInput == "3") {
            cout << "You use " << bendProfile->get_attack_names(2) << "!" << endl;
            playerProfile->setBattleAttack(bendProfile->get_attack_names(2));
        }
        // quit
        else if (moveInput == "QUIT" || moveInput == "quit" || moveInput == "q" || moveInput == "4") {
            playerChoices(playerProfile, bendProfile, arenas);
            //playerChoices(game, currBendPlayer, moveStorage, arenas ,playerTurn);
        }
        // invalid input
        else {
            moveInput = "";
            invalidInput(playerProfile->getBattleName());
        }
    }
}


int damageCalc(BattleManager* actPlayer, BendingManager* actBendProfile, BendingManager* oppBendProfile, Arena *arenas) {
    int damage = 0;
    arenas->DecreaseTimeTillNextArena();
    damage = actBendProfile->Damage(oppBendProfile->get_defense(), actPlayer->getBattleBend(), actPlayer->getBattleAttack(), arenas->getArenaName());
    return damage;
}

// int BattleManager::damageCalc(GameManager* game, BendingManager* actPlayer, BendingManager* oppPlayer, 
// Arena *arenas, int playerTurn) {
//     int damage = 0;
//     if (playerTurn == 1) {
//         arenas->DecreaseTimeTillNextArena();
//         damage = actPlayer->Damage(oppPlayer->get_defense(), game->get_P1Bend(), arenas->getArenaName());
//     }
//     else {
//         damage = actPlayer->Damage(oppPlayer->get_defense(), game->get_P2Bend(), arenas->getArenaName());
//     }
//     oppPlayer->TakeDamage(damage);
//     return damage;
// }

void damageResult(BattleManager* actPlayer, BendingManager* actBendProfile, BattleManager* oppPlayer, BendingManager* oppBendProfile, Arena *arenas) {
    int damageInt = damageCalc(actPlayer, actBendProfile, oppBendProfile, arenas);
    bool dodgeBool = oppPlayer->getBattleDodge();
    if (dodgeBool == true) {
        /*
        Defending player defends against attacking player's <attack>! 
        They take no damage!
        */
        playerDodgeMsg(actPlayer->getBattleName(), oppPlayer->getBattleName());
    }
    else if (actPlayer->getDefenseAttempt() == true) {
        playerDefendingMsg(actPlayer->getBattleName(), actPlayer->getBattleAttack());
        actPlayer->setBattleDodge(false, false);
    }
    else {
        /*
        Attacking player uses <attack>!
        Defending player takes <#> damage from attacking player's <attack>! 
        Defending player's health is now <#>!
        */
        oppBendProfile->TakeDamage(damageInt);
        playerDamageMsg(actPlayer->getBattleName(), actPlayer->getBattleAttack(), oppPlayer->getBattleName(), oppBendProfile->get_health(), damageInt);
    }
    actPlayer->setBattleDodge(false, actPlayer->getDefenseAttempt());
    oppPlayer->setBattleDodge(false, oppPlayer->getDefenseAttempt());
}

// void BattleManager::damageResult(GameManager* game, BendingManager* actPlayer, BendingManager* oppPlayer,
//  BattleManager* moveStorage, Arena *arenas, int playerTurn) {
//     int damageInt = damageCalc(game, actPlayer, oppPlayer, arenas, playerTurn);
//     cout << damageInt << endl;
//     bool dodgeBool = moveStorage->getDodge();
//     if (playerTurn == 2) {
//         if (dodgeBool == true) {
//             cout << game->get_P1Name() << " defends against " << game->get_P2Name() << "'s attack!" << endl
//                  << "They take no damage!" << endl;
//             actPlayer->set_health(damageInt);
//             moveStorage->setDodge(false);
//         }
//         else {
//             // Player 2 takes # damage from player 1's attack!
//             // Player 2's health is now #!
//             cout << game->get_P2Name() << " takes " << damageInt << " damage from "
//                  << game->get_P1Name() << "'s " << moveStorage->getAttack() << "!" << endl
//                  << game->get_P2Name() << "'s health is now " << oppPlayer->get_health() << "!" << endl
//                  << endl;
//         }
//     }
//     else {
//         if (dodgeBool == true) {
//             cout << game->get_P2Name() << " defends against " << game->get_P1Name() << "'s attack!" << endl
//                  << "They take no damage!" << endl;
//                 oppPlayer->set_health(damageInt);
//             moveStorage->setDodge(false);
//         }
//         else {        
//         // Player 1 takes # damage from Player 2's attack!
//         // Player 1's health is now #!
//             cout << game->get_P1Name() << " takes " << damageInt << " damage from " 
//                  << game->get_P2Name() << "'s " << moveStorage->getAttack() << "!" << endl
//                  << game->get_P1Name() << "'s health is now " << oppPlayer->get_health() << "!" << endl
//
//         }