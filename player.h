#ifndef player_h
#define player_h
#include<iostream>
#include"board.h"
using namespace std;

class player
{
    private:
      board my_board;
      board enemy_board;
      int num_ships;

    public:
      player();
      player(int ships);


};
#endif
