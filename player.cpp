#include "player.h"
player::player()
{
    name = "";
    map = new char *[8];
    flags=5;
    acctmap = new char *[8];
    for (int i = 0; i < 8; i++)
    {
        map[i] = new char[8];
        acctmap[i] = new char[8];
        for (int j = 0; j < 8; j++)
        {
            map[i][j] = '~';
            acctmap[i][j] = '~';
        }
    }
}
bool player::dimitioncheck(int x, int y, int num, string z)
{
    if (z == "up" && x - num >= 0)
    {
        return true;
    }
    else if (z == "down" && x + num < 8)
    {
        return true;
    }
    else if (z == "left" && y - num >= 0)
    {
        return true;
    }
    else if (z == "right" && y + num < 8)
    {
        return true;
    }
    else
    {
        cout<<"out of borad"<<endl;
        return false;
    }
}
bool player::overlapcheck(int x, int y, int num, string z)
{
    if (num > 1)
    {

        if (z == "up" && map[x][y] == '~')
        {
            return overlapcheck(x-1, y , num - 1, z);
        }
        else if (z == "down" && map[x][y] == '~')
        {
            return overlapcheck(x+1, y , num - 1, z);
        }
        else if (z == "left" && map[x][y] == '~')
        {
            return overlapcheck(x , y-1, num - 1, z);
        }
        else if (z == "right" && map[x][y] == '~')
        {
            return overlapcheck(x , y+1, num - 1, z);
        }
        else
        {
            cout<<"overlap!"<<endl;
            return false;
        }
    }
    else
    {
        return true;
    }
}
bool player::placeship(int x, int y, string z, int num)
{
    if (x >= 8 || x < 0)
    {
        return false;
    }
    else if (y >= 8 || y < 0)
    {
        return false;
    }
    else if (dimitioncheck(x, y, num, z)&&overlapcheck(x,y,num,z))
    {
        markship(x,y,num,z);
        return true;
    }
    else
    {
        return false;
    }
}
void player::markship(int x,int y,int num, string z)
{
    if (num >= 1)
    {

        if (z == "up")
        {
            map[x][y]='A';
            markship(x-1,y,num-1,z);
        }
        else if (z == "down" )
        {
            map[x][y]='A';
            markship(x+1,y,num-1,z);
        }
        else if (z == "left" )
        {
            map[x][y]='A';
            markship(x,y-1,num-1,z);
        }
        else if (z == "right" )
        {
           map[x][y]='A';
           markship(x,y+1,num-1,z);
        }
    }
}
void player::setname(string n)
{
    name = n;
}

string player::getname() const
{
    return name;
}

void player::printgetmap()
{
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 8; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}