#include "PatternManager.h"

/* Will need to include the ability to shoot then replace
   the cout call with this once inclusion is done*/ 
void PatternManager::bomb(int range, string cordinates)
{
	string strike = "  ";
	for (int i = -range; range >= i; i++)
	{
		for (int j = -range; range >= j; j++)
		{
			strike[0] = (cordinates[0] + i);
			strike[1] = (cordinates[1] + j);
			if (checkFirstAxis(strike[0]) && checkSecondAxis(strike[1]))
				cout << strike[0] << strike[1] << "\n";
		}

	}
}

/* Will need to include the ability to shoot then replace
   the cout call with this once inclusion is done*/ 
void PatternManager::cross(int range, string cordinates)
{
	string strike = "  ";
	for (int i = -range; range >= i; i++)
	{
		strike[0] = (cordinates[0] + i);
		strike[1] = (cordinates[1]);
		if (checkFirstAxis(strike[0]) && checkSecondAxis(strike[1]))
			cout << strike[0] << strike[1] << "\n";

		strike[0] = (cordinates[0]);
		strike[1] = (cordinates[1] + i);
		if (checkFirstAxis(strike[0]) && checkSecondAxis(strike[1]))
			cout << strike[0] << strike[1] << "\n";
	}
}

/* Will need to include the ability to shoot then replace
   the cout call with this once inclusion is done*/ 
void PatternManager::Xshot(int range, string cordinates)
{
	string strike = "  ";
	for (int i = -range; range >= i; i++)
	{
		strike[0] = (cordinates[0] + i);
		strike[1] = (cordinates[1] + i);
		if (checkFirstAxis(strike[0]) && checkSecondAxis(strike[1]))
			cout << strike[0] << strike[1] << "\n";

		strike[0] = (cordinates[0] - i);
		strike[1] = (cordinates[1] + i);
		if (checkFirstAxis(strike[0]) && checkSecondAxis(strike[1]))
			cout << strike[0] << strike[1] << "\n";
	}
}

/* Will need to include the ability to shoot then replace
   the cout call with this once inclusion is done*/ 
void PatternManager::horizontal(int range, string cordinates)
{
	string strike = "  ";
	for (int i = -range; range >= i; i++)
	{
		strike[0] = (cordinates[0] + i);
		strike[1] = (cordinates[1]);
		if (checkFirstAxis(strike[0]) && checkSecondAxis(strike[1]))
			cout << strike[0] << strike[1] << "\n";
	}
}

void PatternManager::vertical(int range, string cordinates)
{
	
}

void PatternManager::coldWarGoneWrong()
{
	
}

void PatternManager::coldWarGoneWrong(int range, string cordinates)
{
	
}


bool PatternManager::checkFirstAxis(char Check)
{
	if (Check == 'A' ||
		Check == 'B' ||
		Check == 'C' ||
		Check == 'D' ||
		Check == 'E' ||
		Check == 'F' ||
		Check == 'G' ||
		Check == 'H')
		return true;
	else
		return false;
}


bool PatternManager::checkSecondAxis(char Check)
{
	if (Check == '1' ||
		Check == '2' ||
		Check == '3' ||
		Check == '4' ||
		Check == '5' ||
		Check == '6' ||
		Check == '7' ||
		Check == '8')
		return true;
	else
		return false;
}
