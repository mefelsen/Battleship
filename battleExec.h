/** -----------------------------------------------------------------------------
 *
* File Name: battleExec.h
* Author: Blake Morrell
* KU ID: 2866535
* Email Adress: blknm4598@ku.edu
* Assignment:   EECS-448 Project Battleship
* Description:  Handles User input for how many ships
* Date: 9-12-19
*
---------------------------------------------------------------------------- */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
//#include "player.h" //Not sure how this got back in the repo, I changed player class and file to HumanPlayer since we're inheriting from interface.
#include "HumanPlayer.h" //For now, try to stick with HumanPlayer when creating objects.
#include "AI.h"
#include <fstream>
#include <limits>
#include <time.h>
using namespace std;

class Executive
{
public:
    /** funtion that runs the program
    *@pre
    *@post runs the program
    *@param None  */
    void run();

    /** Default constructor
   *@pre
   *@post class that houses the functions that will run the program
   *@param None  */
    Executive();

    /** destructor
     *@pre
     *@post
     *@param None  */
    ~Executive();

    /** funtion to print the inital starting screen
    *@pre N/A
    *@post sets up a player versus player game or player versus AI game
    *@param None  */
    void selectGame();

    /** function to print the inital starting screen
     *@pre  N/A
     *@post sets up a game of Battleship
     *@param None  */
    void startMenu();

    /** Clears the screen for the next player
     *@pre  N/A
     *@post Empty console screen
     *@param None  */
    void ClearScreen();

    /**
     *@pre
     *@post checks if the input is valid
     *@param takes a string */
    bool inputChecker(std::string x);

    /**
     *@pre
     *@post takes a string input, parses and transforms into coordinates for the board
     *@param takes in a string */
    bool transfor(std::string x);

    /**
     *@pre
     *@post transforms the char into coordinates for the board
     *@param takes in a char */
    bool transtoint(char x);

    /**
     *@pre
     *@post transforms the string int into an int which is coordinates for the board
     *@param takes an int */
    bool transfromchar(int x);

    /** Calculated number of hits needed to win
     *@pre ship_num must be defined
     *@post updates win_hits from 0 to the total number of hits needed to win
     *@param ship_num is the number of ships each player has. used to calcualte total hits needed to win */
    void CalculateWinHits(int ship_num);

    void setAIDifficulty(AI& someAI);

    /** Random powerup location generator
   @pre powerUps 2D array is already built and initialized.
   @post powerUps 2D array will have random locations marked for the power ups.
   @param None  */
    void powerUpGenerator();

    void shuffleArray(int powerUpPos[], int size);

    void displayPowerUps();


private:

      /** funtion that runs a player versus player game
      *@pre player_num == 2
      *@post runs the PvP game
      *@param None  */
      void runPvP();

      /** funtion that runs a player versus AI game
      *@pre player_num == 1
      *@post runs the PvAI game
      *@param None  */
      void runPvAI();

      int row;
      int col;
      int ship_num;
      int player_num;

      int win_hits = 0;

      string location; //row and column on the map
      int dir; //direction that the ship faces

      int numPowerUps = 0;
      char powerUps [8][8];
};
#endif
