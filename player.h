#ifndef player_h
#define player_h
#include<iostream>
using namespace std;

class player
{
    private:
    string name;
    int health;

    int numship;
    int flags;//[sep13 stop mark] tring to make a flag for each ships


    public:
    player();
    void setname(string name);
    string getname() const;

    void acct(int row,int col);

    int gethealth();


};
#endif
