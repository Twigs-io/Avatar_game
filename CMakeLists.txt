CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(tests/googletest)

ADD_EXECUTABLE(rpg
    src/main.cpp
    src/GameManager.cpp
    src/BendingManager.cpp
    src/GatherBends.cpp
    src/PrintMenu.cpp
    src/SingleOrMulti.cpp
    src/BattleManager.cpp
    src/Arena.cpp
)

ADD_EXECUTABLE(test
    tests/mainTest.cpp 
    tests/test.cpp
    src/GameManager.cpp

    src/BendingManager.cpp
    src/GatherBends.cpp
    src/PrintMenu.cpp
    src/SingleOrMulti.cpp
    src/BattleManager.cpp
    src/Arena.cpp

)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)


