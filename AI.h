#ifndef AI_H
#define AI_H

#include <iostream>
#include "board.h"
#include "PlayerInterface.h"
#include <time.h>

using namespace std;

class AI : public PlayerInterface
{
  private:
    Board aiBoard;//access the board object
    string marks;
    int marked;//ships that are marked
    int unmark;//ships that are unmarked
    int num_hits;
    int numOfShip;

    string difficultyAI;

  public:

     AI();

     void setNum(int x);

     void placement(int x, int y, int z);

     void print();

     bool isAllMarked();

     int getHits();

     void printHidden();

     bool attack(int x, int y);

     void update(int, int, bool);

     int getMarks();

     bool hitRetry(int x, int y);

     void setDifficulty(int difficulty);

     string getDifficulty();

};
#endif
