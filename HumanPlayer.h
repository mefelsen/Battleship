#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <iostream>
#include "board.h"
#include "PlayerInterface.h"
#include <time.h>
#include "Inventory.h"

using namespace std;

class HumanPlayer : public PlayerInterface
{
    private:
    Board playerBoard;//access the board object
    string marks;
    int marked;//ships that are marked
    int unmark;//ships that are unmarked
    int num_hits;
    int numOfShip;
    int coordinatesArraySize = 64;
    string targetCoordinates[64];
    int turn = 0;
    Inventory WeaponInventory;

    public:
    /** Default constructor
 *@pre none
 *@post  initalize marks which is use to mark different ships
 *@param None  */
    HumanPlayer();

    /** Default constructor
 *@pre takes in a integer x
 *@post set up # of ships and set those ships are unmark
 *@param None  */
    void setNum(int x);
    /**Default constructor
 *@pre take in three integers x is row, y is col, z is the direction(1~4)
 *@post throw a error when the direction worrg and catch a error when placment fails
 *@param None  */
    void placement(int x, int y, int z);
    /** Default constructor
 *@pre none
 *@post print the map in board object
 *@param None  */
    void print();

/** Default constructor
 *@pre none
 *@post return true if all ships are marked, false otherwise
 *@param None  */
    bool isAllMarked();

    /** Gets the number of times a player has hit the enemies's ships
 *@pre none
 *@post return num_hits
 *@param None  */
    int getHits();

    /** Prints the hidden map for the player who called it
 *@pre none
 *@post print the "grid" in board object
 *@param None  */
 void printHidden();

 /** calls the board class to compare char and attck if match is found
*@pre none
*@post handles the attack/comparison
*@param  takes in the x and y coordiinate of where the player would like to attack*/
 bool attack(int x, int y, string diff);

 /** calls the board class to compare char and update the board
*@pre none
*@post handles the attack/comparison
*@param  takes in the x and y coordiinate of where the player would like to attack
 the bool is for determining if it was a success or not -- "x" or "o"  */
 void update(int,int, bool);

/** calls the board class to see if the attacking player has already shot at this position
*@pre none
*@post none
*@param  none
 the bool is for determining if it was a success or not  "o"  */
 int getMarks();

/** retry if you've already shot at the same location twice
*@pre none
*@post handles the attack/comparison
*@param  takes in the x and y coordiinate of where the player would like to attack
 the bool is for determining if it was a success or not --  "o"  */
 bool hitRetry(int x, int y);

 // string getTargetCoordinates();
 // void setTargetCoordinates();
 // void shuffleCoordinates(string arr[], int n);
 // void printRandomCoordinates();
 // void fireAtCoordinates();

 Board getBoard();

 void setInventoryFile(string fileName);
 void loadInventory();
 void printInventory();
 void inventoryRoll();
 //void inventorySelect();


};
#endif
