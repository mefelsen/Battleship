/* -----------------------------------------------------------------------------
 *
* File Name: battleExec.cpp
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
//#include <fstream>
#include <limits>


class Executive
{
public:
    /** funtion that runs the program
    @pre
    @post runs the program
    @param None  */
    void run();

    /** Default constructor
   @pre
   @post class that houses the functions that will run the program
   @param None  */
    Executive();

    /** destructor
     @pre
     @post
     @param None  */
    ~Executive();


    /** function to print the inital starting screen
     @pre  N/A
     @post sets up a game of Battleship
     @param None  */
    void startMenu();

    /** Clears the screen for the next player
     @pre  N/A
     @post Empty console screen
     @param None  */
    void ClearScreen();

    /**
     @pre
     @post checks if the input is valid
     @param takes a string **/
    bool inputChecker(std::string x);

    /**
     @pre
     @post takes a string input, parses and transforms into coordinates for the board
     @param takes in a string **/
    bool transfor(std::string x);

    /**
     @pre
     @post transforms the char into coordinates for the board
     @param takes in a char **/
    bool transtoint(char x);

    /**
     @pre
     @post transforms the string int into an int which is coordinates for the board
     @param takes an int **/
    bool transfromchar(int x);


private:

      int row;
      int col;
      int ship_num;

};
#endif
