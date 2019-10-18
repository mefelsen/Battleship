#pragma once
#include "Shot.h"
#include <fstream>
#include <iostream>
#include <array>

using namespace std;
class Inventory
{
private:

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
};

