/* -----------------------------------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Matthew Felson
 * Assignment: EECS-448 Project1
 * Description:  Handles terminal interaction to hand data to battleExec class
 * Date: 9-12-19
 *
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "board.h"
#include "battleExec.h"
//using namespace std;

int main() {

  Executive start;
  start.startMenu();
  
  board player1_grid;
  player1_grid.printBoard();
  return 0;
}
