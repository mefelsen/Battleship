#ifndef player_h
#define player_h
#include<iostream>
using namespace std;

class player
{
    private:
    string name;
    int health;

    char** map;
    char** acctmap;

    int numship;
    int flags;//[sep13 stop mark] tring to make a flag for each ships
    

    public:
    player();
    void setname(string name);
    string getname() const;

    void printgetmap();
    
    bool placeship(int st,int dir,string x,int num);
    //checkers when placement
    bool dimitioncheck(int x, int y,int num,string z); // check 1x2,1x3... ship is in the borad
    bool overlapcheck(int x,int y,int num, string z); //recursive check if spot is empty
    // markship
    void markship(int x,int y,int num, string z);//recursive mark the borad

    void acct(int row,int col);

    int gethealth();
    

};
#endif
