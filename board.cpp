/* -----------------------------------------------------------------------------
 *
* File Name: board.cpp
* Author: Matt Felsen
* Assignment:   EECS-448 Project Battleship
* Description:  Handles Console Output of Board
* Date: 9-14-19
*
---------------------------------------------------------------------------- */
#include "board.h"
#include <iostream>
#include <string>
using namespace std;

board::board() {

  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      grid[i][j] = '~';
      map[i][j] = '~';
    }
  }
  shipsRemaining = 0;
}

void board::PrintMap() {
  aRemaining = false;
  bRemaining = false;
  cRemaining = false;
  dRemaining = false;
  eRemaining = false;
  shipsRemaining = 0;

  cout <<"\n       Your Board: \n\n";
  for(int i = 0; i < 8; i++) {
    if(i == 0) cout << "   A  B  C  D  E  F  G  H\n";
    for(int j = 0; j < 8; j++) {
      if(j == 0) cout << i+1;
       cout << "  " << map[i][j];
       if (map[i][j] == 'a') {
         aActive = true;
         aRemaining = true;
       }
       if (map[i][j] == 'b') {
         bActive = true;
         bRemaining = true;
       }
       if (map[i][j] == 'c') {
         cActive = true;
         cRemaining = true;
       }
       if (map[i][j] == 'd') {
         dActive = true;
         dRemaining = true;
       }
       if (map[i][j] == 'e') {
         eActive = true;
         eRemaining = true;
       }
    }
    cout << '\n';
  }

  cout<< "\n       Ship Legend:\n         a = Patrol Boat\n         b = Submarine\n         c = Destroyer\n         d = Battleship\n         e = Carrier\n\n";
  if (aActive) {
    if (aRemaining) {
      shipsRemaining++;
      cout<< "       Patrol Boat is active\n";
    } else {
      cout<< "       Patrol Boat has been sunk\n";
    }
  }
  if (bActive) {
    if (bRemaining) {
      shipsRemaining++;
      cout<< "       Submarine is active\n";
    } else {
      cout<< "       Submarine has been sunk\n";
    }
  }
  if (cActive) {
    if (cRemaining) {
      shipsRemaining++;
      cout<< "       Destroyer is active\n";
    } else {
      cout<< "       Destroyer has been sunk\n";
    }
  }
  if (dActive) {
    if (dRemaining) {
      shipsRemaining++;
      cout<< "       Battleship is active\n";
    } else {
      cout<< "       Battleship has been sunk\n";
    }
  }
  if (eActive) {
    if (eRemaining) {
      shipsRemaining++;
      cout<< "       Carrier is active\n";
    } else {
      cout<< "       Carrier has been sunk\n";
    }
  }

  if (shipsRemaining == 1) {
    cout << "\n       There is " << shipsRemaining << " ship currently active.\n";
  }
  else {
    cout << "\n       There are " << shipsRemaining << " ships currently active.\n";
  }
}

bool board::DimensionCheck(int x, int y, int num, string z)
{
    if (z == "up" && x - num+1 >= 0)
    {
        return true;
    }
    else if (z == "down" && x + num+1 <= 9)
    {
        return true;
    }
    else if (z == "left" && y - num+1 >= 0)
    {
        return true;
    }
    else if (z == "right" && y + num+1 <= 9)
    {
        return true;
    }
    else
    {
        cout<<"Out of Board!"<<endl;
        return false;
    }
}

bool board::OverlapCheck(int x, int y, int num, string z)
{
    if (num > 0)
    {

        if (z == "up" && map[x][y] == '~')
        {
            return OverlapCheck(x-1, y , num - 1, z);
        }
        else if (z == "down" && map[x][y] == '~')
        {
            return OverlapCheck(x+1, y , num - 1, z);
        }
        else if (z == "left" && map[x][y] == '~')
        {
            return OverlapCheck(x , y-1, num - 1, z);
        }
        else if (z == "right" && map[x][y] == '~')
        {
            return OverlapCheck(x , y+1, num - 1, z);
        }
        else
        {
            cout<<"overlap!"<<endl;
            return false;
        }
    }
    else
    {
        return true;
    }
}

bool board::PlaceShip(int x, int y, string z, int num,char mark)
{
    if (x >= 8 || x < 0)
    {
        return false;
    }
    else if (y >= 8 || y < 0)
    {
        return false;
    }
    else if (DimensionCheck(x, y, num, z)&&OverlapCheck(x,y,num,z))
    {
        MarkShip(x,y,num,z,mark);
        return true;
    }
    else
    {
      throw(std::runtime_error("can't place ship"));
        return false;
    }
}

void board::MarkShip(int x,int y,int num, string z,char mark)
{
    if (num >= 1)
    {

        if (z == "up")
        {
            map[x][y]=mark;
            MarkShip(x-1,y,num-1,z,mark);
        }
        else if (z == "down" )
        {
            map[x][y]=mark;
            MarkShip(x+1,y,num-1,z,mark);
        }
        else if (z == "left" )
        {
            map[x][y]=mark;
            MarkShip(x,y-1,num-1,z,mark);
        }
        else if (z == "right" )
        {
           map[x][y]=mark;
           MarkShip(x,y+1,num-1,z,mark);
        }
    }
}

bool board::Attack(int x, int y)
{
  if(!(map[x][y]=='~'))
  {
    map[x][y] = '*';
   return true;
  }
  return false;
}

void board::PrintGrid() {
  cout <<"\n       Enemy Board: \n\n";
  cout<< "         o = MISS \n         x = !HIT!\n";
  for(int i = 0; i < 8; i++) {
    if(i == 0) cout << "   A  B  C  D  E  F  G  H\n";
    for(int j = 0; j < 8; j++) {
      if(j == 0) cout << i+1;
       cout << "  " << grid[i][j];
    }
    cout << '\n';
  }
}

void board::update(int x, int y, bool hit)
{
  if(hit){
  grid[x][y]= 'x';
  //xCount++;
  }
  else grid[x][y]= 'o';
  //PrintGrid();
}

bool board::retryCheck(int x, int y)
{
  if(grid[x][y] == 'x')
  {
    return true;
  }
  else if(grid[x][y] == 'o')
  {
    return true;
  }
  else
  {
    return false;
  }
}
