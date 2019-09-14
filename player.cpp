#include "player.h"
player::player()
{
    name = "";

}
void player::setname(string n)
{
    name = n;
}

string player::getname() const
{
    return name;
}

// void player::printgetmap()
// {
//     for (int i = 0; i < 8; i++)
//     {
//
//         for (int j = 0; j < 8; j++)
//         {
//             cout << map[i][j] << ' ';
//         }
//         cout << endl;
//     }
// }
