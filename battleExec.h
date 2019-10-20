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
#include "PowerUpBoard.h"
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

    /**
     *@pre Single Player only. Prints difficulty menu for user to select from.
     *@post someAI's difficulty gets set to user selected value 1. Easy, 2. Medium, 3. Hard. Checks user for bad input.
     *@param someAI is an AI object that will set it's difficulty to a string after passing an int (1, 2, 3) into it's own setDifficulty method.
     *return None. */
    void setAIDifficulty(AI& someAI);

    /** set targetCoordinates array
     *@pre none
     *@post populates targetCoordinates with all board coordinates and then shuffles the array values
     *@param none */
    void setTargetCoordinates();

    /** shuffles targetCoordinates array values
     *@pre setTargetCoordinates() is called.
     *@post uses random_shuffle function to shuffle targetCoordinates array
     *@param arr[] is the targetCoordinates array
     *@param n is size of the targetCoordinates array */
    void shuffleCoordinates(string arr[], int n);

    /** prints targetCoordinates array values
     *@pre none
     *@post prints targetCoordinates array,
     *@post targetCoordinates array can also be shuffled and contain coordinates not called for random firing from AI. */
    void printRandomCoordinates();

    /**
     *@pre User selects AI difficulty to be 'Easy'
     *@post AI attacks spaces based on a shuffled array of Battleship labels (A1, A2...) then converts label into integer coordinates
     *@param someAI AI object to update its grid
     *@param somePlayer HumanPlayer object to access its attack method
     *@param row update member variable row
     *@param col update member variable col
     *@return None.*/
    void easyAIAttack(AI& someAI, HumanPlayer& somePlayer, int& row, int& col);

    /**
     *@pre User selects AI difficulty to be 'Medium'
     *@post Default: AI attacks at random. Refer to easyAIAttack. If AI hits: checks above that space, then right, then left, then down.
     *@param someAI AI object to update its grid
     *@param somePlayer HumanPlayer object to access its attack method
     *@param row update member variable row
     *@param col update member variable col
     *@return None.*/
    void mediumAIAttack(AI& someAI, HumanPlayer& somePlayer, int& row, int& col, int& turn);

    /**
     *@pre User selects AI difficulty to be 'Hard'
     *@post AI knows exactly where somePlayer hid their ships and will only attack those spaces occupied by ships.
     *@param someAI AI object to update its grid
     *@param somePlayer HumanPlayer object to access its attack method
     *@param row update member variable row
     *@param col update member variable col
     *@return None.*/
    void hardAIAttack(AI& someAI, HumanPlayer& somePlayer, int& row, int& col, int& turn);

    void p1StandardShot(HumanPlayer& player1, HumanPlayer& player2);
    void p2StandardShot(HumanPlayer& player2, HumanPlayer& player1);

    void p1PowerShot(HumanPlayer& player1, HumanPlayer& player2, string shotType);
    void p2PowerShot(HumanPlayer& player2, HumanPlayer& player1, string shotType);

    void p1InputCheck(HumanPlayer& player1, HumanPlayer& player2);
    void p2InputCheck(HumanPlayer& player2, HumanPlayer& player1);
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

    PowerUpBoard LootBoard;
    bool player1_PowerUpEnabled = false;
    bool player2_PowerUpEnabled = false;

    int turn = 0;
    int coordinatesArraySize = 64; //size of shuffled battleship labels
    string targetCoordinates[64]; //array of shuffled battleship labels

};
#endif
