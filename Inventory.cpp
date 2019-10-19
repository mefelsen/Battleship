#include "Inventory.h"



//Default Constructor
Inventory::Inventory()
{}

Inventory::~Inventory(){}

//Reads from the file "InventoryFile" defined above to populate shotArray
// and cheatnum variables. Run first if already have inventory file setup
void Inventory::readFromInventoryFile()
{
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
				shotArray[i].setShotName(input);
			}
			else if (input == "Code:")
			{								
				file >> input;
				shotArray[i].setShotCode(input[0]);
			}
			else if (input == "Pattern:")
			{								
				file >> input;
				shotArray[i].setPattern(input[0]);
			}
			else if (input == "Amount:")
			{							
				file >> input;
				shotArray[i].setAmmount(stoi(input));
			}
			else if (input == "Range:")
			{					
				file >> input;
				shotArray[i].setRange(stoi(input));
			}
		}
	}
	file >> input;
	if(input == "-cheatermode")
	{
		file >> input;
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

void Inventory::printInventory2()
{
	for(int i = 0; i < NUM_SHOT_TYPES; i++)
	{
		if(shotArray[i].getAmmount() > 0)
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

int Inventory::powerUpSelectMenu()
{
	//display menu options
	cout << "----- Select PowerUp -----\n" << std::endl;
	cout <<	"(0) - - - None Selected\n";
	cout << "(1) - - - Bomb\n";
	cout <<	"(2) - - - Cross\n";
	cout <<	"(3) - - - Vertical\n";
	cout <<	"(4) - - - Horizontal\n";
	cout <<	"(5) - - - Nuke\n";
	

  //create switch case for return value
  int x = 0;
  cin >> x;

  switch(x)
  {
	case 0:
		return (0);
    case 1:
      	return (1);
    case 2:
      	return (2);
    case 3:
      	return (3);
    case 4:
      	return (4);
    case 5:
      	return (5);
    default:
      	return (6);
  }
}
