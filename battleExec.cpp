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
#include "board.h"
#include "player.h"
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;

Executive::Executive()
{
    ship_num = 0; //sets starting ship amount to zero

}

void Executive::run()
{
  string spot;
  string dir;
  startMenu(); //opens start menu
  player player1(ship_num); //creates player 1 with the number of ships obtained from input
  player player2(ship_num); //creates player 2 with the same number of ships as p1
  cout << endl;
  board board1; //creates board for player 1
  board board2; //creates board for player 2
  board board1Hidden; //creates the hidden version of board1
  board board2Hidden; //creates the hidden version of board2
  cout << "PLAYER 1: Place your ships.\n";
  board1.PrintMap(); //prints out map for player to see
  for(int i = 0; i < ship_num; i++) //placing ships
  {
    cout << "Where to place ship " << (i+1) << "?\n";
    // FROM HERE OUT, also need error checking for when someone enters nonsense
    cin >> spot;
    //here we parse spot and use it to get the 'x' and 'y' for
    //PlaceShip() and MarkShip()
    if(i > 0)
    {
      cout << "Choose what direction the ship will be facing (up, down, left, right): ";
      cin >> dir;
    } //this is 'z' in PlaceShip() and MarkShip()
  }
  cout << "PLAYER 2: Place your ships.\n";
  board2.PrintMap(); //prints out map for player to see
  for(int i = 0; i < ship_num; i++) //placing ships
  {
    cout << "Where to place ship " << (i+1) << "?\n";
    cin >> spot;
    //here we parse spot and use it to get the 'x' and 'y' for
    //PlaceShip() and MarkShip()
    if(i > 0)
    {
      cout << "Choose what direction the ship will be facing (up, down, left, right): ";
      cin >> dir;
    } //this is 'z' in PlaceShip() and MarkShip()
  }
  while(player1.current_hits != win_hits && player2.current_hits != win_hits) {
      //attack method here
      //make sure to increment current hits if attack method hits enemy ship
  }
  if(player1.current_hits == win_hits) cout << "Player1 Wins!\n";
  else cout << "Player2 Wins!\n"
  return;

}

Executive::~Executive()
{

}

void Executive::startMenu()
{
  cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
       << "x                  Battleship                x\n"
       << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n"
       << "Enter the number of ships for this game (You may have up to 5 ships): ";
  cin >> ship_num;
  while((ship_num < 1) || (ship_num > 5))
  {
    cout << "You must enter a number between 0 and 5, try again.\n"
         << "Enter the number of ships for this game (You may have up to 5 ships): ";
    cin >> ship_num;
  } //need to do error handling for the case in which user does not enter an int i.e.: "asdf"
}
void Executive::ClearScreen()
{
  cout << "Switching Players in\n";
  usleep(1000000);
  cout << "3\n";
  usleep(1000000);
  cout << "2\n";
  usleep(1000000);
  cout << "1\n";
  usleep(1000000);
  for(int i = 0; i < 100; i++)
  {
    cout << '\n';
  }
}
void Executive::CalculateWinHits()
{
  for(int i = ship_num; i > 0; i--)
  {
    win_hits += ship_num;
  }
}
