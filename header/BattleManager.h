#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H
#include <string>
#include "../header/PrintMenu.h"
#include "../header/GameManager.h"
#include "../header/BendingManager.hpp"
#include "../header/Arena.h"

using namespace std;

class BattleManager {
    public:
        // constructors
        BattleManager() {
            playerName = "";
            playerBend = "";
        }
        BattleManager(string name, string bend) {
            playerName = name;
            playerBend = bend;
        }
        // setters
        void setBattleName(string name);
        void setBattleBend(string bend);
        void setBattleAttack(string bendAttack);
        void setBattleDodge(bool canDodge, bool defenseMode);
        
        // getters
        string getBattleName();
        string getBattleBend();
        string getBattleAttack();
        bool getBattleDodge();
        bool getDefenseAttempt();
    private:
        string playerName;
        string playerBend;
        string attack;
        bool willDodge = false;
        bool defenseAttempt = false;
};

int firstTurn(GameManager* game);
void playerChoices(BattleManager* playerProfile, BendingManager* bendProfile, Arena* arenas);
void cpuMoves(BattleManager* cpuProfile, BendingManager* cpuBendProfile);
void useMove(BattleManager* playerProfile, BendingManager* bendProfile, Arena* arenas);
int damageCalc(BattleManager* actPlayer, BendingManager* actBendProfile, BendingManager* oppBendProfile, Arena *arenas);
void damageResult(BattleManager* actPlayer, BendingManager* actBendProfile, BattleManager* oppPlayer, BendingManager* oppBendProfile, Arena *arenas);

        //void playerMenuTurn(GameManager* game, int playerTurn);
        //void playerChoices(GameManager* game, BendingManager* currBendPlayer, BattleManager* moveStorage, Arena* arenas, int playerTurn);
        //void cpuMoves(BendingManager* cpuBendPlayer, BattleManager* moveStorage);
        //void useMove(GameManager* game, BendingManager* currBendPlayer, BattleManager* moveStorage, Arena *arenas, int playerTurn);
        //int damageCalc(GameManager* game, BendingManager* actPlayer, BendingManager* oppPlayer, Arena* arenas, int playerTurn);
        //void damageResult(GameManager* game, BendingManager* actPlayer, BendingManager* oppPlayer, BattleManager* moveStorage, Arena* arenas, int playerTurn);
    //private:
        //bool nextDodge = false;
        //string nextAttack = "";
        //Arena* arenas = new Arena();
#endif /* BATTLEMANAGER_H */