#include "../header/PrintMenu.h"
#include "../header/GameManager.h"
#include "../header/GatherBends.h"


void runSinglePlayer(GameManager* game){
    string user1Name = game->get_P1Name();

    questionUserMother(user1Name);
    game->set_P1MomBend(gatherIntelMother(user1Name));
        
    questionUserFather(user1Name);
    game->set_P1DadBend(gatherIntelFather(user1Name));

}

void runMultiPlayer(GameManager* game){
    string user1Name = game->get_P1Name();

    questionUserMother(user1Name);
    game->set_P1MomBend(gatherIntelMother(user1Name));
        
    questionUserFather(user1Name);
    game->set_P1DadBend(gatherIntelFather(user1Name));

    string user2Name = game->get_P2Name();

    questionUserMother(user2Name);
    game->set_P2MomBend(gatherIntelMother(user2Name));
        
    questionUserFather(user2Name);
    game->set_P2DadBend(gatherIntelFather(user2Name));
}