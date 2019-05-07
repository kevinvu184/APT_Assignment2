#include "Menu.h"
#include<iostream>
#include<fstream>
#include<array>
#include<sstream>
#include<string> 
#include <bits/stdc++.h>

Menu::Menu()
{
    gameEngine = GameEngine();
}

void Menu::runProgram()
{

   int userInput = 0;
   std::string line;

   std::cout << "\n\nWelcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;

    do {
     printMenu();
     std::cin >> userInput;

     // Validate userInput
     if( !(std::cin.eof()) and ((userInput < 1) or (userInput > 4) or (!std::cin)) ){
       std::cin.clear();
       std::cout << "Invalid Input" << std::endl;
     }
     else{
         if ( userInput == 1 ){ 
           playGame();
         }
         else if( userInput == 2){
           loadGame();
         }
         else if( userInput == 3){
           showStudentInformation();
         }
         else
         {
           std::cout<<"\nGoodbye\n";
         }
         
       }
     } while ( (std::getline(std::cin, line)) && (userInput != 4) );

   


}

bool Menu::checkForNameInput(std::string name)
{
  bool result = true;

  int size = name.size();

  char cArray[size + 1];

  strcpy(cArray, name.c_str());

  for(int i = 0; i < size && result == true; i++)
  {
    //ASCII A-Z:65-90 , a-z:97-122, space:32  -> different than these then set result = false
    if((cArray[i] < 65 || cArray[i] > 90) && cArray[i] != 32)
    {
      result = false;
    }
  }

  return result; 


}

void Menu::playGame()
{
    //read whitespace from previous input before use getline()
    std::cin.ignore();

    std::string p1 = "" ;
    std::string p2 ;

    //to check if it is the initial prompt  
    int count_1 = 0; 
    int count_2 = 0; 

    

    std::cout<<"\nStarting a New Game\n";
    
    do
    {
      if(count_1 == 0)
      {
        std::cout<<"\nEnter a name for player 1 (uppercase characters only)\n";
        std::cout<<"> ";
        
        std::getline(std::cin, p1);
        
      }
      count_1++;
      if(checkForNameInput(p1) == false)
      {
        std::cout<<"\nYour name may contain symbols or numbers or not in uppercase characters, please reenter\n";
        std::cout<<"> ";
        
        std::getline(std::cin, p1);
      }
      
    } while (!checkForNameInput(p1));
    
    do
    {
       if(count_2 == 0)
      {
        std::cout<<"\nEnter a name for player 2 (uppercase characters only)\n";
        std::cout<<"> ";
        std::getline(std::cin, p2);
       
      }
      count_2++;
      if(checkForNameInput(p2) == false)
      {
        std::cout<<"\nYour name may contain symbols or numbers or not in upper case characters, please reenter\n";
        std::cout<<"> ";
        std::getline(std::cin, p2);
     
      }
    } while (!checkForNameInput(p2));  
    
    std::cout<<"\n\nLet's Play!\n\n";
    gameEngine.playGame(p1,p2);
    
}

void Menu::loadGame()
{
  //call loadGame in GameEngine here
  //gameEngine.loadGame();



}

void Menu::printMenu(){
	std::cout << "Menu\n"
    "1. New Game\n"
	   "2. Load Game\n"
	   "3. Show student information\n"
	   "4. Quit\n"
     "> " << std::flush;
}

void Menu::showStudentInformation(){
  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "Name: Jessica Cruz" << std::endl;
  std::cout << "Student ID: s3571051" << std::endl;
  std::cout << "Email: s3571051@student.rmit.edu.au\n" << std::endl;

  std::cout << "Name: Kevin Vu" << std::endl;
  std::cout << "Student ID: s3678490" << std::endl;
  std::cout << "Email: s3678490@rmit.edu.vn\n" << std::endl;
  std::cout << "Name: Khoi Nguyen" << std::endl;
  std::cout << "Student ID: s3678755" << std::endl;
  std::cout << "Email: s3678755@rmit.edu.vn\n" << std::endl;

  std::cout << "Name: Tuan Vu" << std::endl;
  std::cout << "Student ID: s3678491" << std::endl;
  std::cout << "Email: s3678491@rmit.edu.vn" << std::endl;

  std::cout << "---------------------------------------------\n" << std::endl;
}


