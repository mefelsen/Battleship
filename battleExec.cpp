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
#include <cctype>
#include <limits>
#include <iostream>
#include <unistd.h>
using namespace std;

Executive::Executive()
{
    ship_num = 0; //sets starting ship amount to zero
}

void Executive::run()
{
  string location; //row and column on the map
  int dir; //direction that the ship faces
  startMenu(); //opens start menu

  CalculateWinHits(ship_num);//ship_num is inputted by user, this function is called to find total hits to win game

  player player1; //creates player 1 with the number of ships obtained from input
  player1.setnum(ship_num);
  cout<<"\n---------PLAYER 1----------\n\n";
  player1.print();
  while(!player1.IsAllMarked())
  {
    cout<<"Pick which column (A-H) and row (1-8) (Must be in the form [col][row] i.e.: A1): ";
    cin>>location;
    if(transfor(location))
    {
    cout<<"Which direction will your ship face?\n"
        <<"Choose 1 for up, 2 for down, 3 for left, or 4 for right: ";
    cin>>dir;
    while(1) //checking for right input
    {
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
        cin >> dir;
      }
      else
      {
        break;
      }
    }
    while((dir < 1) || (dir > 4)) //error checking
    {
      cout<<"You must enter a number between 1 and 4. Try again: ";
      cin>>dir;
      while(1) //checking for right input
      {
        if(cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
          cin >> dir;
        }
        else
        {
          break;
        }
      }
    }
    try
    {
      player1.placement(row, col, dir);
    }
    catch (const std::runtime_error &e)
    {
      cout << "enter a correct direction!" << endl;
    }
  }
    player1.print();
}
    player player2; //creates player 1 with the number of ships obtained from input
    player2.setnum(ship_num);
    cout<<"\n---------PLAYER 2----------\n\n";
    player2.print();
    while(!player2.IsAllMarked())
    {
      cout<<"Pick which column (A-H) and row (1-8) (Must be in the form [col][row] i.e.: A1): ";
      cin>>location;
      if(transfor(location))
      {
      cout<<"Which direction will your ship face?\n"
          <<"Choose 1 for up, 2 for down, 3 for left, or 4 for right: ";
      cin>>dir;
      while(1) //checking for right input
      {
        if(cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
          cin >> dir;
        }
        else
        {
          break;
        }
      }
      while((dir < 1) || (dir > 4)) //error checking
      {
        cout<<"You must enter a number between 1 and 4. Try again: ";
        cin>>dir;
        while(1) //checking for right input
        {
          if(cin.fail())
          {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
            cin >> dir;
          }
          else
          {
            break;
          }
        }
      }
      try
      {
        player2.placement(row, col, dir);
      }
      catch (const std::runtime_error &e)
      {
        cout << "enter a correct direction!" << endl;
      }
  }
  }
  player2.print();
//  while(CalculateWinHits(num_ships) != )   /////add while loop to check win condition
  {   int x, y;
      cout<<"\n---------PLAYER 1----------\n\n";

      cout <<"Enter the coordinates for your attack: ";
      cin >>x;
      cin >>y;
    //  transfor(x);
      player1.attack(x,y);
      //player1.Play();
        cout<<"\n---------PLAYER 2----------\n\n";
      player2.Play();
  }

    //players attack here
    //while(player1.GetHits() != win_hits && player2.GetHits() != win_hits {
        //player attack method goes here
        //make sure to update each player's number of hits each time they hit a ship
    //}

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
  while(1) //checking for right input
  {
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
      cin >> ship_num;
    }
    else
    {
      break;
    }
  }
  while((ship_num < 1) || (ship_num > 5))
  {
    cout << "You must enter a number between 0 and 5, try again.\n"
         << "Enter the number of ships for this game (You may have up to 5 ships): ";
    cin >> ship_num;
    while(1) //checking for right input
    {
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
        cin >> ship_num;
      }
      else
      {
        break;
      }
    }
  }
}

bool Executive::inputChecker(string x)
{
  string y = "ABCDEFGH";
  string z = "abcdefgh";
  char word = x.at(0);
  bool flag = false;
  for(int i =0; i< 8; i++)
  {
    if (word == y.at(i) || word == z.at(i))
    {
      flag = true;
    }
  }
  return flag;
}
bool Executive::transfor(string x)
{
  //int value = stoi(x.substr(0, 1));
  //cout << value << endl;
  if (x.size() < 2 || x.size() != 2)
  {
    return false;
  }
  else if(!inputChecker(x))
  {
    return false;
  }
  else if (transtoint(x.at(0)) && transfromchar(stoi(x.substr(1, 1))))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Executive::transfromchar(int x)
{
  bool flag = false;
  for (int i = 1; i < 9; i++)
  {
    if (x == i)
    {
      row = i-1;
      flag = true;
    }
  }
  return flag;
}
bool Executive::transtoint(char x)
{
  string y = "ABCDEFGH";
  string z="abcdefgh";
  bool flag = false;
  for (int i = 0; i < 8; i++)
  {
    if (x == y.at(i)||x==z.at(i))
    {
      col = i;
      flag = true;
    }
  }
  return flag;
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

void Executive::CalculateWinHits(int ship_num)
{
    for(int i = ship_num; i > 0; i--)
    {
        win_hits += i;
    }
}
