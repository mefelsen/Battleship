#include "HumanPlayer.h"
#include <bits/stdc++.h>


HumanPlayer::HumanPlayer()
{
  marks = "abcde";
  num_hits = 0;
  marked = 0;
}
void HumanPlayer::setNum(int x)
{
    unmark = x;
    numOfShip = x;
}

int HumanPlayer::getMarks()
{
  return marked;
}

void HumanPlayer::placement(int x,int y,int z)
{
    string direction;
    if(z==1)
    {
        direction="up";
    }
    else if (z==2)
    {
        direction="down";
    }
    else if(z==3)
    {
        direction="left";
    }
    else if(z==4)
    {
        direction="right";
    }
    else
    {
        throw(std::runtime_error(" "));
    }

    if(marked<numOfShip)
    {
        try
        {
            char label=marks.at(marked);
            //cout<<label<<endl;
            playerBoard.PlaceShip(x,y,direction,marked+1,label);
            marked=marked+1;
            unmark=unmark-1;
        }
        catch(const std::runtime_error& e)
        {
            cout<<"fail,try again"<<endl;
        }

    }

}

bool HumanPlayer::isAllMarked()
{
    if(numOfShip>marked)
    {
        return false;
    }
    else
    {
        return true;
    }

}

 void HumanPlayer::update(int x,int y, bool hit)
 {
   playerBoard.update(x,y, hit);
 }

bool HumanPlayer::attack(int x, int y)
{
    if(playerBoard.Attack(x, y))
    {
      num_hits++;
      cout << "\nAttack SUCCESSFUL at " << x << ' ' << y << '\n';
      return true;
    }
    cout << "\n\n\n\n\n\nSPLOOSH!! No ship here at " << x << ' ' << y << '\n';
    return false;
}

void HumanPlayer::printHidden()
{
  playerBoard.PrintGrid();
}

void HumanPlayer::print()
{
    playerBoard.PrintMap();
}

int HumanPlayer::getHits()
{
  return num_hits;
}

bool HumanPlayer::hitRetry(int x, int y)
{
  return(playerBoard.retryCheck(x, y));
}

void HumanPlayer::setInventoryFile(string fileName)
{

  WeaponInventory.setInventoryFile(fileName);
}

void HumanPlayer::loadInventory()
{
  WeaponInventory.readFromInventoryFile();
}

void HumanPlayer::printInventory()
{
  WeaponInventory.printInventory();
}

void HumanPlayer::printInventory2()
{
  WeaponInventory.printInventory2();
}

void HumanPlayer::inventorySelect()
{
  int x = 0;
  while(x != 9)
  {
    x = WeaponInventory.powerUpSelectMenu();
    switch(x)
    {
      case 0:
        cout << " Nothing selected\n";
        x = 9;
        break;
      case 1:
        cout << "Bomb Selected\n\n";
        x = 9;
        break;
      case 2:
        cout << "Cross Selected\n";
        x = 9;
        break;
      case 3:
        cout << "Vertical Selected\n";
        x = 9;
        break;
      case 4:
        cout << "Horizontal Selected\n";
        x = 9;
        break;
      case 5:
        cout << "Nuke Selected\n";
        x = 9;
        break;
      default:
        cout << "Please enter an integer between 0-5\n";
      break;
    }
  }
}

Board HumanPlayer::getBoard()
{
  return playerBoard;
}

void HumanPlayer::inventoryRoll()
{
 WeaponInventory.shuffleInventoryArray();
}
