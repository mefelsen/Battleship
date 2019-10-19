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
  return(marked);
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

bool HumanPlayer::attack(int x, int y, string diff)
{

    if(playerBoard.Attack(x, y))
    {
      num_hits++;
      cout << "\nAttack SUCCESSFUL at " << x << ' ' << y << '\n';
      return true;
    }
    cout << "\n\n\n\n\n\nSPLOOSH!! No ship here at " << x << ' ' << y << '\n';
    return false;
    turn ++;

//
//   else if(diff == "Medium")
//   {
//
//   }
//
//   else if(diff == "Hard")
//   {
//
//   }
//
//   else
//  {
//      if(playerBoard.Attack(x, y)) {
//        num_hits++;
//        cout << "\nYour attack was SUCCESSFUL!\n";
//        return true;
//      }
//      cout <<"\nSPLOOSH!! No ship here.\n";
//      return false;
// //  }
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

/*void HumanPlayer::inventorySelect()
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
*/
/*
string AI::getTargetCoordinates()
{
  return targetCoordinates[0];
}
*/

// void HumanPlayer::setTargetCoordinates() {
//   string letters = "ABCDEFGH";
//   string nums = "12345678";
//   int letterIndex = 0;
//   int numIndex = 0;
//
//   for (int i = 0; i < 64; i++) {
//     targetCoordinates[i] = letters.at(letterIndex);
//     numIndex++;
//     if (numIndex >= 8) {
//       numIndex = 0;
//       letterIndex++;
//     }
//   }
//
//   for (int i = 0; i < 64; i++) {
//     targetCoordinates[i] = targetCoordinates[i] + nums.at(numIndex);
//     numIndex++;
//     if (numIndex >= 8) {
//       numIndex = 0;
//       letterIndex++;
//     }
//   }
//
//   srand(time(0));
//
//   int shuffleNumber = rand() % 1024;
//   cout << "Shuffling " << shuffleNumber << " times\n\n";
//
//   cout << "Coordiantes obtained\n\n";
//   printRandomCoordinates();
//
//   for (int i = 0; i < shuffleNumber; i++) {
//     shuffleCoordinates(targetCoordinates, 64);
//   }
//
//   cout << "Randomizing coordinates\n\n";
//   printRandomCoordinates();
// }
//
// // shuffle vs random_shuffle in C++
// // https://www.geeksforgeeks.org/shuffle-vs-random_shuffle-c/
// void HumanPlayer::shuffleCoordinates(string arr[], int n)
// {
//   // Shuffling our array using random_shuffle
//   random_shuffle(arr, arr + n);
// }
//
// void HumanPlayer::printRandomCoordinates()
// {
//   int index = 0;
//   for (int i = 0; i < 64; i++) {
//     cout << targetCoordinates[i] << ", ";
//     index++;
//     if(index == 8)
//     {
//       cout << "\n";
//       index = 0;
//     }
//   }
//   cout << "\n";
// }

/*
void HumanPlayer::fireAtCoordinates()
{
  string coordinates = getTargetCoordinates();
  string array[coordinatesArraySize];

  for (int i = 0; i < coordinatesArraySize; i++)
  {
    array[i] = targetCoordinates[i];
  }

  coordinatesArraySize--;

  targetCoordinates[coordinatesArraySize];

  for (int i = 0; i < coordinatesArraySize; i++)
  {
    targetCoordinates[i] = array[i + 1];
  }
}
*/

Board HumanPlayer::getBoard()
{
  return playerBoard;
}

 void HumanPlayer::inventoryRoll()
 {
   WeaponInventory.shuffleInventoryArray();
 }
