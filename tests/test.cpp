#include "gtest/gtest.h" 
#include "../header/GameManager.h" 
#include "../header/GatherBends.h"
#include "../header/BattleManager.h"

TEST(avatarTests, checkP1Name) { 
    GameManager game;
    game.setPlayer1Name("TEST");
    EXPECT_EQ(game.get_P1Name(), "TEST");
}

TEST(avatarTests, checkP2Name) { 
    GameManager game;
    game.setPlayer2Name("TEST");
    EXPECT_EQ(game.get_P2Name(), "TEST");
}

TEST(avatarTests, checkP1Bend) { 
    GameManager game;
    game.set_P1Bend("fire");
    EXPECT_EQ(game.get_P1Bend(), "fire");
}

TEST(avatarTests, checkP2Bend) { 
    GameManager game;
    game.set_P1Bend("Water");
    EXPECT_EQ(game.get_P1Bend(), "Water");
}

TEST(avatarTests, checkP2MomBend) { 
    GameManager game;
    game.set_P1Bend("Water");
    EXPECT_EQ(game.get_P1Bend(), "Water");
}


TEST(avatarTests, checkBendCalcWithSameBend){
    GameManager game;
    game.set_P1MomBend("Water");
    game.set_P1DadBend("Water");
    determineBend(&game);

    EXPECT_TRUE(game.get_P1Bend() == "Water");
}

TEST(avatarTests, checkBendCalcWithDiffBend){
    GameManager game;
    game.set_P1MomBend("Water");
    game.set_P1DadBend("Fire");
    determineBend(&game);

    EXPECT_TRUE(game.get_P1Bend() == "Water" || game.get_P1Bend() == "Fire");
    EXPECT_TRUE(game.get_P1Bend() != "Earth" || game.get_P1Bend() != "Air");
}

TEST(avatarTests, checkAangCPU){
    GameManager game;
    selectCPU(1, &game);
    determineBend(&game);                           // determineBend is tested
    EXPECT_TRUE(game.get_P2Name() == "Aang");
    EXPECT_TRUE(game.get_P2MomBend() == "Air");
}

TEST(avatarTests, checkKataraCPU){
    GameManager game;
    selectCPU(2, &game);
    determineBend(&game);                           // determineBend is tested
    EXPECT_TRUE(game.get_P2Name() == "Katara");
    EXPECT_TRUE(game.get_P2MomBend() == "Water");
}

TEST(avatarTests, checkTophCPU){
    GameManager game;
    selectCPU(3, &game);
    determineBend(&game);                           // determineBend is tested
    EXPECT_TRUE(game.get_P2Name() == "Toph");
    EXPECT_TRUE(game.get_P2MomBend() == "Earth");
}

TEST(avatarTests, checkZukoCPU){
    GameManager game;
    selectCPU(4, &game);
    determineBend(&game);                           // determineBend is tested
    EXPECT_TRUE(game.get_P2Name() == "Zuko");
    EXPECT_TRUE(game.get_P2MomBend() == "Fire");
}

TEST(avatarTests, checkSokkaCPU){
    GameManager game;
    selectCPU(5, &game);
    determineBend(&game);                           // determineBend is tested
    EXPECT_TRUE(game.get_P2Name() == "Sokka");
    EXPECT_TRUE(game.get_P2MomBend() == "None");
}

TEST(avatarTests, checkRandomCPU){
    GameManager game;
    selectCPU(6, &game);
    determineBend(&game);                           // determineBend is tested
    EXPECT_TRUE(game.get_P2Name() == "Aang" || game.get_P2Name() == "Katara" || game.get_P2Name() == "Toph" || game.get_P2Name() == "Zuko" || game.get_P2Name() == "Sokka");
}

TEST(BendingManagerTest, bendingManagerConstructor){
    BendingManager player1("Water");;
    EXPECT_TRUE(player1.get_health() == 100);
}

TEST(BendingManagerTest, takeDamageWater){
    BendingManager player1("Water");
    player1.TakeDamage(5);
    EXPECT_TRUE(player1.get_health() == 95);
}

TEST(BendingManagerTest, takeDamageAir){
    BendingManager player1("Air");
    player1.TakeDamage(5);
    EXPECT_TRUE(player1.get_health() == 95);
}

TEST(BendingManagerTest, takeDamageEarth){
    BendingManager player1("Earth");
    player1.TakeDamage(5);
    EXPECT_TRUE(player1.get_health() == 95);
}

TEST(BendingManagerTest, takeDamageFire){
    BendingManager player1("Air");
    player1.TakeDamage(5);
    EXPECT_TRUE(player1.get_health() == 95);
}

TEST(BendingManagerTest, takeDamageNonBender){
    BendingManager player1("None");
    player1.TakeDamage(5);
    EXPECT_TRUE(player1.get_health() == 95);
}


TEST(BendingManagerTest, FireDefense){   // Fire should have 100 defense
    BendingManager player1("Fire");
    EXPECT_TRUE(player1.get_defense() == 100); 
}

TEST(BendingManagerTest, WaterDefense){   // Water should have 100 defense
    BendingManager player1("Water");
    EXPECT_TRUE(player1.get_defense() == 100); 
}

TEST(BendingManagerTest, AirDefense){   // Air should have 100 defense
    BendingManager player1("Air");
    EXPECT_TRUE(player1.get_defense() == 90); 
}

TEST(BendingManagerTest, EarthDefense){   // Air should have 100 defense
    BendingManager player1("Earth");
    EXPECT_TRUE(player1.get_defense() == 120); 
}

TEST(BendingManagerTest, FireHealth){   // Fire should have 100 Health
    BendingManager player1("Fire");
    EXPECT_TRUE(player1.get_health() == 100); 
}


