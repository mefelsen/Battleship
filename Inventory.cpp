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
				shotArray[i].setAmount(stoi(input));
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
			+ "Amount: " + to_string(shotArray[i].getAmount()) + "\n"
			+ "Range: " + to_string(shotArray[i].getRange()) + "\n\n";
	}

	input = input + "-cheatermode\nNum: " + to_string(numCheat);


	file << input;
	file.close();

}

void Inventory::addShot(string shotName)
{
	for(int i = 0; i < NUM_SHOT_TYPES; i++)
	{
		if(shotArray[i].getShotName() == shotName)
		{
			shotArray[i].setAmount(shotArray[i].getAmount() + 1);
		}
	}
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
				"Amount: " << shotArray[i].getAmount() << "\n" <<
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
		if(shotArray[i].getAmount() > 0)
		cout << "Name: " << shotArray[i].getShotName() << "\n" <<
				"ShotCode: " << shotArray[i].getShotCode() << "\n" <<
				"Pattern: " << shotArray[i].getPattern() << "\n" <<
				"Amount: " << shotArray[i].getAmount() << "\n" <<
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
	if(isInventoryEmpty())
	{
		cout << "Inventroy is empty...\n\n";
		return 0;
	}
	else
	{	
		//display menu options
		cout << "----- Select PowerUp -----\n" << std::endl;
		cout <<	"(0) - - - None Selected\n";
		cout << "(1) - - - Bomb\n";
		cout <<	"(2) - - - Cross\n";
		cout <<	"(3) - - - Vertical\n";
		cout <<	"(4) - - - Horizontal\n";
		cout <<	"(5) - - - Nuke\n\n";
		
		cout << "-----Inventory-----\n";
		printInventory2();

		//create switch case for return value
		while(true)
		{
			int x = 0;
			cin >> x;
			/*check for amounts here for each shot type*/
			switch(x)
			{
				case 0:
					return (0);
				case 1:
				{
					//check for bombs
					if(shotArray[0].useShot())
					{
						return (1);
					}      
					else
					{
						cout << shotArray[0].getShotName() << " is not available. Select another power up: "; 
					}
					break;
				}
				case 2:
				{
					//check for cross
					if(shotArray[1].useShot())
					{
						return (2);
					}      
					else
					{
						cout << shotArray[1].getShotName() << " is not available. Select another power up: "; 
					}
					break;
				}
				case 3:
				{
					//check for vertical
					if(shotArray[2].useShot())
					{
						return (3);
					}      
					else
					{
						cout << shotArray[2].getShotName() << " is not available. Select another power up: "; 
					}
					break;
				}
				case 4:
				{
					//check for horizontal
					if(shotArray[3].useShot())
					{
						return (4);
					}      
					else
					{
						cout << shotArray[3].getShotName() << " is not available. Select another power up: "; 
					}
					break;
				}
				case 5:
				{
					//check for nuke
					if(shotArray[4].useShot())
					{
						return (5);
					}      
					else
					{
						cout << shotArray[4].getShotName() << " is not available. Select another power up: "; 
					}
					break;
				}
				default:
					return (6);
			}
		}
		
	}	
}


void Inventory::shuffleInventoryArray()
{
	shuffleArray(rollArray, 5);
}


void Inventory::shuffleArray(string rollArray[], int size)
{
    srand(time(0));  // Initialize random number generator.
  for(int i = 0; i < (size * 10); i++)
  {
    int index1 = (rand() % size);
    int index2 = (rand() % size);
    string placeHolder = rollArray[index1];
    rollArray[index1] = rollArray[index2];
    rollArray[index2] = placeHolder;
  }

  cout << "Power Up from loot box is: " + rollArray[0] + "\n\n";
  addShot(rollArray[0]);
  printInventory2();
  writeToInventoryFile();
}

bool Inventory::isInventoryEmpty()
{
	int inventorySize = 0;
	for(int i = 0; i < NUM_SHOT_TYPES; i++)
	{
		if(shotArray[i].getAmount() > 0)
		{
			inventorySize = inventorySize + shotArray[i].getAmount();
		}
	}
	if(inventorySize > 0)
	{
		return false;
	}
		return true;

}
