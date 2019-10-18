#ifndef POWERUPS_H
#define POWERUPS_H
#include <string>
#include "HumanPlayer.h" 
#include "AI.h"
#include <fstream>
#include <limits>
#include <time.h>
#include <iostream>

using namespace std;

    class PowerUpBoard
    {
        private:
            int numPowerUps = 0;
            char pBoard[8][8];

        public:
            PowerUpBoard();

            ~PowerUpBoard();

            void powerUpSetter(int numPowerUps);

            void shuffleArray(int powerUpPos[], int size);

            void displayPowerUps();

            bool update(int x, int y);
    };
#endif