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
#include "battleExec.h"
#include <iostream>

Executive::Executive()
{
    ship_num = 0;
}

Executive::~Executive()
{

}

void Executive::startMenu()
{
  std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
            << "                   Battleship\n"
            << "Enter the number of ships(You may have up to 5 ships): \n";
  std::cin >> ship_num;

}

