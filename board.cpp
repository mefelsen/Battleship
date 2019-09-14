#include "board.h"
#include <iostream>
using namespace std;

void board::run()
{
   one.printgetmap();
   if(one.placeship(2,3,"down",3))
   {
       cout<<"complete!!"<<endl;
       one.printgetmap();
   }
   cout<<"overlap test"<<endl;

   if(one.placeship(2,2,"right",3))
   {
       cout<<"complete!!"<<endl;
       one.printgetmap();
   }
   else
   {    cout<<"not complete!!"<<endl;
        one.printgetmap();
   }
   
}
