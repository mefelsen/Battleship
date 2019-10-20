#ifndef AI_H
#define AI_H

#include <iostream>
#include "board.h"
#include "PlayerInterface.h"
#include <time.h>
using namespace std;

class AI : public PlayerInterface
{
  private:
    Board aiBoard;//access the board object
    string marks;
    int marked;//ships that are marked
    int unmark;//ships that are unmarked
    int num_hits;
    int numOfShip;

    string difficultyAI; //AI difficulty
    bool isAHit; //true if AI hit a player ship, false otherwise.

    int mediumRow; //keeps tracks of battleExec member variable row for medium difficulty
    int mediumCol; //keeps tracks of battleExec member variable col for medium difficulty

  public:
     /**
      *@pre Constructor. Callled when AI object is created.
      *@post sets marks = "abcde", num_hits = 0, marked = 0, isAHit = false.
      *@param None.
      *@return None. */
     AI();

     /**
      *@pre takes in a integer x
      *@post set up # of ships and set those ships are unmark
      *@param None.
      *@return None. */
     void setNum(int x);

     /**
      *@pre take in three integers x is row, y is col, z is the direction(1~4)
      *@post throw a error when the direction is wrong and catch a error when placment fails
      *@param None.
      *@return None. */
     void placement(int x, int y, int z);

     /**
      *@pre None
      *@post None.
      *@param None.
      *@return True if all ships marked, false otherwise. */
     bool isAllMarked();

     /**
      *@pre Gets the number of times a player has hit the enemies's ships
      *@post None.
      *@param None.
      *@return # of ship parts remaining */
     int getHits();

     /**
      *@pre calls the board class to compare char and attck if match is found
      *@post handles the attack/comparison
      *@param  takes in the x and y coordiinate of where the player would like to attack
      *@return True if can attack at [row][col], false otherwise. */
     bool attack(int x, int y);

     /**
      *@pre calls the board class to compare char and update the board
      *@post handles the attack/comparison
      *@param  takes in the x and y coordiinate of where the player would like to attack
        the bool is for determining if it was a success or not -- "x" or "o"
      *@return None. */
     void update(int, int, bool);

    /** retry if you've already shot at the same location twice
     *@pre none
     *@post checks to see if a space has already been hit or not.
     *@param  takes in the x and y coordiinate of where the player would like to attack
     *@return true if spot has been hit before, false otherwise */
     bool hitRetry(int x, int y);

     /**
      *@pre Input taken from user to set difficulty.
      *@post Takes an int passed in from battleExec, sets ai difficulty
      *@param difficulty is a number 1-3 depending on level of difficulty
      *@return None. */
     void setDifficulty(int difficulty);

     /**
      *@pre None.
      *@post None.
      *@param None.
      *@return Member variable difficulty */
     string getDifficulty();

     /**
      *@pre Called from battleExec
      *@post Checks to see if AI lands a hit.
      *@param None.
      *@return True if lands a hit, false otherwise. */
     bool getIsAHit();

     /**
      *@pre Called from battleExec
      *@post Lets the AI class know if a hit was made.
      *@param flag - true or false
      *@return None. */
     void setIsAHit(bool flag);

     /**
      *@pre None.
      *@post None.
      *@param None.
      *@return Member variable mediumRow */
     int getMediumRow();

     /**
      *@pre None.
      *@post None.
      *@param None.
      *@return Member variable mediumCol */
     int getMediumCol();

     /**
      *@pre Row must be a valid row.
      *@post Sets member variable mediumRow to row to keep track
      *@param row is a temporary row gathered from battleExec
      *@return None. */
     void setMediumRow(int row);

     /**
      *@pre Col must be a valid row.
      *@post Sets member variable mediumCol to col to keep track
      *@param col is a temporary col gathered from battleExec
      *@return None. */
     void setMediumCol(int col);

};
#endif
