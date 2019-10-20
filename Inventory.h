#pragma once
#include "Shot.h"
#include <fstream>
#include <iostream>
#include <array>
#include <limits>
#include <time.h>

using namespace std;

const int NUM_SHOT_TYPES = 5;
const int NUM_SHOT_VARIABLES = 5;

class Inventory
{
private:
	
	string rollArray[5] = {"Bomb", "Cross", "Vertical", "Horizontal", "Nuke"};
	string inventoryFile = "";
	int numCheat = 0;
	Shot shotArray[NUM_SHOT_TYPES];
	bool cheatermode = false;

public:
/** Default Constructor
 *@pre none
 *@post All parts of inventory will be initalized to dummy variables
 *@param None */
	Inventory();

/** Default Deconstructor
 *@pre none
 *@post All reserved memory should be unreserved
 *@param None */
	~Inventory();
	
/** Reads in inventory from the file described by inventoryFile
 *@pre setInventorFile should be ran before this to set intended file to read
 *@post shotArray and cheatermode should be initalized to variables from file
 *@param none  */
	void readFromInventoryFile();
	
/** Writes to file described by inventoryFile
 *@pre readFromINventoryFile should be read, or file will be overwritten with default values for shotArray and file should be set by setInventoryfile before running
 *@pre  
 *@post file will store state from shotArray and cheatermode
 *@param none  */
	void writeToInventoryFile();
	
/** Adds a single shot to the ammount of the shot described by the input
 *@pre none
 *@post shot with the inputted shotname will have one added to its ammount
 *@param takes in the name of the shot to increment  */
	void addShot(string shotName);
	
/** sets the inventoryFile variable
 *@pre none
 *@post inventoryFile should now hold the new value
 *@param takes in new value for inventoryFile  */
	void setInventoryFile(string);
	
/** gets the inventoryFile variable
 *@pre none
 *@post returns inventoryFile
 *@param none  */
	string getInventoryFile();
	
/** sets the numCheat variable
 *@pre none
 *@post numCheat should now hold the new value
 *@param takes in new value for numCheat  */
	void setNumCheat(int);

/** Gets the inventoryFile variable
 *@pre none
 *@post returns numCheat
 *@param none  */
	int getNumCheat();

/** gets the shotArray variable
 *@pre none
 *@post return shotArray
 *@param none  */
	Shot* getShotArray();
	
/** sets the shotArray variable
 *@pre none
 *@post shotArray should now hold the new value
 *@param Takes in  new value for shotArray */
	void setShotArray(Shot*);
	
/** Prints out whole inventory to cout
 *@pre none
 *@post inventory should be printed
 *@param none  */
	void printInventory();	
	
/** Prints out each shot in shotarray as long as it has at least one in amount
 *@pre none
 *@post inventory should be printed
 *@param none  */
	void printInventory2();
	
/** sets the cheatermode variable
 *@pre none
 *@post cheatermode should now hold the new value
 *@param new value for cheatermode  */
	void setCheaterMode(bool);
	
/** gets the cheatermode variable
 *@pre none
 *@post return cheatermode
 *@param none  */
	bool getCheaterMode();
	
/** Randomly adds a shot whose name is in rollArray.
 *@pre none
 *@post shot rolled should have ammount incremented and message displayed
 *@param rollArray contains valid names for shots, int is size of said array \*/
	void shuffleArray(string rollArray[], int size);
	
/** Same as other call, uses standard size of 5 and rollarray variable
 *@pre none
 *@post shot rolled should have ammount incremented and message displayed
 *@param none  */
	void shuffleInventoryArray();
	
	/** displays a menu and lets player choose a shot to use
 *@pre none
 *@post return player choice and menu should be displayed
 *@param none  */
	int powerUpSelectMenu();
	
	/** returns true of all shots in shotArray have amounts = 0
 *@pre none
 *@post returns true or false
 *@param none  */
	bool isInventoryEmpty();
	
};

