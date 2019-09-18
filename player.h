#ifndef player_h
#define player_h
#include<iostream>
#include"board.h"
using namespace std;

class player
{
    private:
    board access;//access the board object

    string marks;
    int marked;//ships that are marked
    int unmark;//ships that are unmarked
    int num_hits;
    int numofship;

    public:
    /* Default constructor
 @pre none
 @post  initalize marks which is use to mark different ships
 @param None  */
    player();
    /* Default constructor
 @pre takes in a integer x
 @post set up # of ships and set those ships are unmark
 @param None  */
    void setnum(int x);
    /* Default constructor
 @pre take in three integers x is row, y is col, z is the direction(1~4)
 @post throw a error when the direction worrg and catch a error when placment fails
 @param None  */
    void placement(int x,int y,int z);
    /* Default constructor
 @pre none
 @post print the map in board object
 @param None  */
    void print();
/* Default constructor
 @pre none
 @post return true if all ships are marked, false otherwise
 @param None  */
    bool IsAllMarked();

    /* Gets the number of times a player has hit the enemies's ships
 @pre none
 @post return num_hits
 @param None  */
    int GetHits();

};
#endif
