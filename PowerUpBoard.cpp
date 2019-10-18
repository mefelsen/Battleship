#include "PowerUpBoard.h"

PowerUpBoard::PowerUpBoard()
{}

void PowerUpBoard::powerUpSetter(int numPowerUps)
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      pBoard[i][j] = '~';
    }
  }

  int* powerUpPositions = new int[64];
  for(int i = 0; i < 64; i++)
  {
    powerUpPositions[i] = i;
  }

  //Shuffle the powerUpPositions array;
  shuffleArray(powerUpPositions, 64);

  int r = 0;
  for(int i = 0; i < numPowerUps; i++)
  {
    r = powerUpPositions[i];
    int x = r / 8;
    int y = r % 8;
    pBoard[x][y] = 'x';
  }
}

PowerUpBoard::~PowerUpBoard()
{

}

void PowerUpBoard::shuffleArray(int powerUpPos[], int size)
{
    srand(time(0));  // Initialize random number generator.
  for(int i = 0; i < (size * 10); i++)
  {
    int index1 = (rand() % size);
    int index2 = (rand() % size);
    int placeHolder = powerUpPos[index1];
    powerUpPos[index1] = powerUpPos[index2];
    powerUpPos[index2] = placeHolder;
  }
}

void PowerUpBoard::displayPowerUps()
{
    cout <<"\n       Power Ups: \n\n";
  for(int i = 0; i < 8; i++) {
    if(i == 0) cout << "   A  B  C  D  E  F  G  H\n";
    for(int j = 0; j < 8; j++) {
      if(j == 0) cout << i+1;
       cout << "  " << pBoard[i][j];
    }
    cout << '\n';
  }
}

bool PowerUpBoard::update(int x, int y)
{
  if((pBoard[x][y]=='x'))
  {
    pBoard[x][y] = '*';
   return true;
  }
  return false;
}