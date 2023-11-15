#include "../header/GatherBends.h"
#include "../header/GameManager.h"

void determineBend(GameManager* game){
 
    string bendTypeP1[2] = {game->get_P1DadBend(), game->get_P1MomBend()};
    int i = rand() % 2; 
    game->set_P1Bend(bendTypeP1[i]);

    string bendTypeP2[2] = {game->get_P2DadBend(), game->get_P2MomBend()};
    int j = rand() % 2;
    game->set_P2Bend(bendTypeP2[j]);
 }

string gatherIntelMother(string userName){
    string bending;
    cin >> bending;

    if (bending == "QUIT") { 
        exit(0);
    }

    while (bending != "Water" && bending != "Earth" && bending != "Fire" && bending != "Air" && bending != "None"){ 
        cout << "Seems like you made a typo "<< userName << ". Please enter whether your mother could bend Water, Earth, Fire, Air or None." << endl;
        cin >> bending;
    }

    return bending;
}

string gatherIntelFather(string userName){
    string bending;
    cin >> bending;

    if (bending == "QUIT") { 
        exit(0);
    }

    while (bending != "Water" && bending != "Earth" && bending != "Fire" && bending != "Air" && bending != "None"){ 
        cout << "Seems like you made a typo "<< userName << ". Please enter whether your mother could bend Water, Earth, Fire, Air, or None." << endl;
        cin >> bending;
    }

    return bending;
}


void selectCPU(int chosenCPU, GameManager* game) { //inf loop if string is entered
    top: 
    
    if (chosenCPU == 1){
        game->setPlayer2Name("Aang");
        game->set_P2MomBend("Air");
        game->set_P2DadBend("Air");

    }
    else if (chosenCPU == 2){
        game->setPlayer2Name("Katara");
        game->set_P2MomBend("Water");
        game->set_P2DadBend("Water");
    }
    else if (chosenCPU == 3){
        game->setPlayer2Name("Toph");
        game->set_P2MomBend("Earth");
        game->set_P2DadBend("Earth");
    }
    else if (chosenCPU == 4){
        game->setPlayer2Name("Zuko");
        game->set_P2MomBend("Fire");
        game->set_P2DadBend("Fire");
    }
    else if (chosenCPU == 5){
        game->setPlayer2Name("Sokka");
        game->set_P2MomBend("None");
        game->set_P2DadBend("None");
    }
    else if (chosenCPU == 6){
        int randomChoice = rand() % 5 + 1; // generate random number between 1-5
        chosenCPU = randomChoice; // set the CPU choice to the random choice
        goto top; // go back to the top and handle the new choice
    }
}