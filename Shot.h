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
	int ammount;
public:
	Shot();
	~Shot();
	bool useShot();
	string getShotName();
	void setShotName(string input);
	char getShotCode();
	void setShotCode(char input);
	char getPattern();
	void setPattern(char input);
	int getRange();
	void setRange(int input);
	int getAmmount();
	void setAmmount(int input);
};

