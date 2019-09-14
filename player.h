#ifndef player_h
#define player_h
#include<iostream>
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
