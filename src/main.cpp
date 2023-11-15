#include <iostream>
#include <string>
#include <cstdlib>
#include "../header/GameManager.h"
#include "../header/BattleManager.h"
#include "../header/GatherBends.h"
#include "../header/PrintMenu.h"
#include "../header/SingleOrMulti.h"
#include "../header/Arena.h"

using namespace std;

int main() {
    string replayChoice="yes";

    while (replayChoice != "no" && replayChoice != "No" && replayChoice != "NO") {
        GameManager game;

        string userChoice;
        cout << "Welcome fellow Avatar player! Today, you get to live within the Avatar world!" << endl;
        cout << "Before we get started, what is your name?" << endl;

        string user1Name;
        cin >> user1Name;

        cout << endl << "Glad to have you aboard, " << user1Name << "!" << endl;
        cout << "Would you like to play single-player, or face against a friend in real time?" << endl;

        top:
        cout << endl << "Enter S for single-player, M for multiplayer, or QUIT at any time to exit." << endl;
        cin >> userChoice;

        int multiplayerFlag = 0;
        if (userChoice == "S" || userChoice == "s") { // singleplayer choice
            game.setPlayer1Name(user1Name);
            runSinglePlayer(&game);

            menuCPU(user1Name);    // user selects CPU selection 1-6

            //===============================
            int chosenCPU;                                 // ensures selection is 1-6
            cin >> chosenCPU; 
            while (cin.fail() || chosenCPU <= 0 || chosenCPU >= 7){
                cout << "Seems like you made an error selecting a CPU. Please try again." << endl;
                cin.clear();
                cin.ignore(100, '\n');
                cin >> chosenCPU;
            }
            //================================
            selectCPU(chosenCPU, &game);
            cout << "You've selected " << game.get_P2Name() << endl; // doesn't work for rn

        }
        else if (userChoice == "M" || userChoice == "m") { // multiplayer choice
            string user2Name;
            cout << "What is your name player 2?" << endl;
            cin >> user2Name;

            game.setPlayer1Name(user1Name);
            game.setPlayer2Name(user2Name);
            runMultiPlayer(&game);
            multiplayerFlag = 1;

        }
        else if (userChoice == "QUIT") { 
            goto end;
        }
        else {
            cout << "Looks like you didn't enter a correct entry. But don't worry, try again!" << endl;
            goto top;
        }

        cout << "Perfect! Now let's figure out what kind of benders you players were destined to become!" << endl;
        determineBend(&game);
                cout << game.get_P1Name() << ", looks like your type is " << game.get_P1Bend() << "!" << endl
                     << game.get_P2Name() << ", looks like your type is " << game.get_P2Bend() << "!" << endl
                     << endl;

        // start fight
        // singleplayer instantly shows results
        // multiplayer has both players choose moves before results
        BendingManager bendPlayer1(game.get_P1Bend());
        BendingManager bendPlayer2(game.get_P2Bend());
        BattleManager battlePlayer1(game.get_P1Name(), game.get_P1Bend());
        BattleManager battlePlayer2(game.get_P2Name(), game.get_P2Bend());
        Arena* arenas = new Arena();
        outputarena(arenas->getArenaName());

        // battle loop        1         2           3         4          5          6
        // singleplayer -  1, DR1, |  2, DR2,  | 1, DR1, |  2, DR2,  | 1, DR1, |  2, DR2,  | ...
        // multiplayer (P1 starts) -    1, 2,  | DR1, DR2, |  1, 2   | DR1, DR2, |  1, 2   | DR1, DR2, | ...
        // multiplayer (P2 starts) -    2, 1,  | DR2, DR1, |  2, 1   | DR2, DR1, |  2, 1   | DR2, DR1, | ...
        // determine first turn
        int turnCount = 0;
        int goesFirst = firstTurn(&game);
        if (goesFirst == 0) {
            turnCount++;
            // 1,
            // case where multiplayer, skip damageCalc
            cout << "Turn " << turnCount << " -====================" << endl;
            playerChoices(&battlePlayer1, &bendPlayer1, arenas);
            // case where singleplayer and p1 starts first
           /*  if (multiplayerFlag == 0) {
                // DR1,
                damageResult(&battlePlayer1, &bendPlayer1, &battlePlayer2, &bendPlayer2, arenas);
            } */
        }
        // singleplayer mode
        if (multiplayerFlag == 0) {
            while ((bendPlayer1.get_health() > 0 && bendPlayer2.get_health() > 0)) {
                // 2, DR2,  | 1, DR1, ...
                // 2, DR2
                turnCount++;
                cout << "Turn " << turnCount << " -====================" << endl;
                cpuMoves(&battlePlayer2, &bendPlayer2);
                damageResult(&battlePlayer1, &bendPlayer1, &battlePlayer2, &bendPlayer2, arenas);
                damageResult(&battlePlayer2, &bendPlayer2, &battlePlayer1, &bendPlayer1, arenas);
                // 1, DR1
                turnCount++;
                cout << "Turn " << turnCount << " -====================" << endl;
                playerChoices(&battlePlayer1, &bendPlayer1, arenas);
                if(arenas->getTimeTillNextArena() == 5) {
                    outputarena(arenas->getArenaName());
                }

            }
        }
        // multiplayer mode
        else {
            while (bendPlayer1.get_health() > 0 && bendPlayer2.get_health() > 0) {
                // 2,  | DR1, DR2, |  1, ...
                // 2
                playerChoices(&battlePlayer2, &bendPlayer2, arenas);
                // DR1, DR2
                turnCount++;
                cout << "Turn " << turnCount << " -====================" << endl;
                damageResult(&battlePlayer1, &bendPlayer1, &battlePlayer2, &bendPlayer2, arenas);
                damageResult(&battlePlayer2, &bendPlayer2, &battlePlayer1, &bendPlayer1, arenas);
                // 1
                playerChoices(&battlePlayer1, &bendPlayer1, arenas);
                if(arenas->getTimeTillNextArena() == 5) {
                        outputarena(arenas->getArenaName());
                }
            }
        }

        // who wins?
        if (bendPlayer1.get_health() > 0 || bendPlayer1.get_health() > bendPlayer2.get_health()) {
            cout << game.get_P1Name() << " wins!" << endl;
        }
        else {
            cout << game.get_P2Name() << " wins!" << endl;
        }
        delete arenas;
        // end prompt
        cout << "Would you like to play again? Enter yes or no." << endl;
        cin >> replayChoice;
        
    }

    end:
    cout << "Thanks for playing! See you next time!" << endl;
    return 0;
}