TEST(BendingManagerTest, WaterHealth){   // Water should have 100 Health
    BendingManager player1("Water");
    EXPECT_TRUE(player1.get_health() == 100); 
}

TEST(BendingManagerTest, AirHealth){   // Air should have 100 Health
    BendingManager player1("Air");
    EXPECT_TRUE(player1.get_health() == 100); 
}

TEST(BendingManagerTest, EarthHealth){   // Air should have 100 Health
    BendingManager player1("Earth");
    EXPECT_TRUE(player1.get_health() == 100); 
}


// need to unit test elemental functions before testing rest of BendingManager functions
TEST(PersonFunctions, checkDamage){
    AirClass player1;
    player1.damage_taken(100);
    EXPECT_TRUE(player1.get_health() == 0);
}

TEST(PersonFunctions, checkAddHealth){
    AirClass player;
    player.damage_taken(100);
    player.add_health(36);
    EXPECT_TRUE(player.get_health() == 36);
}

TEST(PersonFunctions, checkAddHealthOver100){
    AirClass player;
    player.add_health(500);
    EXPECT_TRUE(player.get_health() <= 140);
}

TEST(BendingManagerFunctions, checkDodge){
    BendingManager player("Air");
    EXPECT_TRUE(player.Dodge() == true);
}

TEST(BendingManagerFunctions, checkDodgeFail){
    BendingManager player("Air");
    EXPECT_TRUE(player.Dodge() == true);
}

TEST(BendingManagerFunctions, basicAttackWater){
    WaterClass player;
    EXPECT_TRUE(player.basic_attack("Water") >= 9);  //9+rand()%5
     EXPECT_TRUE(player.basic_attack("Water") <= 12);
}

TEST(BendingManagerFunctions, basicAttackEarth){
    EarthClass player;
    EXPECT_TRUE(player.basic_attack("Earth") >= 6); //6+rand()%5
    EXPECT_TRUE(player.basic_attack("Earth") <=10);
}

TEST(BendingManagerFunctions, basicAttackFire){
    FireClass player;
    EXPECT_TRUE(player.basic_attack("Fire") >= 9); //9+rand()%5
    EXPECT_TRUE(player.basic_attack("Fire") <= 13);
}

TEST(BendingManagerFunctions, basicAttackAir){
    AirClass player;
    EXPECT_TRUE(player.basic_attack("Air") >= 9);  //6+rand()%5
    EXPECT_TRUE(player.basic_attack("Air") <= 13);
}

TEST(BendingManagerFunctions, basicAttackNonBender){
    NON_BENDERClass player;
    EXPECT_TRUE(player.basic_attack("None") >= 10); //10+rand()%5
    EXPECT_TRUE(player.basic_attack("None") <= 14);
}

TEST(BendingManagerFunctions, SpecialAttackWater){
    WaterClass player;
    player.damage_taken(50);
    player.special_attack();  // should heal by 20
    EXPECT_TRUE(player.get_health() == 70);
}

TEST(BendingManagerFunctions, SpecialAttackEarth){
    EarthClass player;
    player.set_defense(0);
    player.special_attack();  // should set defense to 150
    EXPECT_TRUE(player.get_defense() == 150);
}

TEST(BendingManagerFunctions, SpecialAttackAir){
    AirClass player;
    for (int i = 0; i < 10; ++i){
        player.special_attack();      // air bender special attack always gives more dodge
        EXPECT_TRUE(player.dodge() == true); // should never return false
    }
}

TEST(BendingManagerFunctions, SpecialAttackFire){
    FireClass player;
    EXPECT_TRUE(player.special_attack() >= 18);
}

TEST(BattleManager, dodgeConstructor){
    BattleManager battle;
    EXPECT_TRUE(battle.getBattleDodge() == false); // automatically false
}


TEST(BattleManager, dodgeTrue){
    BattleManager battle;
    battle.setBattleDodge(true, 100);
    EXPECT_TRUE(battle.getBattleDodge() == true);
}

TEST(BattleManager, dodgeFalse){
    BattleManager battle;
    battle.setBattleDodge(false,100);
    EXPECT_TRUE(battle.getBattleDodge() == false);
}

TEST(BattleManager, attackConstructor){
    BattleManager battle;
    EXPECT_TRUE(battle.getBattleAttack() == "");
}

TEST(BattleManager, getAttack){
    BattleManager battle;
    battle.setBattleAttack("Blast");
    EXPECT_TRUE(battle.getBattleAttack() == "Blast");
}

TEST(BattleManager, getAttackwithSpace){
    BattleManager battle;
    battle.setBattleAttack("Fire Blast");
    EXPECT_TRUE(battle.getBattleAttack() == "Fire Blast");
}

TEST(Arena, checkArenaConstructor){
    Arena arena;
    EXPECT_TRUE(arena.getArenaName() == "Fire Nation" || arena.getArenaName() == "Earth Nation" || arena.getArenaName() == "Air Nation" || arena.getArenaName() == "Water Nation" );
}

TEST(Arena, checkArenaConstructor2){
    Arena arena;
    EXPECT_TRUE(arena.getTimeTillNextArena() == 5);
}

TEST(Arena, checkChangeArena){
    Arena arena;
    arena.changeArena();
    EXPECT_TRUE(arena.getArenaName() == "Water Nation" || arena.getArenaName() == "Earth Nation" || arena.getArenaName() == "Air Nation" || arena.getArenaName() == "Fire Nation" );
}

TEST(Arena, checkDecreaseTimeTillNextArena){
    Arena arena;
    arena.DecreaseTimeTillNextArena();
    EXPECT_TRUE(arena.getTimeTillNextArena() == 4);
}