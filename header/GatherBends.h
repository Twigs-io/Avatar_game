#ifndef DETERMINEBEND_H
#define DETERMINEBEND_H
#include <string>
#include "../header/GameManager.h"

void determineBend(GameManager* game);
string gatherIntelMother(string userName);
string gatherIntelFather(string userName);
void selectCPU(int chosenCPU, GameManager* game);

#endif