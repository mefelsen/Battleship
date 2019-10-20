#pragma once
#include <string>
#include <iostream>
using namespace std;
class PatternManager
{
	//Note cordinates needs to be a string of at least length 2.
public:
	void bomb(int range, string cordinates);
	void cross(int range, string cordinates);
	void Xshot(int range, string cordinates);
	void horizontal(int range, string cordinates);
	void vertical(int range, string cordinates);
	void coldWarGoneWrong();
	void coldWarGoneWrong(int range, string cordinates);
private:
	bool checkFirstAxis(char Check);
	bool checkSecondAxis(char Check);

};

