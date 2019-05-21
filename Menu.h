#ifndef ASSIGNMENT_2_MENU
#define ASSIGNMENT_2_MENU

#include "GameEngine.h"

class Menu{

public:

    Menu();
    void runProgram();
    void playGame();
    void loadGame();

    void printMenu();
    void showStudentInformation();

    // accept player names from user
    std::string inputPlayerNames(int player);

    //check player name is all uppercase characters
    bool validatePlayerName(std::string playerName);

    bool checkFileExist(std::string& fileName);
    bool validateFormat(std::string& fileName);
    bool checkFormatForPlayerHand(std::string& playerHand);

private:
    GameEngine gameEngine;



};

#endif //ASSIGNMENT_2_MENU
