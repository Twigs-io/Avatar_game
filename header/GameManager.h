#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <string>
#include "../header/BendingManager.hpp"

using namespace std;

class GameManager {
public:
    // setters
    void setPlayer1Name(string name);
    void setPlayer2Name(string name);
    void set_P1MomBend(string bend);
    void set_P1DadBend(string bend);
    void set_P2MomBend(string bend);
    void set_P2DadBend(string bend);

    void set_P1Bend(string bend);
    void set_P2Bend(string bend);

    // void set_P1BendingManager();
    // void set_P2BendingManager();

    // getters
    string get_P1Name();
    string get_P2Name(); 
    string get_P1MomBend(); 
    string get_P1DadBend(); 
    string get_P2MomBend(); 
    string get_P2DadBend(); 
    string get_P1Bend(); 
    string get_P2Bend(); 

    // inheritance info
    
    string gatherIntelMother(string userName);
    string gatherIntelFather(string userName);

    //void menuCPU(string player1Name);


private:
    string player1Name;
    string player2Name;
    string player1MomBend;
    string player1DadBend;
    string player2MomBend;
    string player2DadBend;

    string player1Bend;
    string player2Bend;

    // BendingManager Player1BendingManager;
    // BendingManager Player2BendingManager;
};

#endif /* GAMEMANAGER_H */