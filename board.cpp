#include "board.h"
#include <iostream>
using namespace std;
board::board() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      grid[i][j] = '~';
    }
  }
}

void board::printBoard(){
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

void board::addShip(){

}
