#pragma once
#include <string>
#include <iostream>
using namespace std;
class PatternManager
{
	//Note cordinates needs to be a string of at least length 2.
public:
/** hits tiles in a square AOE
 *@pre none
 *@post every tile on pattern hit
 *@param cordinates is the mid point of the square AOE, range is distance from center it hits */
	void bomb(int range, string cordinates);
	
/** hits tiles in a + pattern
 *@pre none
 *@post every tile on pattern hit
 *@param cordinates is the mid point of the line, range is the legnth of each branch */
	void cross(int range, string cordinates);
	
/** hits tiles in a X pattern
 *@pre none
 *@post every tile on pattern hit
 *@param cordinates is the mid point of the line, range is the legnth of each branch */
	void Xshot(int range, string cordinates);
	
/** hits tiles in a horizontal line
 *@pre none
 *@post every tile on line hit
 *@param cordinates is the mid point of the line, range is the furthest hit from center */
	void horizontal(int range, string cordinates);
	/** hits tiles in a vertical line
 *@pre none
 *@post every tile on line hit
 *@param cordinates is the mid point of the line, range is the furthest hit from center */
	void vertical(int range, string cordinates);
	
/** hits every tile on board
 *@pre none
 *@post every tile on board hit
 *@param none  */
	void coldWarGoneWrong();
	
/** hits every tile on board
 *@pre none
 *@post every tile on board hit
 *@param range and cordinates are dummy variables to keep consistent with other methods  */
	void coldWarGoneWrong(int range, string cordinates);
private:

/** Checks if value is valid for the first part of cordinate string
 *@pre none
 *@post returns true if character is valid for the letter axis
 *@param takes in character to be checked  */
	bool checkFirstAxis(char Check);
/** Checks if value is valid for the second part of cordinate string
 *@pre none
 *@post returns true if character is valid for the number axis
 *@param takes in character to be checked  */
	bool checkSecondAxis(char Check);

};

