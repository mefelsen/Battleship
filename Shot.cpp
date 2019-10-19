#include "Shot.h"
#include <array>

Shot::Shot() : shotname("z"),
			   shotCode('z'),
	           pattern('z'),
			   range(0),
			   amount(0)
{}

Shot::~Shot(){}

//Run this for a cleaner decrement of shot after being used returnss false if no shots are left for use
bool Shot::useShot()
{
	if (amount >= 0)
	{
		amount--;
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

int Shot::getAmount()
{
	return amount;
}

void Shot::setAmount(int input)
{
	amount = input;
}


