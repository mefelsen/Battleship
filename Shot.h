#pragma once
#include <string>
using namespace std;



class Shot
{

private:
	string shotname;
	char shotCode;
	char pattern;
	int range;
	int amount;

public:
 /** Default Constructor
 *@pre none
 *@post Initalizes the varaibles to be set later.
 *@param None  */
	Shot();
	
 /** Default Deconstructor
 *@pre none
 *@post Variables are deleted to free memory
 *@param None  */
	~Shot();
	
/** Called to attempt decrementing shot
 *@pre none
 *@post return true if shot was decremented, false otherwise.
 *@param None  */
	bool useShot();

 /** Gets the name of the shot
 *@pre none
 *@post return shotName
 *@param None  */
	string getShotName();
	
 /** Sets the name of the shot
 *@pre none
 *@post Shot name should be set to input
 *@param Takes in new name for shot  */
	void setShotName(string input);

 /** Gets the code of the shot
 *@pre none
 *@post return shotCode
 *@param None  */
	char getShotCode();
	
 /** Set the code of the shot
 *@pre none
 *@post Set shotCode to new code
 *@param Takes in new value for code  */
	void setShotCode(char input);

/** Gets the pattern of the shot
 *@pre none
 *@post return pattern
 *@param None */
	char getPattern();
	
/** Set the pattern of the shot
 *@pre none
 *@post Set pattern to new pattern
 *@param Takes in new value for pattern  */
	void setPattern(char input);

/** Get the range of the shot
 *@pre none
 *@post return range
 *@param None  */
	int getRange();
	
/** Set the code of the shot
 *@pre none
 *@post Set range to new value
 *@param Takes in the new value for range*/
	void setRange(int input);
	
/** Gets the ammount of shots
 *@pre none
 *@post return ammount
 *@param None  */
	int getAmount();
	
/** Set the amount of the shot
 *@pre none
 *@post Set amount to new value
 *@param input is the new value for amount  */
	void setAmount(int input);

};

