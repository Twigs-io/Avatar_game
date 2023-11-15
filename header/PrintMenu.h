#ifndef PRINTMENU_H
#define PRINTMENU_H
#include <iostream>
#include <string>
#include "../header/GameManager.h"
#include "../header/BendingManager.hpp"
#include "../header/BattleManager.h"

void questionUserMother(string userName); 
void questionUserFather(string userName);
void menuCPU(string player1Name);
void playerMenu(string playerName);
void invalidInput(string playerName);
void playerDamageMsg(string attackingPlayerName, string attackingPlayerAttack, string defendingPlayerName, int defendingPlayerHealth, int damageInt);
void playerDodgeMsg(string attackingPlayer, string defendingPlayer);
void playerDefendingMsg(string activePlayer, string defenseMove);
void outputarena(string arena_name);

#endif