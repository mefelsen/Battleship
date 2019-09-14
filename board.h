/* -----------------------------------------------------------------------------
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
#include"player.h"
using namespace std;



class board {
public:
  /* Prints board to console
 @pre
 @post
 @param None  */
  void PrintMap();

  /* Default constructor
 @pre
 @post
 @param None  */
  board();

  /* Checks if the position does not exceed board boundary
 @pre none
 @post returns true if ship placement is valid, false if not valid
 @param x,y are position. x is horizontal position, y is vertical position,
 num is the size of the ship in question. z is the orientation (up,down,left,right)
   */
  bool DimensionCheck(int x, int y, int num, string z);

  /* Checks if the position does not run into existing
 @pre none
 @post returns true if ship placement is valid, false if not valid
 @param x,y are position. x is horizontal position, y is vertical position,
 num is the size of the ship in question. z is the orientation (up,down,left,right)
   */
  bool OverlapCheck(int x, int y, int num, string z);

  /* Checks if input values are safe (within the grid)
 @pre none
 @post returns true if valid, false if not valid
 @param x,y are position. x is horizontal position, y is vertical position,
 num is the size of the ship in question. z is the orientation (up,down,left,right),mark is a flag for a single ship
   */
  bool PlaceShip(int x, int y, string z, int num,char mark);

  /* Places ship on board (changes ~ to A)
 @pre none
 @post none
 @param x,y are position. x is horizontal position, y is vertical position,
 num is the size of the ship in question. z is the orientation (up,down,left,right), mark is a flag for a single ship
   */
  void MarkShip(int x,int y,int num, string z,char mark);
private:
  /*

  */
  char grid[8][8];
  char map[8][8];

};

#endif
