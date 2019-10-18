#include "Inventory.h"



//Default Constructor
Inventory::Inventory()
{}

Inventory::~Inventory(){}

//Reads from the file "InventoryFile" defined above to populate shotArray
// and cheatnum variables. Run first if already have inventory file setup
void Inventory::readFromInventoryFile()
{
	cout << "readFromInventoryFile Called " << inventoryFile << "\n\n";
	string input;
	std::ifstream file;
	file.open(inventoryFile, fstream::in);
	for (int i = 0; NUM_SHOT_TYPES > i; i++)
	{
		for (int j = 0; NUM_SHOT_VARIABLES > j; j++)
		{
			file >> input;
			if (input == "Name:")
			{			
				file >> input;
				cout << "Reading: " + input + "\n";
				shotArray[i].setShotName(input);
			}
			else if (input == "Code:")
			{								
				file >> input;
				cout << "Reading: " + input + "\n";
				shotArray[i].setShotCode(input[0]);
			}
			else if (input == "Pattern:")
			{								
				file >> input;
				cout << "Reading: " + input + "\n";
				shotArray[i].setPattern(input[0]);
			}
			else if (input == "Amount:")
			{							
				file >> input;
				cout << "Reading: " + input + "\n";
				shotArray[i].setAmmount(stoi(input));
			}
			else if (input == "Range:")
			{					
				file >> input;
				cout << "Reading: " + input + "\n";
				shotArray[i].setRange(stoi(input));
			}
		}
	}
	file >> input;
	cout << "Reading: " + input + "\n";
	if(input == "-cheatermode")
	{
		file >> input;
		cout << "Reading: " + input + "\n";
		if(input == "enabled")
		{
			setCheaterMode(true);
		}
		else if(input == "disabled")
		{
			setCheaterMode(false);
		}
	}

	file.close();
}

//Writes current inventory to the inventoryFile defined above. Warning
//WARNING:Default constructor for Shot produces nonsense so only write after
//Variables have been manually set or read from already existing file
void Inventory::writeToInventoryFile()
{
	std::ofstream file;
	string input = "";

	file.open(inventoryFile, fstream::trunc);
	for (int i = 0; NUM_SHOT_TYPES > i; i++)
	{
		input = input
			+ "Name: " + shotArray[i].getShotName() + "\n"
			+ "Code: " + shotArray[i].getShotCode() + "\n"
			+ "Pattern: " + shotArray[i].getPattern() + "\n"
			+ "Ammount: " + to_string(shotArray[i].getAmmount()) + "\n"
			+ "Range: " + to_string(shotArray[i].getRange()) + "\n\n";
	}

	input = input + "-cheatermode\nNum: " + to_string(numCheat);


	file << input;
	file.close();

}

void Inventory::setInventoryFile(string input)
{	
	cout << "setInventoryFile Called: " << input << " \n\n";
	inventoryFile = input;
}
string Inventory::getInventoryFile()
{
	return inventoryFile;
}
void Inventory::setNumCheat(int input)
{
	numCheat = input;
}
int Inventory::getNumCheat()
{
	return numCheat;
}

Shot* Inventory::getShotArray()
{
	return shotArray;
}

void Inventory::setShotArray(Shot* input)
{
	for (int i = 0; NUM_SHOT_TYPES > i; i++)
	{
		shotArray[i] = input[i];
	}
}

void Inventory::printInventory()
{
	for(int i = 0; i < NUM_SHOT_TYPES; i++)
	{
		cout << "Name: " << shotArray[i].getShotName() << "\n" <<
				"ShotCode: " << shotArray[i].getShotCode() << "\n" <<
				"Pattern: " << shotArray[i].getPattern() << "\n" <<
				"Amount: " << shotArray[i].getAmmount() << "\n" <<
				"Range: " << shotArray[i].getRange() << "\n\n";
	}
	if(getCheaterMode())
	{
		cout << "cheatermode: enabled\n\n";
	}
	else
	{
		cout << "cheatermode: disabled\n\n";
	}
	
}

void Inventory::setCheaterMode(bool mode)
{
	cheatermode = mode;
}

bool Inventory::getCheaterMode()
{
	return cheatermode;
}
