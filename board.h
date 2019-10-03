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
using namespace std;
class board {
public:
  /** Prints board to console
 *@pre
 *@post
 *@param None  */
  void PrintMap();

  /** Default constructor
 @pre
 @post
 @param None  */
  board();

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
  bool PlaceShip(int x, int y, string z, int num,char mark);

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


private:
  /**
  grid = enemy board
  map = personal board
  */
  char grid[8][8];
  char map[8][8];
  bool aRemaining, bRemaining, cRemaining, dRemaining, eRemaining;
  int shipsRemaining;

};

#endif
