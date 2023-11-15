#include "../header/GameManager.h"
#include "../header/GatherBends.h"
#include "../header/PrintMenu.h"
#include "../header/BendingManager.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// setters
void GameManager::setPlayer1Name(string name) {
    player1Name = name;
}

void GameManager::setPlayer2Name(string name) {
    player2Name = name;
}

void GameManager::set_P1MomBend(string bend) {
    player1MomBend = bend;
}

void GameManager::set_P1DadBend(string bend) {
    player1DadBend = bend;
}

void GameManager::set_P2MomBend(string bend) {
    player2MomBend = bend;
}

void GameManager::set_P2DadBend(string bend) {
    player2DadBend = bend;
}

void GameManager::set_P1Bend(string bend) {
    player1Bend = bend;
}

void GameManager::set_P2Bend(string bend) {
    player2Bend = bend;
}


//================================================================================

// getters
string GameManager::get_P1Name() { 
    return player1Name;
}

string GameManager::get_P2Name() { 
    return player2Name;
}

string GameManager::get_P1MomBend() { 
    return player1MomBend;
}

string GameManager::get_P1DadBend() { 
    return player1DadBend;
}

string GameManager::get_P2MomBend() { 
    return player2MomBend;
}

string GameManager::get_P2DadBend() { 
    return player2DadBend;
}

string GameManager::get_P1Bend() { 
    return player1Bend;
}

string GameManager::get_P2Bend() { 
    return player2Bend;
}

