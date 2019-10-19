/** -----------------------------------------------------------------------------
 *
* File Name: board.h
* Author: Matt Felsen
* Assignment:   EECS-448 Project Battleship
* Description:  Handles Console Output of Board
* Date: 9-14-19
*
---------------------------------------------------------------------------- */
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <limits>

using namespace std;

class Board {
public:
  /** Prints board to console
 *@pre none
 *@post n/a
 *@param None  */
  void PrintMap();

  /** Default constructor
 @pre
 @post
 @param None  */
  Board();

  /** notify player of all active ships
 *@pre PrintMap is called
 *@post statusReport will notify the player of any ships active during gameplay
 *@param None  */
  void statusReport();

  /** Checks if the position does not exceed board boundary
 *@pre none
 *@post returns true if ship placement is valid, false if not valid
 *@param x,y are position. x is horizontal position, y is vertical position,
 num is the size of the ship in question. z is the orientation (up,down,left,right)
   */
  bool DimensionCheck(int x, int y, int num, string z);

  /** Checks if the position does not run into existing
 *@pre none
 *@post returns true if ship placement is valid, false if not valid
 *@param x,y are position. x is horizontal position, y is vertical position,
 num is the size of the ship in question. z is the orientation (up,down,left,right)
   */
  bool OverlapCheck(int x, int y, int num, string z);

  /** Checks if input values are safe (within the grid)
 *@pre none
 *@post returns true if valid, false if not valid
 *@param x,y are position. x is horizontal position, y is vertical position,
 num is the size of the ship in question. z is the orientation (up,down,left,right),mark is a flag for a single ship
   */
  bool PlaceShip(int x, int y, string z, int num, char mark);

  /** Places ship on board (changes ~ to A)
 *@pre none
 *@post none
 *@param x,y are position. x is horizontal position, y is vertical position,
 num is the size of the ship in question. z is the orientation (up,down,left,right), mark is a flag for a single ship
   */
  void MarkShip(int x,int y,int num, string z,char mark);

  /** Checks for hit
 *@pre none
 *@post none
 *@param x,y are position. x is horizontal position, y is vertical position,
    */
  bool Attack(int, int);

  /** Prints the hidden board to console
 *@pre
 *@post
 *@param None  */
  void PrintGrid();

  /** Prints the PowerUp board. USE FOR TESTING PURPOSES
 *@pre
 *@post
 *@param None  */
  //void PrintPowerUpMap();

  /** updates the hidden board to reflect players attack
 *@pre
 *@post
 *@param  the x and y coordinates of the place to update the map
 the bool is for determining if it was a success or not -- "x" or "o"  */
  void update(int,int, bool);

  /** If a player already attempted to hit a targe this is a check to retry
 *@pre
 *@post
 *@param  the x and y coordinates of the place to check if it has a 'o'
 the bool is for determining if it was a success or not  */
  bool retryCheck(int x, int y);

  /** Array shuffle function for the powerup board.
  *@pre powerup array is already made, and the board is already made.
  *@post will shuffle an array containgin the indecies for where the power ups will be located.
  *@param  int powerUpPos[] - the array to be shuffled so random number can be selected without repeats.
           int size - the size of the array to be shuffled.
  */
  //void shuffleArray(int powerUpPos[], int size);
  //void setNumPowerUps(int n);

  char** getMap();

  char** getGrid();


private:
  /**
  grid = enemy board
  map = personal board
  actives = is ship being used and not sunken during current game
  shipsRemaining = number of ships remaining on the personal board during gameplay
  */
  //char powerUps[8][8];
  char** grid;
  char** map;
  bool aActive, bActive, cActive, dActive, eActive;
  int shipsRemaining;
};

#endif
