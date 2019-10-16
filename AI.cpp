#include "AI.h"

AI::AI()
{
  marks = "abcde";
  num_hits = 0;
  marked = 0;
}

void AI::setNum(int x)
{
  unmark = x;
  numOfShip = x;
}

int AI::getMarks()
{
  return marked;
}

void AI::placement(int x, int y, int z)
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

  if(marked < numOfShip)
  {
    try
    {
      char label=marks.at(marked);
      //cout<<label<<endl;
      aiBoard.PlaceShip(x,y,direction,marked+1,label);
      marked=marked+1;
      unmark=unmark-1;
    }

    catch(const std::runtime_error& e)
    {
      // cout << "Silly AI. Try again.";
    }
  }
}

bool AI::isAllMarked()
{
  if(numOfShip > marked)
    return false;

  else
    return true;
}

void AI::update(int x, int y, bool hit)
{
  aiBoard.update(x, y, hit);
}

bool AI::attack(int x, int y)
{
    if(aiBoard.Attack(x, y))
    {
      num_hits++;
      cout << "\nYour attack was SUCCESSFUL\n";
      return true;
    }
    cout << "\n\n\n\n\n\nSPLOOSH!! No ship here.\n";
    return false;
}


void AI::printHidden()
{
  aiBoard.PrintGrid();
}

void AI::print()
{
  aiBoard.PrintMap();
}

int AI::getHits()
{
  return num_hits;
}

bool AI::hitRetry(int x, int y)
{
  return(aiBoard.retryCheck(x, y));
}

void AI::setDifficulty(int difficulty)
{
  if(difficulty == 1)
  {
    this->difficultyAI = "Easy";
  }

  else if(difficulty == 2)
  {
    this->difficultyAI = "Medium";
  }

  else if(difficulty == 3)
  {
    this->difficultyAI = "Hard";
  }

  else
  {
    cout << "Please input a valid difficulty.\n";
  }
}

string AI::getDifficulty()
{
  return this->difficultyAI;
}

void AI::setPlayerCalledAttack(bool called)
{
  this->playerCalledAttack = called;
}
