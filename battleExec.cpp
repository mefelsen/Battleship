/* -----------------------------------------------------------------------------
 *
* File Name: battleExec.cpp
* Author: Blk Morrell
* KU ID: 28653
* Email Adress: blk459@ku.edu
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
bool Executive::inputchecker(string x)
{
  string y = "ABCDEFGH";
  string z = "abcdefgh";
  char word = x.at(1);
  bool flag = false;
  for (int i = 0; i < 8; i++)
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
  else if (!inputchecker(x))
  {
    return false;
  }
  else if (transtoint(x.at(1)) && transfromchar(stoi(x.substr(0, 1))))
  {

    //cout << "row: " << row << " col: " << col << endl;
    return true;
  }
  else
  {
    cout<<"input does not transfor"<<endl;
    return false;
  }
}

bool Executive::transfromchar(int x)
{
  bool flag = false;
  for (int i = 0; i <=8; i++)
  {
    if (x == i)
    {
      row = i - 1;
      flag = true;
    }
  }
  return flag;
}
bool Executive::transtoint(char x)
{
  string y = "ABCDEFGH";
  string z = "abcdefgh";
  bool flag = false;
  for (int i = 0; i < 8; i++)
  {
    if (x == y.at(i) || x == z.at(i))
    {
      col = i;
      flag = true;
    }
  }
  return flag;
}

void Executive::testrun()
{
  int num;
  int x, y, z;
  cout << "num:";
  cin >> num;
  one.setnum(num);
  one.print();
  while (!one.IsAllMarked())
  {
    cout << "row";
    cin >> x;
    cout << "col";
    cin >> y;
    cout << "1.up 2.down 3.left 4.right";
    cin >> z;
    try
    {
      one.placement(x - 1, y - 1, z);
    }
    catch (const std::runtime_error &e)
    {
      cout << "enter a correct direction!" << endl;
    }
    one.print();
  }
}
void Executive::testrun2()
{
  string x;
  cout << "give a co eg 1A,1 is row A is col:" << endl;
  cin >> x;
  //cout<<x.size()<<endl;
  if (transfor(x))
  {
    cout << "row: " << row << " col: " << col << endl;
  }
}

void ::Executive::testrun3()
{
  int num;
  int z;
  string line;
  cout << "num:";
  cin >> num; // !!
  one.setnum(num);
  one.print();
  while (!one.IsAllMarked())
  {
    cout << "give a co eg 1A,1 is row A is col:" << endl;
    cin >> line;
    if (transfor(line))
    {
      //cout << "row: " << row << " col: " << col << endl;

      cout << "1.up 2.down 3.left 4.right";
      cin >> z; //!!

      try
      {
        one.placement(row, col, z);
      }
      catch (const std::runtime_error &e)
      {
        cout << "enter a correct direction!" << endl;
      }
      one.print();
    }
    else
    {
      cout << "input !" << endl;
    }
  }
}
