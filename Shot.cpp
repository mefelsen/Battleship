#include "Shot.h"
#include <array>

Shot::Shot() : shotname("z"),
			   shotCode('z'),
	           pattern('z'),
			   range(0),
			   ammount(0)
{}

Shot::~Shot(){}

//Run this for a cleaner decrement of shot after being used returnss false if no shots are left for use
bool Shot::useShot()
{
	if (ammount >= 0)
	{
		ammount--;
		return true;
	}
	else
	{
		return false;
	}
}

string Shot::getShotName()
{
	return shotname;
}

void Shot::setShotName(string input)
{
	shotname = input;
}

char Shot::getShotCode()
{
	return shotCode;
}

void Shot::setShotCode(char input)
{
	shotCode = input;
}

char Shot::getPattern()
{
	return pattern;
}

void Shot::setPattern(char input)
{
	pattern = input;
}

int Shot::getRange()
{
	return range;
}

void Shot::setRange(int input)
{
	range = input;
}

int Shot::getAmmount()
{
	return ammount;
}

void Shot::setAmmount(int input)
{
	ammount = input;
}


