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
	Inventory();
	~Inventory();
	void readFromInventoryFile();
	void writeToInventoryFile();
	void setInventoryFile(string);
	string getInventoryFile();
	void setNumCheat(int);
	int getNumCheat();
	Shot* getShotArray();
	void setShotArray(Shot*);
	void printInventory();	
	void setCheaterMode(bool);
	bool getCheaterMode();
	void shuffleArray(string rollArray[], int size);
	void shuffleInventoryArray();
	//int powerUpSelectMenu();
	
};

